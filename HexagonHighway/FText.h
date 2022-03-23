#pragma once
#include <SFML/Graphics.hpp>

class FText
{
private:
	sf::Font font;
	sf::Text text;

public:
	FText();
	FText(std::string str, int size, std::string fontPath, const sf::Color col = sf::Color::White);

	~FText();

	sf::Text GetText();

	void ChangeColor(sf::Color col);

	void ChangeText(std::string txt);

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f pos);

	void operator=(FText txt);
};
