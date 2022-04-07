#pragma once
#include <SFML/Graphics.hpp>

class Background
{
private:
	sf::Texture* texture;
	sf::Sprite sprite;

public:

	Background();
	Background(sf::Texture& tx);
	~Background();

	sf::Sprite GetSprite();
	void SetPosition(sf::Vector2f pos);
};