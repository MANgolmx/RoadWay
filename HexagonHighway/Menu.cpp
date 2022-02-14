#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Assistant.h"
#include "Car.h"
#include "Level.h"

using namespace sf;

int main()
{
	srand(time(0));

#pragma region INITIALIZATION

	int window_width = 1212, window_height = 808;

	RenderWindow window(VideoMode(window_width, window_height), "RoadWay");

	Texture texture;
	Sprite sprite;

	if (!texture.loadFromFile("resources\\buttons\\button_play.png")) {
		std::cout << "[ERROR OCURRED] Can not open cell texture" << std::endl;
		exit(1);
	}

	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	window.setFramerateLimit(60);

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
				break;
			}
		}

		window.clear({ 181, 230, 29, 255 });
		window.display();
	}

	return 0;
}