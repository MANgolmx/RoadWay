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
#include <SFML/Audio.hpp>
#include "TextureManager.h"

using namespace sf;

int levelMenu(sf::RenderWindow& window, TextureManager& tm)
{

#pragma region INITIALIZATION

	float f1, f2;

	Background menu("resources\\menu.png");

	f1 = 3840 / 2 - window.getSize().x / 2;
	f2 = 2160 / 2 - window.getSize().y / 2;
	menu.SetPosition({ -f1,-f2 });

	FText txt_lvl1("1", 120, "resources\\fonts\\pixeltime\\PixelTimes.ttf");
	Button bt_lvl1(txt_lvl1, "resources\\buttons\\button_level.png", { 60, 5 });

	f1 = window.getSize().x / 10;
	f2 = window.getSize().y / 10 + 50;
	bt_lvl1.SetPosition({ f1, f2 });

	window.setFramerateLimit(60);

	bool inMenu = true;

#pragma endregion

	while (inMenu) //Цикл игры
	{
		Event event;
		while (window.pollEvent(event)) //Цикл событий
		{
			switch (event.type)
			{
			case Event::Closed:
				return 1;
			case Event::MouseButtonPressed: //Нажата кнопка мыши
				if (Mouse::isButtonPressed(Mouse::Button::Left)) //Левая кнопка мыши
				{ 
					if (isBelong(Mouse::getPosition(window), bt_lvl1))
						if (levelStart(window, tm, "levels\\level_test.lvl", "levels\\level_testcar.lvl", "levels\\level_testtypes.lvl"))
							return 1;
				}
				break;
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape)
					inMenu = false;
				break;
			case Event::Resized:
				Vector2f windowSize = Vector2f(event.size.width, event.size.height);
				window.setView(View(Vector2f(windowSize.x / 2.f,
					windowSize.y / 2.f), Vector2f(windowSize)));
				
				f1 = window.getSize().x / 10;
				f2 = window.getSize().y / 10 + 50;
				bt_lvl1.SetPosition({ f1, f2 });

				float f1 = 3840 / 2 - window.getSize().x / 2;
				float f2 = 2160 / 2 - window.getSize().y / 2;
				menu.SetPosition({ -f1,-f2 });
				break;
			}
		}

		window.draw(menu.GetSprite());
		bt_lvl1.Draw(window);
		window.display();
	}

	return 0;
}
