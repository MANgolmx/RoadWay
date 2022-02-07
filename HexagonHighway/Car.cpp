#include "Car.h"
#include "DrivableCell.h"

Car::Car()
{
	timeToMove = 15;
	timePassed;
	position.x = position.y = 0;
	mainPosition.x = mainPosition.y = 0;
	direction = lastDirection = up;
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
					if (!IsOnCell(*DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount)))
						mainPosition.y--;

				case turned:
					if (DrivableCell::GetCellFromPos({ position.y - 1, position.y }, roads, roadCount)->GetType() != turned && toTurn == 0)
					{
						toTurn = 30;
						position.y--;
					}
					else {
						toTurn--;
						if (toTurn == 0)
						{
							lastDirection = up;
							if (DrivableCell::GetCellFromPos({ position.y - 1, position.y }, roads, roadCount)->GetDirection() == down)
								direction = left;
							else direction = right;
						}
						else {
							position.y--;
						}
					}
					break;
				}
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
					if (!IsOnCell(*DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount)))
						mainPosition.y++;

				case turned:
					if (DrivableCell::GetCellFromPos({ position.y + 33, position.y }, roads, roadCount)->GetType() != turned && toTurn == 0)
					{
						toTurn = 30;
						position.y++;
					}
					else {
						toTurn--;
						if (toTurn == 0)
						{
							lastDirection = down;
							if (DrivableCell::GetCellFromPos({ position.y + 33, position.y }, roads, roadCount)->GetDirection() == up)
								direction = right;
							else direction = left;
						} else {
							position.y++;
						}
					}
					break;
				}
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
					if (!IsOnCell(*DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount)))
						mainPosition.x++;

				case turned:
					if (DrivableCell::GetCellFromPos({ position.x + 33, position.y }, roads, roadCount)->GetType() != turned && toTurn == 0)
					{
						toTurn = 30;
						position.x++;
					}
					else {
						toTurn--;
						if (toTurn == 0)
						{
							lastDirection = right;
							if (DrivableCell::GetCellFromPos({ position.x + 33, position.y }, roads, roadCount)->GetDirection() == right)
								direction = down;
							else direction = up;
						} else {
							position.x++;
						}

					}
					break;
				}
			}
			break;
		case left:
			tmp = DrivableCell::GetCellFromPos({ position.x - 1, position.y }, roads, roadCount);
			if (tmp != nullptr && tmp->CanGo(direction, lastDirection))
			{
				switch (tmp->GetType())
				{
				case straight:
				position.x--;
				if (!IsOnCell(*DrivableCell::GetCellFromPos({ position.x, position.y }, roads, roadCount)))
					mainPosition.x--;

				case turned:
					if (DrivableCell::GetCellFromPos({position.x + 2, position.y}, roads, roadCount)->GetType() != turned && toTurn == 0)
					{
						toTurn = 30;
						position.x--;
					}
					else {
						toTurn--;
						if (toTurn == 0)
						{
							lastDirection = left;
							if (DrivableCell::GetCellFromPos({ position.x + 2, position.y }, roads, roadCount)->GetDirection() == up)
								direction = down;
							else direction = up;
						} else {
							position.x--;
						}
					}
					break;
				}
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

void Car::ResetPosition()
{
	car_sprite.setPosition(position.x, position.y);
}

Point Car::GetPosition()
{
	return position;
}

Point Car::GetMainPosition()
{
	return mainPosition;
}
