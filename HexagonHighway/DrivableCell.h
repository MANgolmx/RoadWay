#pragma once
#include "Cell.h"

enum drivableTypes { undefiened, straight, turned, threeway, fourway, finish, start };

class NonDrivableCell;
class TextureManager;

class DrivableCell:public Cell
{
private:
	drivableTypes type;
	bool isChosen;

	bool canBeMoved;
public:
	DrivableCell();
	DrivableCell(sf::Texture& tx);
	~DrivableCell();
	
	bool ifChosen();
	void SetChose(bool ch);

	void SetDrivableType(drivableTypes tp);
	bool CanGo(Directions& carDir, Directions& lastCarDir);

	void Draw(sf::RenderWindow& win, NonDrivableCell chosen);

	void static Swap(DrivableCell& cell1, DrivableCell& cell2);

	static DrivableCell* GetCellFromMainPos(sf::Vector2f mainPos, DrivableCell cells[], const int size);
	static DrivableCell* GetCellFromPos(sf::Vector2f pos, DrivableCell cells[], const int size);

	void ChangeMoveStatus(bool newMode);
	bool CanBeMoved();

	drivableTypes GetType();
	void SetType(TextureManager& tm, int& straight, int& turned, int& threeway, int& fourway);
};