#pragma once
#include <SFML/Graphics.hpp>

class Text
{
private:
	sf::Font font;
	sf::Text text;

public:
	Text();
	Text(std::string str, int size, std::string fontPath, sf::Color col = sf::Color::White);
	
	~Text();

	sf::Text GetText();


};