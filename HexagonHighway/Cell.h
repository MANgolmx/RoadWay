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
	Cell(std::string path);
	~Cell();

	Point GetPosition();
	void SetPosition(Cell cell);
	void SetPosition(Point pos);
	void SetPosition(int x, int y);

	virtual void SetCellSprite(std::string path);

	void SetMainPosition(Point pos);
	void SetMainPosition(int x, int y);
	Point GetMainPosition();

	directions GetDirection();
	void SetDirection(directions dir);

	void Rotation();

	virtual void Draw(RenderWindow& win);

	Texture GetCellTexture();
	Sprite GetCellSprite();
};