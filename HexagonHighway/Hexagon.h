#pragma once
#include <iostream>

struct Point
{
	int x, y;
};

class Hexagon
{
	Point position;
	int direction;
	// direction = 0 -> up
	// direction = 1 -> up-right
	// direction = 2 -> down-right
	// direction = 3 -> down
	// direction = 4 -> down-left
	// direction = 5 -> up-left

public:
	Hexagon();
	~Hexagon();


};