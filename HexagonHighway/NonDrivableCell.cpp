#include "NonDrivableCell.h"
#include <iostream>
#include "TextureManager.h"

NonDrivableCell::NonDrivableCell()
{
	type = undefined;
	Cell();
}

NonDrivableCell::NonDrivableCell(TextureManager& tm, std::string path)
{
	type = undefined;

	square_texture = &tm.PullTexture(path);
	square_sprite.setTexture(*square_texture);
	square_sprite.setPosition(0, 0);
}

NonDrivableCell::~NonDrivableCell()
{
}

void NonDrivableCell::SetType(TextureManager& tm, int& flowers, int& private_residence, int& apartment)
{
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
			case 0: square_texture = &tm.PullTexture("resources\\cells\\flowers\\flowers_1.png"); break;
			case 1: square_texture = &tm.PullTexture("resources\\cells\\flowers\\flowers_2.png"); break;
			case 2: square_texture = &tm.PullTexture("resources\\cells\\flowers\\flowers_3.png"); break;
			case 3: square_texture = &tm.PullTexture("resources\\cells\\flowers\\flowers_4.png"); break;
			case 4: square_texture = &tm.PullTexture("resources\\cells\\flowers\\flowers_5.png"); break;
			case 5: square_texture = &tm.PullTexture("resources\\cells\\flowers\\flowers_6.png"); break;
			}

			square_sprite.setTexture(*square_texture);

			flowers--;
			return;
		}

	privateResidenceRand:
		if (private_residence > 0)
		{
			type = nondrivableTypes::private_residence;
			a = rand() % 4;

			switch (a) {
			case 0: square_texture = &tm.PullTexture("resources\\cells\\privateResidence\\private_residence_1.png"); break;
			case 1: square_texture = &tm.PullTexture("resources\\cells\\privateResidence\\private_residence_2.png"); break;
			case 2: square_texture = &tm.PullTexture("resources\\cells\\privateResidence\\private_residence_3.png"); break;
			case 3: square_texture = &tm.PullTexture("resources\\cells\\privateResidence\\private_residence_4.png"); break;
			}

			square_sprite.setTexture(*square_texture);

			private_residence--;
			return;
		}

	apartmentRand:
		if (apartment > 0)
		{
			type = nondrivableTypes::apartments;



			//square_sprite.setTexture(*square_texture);

			apartment--;
			return;
		}
		Exit++;

		if (Exit > 10)
			return;
	goto flowersRand;
}
