#pragma once
#include <SFML/Graphics.hpp>

class DrivableCell;
class NonDrivableCell;
class StructureCell;
class Button;
class Car;

int ReadLevelFile(const char lvlpath[]);

bool isBelong(sf::Vector2i a, DrivableCell cell);

bool isBelong(sf::Vector2i a, Button bt);

void SetDrivablePath(DrivableCell* mas, const int masSize,
	int straight, int turned, int threeway, int fourway);

void SetNonDrivablePath(NonDrivableCell* mas, const int masSize,
	int forest, int private_residence, int apartment);

void CheckSwap(const int N, DrivableCell cell[], sf::RenderWindow& window);

void ReadMainPositions(const int N, DrivableCell cell[],
	const int decorSize, NonDrivableCell decor[],
	const int structSize, StructureCell structs[], const char lvlpath[]);

void SetPositions(const int roadSize, DrivableCell cell[],
	const int decorSize, NonDrivableCell decor[],
	const int structSize, StructureCell structs[], sf::RenderWindow& window);

void SetIsChosen(bool var, const int N, DrivableCell cell[]);

void ReadCarPosition(Car& car, const char lvlpath[]);

void DrawCells(sf::RenderWindow& win, DrivableCell roads[], NonDrivableCell chosen,
	const int roadSize, NonDrivableCell decor[], const int decorSize, 
	StructureCell structs[], const int structSize);