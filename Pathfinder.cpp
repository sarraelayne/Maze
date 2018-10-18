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
bool Pathfinder::isValid(string currMaze) {
    int height;
    int rows;
    int cols;
    if ((height == HEIGHT) && (rows == ROWS) && (cols == COLS)) {
       if (maze[4][4][4] == 1 && maze[0][0][0] == 1) {
           return true;
       }
       else {
           return false;
       }
    }
    else {
        return false;
    }
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
    cout << "Maze: " << endl;
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                cout << maze[k][j][i] << " ";
            }
        }
    }
    return;
}
bool Pathfinder::importMaze(string file_name) {
    bool importStat = true;
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
        if ((height == HEIGHT) && (rows == ROWS) && (cols == COLS)) {
            if (maze[4][4][4] == 1 && maze[0][0][0] == 1) {
                importStat = true;
            }
            else {
                importStat = false;
            }
        }
        else {
            importStat = false;
        }
        while(importFile >> token){
            if(token == '1'){
                one_count++;
                count++;
            } 
            else if(token == '0'){
                zero_count++;
                count++;
            }
        }
        
        importFile.close();
    } 
    importFile.open(file_name);
    if (!importFile.is_open()) {
        importStat = false;
    }
    if(count!=125){
        return false;
    }
    else {
        for (int i = 0; i < HEIGHT; i++) {
            for(int j = 0; j < ROWS; j++) {
                getline(importFile, line);
                stringstream ss(line);
                for(int k = 0; k < COLS; k++) {
                    
                    int value;
                    ss >> value;
                    if(ss.fail()) {
                        return false;
                    }
                    maze[k][j][i] = value;
                    importStat = true;
                }
            }
            getline(importFile, line);
        }
        
    }
    importFile.close();
    
    if (maze[4][4][4] == 1 && maze[0][0][0] == 1) {
        importStat = true;
    }
    else {
        importStat = false;
    }
    
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
    return importStat;
}
bool Pathfinder::findPath(int x, int y, int z) {
    //base cases:
    if(x < 0 || y < 0 || z < 0 || x > 4 || y > 4 || z > 4) {
        return false;
    }
    else if (maze[z][y][x] == WALL || maze[z][y][x] == PREV) {
        return false;
    }
    else if (z = HEIGHT - 1 && y == ROWS - 1 && x == COLS - 1) {
        solution.push_back("(4, 4, 4)");
        return true;
    }
    solution.push_back("(" + to_string(z) + ", " + to_string(y) + ", " + to_string(x) + ")")
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
    solution.clear();
    findPath(0, 0, 0);
    for (int k = 0; k < HEIGHT; k++) {
        for (int j = 0; j < ROWS; j++) {
            for (int i = 0; i < COLS; i++ {
                if (maze[i][j][k] == 2) {
                    maze[i][j][k] = 1;
                }
            }
        }
    }
    
}