#pragma once
#include "Cell.h"

enum types { undefiened, straight, turned, threeway, fourway };

class DrivableCell:public Cell
{
private:
	types type;

public:
	DrivableCell();
	DrivableCell(std::string path);
	~DrivableCell();
	
	types GetType();
	void SetType(int& straight, int& turned, int& threeway, int& fourway);
};