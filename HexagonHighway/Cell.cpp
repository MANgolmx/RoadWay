#include "Cell.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Cell::Cell()
{
	position.x = 0;
	position.y = 0;
	mainPosition.x = 0;
	mainPosition.y = 0;
	direction = up;
}

Cell::Cell(std::string path)
{
	if (!square_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open Hexagon.png" << std::endl;
		exit(1);
	}

	square_sprite.setTexture(square_texture);
	square_sprite.setPosition(50, 25);
}

Cell::~Cell()
{
}

Point Cell::GetPosition()
{
	return position;
}

void Cell::SetPosition(Point pos)
{
	position.x = pos.x;
	position.y = pos.y;
}

void Cell::SetMainPosition(Point pos)
{
	mainPosition.x = pos.x;
	mainPosition.y = pos.y;
}

Point Cell::GetMainPosition()
{
	return mainPosition;
}

int Cell::GetDirection()
{
	return direction;
}

void Cell::SetDirection(directions dir)
{
	direction = dir;
}

void Cell::Rotation()
{
	switch (direction)
	{
	case up: 
		square_sprite.rotate(90);
		square_sprite.setOrigin(0, 100);
		direction = right;
		break;
	case right:
		square_sprite.rotate(90);
		square_sprite.setOrigin(100, 100);
		direction = down;
		break;
	case down:
		square_sprite.rotate(90);
		square_sprite.setOrigin(100, 0);
		direction = left;
		break;
	case left:
		square_sprite.rotate(90);
		square_sprite.setOrigin(0, 0);
		direction = up;
		break;
	}
}

Texture Cell::GetCellTexture()
{
	return square_texture;
}

Sprite Cell::GetCellSprite()
{
	return square_sprite;
}

//TODO: Сделать ориджин для каждого из возможных поворотов