#include "NonDrivableCell.h"
#include <iostream>


NonDrivableCell::NonDrivableCell()
{
	type = undefined;
}

NonDrivableCell::NonDrivableCell(std::string path)
{
	if (!square_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open cell texture" << std::endl;
		exit(1);
	}

	square_sprite.setTexture(square_texture);
	square_sprite.setPosition(0, 0);
}

NonDrivableCell::~NonDrivableCell()
{
}

void NonDrivableCell::SetType(int& forest, int& private_residence, int& apartment)
{
	std::string path;

	int Exit = 0;

	int a = rand() % 4;
	switch (a) {
	case 0: Cell::direction = up; break;
	case 1: Cell::direction = right; break;
	case 2: Cell::direction = down; break;
	case 3: Cell::direction = left; break;
	}
	Rotation();

	 a = rand() % 3;
	switch (a) {
	case 0: goto forestRand;
	case 1: goto privateResidenceRand;
	case 2: goto apartmentRand;
	}

	forestRand:
		if (forest > 0)
		{
			type = nondrivableTypes::forest;

			a = rand() % 6;

			switch (a) {
			case 0: path = "resources\\cells\\flowers\\floawers_1.png"; break;
			case 1: path = "resources\\cells\\flowers\\floawers_2.png"; break;
			case 2: path = "resources\\cells\\flowers\\floawers_3.png"; break;
			case 3: path = "resources\\cells\\flowers\\floawers_4.png"; break;
			case 4: path = "resources\\cells\\flowers\\floawers_5.png"; break;
			case 5: path = "resources\\cells\\flowers\\floawers_6.png"; break;
			}

			if (!square_texture.loadFromFile(path)) {
				std::cout << "[ERROR OCURRED] Can not open Forest.png" << std::endl;
				exit(1);
			}

			square_sprite.setTexture(square_texture);

			forest--;
			return;
		}

	privateResidenceRand:
		if (private_residence > 0)
		{
			type = nondrivableTypes::private_residence;
			a = rand() % 4;

			switch (a) {
			case 0: path = "resources\\cells\\privateResidence\\privateResidence_1.png"; break;
			case 1: path = "resources\\cells\\privateResidence\\privateResidence_2.png"; break;
			case 2: path = "resources\\cells\\privateResidence\\privateResidence_3.png"; break;
			case 3: path = "resources\\cells\\privateResidence\\privateResidence_4.png"; break;
			}

			if (!square_texture.loadFromFile(path)) {
				std::cout << "[ERROR OCURRED] Can not open PrivateResidence.png" << std::endl;
				exit(1);
			}

			square_sprite.setTexture(square_texture);

			private_residence--;
			return;
		}

	apartmentRand:
		if (apartment > 0)
		{
			type = nondrivableTypes::apartments;



			if (!square_texture.loadFromFile(path)) {
				std::cout << "[ERROR OCURRED] Can not open Apartments.png" << std::endl;
				exit(1);
			}

			square_sprite.setTexture(square_texture);

			apartment--;
			return;
		}
		Exit++;

		if (Exit > 10)
			return;
	goto forestRand;
}
