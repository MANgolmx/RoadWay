#pragma once
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include <iostream>

class Car
{
private:

	int timeToMove = 800;
	int timePassed = 0;

	Point position;
	Point mainPosition;

	Texture car_texture;
	Sprite car_sprite;

	directions direction;

public:

	Car();
	Car(std::string path);
	~Car();

	void ResetPosition();

	void Move(Time time, DrivableCell* roads, const int roadCount,
		NonDrivableCell decor, const int decorCount);
};