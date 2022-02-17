#pragma once
#include "NonDrivableCell.h"
#include <SFML/Graphics.hpp>

class StructureCell :public NonDrivableCell
{
private:
	sf::Vector2f size;


public:
	StructureCell();
	StructureCell(std::string path);
	~StructureCell();



};