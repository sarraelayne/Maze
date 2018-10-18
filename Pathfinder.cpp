#include "Pathfinder.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

string Pathfinder::toString() const {
    stringstream ss;
    
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                ss << maze[i][j][k];
                if (k < 4) {
                    ss << " ";
                }
            }
            ss << endl;
        }
        if(i < 5) {
            ss << endl;
        }
    }
    cout << ss.str();
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
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                mazeDigit = rand() % 2;
                maze[i][j][k] = mazeDigit;
            }
        }
    }
    maze[0][0][0] = 1;
    maze[4][4][4] = 1;
    cout << "Maze: " << endl;
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                cout << maze[i][j][k] << " ";
            }
        }
    }
    return;
}
bool Pathfinder::importMaze(string file_name) {
    bool importStat = true;
    ifstream importFile;
    string line;
    
    cout << "importing maze"<< endl;
    importFile.open(file_name.c_str());
    
    if (!importFile.is_open()) {
        importStat = false;
    }
    else {
        for (int i = 0; i < HEIGHT; i++) {
            for(int j = 0; j < ROWS; j++) {
                getline(importFile, line);
                stringstream ss(line);
                for(int k = 0; k < COLS; k++) {
                    int value;
                    ss >> value;
                    maze[i][j][k] = value;
                    importStat = true;
                }
            }
            getline(importFile, line);
            cout << line << endl;
        }
    }
    importFile.close();
    
    cout << "Imported: " << importStat << endl;
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