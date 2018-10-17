#include "Pathfinder.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Pathfinder::toString() const {
    int mazeSize = 125;
    stringstream ss;
    
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                ss << maze[i][j][k] << " ";
            }
            ss << endl;
        }
        ss << endl;
    }
    currMaze = ss;
    if (!isValid(currMaze)) {
        return "invalid maze";
    }
    else {
        return currMaze;
    }
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
            cout << endl;
        }
        cout << endl;
    }
    return "maze created";
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
        if (!isValid(currMaze)) {
            importStat = false;
        }
    }
    importFile.close();
    
    cout << "Imported: " << importStat << endl;
    return importStat;
}

vector<string> Pathfinder::solveMaze() {
    vector<string> solution;
    int const WALL = 0;
    int const PATH = 1;
    int const PREV = 2;
    int const TRIED = 3;
    
    /*if (maze[xyz] == 0 || 2 || 3 ||outside of maze)
        pop_back
        return false;
      if (location == maze[4][4][4]) {
          return solution;
      }
      maze[x][y][z] = PREV;
      if (maze[xyz] == 1) {
          go there
      }
      else {
          pop_back
          return false;
      }
    
    */
}