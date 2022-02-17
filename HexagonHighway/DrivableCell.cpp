#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace sf;

DrivableCell::DrivableCell()
{
	type = undefiened;
	isChosen = false;
}

DrivableCell::DrivableCell(std::string path)
{
	type = undefiened;

	if (!square_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open cell texture" << std::endl;
		exit(1);
	}

	square_sprite.setTexture(square_texture);
	square_sprite.setPosition(position.x, position.y);
}

DrivableCell::~DrivableCell()
{

}

bool DrivableCell::ifChosen()
{
	return isChosen;
}

void DrivableCell::SetChose(bool ch)
{
	isChosen = ch;
}

bool DrivableCell::CanGo(directions& carDir, directions& lastCarDir)
{
	switch (type) {
	case straight:
		switch (direction) {
		case up: case down: if (carDir == up || carDir == down) return false; else return true; break;
		case right: case left: if (carDir == right || carDir == left) return false; else return true; break;
		} break;
	case turned:
		switch (direction) {
		case up: if (carDir == right || carDir == down ||
			carDir == left && lastCarDir == down || carDir == up && lastCarDir == right) return true; break;
		case right: if (carDir == down || carDir == left ||
			carDir == right && lastCarDir == down || carDir == up && lastCarDir == left) return true; break;
		case down: if (carDir == left || carDir == up ||
			carDir == right && lastCarDir == up || carDir == down && lastCarDir == left) return true; break;
		case left:  if (carDir == up || carDir == right ||
			carDir == left && lastCarDir == up || carDir == down && lastCarDir == right) return true; break;
		} break;
	case threeway:
		switch (direction) {
		case up: if (carDir == left && lastCarDir == left) return false; else return true; break;
		case right: if (carDir == up && lastCarDir == up) return false; else return true; break;
		case down: if (carDir == right && lastCarDir == right) return false; else return true; break;
		case left: if (carDir == down && lastCarDir == down) return false; else return true; break;
		} break;
	case fourway:
		return true; break;
	case finish:
		return true; break;
	}
	return false;
}

void DrivableCell::Draw(RenderWindow& win, NonDrivableCell chosen)
{
	win.draw(GetCellSprite());	
	if (ifChosen())
	{
		chosen.SetPosition(GetPosition().x, GetPosition().y);
		win.draw(chosen.GetCellSprite());
	}
}

void DrivableCell::Swap(DrivableCell& cell1, DrivableCell& cell2)
{
	Vector2f p = cell2.position;
	Vector2f mp = cell2.mainPosition;

	cell2.position = cell1.position;
	cell2.mainPosition = cell1.mainPosition;

	cell2.square_sprite.setPosition(cell2.position.x, cell2.position.y);

	cell1.position = p;
	cell1.mainPosition = mp;

	cell1.square_sprite.setPosition(cell1.position.x, cell1.position.y);
}

drivableTypes DrivableCell::GetType()
{
	return type;
}

DrivableCell* DrivableCell::GetCellFromMainPos(Vector2f mainPos, DrivableCell cells[], const int size)
{
	for (int i = 0; i < size; i++)
		if (cells[i].mainPosition == mainPos)
			return &cells[i];
	return nullptr;
}

DrivableCell* DrivableCell::GetCellFromPos(Vector2f pos, DrivableCell cells[], const int size)
{
	for (int i = 0; i < size; i++)
		if (pos.x >= cells[i].position.x &&
			pos.x < cells[i].position.x + 101 &&
			pos.y >= cells[i].position.y &&
			pos.y < cells[i].position.y + 101)
			return &cells[i];
	return nullptr;
}

