#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"

bool isBelong(Vector2i a, DrivableCell cell);

void SetPath(DrivableCell* mas, const int N,
	int straight, int turned, int threeway, int fourway);