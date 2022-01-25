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

Cell::Cell(const Cell& cell)
{
	position.x = cell.position.x;
	position.y = cell.position.y;
	mainPosition.x = cell.mainPosition.x;
	mainPosition.y = cell.mainPosition.y;
	direction = cell.direction;
}

Cell::Cell(std::string path)
{
	if (!square_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open Cell.png" << std::endl;
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

void Cell::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
	square_sprite.setPosition(position.x, position.y);
}

void Cell::ReSetPosition()
{
	position.x = position.x + mainPosition.x;
	position.y = position.y + mainPosition.y;
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
		square_sprite.setRotation(90);
		square_sprite.setOrigin(0, 101);
		direction = right;
		break;
	case right:
		square_sprite.setRotation(180);
		square_sprite.setOrigin(101, 101);
		direction = down;
		break;
	case down:
		square_sprite.setRotation(270);
		square_sprite.setOrigin(101, 0);
		direction = left;
		break;
	case left:
		square_sprite.setRotation(0);
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