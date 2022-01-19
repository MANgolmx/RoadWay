#include <SFML/Graphics.hpp>
#include <math.h>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"

using namespace sf;

bool isBelong(Vector2i a, DrivableCell hex)
{
	if (a.x >= hex.GetPosition().x &&
		a.x <= hex.GetPosition().x + 100 &&
		a.y >= hex.GetPosition().y + 25 &&
		a.y <= hex.GetPosition().y + 75)
		return true;
	return false;
}

int main()
{

#pragma region INITIALIZATION

	int window_width = 1200, window_height = 800;

	RenderWindow window(VideoMode(window_width, window_height), "RoadWay");

	DrivableCell cell("resources/cells/Cell.png");

#pragma endregion

	while (window.isOpen()) //Цикл программы
	{
		Event event;
		while (window.pollEvent(event)) //Цикл событий
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
			case Event::MouseButtonPressed:
				if (isBelong(Mouse::getPosition(window), cell))
				{
					cell.Rotation();
				}
			}
		}
		

		window.clear();
		window.draw(cell.GetCellSprite());
		window.display();
	}

	return 0;
}