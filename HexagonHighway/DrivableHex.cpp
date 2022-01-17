#include "DrivableHex.h"

DrivableHex::DrivableHex(std::string path)
{
	type = undefiened;

	if (!hexagon_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open Hexagon.png" << std::endl;
		exit(1);
	}

	hexagon_sprite.setTexture(hexagon_texture);
	hexagon_sprite.setPosition(position.x, position.y);
}

DrivableHex::~DrivableHex()
{

}

types DrivableHex::GetType()
{
	return type;
}
