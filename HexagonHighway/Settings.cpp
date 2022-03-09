#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Assistant.h"
#include "Car.h"
#include "FText.h"
#include "Button.h"
#include "Level.h"
#include "Logo.h"
#include "Background.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Settings.h"

using namespace sf;

void settings(sf::RenderWindow& window)
{
	srand(time(0));

#pragma region INITIALIZATION

	Background menu("resources\\menu.png");

	float f1 = 1920 / 2 - window.getSize().x / 2;
	float f2 = 1080 / 2 - window.getSize().y / 2;
	menu.SetPosition({ -f1,-f2 });

	window.setFramerateLimit(60);

	bool inSettings = true;

#pragma endregion

	while (inSettings) //Цикл программы
	{
		Event event;
		while (window.pollEvent(event)) //Цикл событий
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Button::Left)) //Левая кнопка мыши
				{

				}
				break;
			case Event::Resized:
				Vector2f windowSize = Vector2f(event.size.width, event.size.height);
				window.setView(View(Vector2f(windowSize.x / 2.f,
					windowSize.y / 2.f), Vector2f(windowSize)));

				f1 = (1920 / 2 - window.getSize().x / 2);
				f2 = (1080 / 2 - window.getSize().y / 2);
				menu.SetPosition({ -f1,-f2 });
				break;
			}
		}

		window.draw(menu.GetSprite());
		window.display();
	}
}