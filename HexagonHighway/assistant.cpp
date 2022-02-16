#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Assistant.h"

int ReadLevelFile(std::string lvlpath)
{
	int a;
	FILE* level_file;
	if (fopen_s(&level_file, "levels\\level_test.lvl", "rt"))
	{
		std::cout << "Can not open level file!" << std::endl;
		system("pause");
		return 0;
	}

	fscanf_s(level_file, "%i", &a);

	fclose(level_file);

	return a;
}

bool isBelong(Vector2i a, DrivableCell cell)
{
	if (a.x >= cell.GetPosition().x &&
		a.x <= cell.GetPosition().x + cell.GetCellTexture().getSize().x &&
		a.y >= cell.GetPosition().y &&
		a.y <= cell.GetPosition().y + cell.GetCellTexture().getSize().y)
		return true;
	return false;
}

bool isBelong(Vector2i a, Button bt)
{
	if (a.x >= bt.GetPosition().x &&
		a.x <= bt.GetPosition().x + bt.GetTexture().getSize().x &&
		a.y >= bt.GetPosition().y &&
		a.y <= bt.GetPosition().y + bt.GetTexture().getSize().y)
		return true;
	return false;
}

void SetDrivablePath(DrivableCell* mas, const int masSize,
	int straight, int turned, int threeway, int fourway)
{
	for (int i = 0; i < masSize; i++)
		mas[i].SetType(straight, turned, threeway, fourway);
}

void SetNonDrivablePath(NonDrivableCell* mas, const int masSize,
	int forest, int private_residence, int apartment)
{
	for (int i = 0; i < masSize; i++)
		mas[i].SetType(forest, private_residence, apartment);
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

void ReadMainPositions(const int roadSize, DrivableCell roads[], 
	const int decorSize, NonDrivableCell decor[])
{
	int mpx, mpy;
	FILE* level_file;
	if (fopen_s(&level_file, "levels\\level_test.lvl", "rt"))
	{
		std::cout << "Can not open level file!" << std::endl;
		system("pause");
		return;
	}

	fscanf_s(level_file, "%i %i", &mpx, &mpy); //Сканирование позиции нулевого элемента
	roads[0].SetPosition(mpx, mpy);

	for (int i = 0; i < roadSize; i++)
	{
		fscanf_s(level_file, "%i %i", &mpx, &mpy);
		roads[i].SetMainPosition(mpx, mpy);
	}

	for (int i = 0; i < decorSize; i++)
	{
		fscanf_s(level_file, "%i %i", &mpx, &mpy);
		decor[i].SetMainPosition(mpx, mpy);
	}

	fclose(level_file);
}

void SetPositions(const int roadSize, DrivableCell roads[],
	const int decorSize, NonDrivableCell decor[])
{
	for (int i = 0; i < roadSize; i++)
		roads[i].SetPosition(roads[0]);

	for (int i = 0; i < decorSize; i++)
		decor[i].SetPosition(roads[0]);
}

void SetIsChosen(bool var, const int N, DrivableCell cell[])
{
	for (int i = 0; i < N; i++)
		cell[i].SetChose(var);
}

void DrawCells(RenderWindow& win, DrivableCell roads[], NonDrivableCell chosen,
	const int roadSize, NonDrivableCell decor[], const int decorSize)
{
	for (int i = 0; i < roadSize; i++)
		roads[i].Draw(win, chosen);
	for (int i = 0; i < decorSize; i++)
		decor[i].Draw(win);
}