#pragma once

#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Button.h"

bool isBelong(Vector2i a, DrivableCell cell);

bool isBelong(Vector2i a, Button bt);

void SetDrivablePath(DrivableCell* mas, const int masSize,
	int straight, int turned, int threeway, int fourway);

void SetNonDrivablePath(NonDrivableCell* mas, const int masSize,
	int forest, int private_residence, int apartment);

void CheckSwap(const int N, DrivableCell cell[], RenderWindow& window);

void ReadMainPositions(const int N, DrivableCell cell[],
	const int decorSize, NonDrivableCell decor[]);

void SetPositions(const int roadSize, DrivableCell cell[],
	const int decorSize, NonDrivableCell decor[]);

void SetIsChosen(bool var, const int N, DrivableCell cell[]);

void DrawCells(RenderWindow& win, DrivableCell roads[], NonDrivableCell chosen,
	const int roadSize, NonDrivableCell decor[], const int decorSize);