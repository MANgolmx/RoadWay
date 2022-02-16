#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class FText
{
private:
	sf::Font font;
	sf::Text text;

public:
	FText();
	FText(std::string str, int size, std::string fontPath, const sf::Color col = sf::Color::White);

	~FText();

	Text GetText();

	void ChangeColor(Color col);

	Vector2f GetPosition();
	void SetPosition(Vector2f pos);

	void operator=(FText txt);
};
