#include "FText.h"

FText::FText()
{



}

FText::FText(std::string str, int size, std::string fontPath, const sf::Color col)
{
	font.loadFromFile(fontPath);
	text.setFont(font);
	text.setCharacterSize(size);
	text.setString(str);
	text.setFillColor(col);
}

FText::~FText()
{



}

Text FText::GetText()
{
	return text;
}

void FText::SetPosition(Vector2f pos)
{
	text.setPosition(pos);
}
