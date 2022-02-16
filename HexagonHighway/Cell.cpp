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
		std::cout << "[ERROR OCURRED] Can not open cell texture" << std::endl;
		exit(1);
	}

	square_sprite.setTexture(square_texture);
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
	position.x = cell.position.x + mainPosition.x * GetCellTexture().getSize().x;
	position.y = cell.position.y + mainPosition.y * GetCellTexture().getSize().y;
	square_sprite.setPosition(position.x, position.y);
}

void Cell::SetPosition(Vector2f pos)
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

void Cell::SetCellSprite(std::string path)
{
	if (!square_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open cell texture" << std::endl;
		exit(1);
	}

	square_sprite.setTexture(square_texture);
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

void Cell::Draw(RenderWindow& win)
{
	win.draw(GetCellSprite());
}

Texture Cell::GetCellTexture()
{
	return square_texture;
}

Sprite Cell::GetCellSprite()
{
	return square_sprite;
}