#include "DrivableHex.h"

DrivableHex::DrivableHex(std::string path)
{
	type = undefiened;
	Hexagon(path);
}

DrivableHex::~DrivableHex()
{

}

types DrivableHex::GetType()
{
	return type;
}
