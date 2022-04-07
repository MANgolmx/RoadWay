#include "Background.h"
#include <iostream>

Background::Background()
{
}

Background::Background(sf::Texture& tx)
{
	texture = &tx;

	sprite.setTexture(*texture);
	sprite.setPosition(0, 0);
}

Background::~Background()
{
}

sf::Sprite Background::GetSprite()
{
	return sprite;
}

void Background::SetPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}
