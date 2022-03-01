#include "StructureCell.h"
#include <iostream>

StructureCell::StructureCell()
{
	size = { 1,1 };
	type = structure;
	NonDrivableCell();
}

StructureCell::StructureCell(std::string path, sf::Vector2f size)
{
	this->size = size;
	type = structure;
	if (!square_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open structureCell texture" << std::endl;
		exit(1);
	}

	square_sprite.setTexture(square_texture);
	square_sprite.setPosition(0, 0);
}

StructureCell::~StructureCell()
{
}
