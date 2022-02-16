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
	int toTurn = 0;

	Vector2f position;
	Vector2f mainPosition;

	Texture car_texture;
	Sprite car_sprite;

	directions lastDirection;
	directions direction;

public:

	Car();
	Car(std::string path);
	~Car();

	Vector2f GetPosition();
	Vector2f GetMainPosition();

	void ResetPosition();

	void Draw(RenderWindow& win);

	bool IsOnCell(DrivableCell cell);

	void Move(Time time, DrivableCell roads[], const int roadCount,
		NonDrivableCell decor[], const int decorCount);
};