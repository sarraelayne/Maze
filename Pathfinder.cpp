#include "Pathfinder.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Pathfinder::toString() const {
    int mazeSize = 125;
    int rows = 5;
    int cols = 5;
    
    /* if (no maze) {
        for (int i = 0; i < mazeSize; i++) {
            maze[x][y][z] == 1;
        }
    }
    
    */
    if (!isValid(currMaze)) {
        return "invalid maze";
    }
    else {
        return currMaze;
    }
}
bool Pathfinder::isValid(string currMaze) {
    if (/*correct maze structure*/) {
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
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                mazeDigit = rand() % 2;
            }
        }
    }
    maze[0][0][0] = 1;
    maze[4][4][4] = 1;
    
    return "maze created";
}
bool Pathfinder::importMaze(string file_name) {
    bool importStat = true;
    ifstream importFile;
    
    importFile.open("file_name");
    if (!importFile.is_open()) {
        importStat = false;
    }
    else {
        currMaze = importFile;
        if (!isValid(currMaze)) {
            importStat = false;
        }
    }
    importFile.close();
    
    return importStat;
}
vector<string> Pathfinder::solveMaze() {
    vector<string> solution;
    
    /*if (outside of maze||not valid path|| been there before)
        pop_back
        return false
      if ( end of maze) {
          return true; YAY
      }
      maze[x][y][z] = 2;
      if (up||down||left||right||in||out == 1) {
          go there
          return true;
      }
      else {
          pop_back
          return false;
      }
    
    */
    
    return solution;
}