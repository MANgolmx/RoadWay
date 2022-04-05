#pragma once
#include <SFML\Graphics.hpp>
#include <map>

class TextureManager
{
private:
	std::map<std::string, sf::Texture> Textures;
	std::map<std::string, sf::Texture*> TexturePointers;

public:

	TextureManager();
	~TextureManager();

	void IncludeCellTextures();

	sf::Texture* PullTexture(std::string key);
};