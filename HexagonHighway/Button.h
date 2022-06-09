#pragma once
#include <SFML/Graphics.hpp>
#include "FText.h"

class Button
{
private:
	FText ftext;

	sf::Sprite sprite;
	sf::Texture* texture;

	sf::Vector2f textPosition;

public:
	Button();
	Button(FText txt, std::string texturePath, sf::Vector2f textPos);
	Button(FText txt, sf::Texture& Texture, sf::Vector2f textPos);
	Button(std::string texturePath);
	Button(sf::Texture& txture);

	~Button() {};

	sf::Sprite GetSprite();
	sf::Texture GetTexture();
	
	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f pos);

	void SetScale(sf::Vector2f factors);

	void Mirrored(float angle);

	FText GetFText();

	void Draw(sf::RenderWindow& win);

	void operator=(Button bt);
};