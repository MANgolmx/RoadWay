#pragma once
#include "FText.h"

class Button
{
private:
	FText ftext;

	sf::Sprite sprite;
	sf::Texture texture;

	Vector2f textPosition;

public:
	Button();
	Button(FText txt, std::string texturePath, Vector2f textPos);
	Button(FText txt, sf::Texture Texture, Vector2f textPos);

	~Button() {};

	sf::Sprite GetSprite();
	sf::Texture GetTexture();
	
	Vector2f GetPosition();
	void SetPosition(Vector2f pos);

	FText GetFText();

	void operator=(Button bt);
};