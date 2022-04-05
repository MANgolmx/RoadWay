#include "Cell.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Cell::Cell()
{
	position.x = 0;
	position.y = 0;
	mainPosition.x = 0;
	mainPosition.y = 0;
	direction = UP;
}

Cell::Cell(std::string path)
{
	if (!square_texture->loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open cell texture" << std::endl;
		exit(1);
	}

	square_sprite.setTexture(*square_texture);
	square_sprite.setPosition(0, 0);
}

Cell::~Cell()
{
}

Vector2f Cell::GetPosition()
{
	return position;
}

void Cell::SetPosition(Cell cell)
{
	position.x = cell.position.x + mainPosition.x * 101;
	position.y = cell.position.y + mainPosition.y * 101;
	square_sprite.setPosition(position.x, position.y);
}

void Cell::SetPosition(Cell* cell)
{
	position.x = cell->position.x + mainPosition.x * 101;
	position.y = cell->position.y + mainPosition.y * 101;
	square_sprite.setPosition(position.x, position.y);
}

void Cell::SetPosition(Vector2f pos)
{
	position.x = pos.x;
	position.y = pos.y;
	square_sprite.setPosition(position);
}

void Cell::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
	square_sprite.setPosition(position.x, position.y);
}

void Cell::SetCellSprite(std::string path)
{
	if (!square_texture->loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open Cell texture" << std::endl;
		exit(1);
	}

	square_sprite.setTexture(*square_texture);
	square_sprite.setPosition(0, 0);
}

void Cell::SetCellSprite(sf::Texture* tx)
{
	square_texture = tx;

	square_sprite.setTexture(*square_texture);
	square_sprite.setPosition(0, 0);
}

void Cell::SetMainPosition(Vector2f pos)
{
	mainPosition.x = pos.x;
	mainPosition.y = pos.y;
}

void Cell::SetMainPosition(int x, int y)
{
	mainPosition.x = x;
	mainPosition.y = y;
}

Vector2f Cell::GetMainPosition()
{
	return mainPosition;
}

directions Cell::GetDirection()
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
	case UP: 
		square_sprite.setRotation(90);
		square_sprite.setOrigin(0, 101);
		direction = RIGHT;
		break;
	case RIGHT:
		square_sprite.setRotation(180);
		square_sprite.setOrigin(101, 101);
		direction = DOWN;
		break;
	case DOWN:
		square_sprite.setRotation(270);
		square_sprite.setOrigin(101, 0);
		direction = LEFT;
		break;
	case LEFT:
		square_sprite.setRotation(0);
		square_sprite.setOrigin(0, 0);
		direction = UP;
		break;
	}
}

void Cell::Draw(RenderWindow& win)
{
	win.draw(GetCellSprite());
}

Texture* Cell::GetCellTexture()
{
	return square_texture;
}

Sprite Cell::GetCellSprite()
{
	return square_sprite;
}