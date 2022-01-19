#include "DrivableCell.h"

DrivableCell::DrivableCell()
{
	type = undefiened;
}

DrivableCell::DrivableCell(std::string path)
{
	type = undefiened;

	if (!square_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open Hexagon.png" << std::endl;
		exit(1);
	}

	square_sprite.setTexture(square_texture);
	square_sprite.setPosition(position.x, position.y);
}

DrivableCell::DrivableCell(int num, int tsize[4], int flowers, int trashes, int cities)
{
	int tmp;
	int size = num;
	mas = new DrivableCell[size];
	for (int i = 0; i < size; i++) {
		tmp = rand() % 10 + 1;
		
	}
}

DrivableCell::~DrivableCell()
{

}

types DrivableCell::GetType()
{
	return type;
}
