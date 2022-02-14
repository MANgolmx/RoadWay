#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class FText
{
private:
public:
	sf::Font font;
	sf::Text text;

	FText();
	FText(std::string str, int size, std::string fontPath, const sf::Color col = sf::Color::White);

	~FText();

	Text GetText();

	void SetPosition(Vector2f pos);
};
