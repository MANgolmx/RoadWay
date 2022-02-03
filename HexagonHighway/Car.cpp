#include "Car.h"

Car::Car()
{
	timeToMove = 10;
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
	timeToMove = 10;
	timePassed;
	position.x = position.y = 35;
	mainPosition.x = mainPosition.y = 0;
	direction = up;

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
		switch (direction) {
		case up:
			for (int i = 0; i < roadCount;i++)
				if (mainPosition.x == roads[i].GetMainPosition().x &&
					mainPosition.y == roads[i].GetMainPosition().y + 1)
				{
					position.y -= 2;
					//mainPosition.y--;
					break;
				}
			break;
		case down:
			for (int i = 0; i < roadCount; i++)
				if (mainPosition.x == roads[i].GetMainPosition().x &&
					mainPosition.y == roads[i].GetMainPosition().y - 1)
				{
					position.y += 2;
				//	mainPosition.y++;
					break;
				}
			break;
		case right:
			for (int i = 0; i < roadCount; i++)
				if (mainPosition.x == roads[i].GetMainPosition().x - 1 &&
					mainPosition.y == roads[i].GetMainPosition().y)
				{
					position.x += 2;
					//mainPosition.x++;
					break;
				}
			break;
		case left:
			for (int i = 0; i < roadCount; i++)
				if (mainPosition.x == roads[i]. GetMainPosition().x + 1 &&
					mainPosition.y == roads[i].GetMainPosition().y)
				{
					position.x -= 2;
					//mainPosition.x--;
					break;
				}
			break;
		}
	}

	ResetPosition();

	timePassed = timePassed + time.asMilliseconds() % timeToMove;
}

void Car::Draw(RenderWindow& win)
{
	switch (direction) {
	case up: car_sprite.setOrigin(30, 0); car_sprite.setRotation(0); break;
	case down: car_sprite.setOrigin(-30, 30); car_sprite.setRotation(180); break;
	case right: car_sprite.setOrigin(30, 30); car_sprite.setRotation(90); break;
	case left: car_sprite.setOrigin(0, 0); car_sprite.setRotation(270); break;
	}
	
	win.draw(car_sprite);
}

void Car::ResetPosition()
{
	car_sprite.setPosition(position.x, position.y);
}