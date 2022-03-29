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

	bool isMoving;

	bool isFinished = false;

public:

	Car();
	Car(std::string path);
	~Car();

	sf::Vector2f GetPosition();
	sf::Vector2f GetMainPosition();

	void ResetPosition();

	void SetPosition(sf::Vector2f pos);
	void SetMainPosition(sf::Vector2f pos);
	void SetDirection(directions dir);

	void ReCalcPosition(sf::RenderWindow& window);

	void Draw(sf::RenderWindow& win);

	void StopMoving();
	void StartMoving();

	bool IsMoving();
	bool IsFinished();

	bool IsOnCell(DrivableCell cell);

	void Move(sf::Time time, DrivableCell roads[], const int roadCount,
		NonDrivableCell decor[], const int decorCount);
};