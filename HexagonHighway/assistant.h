#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"

bool isBelong(Vector2i a, DrivableCell cell);

void SetPath(DrivableCell* mas, const int N,
	int straight, int turned, int threeway, int fourway);

void CheckSwap(const int N, DrivableCell cell[], RenderWindow& window);

void ReadMainPositions(const int N, DrivableCell cell[]);

void SetPositions(const int N, DrivableCell cell[]);

void SetIsChosen(bool var, const int N, DrivableCell cell[]);

void DrawCells(RenderWindow& win, DrivableCell cell[], NonDrivableCell chosen, 
	const int N);