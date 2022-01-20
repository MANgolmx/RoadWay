#include "DrivableCell.h"

DrivableCell::DrivableCell()
{
	type = undefiened;
}

DrivableCell::DrivableCell(std::string path)
{
	type = undefiened;

	if (!square_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open Cell.png" << std::endl;
		exit(1);
	}

	square_sprite.setTexture(square_texture);
	square_sprite.setPosition(position.x, position.y);
}

DrivableCell::~DrivableCell()
{

}

types DrivableCell::GetType()
{
	return type;
}

void DrivableCell::SetType(int& straight, int& turned, int& threeway, int& fourway)
{
	std::string path;
	if (straight > 0)
	{
		type = types::straight;

		int tmp = rand() % 10;
		switch (tmp) {
		case 0: path = "resources\\cells\\straight_flowers_1.png";   break;
		case 1: path = "resources\\cells\\straight_flowers_2.png";	 break;
		case 2: path = "resources\\cells\\straight_flowers_3.png"; 	 break;
		case 3: path = "resources\\cells\\straight_flowers_4.png";	 break;
		case 4: path = "resources\\cells\\straight_trashbin_1.png";	 break;
		case 5: path = "resources\\cells\\straight_trashbin_2.png";	 break;
		case 6: path = "resources\\cells\\straight_trashbin_3.png";	 break;
		case 7: path = "resources\\cells\\straight_trashbin_4.png";	 break;
		case 8: path = "resources\\cells\\straight_trashbin_5.png";	 break;
		case 9: path = "resources\\cells\\straight_trashbin_6.png";	 break;
		}

		if (!square_texture.loadFromFile(path)) {
			std::cout << "[ERROR OCURRED] Can not open Cell.png" << std::endl;
			exit(1);
		}

		square_sprite.setTexture(square_texture);

		straight--;
	}
}