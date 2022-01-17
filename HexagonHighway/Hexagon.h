#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

struct Point
{
	int x, y;
};

enum directions { up, up_right, down_right, down, down_left, up_left };

class Hexagon
{
protected:
public:
	Texture hexagon_texture;
	Sprite hexagon_sprite;

	Point position;
	Point mainPosition;
	directions direction;

	Hexagon();
	Hexagon(std::string path);
	~Hexagon();

	Point GetPosition();
	void SetPosition(Point pos);

	void SetMainPosition(Point pos);
	Point GetMainPosition();

	int GetDirection();
	void SetDirection(directions dir);

	void Rotation();

	Texture GetHexTexture();
	Sprite GetHexSprite();

};