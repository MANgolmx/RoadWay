#pragma once
#include "Cell.h"

class NonDrivableCell:public Cell
{

public:
	NonDrivableCell();
	NonDrivableCell(const NonDrivableCell& cell);
	~NonDrivableCell();

};