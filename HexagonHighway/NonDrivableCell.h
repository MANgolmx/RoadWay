#pragma once
#include "Cell.h"

enum nondrivableTypes { undefined, flowers, private_residence, apartments, structure};

class TextureManager;

class NonDrivableCell:public Cell
{
protected:
	nondrivableTypes type;

public:
	NonDrivableCell();
	NonDrivableCell(TextureManager& tm, std::string path);
	~NonDrivableCell();

	void SetType(TextureManager& tm, int& flowers, int& private_residence, int& apartment);

};