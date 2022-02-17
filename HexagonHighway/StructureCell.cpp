#include "StructureCell.h"
#include <iostream>
#include <SFML/Graphics.hpp>

StructureCell::StructureCell()
{
}

StructureCell::StructureCell(std::string path)
{
	type = structure;
	if (!square_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open car texture" << std::endl;
		exit(1);
	}

	square_sprite.setTexture(square_texture);
	square_sprite.setPosition(0, 0);
	size = { 2, 3 };
}

StructureCell::~StructureCell()
{
}
