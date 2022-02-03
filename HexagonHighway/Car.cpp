#include "Car.h"

Car::Car()
{
	timeToMove = 800;
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
	timeToMove = 800;
	timePassed;
	position.x = position.y = 0;
	mainPosition.x = mainPosition.y = 0;
	direction = up;

	if (!car_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open car texture" << std::endl;
		exit(1);
	}

	car_sprite.setTexture(car_texture);
	car_sprite.setPosition(0, 0);
}

void Car::Move(Time time, DrivableCell* roads, const int roadCount,
	NonDrivableCell decor, const int decorCount)
{
	if (timePassed + time.asMicroseconds() > timeToMove)
	{
		switch (direction) {
		case up:
			for (int i = 0; i < roadCount;i++)
				if (mainPosition.x == roads->GetMainPosition().x &&
					mainPosition.y == roads->GetMainPosition().y - 1)
				{
					position.y -= 101;
					mainPosition.y--;
					break;
				}
			break;
		case down:
			for (int i = 0; i < roadCount; i++)
				if (mainPosition.x == roads->GetMainPosition().x &&
					mainPosition.y == roads->GetMainPosition().y + 1)
				{
					position.y += 101;
					mainPosition.y++;
					break;
				}
			break;
		case right:
			for (int i = 0; i < roadCount; i++)
				if (mainPosition.x == roads->GetMainPosition().x + 1 &&
					mainPosition.y == roads->GetMainPosition().y)
				{
					position.x += 101;
					mainPosition.x++;
					break;
				}
			break;
		case left:
			for (int i = 0; i < roadCount; i++)
				if (mainPosition.x == roads->GetMainPosition().x - 1 &&
					mainPosition.y == roads->GetMainPosition().y)
				{
					position.x -= 101;
					mainPosition.x--;
					break;
				}
			break;
		}
	}

	ResetPosition();

	timePassed = timePassed + time.asMilliseconds() % timeToMove;
}

void Car::ResetPosition()
{
	car_sprite.setPosition(position.x, position.y);
}