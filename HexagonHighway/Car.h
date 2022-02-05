#pragma once
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include <iostream>

class Car
{
private:

	int timeToMove = 15;
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

	Point GetPosition();
	Point GetMainPosition();

	void ResetPosition();

	void Draw(RenderWindow& win);

	bool IsOnCell(DrivableCell cell);

	void Move(Time time, DrivableCell roads[], const int roadCount,
		NonDrivableCell decor[], const int decorCount);
};