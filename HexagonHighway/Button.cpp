#include "Button.h"
#include  <iostream>

Button::Button()
{
}

Button::Button(FText txt, std::string txtPath)
{
	text = txt;
	if (!texture.loadFromFile(txtPath)) {
		std::cout << "[ERROR OCURRED] Can not open button texture" << std::endl;
		exit(1);
	}

	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	text.SetPosition({0,0});

}

sf::Sprite Button::GetSprite()
{
	return sprite;
}

sf::Texture Button::GetTexture()
{
	return texture;
}

FText Button::GetFText()
{
	return text;
}
