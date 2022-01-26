#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
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
	int isNext = -1;
	for (int i = 0; i < N; i++)
		mas[i].SetType(straight, turned, threeway, fourway, isNext);
}

void CheckSwap(const int N, DrivableCell cell[], RenderWindow& window)
{
	int count = 0;
	int ind1 = -1, ind2 = -1;
	for (int i = 0; i < N; i++)
		if (isBelong(Mouse::getPosition(window), cell[i]))
			cell[i].SetChose(true);
	for (int i = 0; i < N; i++)
		if (cell[i].ifChosen())
		{
			if (count == 0) ind1 = i;
			else ind2 = i;
			count++;
		}
	if (count == 2)
	{
		DrivableCell::Swap(cell[ind1], cell[ind2]);
		for (int i = 0; i < N; i++)
			cell[i].SetChose(false);
	}
}

void ReadMainPositions(const int N, DrivableCell cell[])
{
	FILE* level_file;
	if (fopen_s(&level_file, "levels\\level_test.lvl", "rt"))
	{
		std::cout << "Can not open level file!" << std::endl;
		system("pause");
		return;
	}

	int mpx, mpy;
	fscanf_s(level_file, "%i %i", &mpx, &mpy); //Сканирование позиции нулевого элемента
	cell[0].SetPosition(mpx, mpy);

	for (int i = 0; i < N; i++)
	{
		fscanf_s(level_file, "%i %i", &mpx, &mpy);
		cell[i].SetMainPosition(mpx, mpy);
	}

	fclose(level_file);
}

void SetPositions(const int N, DrivableCell cell[])
{
	for (int i = 0; i < N; i++)
		cell[i].SetPosition(cell[0]);
}