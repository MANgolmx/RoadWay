#include "Background.h"
#include <iostream>

Background::Background()
{
}

Background::Background(std::string path)
{
	if (!texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open menu texture" << std::endl;
		exit(1);
	}

	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
}

Background::~Background()
{
}

sf::Sprite Background::GetSprite()
{
	return sprite;
}
