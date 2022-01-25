#include "NonDrivableCell.h"

NonDrivableCell::NonDrivableCell()
{
}

NonDrivableCell::NonDrivableCell(const NonDrivableCell& cell)
{
	position.x = cell.position.x;
	position.y = cell.position.y;
	mainPosition.x = cell.mainPosition.x;
	mainPosition.y = cell.mainPosition.y;
	direction = cell.direction;
}

NonDrivableCell::~NonDrivableCell()
{
}