void DrivableCell::SetType(int& straight, int& turned, int& threeway, int& fourway)
{
	std::string path;

	int Exit = 0;

	int a = rand() % 4;
	switch (a) {
	case 0: Cell::direction = up; break;
	case 1: Cell::direction = right; break;
	case 2: Cell::direction = down; break;
	case 3: Cell::direction = left; break;
	}
	Rotation();
	
	a = rand() % 3;

	switch (a) {
	case 0: goto straightRand;
	case 1: goto turnedRand;
	case 2: goto threewayRand;
	}

	straightRand:
		if (straight > 0)
		{
			type = drivableTypes::straight;

			int tmp = rand() % 23;

			switch (tmp) {
			case 4: case 8: case 12:
			case 0: path = "resources\\cells\\straight\\straight_flowers_1.png";	 break;
			case 5: case 9: case 13:
			case 1: path = "resources\\cells\\straight\\straight_flowers_2.png";	 break;
			case 6: case 10: case 20:
			case 2: path = "resources\\cells\\straight\\straight_flowers_3.png"; 	 break;
			case 7: case 11: case 21:
			case 3: path = "resources\\cells\\straight\\straight_flowers_4.png";	 break;
			case 14: path = "resources\\cells\\straight\\straight_trashbin_1.png";	 break;
			case 15: path = "resources\\cells\\straight\\straight_trashbin_2.png";	 break;
			case 16: path = "resources\\cells\\straight\\straight_trashbin_3.png";	 break;
			case 17: path = "resources\\cells\\straight\\straight_trashbin_4.png";	 break;
			case 18: path = "resources\\cells\\straight\\straight_trashbin_5.png";	 break;
			case 19: path = "resources\\cells\\straight\\straight_trashbin_6.png";	 break;
			case 22: path = "resources\\cells\\straight\\straight_busstop_1.png";	 break;
			}

			if (!square_texture.loadFromFile(path)) {
				std::cout << "[ERROR OCURRED] Can not open Straight.png" << std::endl;
				exit(1);
			}

			square_sprite.setTexture(square_texture);

			straight--;
			return;
		}

	turnedRand:
		if (turned > 0)
		{
			type = drivableTypes::turned;

			int tmp = rand() % 6;

			switch (tmp) {
			case 0: path = "resources\\cells\\turned\\turned_flowers_1.png"; break;
			case 1: path = "resources\\cells\\turned\\turned_flowers_2.png"; break;
			case 2: path = "resources\\cells\\turned\\turned_flowers_3.png"; break;
			case 3: path = "resources\\cells\\turned\\turned_flowers_4.png"; break;
			case 4: path = "resources\\cells\\turned\\turned_busstop_1.png"; break;
			case 5: path = "resources\\cells\\turned\\turned_busstop_2.png"; break;
			}

			if (!square_texture.loadFromFile(path)) {
				std::cout << "[ERROR OCURRED] Can not open Turned.png" << std::endl;
				exit(1);
			}

			square_sprite.setTexture(square_texture);

			turned--;
			return;
		}

	threewayRand:
		if (threeway > 0)
		{
			type = drivableTypes::threeway;

			int tmp = rand() % 7;

			switch (tmp) {
			case 0: path = "resources\\cells\\threeway\\threeway_flowers_1.png"; break;
			case 1: path = "resources\\cells\\threeway\\threeway_flowers_2.png"; break;
			case 2: path = "resources\\cells\\threeway\\threeway_flowers_3.png"; break;
			case 3: path = "resources\\cells\\threeway\\threeway_flowers_4.png"; break;
			case 4: path = "resources\\cells\\threeway\\threeway_flowers_5.png"; break;
			case 5: path = "resources\\cells\\threeway\\threeway_busstop_1.png"; break;
			case 6: path = "resources\\cells\\threeway\\threeway_busstop_2.png"; break;
			}

			if (!square_texture.loadFromFile(path)) {
				std::cout << "[ERROR OCURRED] Can not open Turned.png" << std::endl;
				exit(1);
			}

			square_sprite.setTexture(square_texture);

			threeway--;
			return;
		}
		Exit++;

		if (Exit > 10)
			return;

		goto straightRand;
 }