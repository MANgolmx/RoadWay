#pragma once
#include "Cell.h"

enum nondrivableTypes { undefined, flowers, private_residence,
	apartments, structure};

class NonDrivableCell:public Cell
{
private:
	nondrivableTypes type;

public:
	NonDrivableCell();
	NonDrivableCell(std::string path);
	~NonDrivableCell();

	void SetType(int& forest, int& private_residence, int& apartment);

};