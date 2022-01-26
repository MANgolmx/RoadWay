#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"

bool isBelong(Vector2i a, DrivableCell cell)
{
	if (a.x >= cell.GetPosition().x &&
		a.x <= cell.GetPosition().x + cell.GetCellTexture().getSize().x &&
		a.y >= cell.GetPosition().y &&
		a.y <= cell.GetPosition().y + cell.GetCellTexture().getSize().y)
		return true;
	return false;
}

void SetPath(DrivableCell* mas, const int N,
	int straight, int turned, int threeway, int fourway)
{
	for (int i = 0; i < N; i++)
		mas[i].SetType(straight, turned, threeway, fourway);
}