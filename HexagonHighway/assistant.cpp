#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "StructureCell.h"
#include "Assistant.h"
#include "Car.h"
#include "Button.h"

using namespace sf;

void ReadLevelFile(const char lvlpath[], int& roadSize, int& decorSize, int& structSize)
{
	FILE* level_file;
	if (fopen_s(&level_file, lvlpath, "rt"))
	{
		std::cout << "Can not open level file!" << std::endl;
		system("pause");
		return;
	}

	fscanf_s(level_file, "%i%i%i", &roadSize, &decorSize, &structSize);

	fclose(level_file);
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

bool isBelong(sf::Vector2i a, sf::Rect<float> pl)
{
	if (a.x >= pl.left &&
		a.x <= pl.left + pl.width &&
		a.y >= pl.top &&
		a.y <= pl.top + pl.height)
		return true;
	return false;
}

void SetDrivablePath(DrivableCell mas[], const int masSize,
	int straight, int turned, int threeway, int fourway)
{
	mas[0].SetCellSprite("resources\\cells\\finish.png");
	mas[0].SetDrivableType(start);
	mas[1].SetCellSprite("resources\\cells\\finish.png");
	mas[1].SetDrivableType(finish);
	for (int i = 2; i < masSize; i++)
		mas[i].SetType(straight, turned, threeway, fourway);
}

void SetNonDrivablePath(NonDrivableCell mas[], const int masSize,
	int forest, int private_residence, int apartment)
{
	for (int i = 0; i < masSize; i++)
		mas[i].SetType(forest, private_residence, apartment);
}

void CheckSwap(sf::RenderWindow& window, DrivableCell road[], const int roadSize)
{
	int count = 0;
	int ind1 = -1, ind2 = -1;
	for (int i = 0; i < roadSize; i++)
		if (isBelong(Mouse::getPosition(window), road[i]))
			road[i].SetChose(true);
	for (int i = 0; i < roadSize; i++)
		if (road[i].ifChosen())
		{
			if (count == 0) ind1 = i;
			else ind2 = i;
			count++;
		}
	if (count == 2)
	{
		DrivableCell::Swap(road[ind1], road[ind2]);
		for (int i = 0; i < roadSize; i++)
			road[i].SetChose(false);
	}
}

void ReadMainPositions(const char lvlpath[], DrivableCell road[], const int roadSize,
	NonDrivableCell decor[], const int decorSize,
	StructureCell structs[], const int structSize)
{
	int mpx, mpy;
	FILE* level_file;
	if (fopen_s(&level_file, lvlpath, "rt"))
	{
		std::cout << "Can not open level file!" << std::endl;
		system("pause");
		return;
	}

	fscanf_s(level_file, "%i %i", &mpx, &mpy);//TODO: Заменить на движение курсора
	fscanf_s(level_file, "%i", &mpx);//TODO: Заменить на движение курсора

	for (int i = 0; i < roadSize; i++)
	{
		fscanf_s(level_file, "%i %i", &mpx, &mpy);
		road[i].SetMainPosition(mpx, mpy);
	}

	for (int i = 0; i < decorSize; i++)
	{
		fscanf_s(level_file, "%i %i", &mpx, &mpy);
		decor[i].SetMainPosition(mpx, mpy);
	}

	for (int i = 0; i < structSize; i++)
	{
		fscanf_s(level_file, "%i %i", &mpx, &mpy);
		structs[i].SetMainPosition(mpx, mpy);
	}

	fclose(level_file);
}

void SetPositions(const int roadSize, DrivableCell roads[],
	const int decorSize, NonDrivableCell decor[],
	const int structSize, StructureCell structs[], RenderWindow& window)
{
	//TODO: Пофиксить баг с исчезновением клетки при масштибировании
	float f1 = window.getSize().x / 2 - 101 / 2;
	float f2 = window.getSize().y / 2 - 101 / 2;

	DrivableCell *tmp = DrivableCell::GetCellFromMainPos({ 0,0 }, roads, roadSize);

	tmp->SetPosition({f1,f2});

	for (int i = 0; i < roadSize; i++)
		roads[i].SetPosition(*tmp);

	for (int i = 0; i < decorSize; i++)
		decor[i].SetPosition(*tmp);

	for (int i = 0; i < structSize; i++)
		structs[i].SetPosition(*tmp);
}

void SetIsChosen(bool var, DrivableCell road[], const int roadSize)
{
	for (int i = 0; i < roadSize; i++)
		road[i].SetChose(var);
}

void ReadCarPosition(Car& car, const char lvlpath[])
{
	float mx, my;
	directions dir;

	FILE* level_file;

	if (fopen_s(&level_file, lvlpath, "rt"))
	{
		std::cout << "Can not open level file!" << std::endl;
		system("pause");
		return;
	}

	fscanf_s(level_file, "%f %f %i", &mx, &my, &dir);

	car.SetMainPosition({ mx,my });
	car.SetDirection(dir);
	fclose(level_file);
}

void ReadCellsTypes(const char path[], int& straight, int& turned, int& threeway, int& fourway, int& finish, int& flowers, int& private_residence, int& apartments)
{
	FILE* level_file;
	if (fopen_s(&level_file, path, "rt"))
	{
		std::cout << "Can not open level file!" << std::endl;
		system("pause");
		return;
	}

	fscanf_s(level_file, "%i%i%i%i%i%i%i%i", &straight, &turned, &threeway, &fourway, &finish, &flowers, &private_residence, &apartments);

	fclose(level_file);
}

void DrawCells(RenderWindow& win, DrivableCell roads[], NonDrivableCell chosen, 
	const int roadSize, NonDrivableCell decor[], const int decorSize,
	StructureCell structs[], const int structSize)
{
	for (int i = 0; i < roadSize; i++)
		roads[i].Draw(win, chosen);
	for (int i = 0; i < decorSize; i++)
		decor[i].Draw(win);
	for (int i = 0; i < structSize; i++)
		structs[i].Draw(win);
}