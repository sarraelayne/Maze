#pragma once
#include "PathfinderInterface.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Pathfinder: public PathfinderInterface{
    public:
	Pathfinder() {}
	~Pathfinder() {}
	
    string toString() const;
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
	bool isValid(string currMaze);
	
	protected:
	int maze[5][5][5];
	string currMaze;
	int const ROWS = 5;
    int const COLS = 5;
    int const HEIGHT = 5;
    vector<string> solution;
};
