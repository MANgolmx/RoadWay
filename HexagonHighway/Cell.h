#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

enum directions { up, right, down, left };

class Cell
{
protected:
	Texture square_texture;
	Sprite square_sprite;

	Vector2f position;
	Vector2f mainPosition;
	directions direction;

public:
	Cell();
	Cell(std::string path);
	~Cell();

	Vector2f GetPosition();
	void SetPosition(Cell cell);
	void SetPosition(Vector2f pos);
	void SetPosition(int x, int y);

	virtual void SetCellSprite(std::string path);

	void SetMainPosition(Vector2f pos);
	void SetMainPosition(int x, int y);
	Vector2f GetMainPosition();

	directions GetDirection();
	void SetDirection(directions dir);

	void Rotation();

	virtual void Draw(sf::RenderWindow& win);

	Texture GetCellTexture();
	Sprite GetCellSprite();
};