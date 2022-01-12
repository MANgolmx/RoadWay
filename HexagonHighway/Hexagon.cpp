#include "Hexagon.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Hexagon::Hexagon()
{
	position.x = 0;
	position.y = 0;
	direction = 0;
}

Hexagon::Hexagon(std::string path)
{
	if (!hexagon_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open Hexagon.png" << std::endl;
		exit(1);
	}

	hexagon_sprite.setTexture(hexagon_texture);
	hexagon_sprite.setPosition(50, 25);
}

Hexagon::~Hexagon()
{
}

Point Hexagon::GetPosition()
{
	return position;
}

void Hexagon::SetPosition(Point pos)
{
	position.x = pos.x;
	position.y = pos.y;
}

int Hexagon::GetDirection()
{
	return direction;
}

void Hexagon::SetDirection(int dir)
{
	direction = dir;
}

Texture Hexagon::GetHexTexture()
{
	return hexagon_texture;
}

Sprite Hexagon::GetHexSprite()
{
	return hexagon_sprite;
}
