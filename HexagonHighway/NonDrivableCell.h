#pragma once
#include "Cell.h"

enum nondrivableTypes { undefined, flowers, private_residence,
	apartments, structure};

class NonDrivableCell:public Cell
{
protected:
	nondrivableTypes type;

public:
	NonDrivableCell();
	NonDrivableCell(std::string path);
	~NonDrivableCell();

	void SetType(int& flowers, int& private_residence, int& apartment);

};