#include "NonDrivableCell.h"

class StructureCell :
    public NonDrivableCell
{
protected:
	sf::Vector2f size;

public:

	StructureCell();
	~StructureCell();
};