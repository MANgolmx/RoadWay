#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

struct Point
{
	int x, y;
};

enum directions { up, right, down, left };

class Cell
{
protected:
	Texture square_texture;
	Sprite square_sprite;

	Point position;
	Point mainPosition;
	directions direction;

public:
	Cell();
	Cell(const Cell& cell);
	Cell(std::string path);
	~Cell();

	Point GetPosition();
	void SetPosition(Point pos);
	void SetPosition(int x, int y);

	void ReSetPosition();

	void SetMainPosition(Point pos);
	Point GetMainPosition();

	int GetDirection();
	void SetDirection(directions dir);

	void Rotation();

	Texture GetCellTexture();
	Sprite GetCellSprite();

};