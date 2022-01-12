#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

struct Point
{
	int x, y;
};

class Hexagon
{
private:
	Texture hexagon_texture;
	Sprite hexagon_sprite;

	Point position;
	int direction;
	// direction = 0 -> up
	// direction = 1 -> up-right
	// direction = 2 -> down-right
	// direction = 3 -> down
	// direction = 4 -> down-left
	// direction = 5 -> up-left

	// TODO: directions -> enum
	// TODO: Hexagon -> virtual

public:
	Hexagon();
	Hexagon(std::string path);
	~Hexagon();

	Point GetPosition();
	void SetPosition(Point pos);

	int GetDirection();
	void SetDirection(int dir);

	Texture GetHexTexture();
	Sprite GetHexSprite();

};