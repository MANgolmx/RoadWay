#include "NonDrivableCell.h"

NonDrivableCell::NonDrivableCell()
{
}

NonDrivableCell::NonDrivableCell(std::string path)
{
	if (!square_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open cell texture" << std::endl;
		exit(1);
	}

	square_sprite.setTexture(square_texture);
	square_sprite.setPosition(0, 0);
}

NonDrivableCell::~NonDrivableCell()
{
}
