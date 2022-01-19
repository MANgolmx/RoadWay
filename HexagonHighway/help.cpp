#include <SFML/Graphics.hpp>
#include <math.h>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"

using namespace sf;

std::string getPath(types type, int tsize, int flowers, int trashes, int cities)
{
	switch (type)
	{
	case straight:
		for (int i = 0; i < tsize; i++)
		{


		}
	}


}

bool isBelong(Vector2i a, DrivableCell cell)
{
	if (a.x >= cell.GetPosition().x &&
		a.x <= cell.GetPosition().x + 100 &&
		a.y >= cell.GetPosition().y &&
		a.y <= cell.GetPosition().y + 100)
		return true;
	return false;
}