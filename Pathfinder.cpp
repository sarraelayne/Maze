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

vector<string> Pathfinder::solveMaze() {
    int const WALL = 0;
    int const PATH = 1;
    int const PREV = 2;
    int const TRIED = 3;
    //base cases:
    /*
  
    if (maze[xyz] == outside of maze) {//outside of maze
        return false;
    }
    else if (maze[xyz] == 0 || 3 ||) { //Wall or dead end
        return false;
    }
    else if (location == maze[4][4][4]) { 
        solution.push_back();
        return solution;
    }
    else if () {
        maze[xyz] = PATH; 
        if ((mazePath == h, r-1, c) || (mazePath == h, r+1, c)
           || (mazePath == h, r, c+1) || (mazePath == h, r, c-1)
           || (mazePath == h+1, r, c) || (mazePath == h-1, r, c)) {
            solution.push_back();
            }
    }
    */
}