#pragma once
#include "Cell.h"
#include "NonDrivableCell.h"

enum types { undefiened, straight, turned, threeway, fourway };

class DrivableCell:public Cell
{
private:
	types type;
	bool isChosen;

public:
	DrivableCell();
	DrivableCell(std::string path);
	~DrivableCell();
	
	bool ifChosen();
	void SetChose(bool ch);

	void Draw(RenderWindow& win, NonDrivableCell chosen);

	void static Swap(DrivableCell& cell1, DrivableCell& cell2);

	types GetType();
	void SetType(int& straight, int& turned, int& threeway, int& fourway);
};