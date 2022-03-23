#include "FText.h"
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace sf;

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

void FText::ChangeColor(Color col)
{
	text.setFillColor(col);
}

void FText::ChangeText(std::string txt)
{
	text.setString(txt);
}

Vector2f FText::GetPosition()
{
	return text.getPosition();
}

void FText::SetPosition(Vector2f pos)
{
	text.setPosition(pos);
}

void FText::operator=(FText txt)
{
	font = txt.font;
	text = txt.text;
	text.setPosition(txt.text.getPosition());
}
