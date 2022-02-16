#pragma once
#include <SFML/Graphics.hpp>
#include "FText.h"

class Button
{
private:
	FText ftext;

	sf::Sprite sprite;
	sf::Texture texture;

	sf::Vector2f textPosition;

public:
	Button();
	Button(FText txt, std::string texturePath, sf::Vector2f textPos);
	Button(FText txt, sf::Texture Texture, sf::Vector2f textPos);

	~Button() {};

	sf::Sprite GetSprite();
	sf::Texture GetTexture();
	
	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f pos);

	FText GetFText();

	void operator=(Button bt);
};