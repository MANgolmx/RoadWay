#pragma once
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include <iostream>

class Car
{
private:
public:

	int timeToMove = 15;
	int timePassed = 0;

	Point position;
	Point mainPosition;

	Texture car_texture;
	Sprite car_sprite;

	directions direction;


	Car();
	Car(std::string path);
	~Car();

	void ResetPosition();

	void Draw(RenderWindow& win);

	void Move(Time time, DrivableCell roads[], const int roadCount,
		NonDrivableCell decor[], const int decorCount);
};