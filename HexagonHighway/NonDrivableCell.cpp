#include "NonDrivableCell.h"
#include <iostream>
#include "TextureManager.h"

NonDrivableCell::NonDrivableCell()
{
	type = undefined;
	Cell();
}

NonDrivableCell::NonDrivableCell(std::string path)
{
	type = undefined;
	if (!square_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open nonDrivableCell texture" << std::endl;
		exit(1);
	}

	square_sprite.setTexture(square_texture);
	square_sprite.setPosition(0, 0);
}

NonDrivableCell::~NonDrivableCell()
{
}

void NonDrivableCell::SetType(TextureManager& tm, int& flowers, int& private_residence, int& apartment)
{
	std::string path;

	int Exit = 0;

	int a = rand() % 4;
	switch (a) {
	case 0: Cell::direction = UP; break;
	case 1: Cell::direction = RIGHT; break;
	case 2: Cell::direction = DOWN; break;
	case 3: Cell::direction = LEFT; break;
	}
	Rotation();

	 a = rand() % 3;
	switch (a) {
	case 0: goto flowersRand;
	case 1: goto privateResidenceRand;
	case 2: goto apartmentRand;
	}

	flowersRand:
		if (flowers > 0)
		{
			type = nondrivableTypes::flowers;

			a = rand() % 6;

			switch (a) {
			case 0: path = "resources\\cells\\flowers\\flowers_1.png"; break;
			case 1: path = "resources\\cells\\flowers\\flowers_2.png"; break;
			case 2: path = "resources\\cells\\flowers\\flowers_3.png"; break;
			case 3: path = "resources\\cells\\flowers\\flowers_4.png"; break;
			case 4: path = "resources\\cells\\flowers\\flowers_5.png"; break;
			case 5: path = "resources\\cells\\flowers\\flowers_6.png"; break;
			}

			if (!square_texture.loadFromFile(path)) {
				std::cout << "[ERROR OCURRED] Can not open Flowers.png" << std::endl;
				exit(1);
			}

			square_sprite.setTexture(square_texture);

			flowers--;
			return;
		}

	privateResidenceRand:
		if (private_residence > 0)
		{
			type = nondrivableTypes::private_residence;
			a = rand() % 4;

			switch (a) {
			case 0: path = "resources\\cells\\privateResidence\\private_residence_1.png"; break;
			case 1: path = "resources\\cells\\privateResidence\\private_residence_2.png"; break;
			case 2: path = "resources\\cells\\privateResidence\\private_residence_3.png"; break;
			case 3: path = "resources\\cells\\privateResidence\\private_residence_4.png"; break;
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
	goto flowersRand;
}
