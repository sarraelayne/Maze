main: main.cpp Pathfinder.cpp Pathfinder.h PathfinderInterface.h
	g++ -std=c++11 main.cpp Pathfinder.cpp -o main
debugged: main.cpp
	g++ -std=c++11 main.cpp -o debugged -g