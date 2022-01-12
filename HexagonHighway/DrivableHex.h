#pragma once
#include "Hexagon.h"

enum types { undefiened, straight, turned, turned_mirrored, threeway_y, fourway_x, straight_c };

class DrivableHex:public Hexagon
{
	types type;


	DrivableHex();
	~DrivableHex();

};