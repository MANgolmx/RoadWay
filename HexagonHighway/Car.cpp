#include "Car.h"
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace sf;

Car::Car()
{
	timeToMove = 15;
	timePassed;
	position.x = position.y = 0;
	mainPosition.x = mainPosition.y = 0;
	direction = lastDirection = RIGHT;
	isMoving = false;
}

Car::~Car()
{
}

Car::Car(std::string path)
{
	timeToMove = 15;
	timePassed;
	position = { 535,436 };
	mainPosition = { 0,1 };
	direction = lastDirection = RIGHT;
	isMoving = false;

	if (!car_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open car texture" << std::endl;
		exit(1);
	}

	car_sprite.setTexture(car_texture);
	car_sprite.setPosition(0, 0);
}

void Car::Move(Time time, DrivableCell roads[], const int roadCount,
	NonDrivableCell decor[], const int decorCount)
{
	sf::Vector2f pos = DrivableCell::GetCellFromMainPos({ 0,0 }, roads, roadCount)->GetPosition();
	int f1 = (position.x - pos.x) / 101;
	int f2 = (position.y - pos.y) / 101;

	mainPosition = { float(f1), float(f2) };

	bool isOnCell = false;
	for (int i = 0; i < roadCount; i++)
		if (mainPosition == roads[i].GetMainPosition())
		{
			isOnCell = true;
			break;
		}

	if (!isOnCell)
		StopMoving();

	if (isMoving)
	{
		if (timeToMove < time.asMilliseconds())
		{
			switch (direction) {
			case UP: speed = { 0,-maxspeed * (time.asSeconds() / timeToMove) }; break;
			case RIGHT: speed = { maxspeed * (time.asSeconds() / timeToMove),0 }; break;
			case DOWN: speed = { 0,maxspeed * (time.asSeconds() / timeToMove) }; break;
			case LEFT: speed = { -maxspeed * (time.asSeconds() / timeToMove),0 }; break;
			case STOP: speed = { 0,0 }; break;
			}
		}

		MoveOn(speed);
	}
}

bool Car::IsOnCell(DrivableCell cell)
{
	if (position.x >= cell.GetPosition().x &&
		position.x + 30 < cell.GetPosition().x + 101 &&
		position.y >= cell.GetPosition().y &&
		position.y + 30 < cell.GetPosition().y + 101)
		return true;
	return false;
}

void Car::Draw(RenderWindow& win)
{
	switch (direction) {
	case UP: car_sprite.setOrigin(0, 0); car_sprite.setRotation(0); break;
	case RIGHT: car_sprite.setOrigin(0, 30); car_sprite.setRotation(90); break;
	case DOWN: car_sprite.setOrigin(30, 30); car_sprite.setRotation(180); break;
	case LEFT: car_sprite.setOrigin(30, 0); car_sprite.setRotation(270); break;
	}
	
	win.draw(car_sprite);
}

void Car::StopMoving()
{
	isMoving = false;
}

void Car::StartMoving()
{
	isMoving = true;
}

bool Car::IsMoving()
{
	return isMoving;
}

void Car::ResetPosition()
{
	car_sprite.setPosition(position.x, position.y);
}

void Car::SetPosition(sf::Vector2f pos)
{
	position = pos;
	car_sprite.setPosition(position);
}

void Car::SetMainPosition(sf::Vector2f pos)
{
	mainPosition = pos;
}

void Car::SetDirection(directions dir)
{
	direction = dir;
}

void Car::MoveOn(sf::Vector2f pos)
{
	position += pos;
	car_sprite.setPosition(position);
}

void Car::ReCalcPosition(RenderWindow& window)
{
	position.x = window.getSize().x / 2 + mainPosition.x * 101 - 30 / 2;
	position.y = window.getSize().y / 2 + mainPosition.y * 101 - 30 / 2;
	car_sprite.setPosition(position);
}

Vector2f Car::GetPosition()
{
	return position;
}

Vector2f Car::GetMainPosition()
{
	return mainPosition;
}
