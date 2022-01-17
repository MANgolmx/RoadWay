#include <SFML/Graphics.hpp>
#include <math.h>
#include "Hexagon.h"
#include "DrivableHex.h"
#include "NonDrivableHex.h"

using namespace sf;

bool isBelong(Vector2i a, DrivableHex hex)
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

	RenderWindow window(VideoMode(window_width, window_height), "HexagonHighway");

	DrivableHex hexagon("resources/hexagons/Hexagon.png");

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
				if (isBelong(Mouse::getPosition(window), hexagon))
				{
					hexagon.Rotation();
				}
			}
		}
		

		window.clear();
		window.draw(hexagon.GetHexSprite());
		window.display();
	}

	return 0;
}