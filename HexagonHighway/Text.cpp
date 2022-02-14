#include "Text.h"

Text::Text()
{



}

Text::Text(std::string str, int size, std::string fontPath, sf::Color col)
{
	font.loadFromFile(fontPath);
	text.setFont(font);
	text.setCharacterSize(size);
	text.setString(str);
	text.setColor(col);
}

Text::~Text()
{



}

sf::Text Text::GetText()
{
	return text;
}