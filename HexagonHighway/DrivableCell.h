#pragma once
#include "Cell.h"

enum types { undefiened, straight, turned, threeway, fourway };

class DrivableCell:public Cell
{
private:
	DrivableCell* mas = NULL;
	int typesSize[4];
	int size;
	types type;

public:
	DrivableCell();
	DrivableCell(std::string path);
	DrivableCell(int num, int tsize[4], int flowers, int trashes, int cities);
	~DrivableCell();
	
	types GetType();
};