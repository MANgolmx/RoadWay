#pragma once
#include <SFML\Graphics.hpp>

class TextureManager;

int levelStart(sf::RenderWindow& window, TextureManager& tm, const char level_path[], const char level_carpath[], const char level_typespath[]);