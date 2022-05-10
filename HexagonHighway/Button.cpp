#include "Button.h"
#include "FText.h"
#include  <iostream>
#include <SFML\Graphics.hpp>

using namespace sf;

Button::Button()
{
}

Button::Button(FText txt, std::string texturePath, Vector2f textPos)
{
	ftext = txt;
	textPosition = textPos;
	if (!texture->loadFromFile(texturePath)) {
		std::cout << "[ERROR OCURRED] Can not open button texture" << std::endl;
		exit(1);
	}

	sprite.setTexture(*texture);
	sprite.setPosition(0, 0);
	ftext.SetPosition(sprite.getPosition() + textPos);

}

Button::Button(FText txt, sf::Texture& Texture, Vector2f textPos)
{
	ftext = txt;
	texture = &Texture;
	textPosition = textPos;
	sprite.setTexture(*texture);
	sprite.setPosition(0, 0);
	ftext.SetPosition(sprite.getPosition() + textPos);
}

Button::Button(std::string texturePath)
{
	textPosition = { 0,0 };
	if (!texture->loadFromFile(texturePath)) {
		std::cout << "[ERROR OCURRED] Can not open button texture" << std::endl;
		exit(1);
	}

	sprite.setTexture(*texture);
	sprite.setPosition(0, 0);
	ftext.SetPosition(sprite.getPosition());
}

Button::Button(sf::Texture& txture)
{
	textPosition = { 0,0 };
	texture = &txture;

	sprite.setTexture(*texture);
	sprite.setPosition(0, 0);
	ftext.SetPosition(sprite.getPosition());
}

sf::Sprite Button::GetSprite()
{
	return sprite;
}

sf::Texture Button::GetTexture()
{
	return *texture;
}

Vector2f Button::GetPosition()
{
	return sprite.getPosition();
}

void Button::SetPosition(Vector2f pos)
{
	sprite.setPosition(pos);
	ftext.SetPosition(sprite.getPosition() + textPosition);
}

void Button::Mirrored(float angle)
{
	sprite.setRotation(angle);
	sprite.setOrigin(0, texture->getSize().x);
}

FText Button::GetFText()
{
	return ftext;
}

void Button::Draw(sf::RenderWindow& win)
{
	win.draw(sprite);
	win.draw(ftext.GetText());
}

void Button::operator=(Button bt)
{
	ftext = bt.ftext;
	texture = bt.texture;
	sprite.setTexture(*texture);
	sprite.setPosition(bt.sprite.getPosition());
	ftext.SetPosition(bt.ftext.GetPosition());
}
