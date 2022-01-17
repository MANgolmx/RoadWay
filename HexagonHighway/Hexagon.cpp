#include "Hexagon.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Hexagon::Hexagon()
{
	position.x = 0;
	position.y = 0;
	mainPosition.x = 0;
	mainPosition.y = 0;
	direction = up;
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

void Hexagon::SetMainPosition(Point pos)
{
	mainPosition.x = pos.x;
	mainPosition.y = pos.y;
}

Point Hexagon::GetMainPosition()
{
	return mainPosition;
}

int Hexagon::GetDirection()
{
	return direction;
}

void Hexagon::SetDirection(directions dir)
{
	direction = dir;
}

void Hexagon::Rotation()
{
	hexagon_sprite.rotate(62); //TODO: Расчитать правильный угол по формуле
}

Texture Hexagon::GetHexTexture()
{
	return hexagon_texture;
}

Sprite Hexagon::GetHexSprite()
{
	return hexagon_sprite;
}

//TODO: Сделать ориджин для каждого из возможных поворотов