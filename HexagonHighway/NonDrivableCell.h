#pragma once
#include "Cell.h"

enum nondrivableTypes { forest, private_residence, apartments };

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