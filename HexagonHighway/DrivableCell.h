#pragma once
#include "Cell.h"

enum drivableTypes { undefiened, straight, turned, threeway, fourway, finish, start };

class DrivableCell;
class NonDrivableCell;

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

	void SetDrivableType(drivableTypes tp);
	bool CanGo(directions& carDir, directions& lastCarDir);

	void Draw(sf::RenderWindow& win, NonDrivableCell chosen);

	void static Swap(DrivableCell& cell1, DrivableCell& cell2);

	static DrivableCell* GetCellFromMainPos(sf::Vector2f mainPos, DrivableCell cells[], const int size);
	static DrivableCell* GetCellFromPos(sf::Vector2f pos, DrivableCell cells[], const int size);

	drivableTypes GetType();
	void SetType(TextureManager& tm, int& straight, int& turned, int& threeway, int& fourway);
};