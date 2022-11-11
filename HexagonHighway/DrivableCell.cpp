#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include "TextureManager.h"

using namespace sf;

DrivableCell::DrivableCell()
{
	type = undefiened;
	isChosen = false;
	canBeMoved = true;
	Cell();
}

DrivableCell::DrivableCell(sf::Texture& tx)
{
	square_texture = &tx;

	square_sprite.setTexture(*square_texture);
	square_sprite.setPosition(0, 0);
	canBeMoved = true;
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

void DrivableCell::SetDrivableType(drivableTypes tp)
{
	type = tp;
}

bool DrivableCell::CanGo(Directions& carDir, Directions& lastCarDir)
{
	switch (type) {
	case straight:
		switch (direction) {
		case UP: case DOWN: if (carDir == UP || carDir == DOWN) return false; else return true; break;
		case RIGHT: case LEFT: if (carDir == RIGHT || carDir == LEFT) return false; else return true; break;
		} break;
	case turned:
		switch (direction) {
		case UP: if (carDir == RIGHT || carDir == DOWN ||
			carDir == LEFT && lastCarDir == DOWN || carDir == UP && lastCarDir == RIGHT) return true; break;
		case RIGHT: if (carDir == DOWN || carDir == LEFT ||
			carDir == RIGHT && lastCarDir == DOWN || carDir == UP && lastCarDir == LEFT) return true; break;
		case DOWN: if (carDir == LEFT || carDir == UP ||
			carDir == RIGHT && lastCarDir == UP || carDir == DOWN && lastCarDir == LEFT) return true; break;
		case LEFT:  if (carDir == UP || carDir == RIGHT ||
			carDir == LEFT && lastCarDir == UP || carDir == DOWN && lastCarDir == RIGHT) return true; break;
		} break;
	case threeway:
		switch (direction) {
		case UP: if (carDir == LEFT && lastCarDir == LEFT) return false; else return true; break;
		case RIGHT: if (carDir == UP && lastCarDir == UP) return false; else return true; break;
		case DOWN: if (carDir == RIGHT && lastCarDir == RIGHT) return false; else return true; break;
		case LEFT: if (carDir ==  DOWN && lastCarDir == DOWN) return false; else return true; break;
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

void DrivableCell::ChangeMoveStatus(bool newMode)
{
	canBeMoved = newMode;
}

bool DrivableCell::CanBeMoved()
{
	return canBeMoved;
}

void DrivableCell::SetType(TextureManager& tm, int& straight, int& turned, int& threeway, int& fourway)
{
	int Exit = 0;

	int a = rand() % 4;
	switch (a) {
	case 0: Cell::direction = UP; break;
	case 1: Cell::direction = RIGHT; break;
	case 2: Cell::direction = DOWN; break;
	case 3: Cell::direction = LEFT; break;
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
			case 0: square_texture = &tm.PullTexture("resources\\cells\\straight\\straight_flowers_1.png");	 break;
			case 5: case 9: case 13:
			case 1: square_texture = &tm.PullTexture("resources\\cells\\straight\\straight_flowers_2.png");	 break;
			case 6: case 10: case 20:
			case 2: square_texture = &tm.PullTexture("resources\\cells\\straight\\straight_flowers_3.png"); 	 break;
			case 7: case 11: case 21:
			case 3: square_texture = &tm.PullTexture("resources\\cells\\straight\\straight_flowers_4.png");	 break;
			case 14: square_texture = &tm.PullTexture("resources\\cells\\straight\\straight_trashbin_1.png"); break;
			case 15: square_texture = &tm.PullTexture("resources\\cells\\straight\\straight_trashbin_2.png"); break;
			case 16: square_texture = &tm.PullTexture("resources\\cells\\straight\\straight_trashbin_3.png"); break;
			case 17: square_texture = &tm.PullTexture("resources\\cells\\straight\\straight_trashbin_4.png"); break;
			case 18: square_texture = &tm.PullTexture("resources\\cells\\straight\\straight_trashbin_5.png"); break;
			case 19: square_texture = &tm.PullTexture("resources\\cells\\straight\\straight_trashbin_6.png"); break;
			case 22: square_texture = &tm.PullTexture("resources\\cells\\straight\\straight_busstop_1.png");	 break;
			}

			square_sprite.setTexture(*square_texture);

			straight--;
			return;
		}

	turnedRand:
		if (turned > 0)
		{
			type = drivableTypes::turned;

			int tmp = rand() % 6;

			switch (tmp) {
			case 0: square_texture = &tm.PullTexture("resources\\cells\\turned\\turned_flowers_1.png"); break;
			case 1: square_texture = &tm.PullTexture("resources\\cells\\turned\\turned_flowers_2.png"); break;
			case 2: square_texture = &tm.PullTexture("resources\\cells\\turned\\turned_flowers_3.png"); break;
			case 3: square_texture = &tm.PullTexture("resources\\cells\\turned\\turned_flowers_4.png"); break;
			case 4: square_texture = &tm.PullTexture("resources\\cells\\turned\\turned_busstop_1.png"); break;
			case 5: square_texture = &tm.PullTexture("resources\\cells\\turned\\turned_busstop_2.png"); break;
			}

			square_sprite.setTexture(*square_texture);

			turned--;
			return;
		}

	threewayRand:
		if (threeway > 0)
		{
			type = drivableTypes::threeway;

			int tmp = rand() % 7;

			switch (tmp) {
			case 3: square_texture = &tm.PullTexture("resources\\cells\\threeway\\threeway_flowers_4.png"); break;
			case 4: square_texture = &tm.PullTexture("resources\\cells\\threeway\\threeway_flowers_5.png"); break;
			case 0: square_texture = &tm.PullTexture("resources\\cells\\threeway\\threeway_flowers_1.png"); break;
			case 1: square_texture = &tm.PullTexture("resources\\cells\\threeway\\threeway_flowers_2.png"); break;
			case 2: square_texture = &tm.PullTexture("resources\\cells\\threeway\\threeway_flowers_3.png"); break;
			case 5: square_texture = &tm.PullTexture("resources\\cells\\threeway\\threeway_busstop_1.png"); break;
			case 6: square_texture = &tm.PullTexture("resources\\cells\\threeway\\threeway_busstop_2.png"); break;
			}

			square_sprite.setTexture(*square_texture);

			threeway--;
			return;
		}
		Exit++;

		if (Exit > 10)
			return;

		goto straightRand;
 }