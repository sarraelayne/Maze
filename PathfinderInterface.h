#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
WARNING: It is expressly forbidden to modify any part of this document, including its name
*/
class PathfinderInterface
{
public:
	PathfinderInterface() {}
	virtual ~PathfinderInterface() {}

	virtual string toString() const = 0;

	virtual void createRandomMaze() = 0;

	//Part 2-----------------------------------------------------------------------------------
	/*
	* importMaze
	*
	* Reads in a maze from a file with the given file name and stores it as the current maze.
	* Does nothing if the file does not exist or if the file's data does not represent a valid
	* maze.
	*
	* The file's contents must be of the format described above to be considered valid.
	*
	* Parameter:	file_name
	*				The name of the file containing a maze
	* Returns:		bool
	*				True if the maze is imported correctly; false otherwise
	*/
	virtual bool importMaze(string file_name) = 0;
	//-----------------------------------------------------------------------------------------

	//Part 3-----------------------------------------------------------------------------------
	/*
	* solveMaze
	*
	* Attempts to solve the current maze and returns a solution if one is found.
	*
	* A solution to a maze is a list of coordinates for the path from the entrance to the exit
	* (or an empty vector if no solution is found). This list cannot contain duplicates, and
	* any two consecutive coordinates in the list can only differ by 1 for only one
	* coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
	* in the solution. Each string in the solution vector must be of the format "(x, y, z)",
	* where x, y, and z are the integer coordinates of a cell.
	*
	* Understand that most mazes will contain multiple solutions
	*
	* Returns:		vector<string>
	*				A solution to the current maze, or an empty vector if none exists
	*/
	virtual vector<string> solveMaze() = 0;
	//-----------------------------------------------------------------------------------------
};
