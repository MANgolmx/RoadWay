#pragma once
#include "FText.h"

class Button
{
private:
	FText text;

	sf::Sprite sprite;
	sf::Texture texture;
public:

	Button();
	Button(FText txt, std::string txtPath);

	~Button() {};

	sf::Sprite GetSprite();
	sf::Texture GetTexture();

	FText GetFText();

};