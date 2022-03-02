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
	direction = lastDirection = up;
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
	direction = lastDirection = up;
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
	//TODO: Fix turned cell problem
	if (isMoving)
	if (timePassed + time.asMilliseconds() > timeToMove)
	{
		DrivableCell* tmp;
		switch (direction) {
		case up:
			tmp = DrivableCell::GetCellFromPos({ position.x, position.y - 1 }, roads, roadCount);
			if (tmp != nullptr && tmp->CanGo(direction, lastDirection))
			{
				switch (tmp->GetType())
				{
				case straight:
					position.y--;
					if (!IsOnCell(*DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount))) {
						mainPosition.y--;
						lastDirection = direction;
					}
					break;
				case turned:
					if (DrivableCell::GetCellFromPos({ position.x, position.y + 1 }, roads, roadCount) != tmp && toTurn <= 0)
					{
						toTurn = 65;
						position.y--;
					}
					else {
						if (toTurn == 0)
						{
							lastDirection = up;
							if (DrivableCell::GetCellFromPos({ position.x, position.y + 1 }, roads, roadCount)->GetDirection() == down)
								direction = right;
							else direction = left;
						}
						else {
							position.y--;
						}
						toTurn--;
					}
					break;
				case threeway:
					if (DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount)->GetDirection() == up)
					{
						position.y--;
						if (!IsOnCell(*DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount))) {
							mainPosition.y--;
							lastDirection = direction;
						}
					}
					break;
				}
			}
			else {
				isMoving = false;
			}
			break;
		case down:
			tmp = DrivableCell::GetCellFromPos({ position.x, position.y + 31}, roads, roadCount);
			if (tmp != nullptr && tmp->CanGo(direction, lastDirection))
			{
				switch (tmp->GetType())
				{
				case straight:
					position.y++;
					if (!IsOnCell(*DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount))) {
						mainPosition.y++;
						lastDirection = direction;
					}
					break;
				case turned:
					if (DrivableCell::GetCellFromPos({ position.x, position.y + 29}, roads, roadCount) != tmp && toTurn <= 0)
					{
						toTurn = 65;
						position.y++;
					}
					else {
						if (toTurn == 0)
						{
							lastDirection = down;
							if (DrivableCell::GetCellFromPos({ position.x, position.y + 29}, roads, roadCount)->GetDirection() == up)
								direction = left;
							else direction = right;
						} else {
							position.y++;
						}
						toTurn--;
					}
					break;
				case threeway:
					if (DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount)->GetDirection() == left)
					{
						position.y++;
						if (!IsOnCell(*DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount))) {
							mainPosition.y++;
							lastDirection = direction;
						}
					}
					break;
				}
			}
			else {
				isMoving = false;
			}
			break;
		case right:
			tmp = DrivableCell::GetCellFromPos({ position.x + 31, position.y }, roads, roadCount);
			if (tmp != nullptr && tmp->CanGo(direction, lastDirection))
			{
				switch (tmp->GetType())
				{
				case straight:
					position.x++;
					if (!IsOnCell(*DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount))) {
						mainPosition.x++;
						lastDirection = direction;
					}
					break;
				case turned:
					if (DrivableCell::GetCellFromPos({ position.x + 29, position.y }, roads, roadCount) != tmp && toTurn <= 0)
					{
						toTurn = 65;
						position.x++;
					}
					else {
						if (toTurn == 0)
						{
							lastDirection = right;
							if (DrivableCell::GetCellFromPos({ position.x + 29, position.y }, roads, roadCount)->GetDirection() == up)
								direction = up;
							else direction = down;
						}
						else {
							position.x++;
						}
						toTurn--;
					}
					break;
				case threeway:
					if (DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount)->GetDirection() == up)
					{
						position.x++;
						if (!IsOnCell(*DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount))) {
							mainPosition.x++;
							lastDirection = direction;
						}
					}
					break;
				}
			} else {
				isMoving = false;
			}
			break;
		case left:
			tmp = DrivableCell::GetCellFromPos({ position.x - 4, position.y }, roads, roadCount);
			if (tmp != nullptr && tmp->CanGo(direction, lastDirection))
			{
				switch (tmp->GetType())
				{
				case straight:
				position.x--;
				if (!IsOnCell(*DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount))) {
					mainPosition.x--;
					lastDirection = direction;
				}
				break;
				case turned:
					if (DrivableCell::GetCellFromPos({position.x + 1, position.y}, roads, roadCount) != tmp && toTurn <= 0)
					{
						toTurn = 65;
						position.x--;
					}
					else {
						if (toTurn == 0)
						{
							lastDirection = left;
							if (DrivableCell::GetCellFromPos({ position.x + 1, position.y }, roads, roadCount)->GetDirection() == down)
								direction = down;
							else direction = up;
						} else {
							position.x--;
						}
						toTurn--;
					}
					break;
				case threeway:
					if (DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount)->GetDirection() == up)
					{
						position.x--;
						if (!IsOnCell(*DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount))) {
							mainPosition.x--;
							lastDirection = direction;
						}
					}
					break;
				}
			}
			else {
				isMoving = false;
			}
			break;
		}
	}

	ResetPosition();

	timePassed = timePassed + time.asMilliseconds() % timeToMove;
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
	case up: car_sprite.setOrigin(0, 0); car_sprite.setRotation(0); break;
	case right: car_sprite.setOrigin(0, 30); car_sprite.setRotation(90); break;
	case down: car_sprite.setOrigin(30, 30); car_sprite.setRotation(180); break;
	case left: car_sprite.setOrigin(30, 0); car_sprite.setRotation(270); break;
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
