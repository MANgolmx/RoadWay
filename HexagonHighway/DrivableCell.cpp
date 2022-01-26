#include "DrivableCell.h"

DrivableCell::DrivableCell()
{
	type = undefiened;
	isChosen = false;
}

DrivableCell::DrivableCell(std::string path)
{
	type = undefiened;

	if (!square_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open Cell.png" << std::endl;
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

void DrivableCell::Swap(DrivableCell& cell1, DrivableCell& cell2)
{
	Point p = cell2.GetPosition();
	Point mp = cell2.GetMainPosition();

	cell2.SetPosition(cell1.GetPosition());
	cell2.SetMainPosition(cell1.GetMainPosition());

	cell1.SetPosition(p);
	cell1.SetPosition(mp);
}

types DrivableCell::GetType()
{
	return type;
}

void DrivableCell::SetType(int& straight, int& turned, int& threeway, int& fourway, int& isNext)
{
	std::string path;

	int a = rand() % 4;
	switch (a) {
	case 0: Cell::direction = up; break;
	case 1: Cell::direction = right; break;
	case 2: Cell::direction = down; break;
	case 3: Cell::direction = left; break;
	}
	Rotation();
	
	a = rand() % 2;

	switch (a) {
	case 0: goto straightRand;
	case 1: goto turnedRand;
	}

	straightRand:
		if (straight > 0)
		{
			type = types::straight;

			stRand:
			int tmp = rand() % 23;
			if (tmp == isNext)
				goto stRand;

			switch (tmp) {
			case 4: case 8: case 12:
			case 0: path = "resources\\cells\\straight\\straight_flowers_1.png";		 break;
			case 5: case 9: case 13:
			case 1: path = "resources\\cells\\straight\\straight_flowers_2.png";		 break;
			case 6: case 10: case 20:
			case 2: path = "resources\\cells\\straight\\straight_flowers_3.png"; 		 break;
			case 7: case 11: case 21:
			case 3: path = "resources\\cells\\straight\\straight_flowers_4.png";	 break;
			case 14: path = "resources\\cells\\straight\\straight_trashbin_1.png";	 isNext = 14;  break;
			case 15: path = "resources\\cells\\straight\\straight_trashbin_2.png";	 isNext = 15; break;
			case 16: path = "resources\\cells\\straight\\straight_trashbin_3.png";	 isNext = 16; break;
			case 17: path = "resources\\cells\\straight\\straight_trashbin_4.png";	 isNext = 17; break;
			case 18: path = "resources\\cells\\straight\\straight_trashbin_5.png";	 isNext = 18; break;
			case 19: path = "resources\\cells\\straight\\straight_trashbin_6.png";	 isNext = 19; break;
			case 22: path = "resources\\cells\\straight\\straight_busstop_1.png";	 isNext = 24; break;
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
			type = types::turned;

			tnRand:
			int tmp = rand() % 6;
			if (tmp == isNext)
				goto tnRand;

			switch (tmp) {
			case 0: path = "resources\\cells\\turned\\turned_flowers_1.png"; isNext = 0; break;
			case 1: path = "resources\\cells\\turned\\turned_flowers_2.png"; isNext = 1; break;
			case 2: path = "resources\\cells\\turned\\turned_flowers_3.png"; isNext = 2; break;
			case 3: path = "resources\\cells\\turned\\turned_flowers_4.png"; isNext = 3; break;
			case 4: path = "resources\\cells\\turned\\turned_busstop_1.png"; isNext = 4; break;
			case 5: path = "resources\\cells\\turned\\turned_busstop_2.png"; isNext = 5; break;
			}

			if (!square_texture.loadFromFile(path)) {
				std::cout << "[ERROR OCURRED] Can not open Turned.png" << std::endl;
				exit(1);
			}

			square_sprite.setTexture(square_texture);

			turned--;
			return;
		}

	goto straightRand;
}