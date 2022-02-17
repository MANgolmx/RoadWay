#pragma once
#include <SFML/Graphics.hpp>

class DrivableCell;
class StructureCell;
class NonDrivableCell;
class Button;
class Car;

int ReadLevelFile(std::string lvlpath);

bool isBelong(sf::Vector2i a, DrivableCell cell);

bool isBelong(sf::Vector2i a, Button bt);

void SetDrivablePath(DrivableCell* mas, const int masSize,
	int straight, int turned, int threeway, int fourway);

void SetNonDrivablePath(NonDrivableCell* mas, const int masSize,
	int forest, int private_residence, int apartment);

void CheckSwap(const int N, DrivableCell cell[], sf::RenderWindow& window);

void ReadMainPositions(const int N, DrivableCell cell[],
	const int decorSize, NonDrivableCell decor[]);

void SetPositions(sf::RenderWindow& window, const int roadSize, DrivableCell cell[],
	const int decorSize, NonDrivableCell decor[]);

void SetIsChosen(bool var, const int N, DrivableCell cell[]);

void ReadCarPosition(Car& car, std::string lvlpath, sf::RenderWindow& window);

void DrawCells(sf::RenderWindow& win, DrivableCell roads[], NonDrivableCell chosen,
	const int roadSize, NonDrivableCell decor[], const int decorSize,
	StructureCell park);

sf::Vector2f ReadSizes(std::string path);