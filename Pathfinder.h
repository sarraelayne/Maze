#pragma once
#include "PathfinderInterface.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pathfinder: public PathfinderInterface{
    public:
	PathfinderInterface() {}
	~PathfinderInterface() {}
    string toString() const;
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
	bool isValid(string currMaze);
	
	protected:
	string currMaze;
	int const ROWS = 5;
    int const COLS = 5;
    int const HEIGHT = 5;
};
