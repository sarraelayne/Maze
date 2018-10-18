#include "Pathfinder.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

Pathfinder::Pathfinder() {

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                maze[k][j][i] = 1;
            }
        }
    } 
}
string Pathfinder::toString() const {
    stringstream ss;
    
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                ss << maze[k][j][i];
                if (k < 4) {
                    ss << " ";
                }
            }
            ss << endl;
        }
        if(i < 4) {
            ss << endl;
        }
    }
    return ss.str();
}

void Pathfinder::createRandomMaze() {
    int mazeDigit;
    srand(time(NULL));
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                mazeDigit = rand() % 2;
                maze[k][j][i] = mazeDigit;
            }
        }
    }
    maze[0][0][0] = 1;
    maze[4][4][4] = 1;
    //cout << "Maze: " << endl;
    /*for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                cout << maze[k][j][i] << " ";
            }
        }
    }*/
}
bool Pathfinder::importMaze(string file_name) {
    ifstream importFile;
    string line;
    char token;
    int one_count=0;
    int zero_count=0;
    int count = 0;
    int height;
    int rows;
    int cols;
    
    cout << "importing maze"<< endl;
    importFile.open(file_name.c_str());
    
    
    if(importFile.is_open()){
        while(importFile >> token){
            if(token == '1'){
                one_count++;
                count++;
            } 
            else if(token == '0'){
                zero_count++;
                count++;
            }
            else {
                return false;
            }
        }
        importFile.close();
    } 
    else {
        return false;
    }
    if(count!=125){
        return false;
    }
    cout << "error checked" << endl;
    importFile.open(file_name);
    if (!importFile.is_open()) {
        return false;
    }
    else {
        for (int i = 0; i < HEIGHT; i++) {
            for(int j = 0; j < ROWS; j++) {
                line = "";
                getline(importFile, line);
                stringstream ss(line);
                for(int k = 0; k < COLS; k++) {
                    int value;
                    ss >> value;
                    if (i == 0 && j == 0 && k == 0) {
                        if (value == 0) {
                            return false;
                        }
                    }
                    if (i == 4 && j == 4 && k == 4) {
                        if (value == 0) {
                            return false;
                        }
                    }
                    if(ss.fail()) {
                        return false;
                    }
                    maze[k][j][i] = value;
                }
                ss.str("");
            }
            getline(importFile, line);
        }
        
    }
    cout << "imported" << endl;
    importFile.close();
    
   /* for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
        for(int k = 0; k < 5; k++){
          cout << maze[k][j][i];
          if(k < 4){
            cout << " ";
          }
        }
        cout << endl;
      }
    }
    */
    return true;
}
bool Pathfinder::findPath(int x, int y, int z) {
    //base cases:
    if(x < 0 || y < 0 || z < 0 || x > 4 || y > 4 || z > 4) {
        return false;
    }
    else if (maze[z][y][x] == WALL || maze[z][y][x] == PREV) {
        return false;
    }
    else if (z == 4 && y == 4 && x == 4) {
        solution.push_back("(4, 4, 4)");
        return true;
    }
    solution.push_back("(" + to_string(z) + ", " + to_string(y) + ", " + to_string(x) + ")");
    maze[z][y][x] = PREV;
    
    if(findPath(x - 1, y, z)) {
        return true;
    }
    else if (findPath(x + 1, y, z)) {
        return true;
    }
    else if (findPath(x, y - 1, z)) {
        return true;
    }
    else if (findPath(x, y + 1, z)) {
        return true;
    }
    else if (findPath(x, y, z - 1)) {
        return true;
    }
    else if (findPath(x, y, z + 1)) {
        return true;
    }
    else {
        solution.pop_back();
        return false;
    }
  return false;
}

vector<string> Pathfinder::solveMaze() {
    cout << "in solveMaze" << endl;
    solution.clear();
    findPath(0, 0, 0);
    for (int k = 0; k < HEIGHT; k++) {
        for (int j = 0; j < ROWS; j++) {
            for (int i = 0; i < COLS; i++) {
                if (maze[i][j][k] == 2) {
                    maze[i][j][k] = 1;
                }
            }
        }
    }
    return solution;
}