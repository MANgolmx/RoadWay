#include <SFML/Graphics.hpp>
#include "Hexagon.h"
#include "DrivableHex.h"
#include "NonDrivableHex.h"

using namespace sf;

int main()
{

#pragma region INITIALIZATION

	int window_width = 1200, window_height = 800;

	RenderWindow window(VideoMode(window_width, window_height), "HexagonHighway");
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);

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



			}
		}

		window.clear();
		window.draw(hexagon.GetHexSprite());
		window.display();
	}

	return 0;
}