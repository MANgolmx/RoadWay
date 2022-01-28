#pragma once
#include "Cell.h"

class NonDrivableCell:public Cell
{

public:
	NonDrivableCell();
	NonDrivableCell(std::string path);
	~NonDrivableCell();

};