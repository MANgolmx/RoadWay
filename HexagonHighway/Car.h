#pragma once
#include <SFML/Graphics.hpp>

class DrivableCell;
class NonDrivableCell;

enum directions;

class Car
{
private:

	int timeToMove = 15;
	int timePassed = 0;
	int toTurn = 0;

	sf::Vector2f position;
	sf::Vector2f mainPosition;

	sf::Texture car_texture;
	sf::Sprite car_sprite;

	directions lastDirection;
	directions direction;

public:

	Car();
	Car(std::string path);
	~Car();

	sf::Vector2f GetPosition();
	sf::Vector2f GetMainPosition();

	void ResetPosition();

	void Draw(sf::RenderWindow& win);

	bool IsOnCell(DrivableCell cell);

	void Move(sf::Time time, DrivableCell roads[], const int roadCount,
		NonDrivableCell decor[], const int decorCount);
};