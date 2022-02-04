#include "Car.h"
#include "DrivableCell.h"

Car::Car()
{
	timeToMove = 15;
	timePassed;
	position.x = position.y = 0;
	mainPosition.x = mainPosition.y = 0;
	direction = up;
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
	direction = left;

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
		Point tmp;
		switch (direction) {
		case up:
			tmp = { mainPosition.x, mainPosition.y - 1 };
			if (roads[DrivableCell::GetCellFromMainPos(tmp, roads, roadCount)].GetMainPosition() != NULL)
			{
				position.y -= 1;
				if (!IsOnCell(roads[DrivableCell::GetCellFromMainPos(mainPosition, roads, roadCount)]))
					mainPosition.y--;
				break;
			}
			break;
		case down:
			tmp = { mainPosition.x, mainPosition.y + 1 };
				if (roads[DrivableCell::GetCellFromMainPos(tmp, roads, roadCount)].GetMainPosition() != NULL)
				{
					position.y += 1;
					if (!IsOnCell(roads[DrivableCell::GetCellFromMainPos(mainPosition, roads, roadCount)]))
						mainPosition.y++;
					break;
				}
			break;
		case right:
			tmp = { mainPosition.x - 1, mainPosition.y };
				if (roads[DrivableCell::GetCellFromMainPos(tmp, roads, roadCount)].GetMainPosition() != NULL)
				{
					position.x += 1;
					if (!IsOnCell(roads[DrivableCell::GetCellFromMainPos(mainPosition, roads, roadCount)]))
						mainPosition.x++;
					break;
				}
			break;
		case left:
			tmp = { mainPosition.x + 1, mainPosition.y };
				if (roads[DrivableCell::GetCellFromMainPos(tmp, roads, roadCount)].GetMainPosition() != NULL)
				{
					position.x -= 1;
					if (!IsOnCell(roads[DrivableCell::GetCellFromMainPos(mainPosition, roads, roadCount)]))
						mainPosition.x--;
					break;
				}
			break;
		}
	}

	ResetPosition();

	timePassed = timePassed + time.asMilliseconds() % timeToMove;
}

bool Car::IsOnCell(Cell cell)
{
	return (position.x < cell.GetPosition().x + 101 &&
		position.x > cell.GetPosition().x &&
		position.y < cell.GetPosition().y + 101 &&
		position.y > cell.GetPosition().y);
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
