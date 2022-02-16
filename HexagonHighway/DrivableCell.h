#pragma once
#include "Cell.h"
#include "NonDrivableCell.h"

enum drivableTypes { undefiened, straight, turned, threeway, fourway };

class DrivableCell:public Cell
{
private:
	drivableTypes type;
	bool isChosen;

public:
	DrivableCell();
	DrivableCell(std::string path);
	~DrivableCell();
	
	bool ifChosen();
	void SetChose(bool ch);

	bool CanGo(directions& carDir, directions& lastCarDir);

	void Draw(sf::RenderWindow& win, NonDrivableCell chosen);

	void static Swap(DrivableCell& cell1, DrivableCell& cell2);

	static DrivableCell* GetCellFromMainPos(Vector2f mainPos, DrivableCell cells[], const int size);
	static DrivableCell* GetCellFromPos(Vector2f pos, DrivableCell cells[], const int size);

	drivableTypes GetType();
	void SetType(int& straight, int& turned, int& threeway, int& fourway);
};