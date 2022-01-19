#include "DrivableCell.h"

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

DrivableCell::~DrivableCell()
{

}

types DrivableCell::GetType()
{
	return type;
}
