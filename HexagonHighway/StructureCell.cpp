#include "StructureCell.h"
#include <iostream>

StructureCell::StructureCell()
{
	size = { 1,1 };
	type = structure;
	NonDrivableCell();
}

StructureCell::~StructureCell()
{
}
