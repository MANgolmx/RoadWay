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

	int carType = 0;

	Background menu(tm.PullTexture("resources\\menu.png"));

	f1 = 3840 / 2 - window.getSize().x / 2;
	f2 = 2160 / 2 - window.getSize().y / 2;
	menu.SetPosition({ -f1,-f2 });

	FText txt_lvl1("1", 120, "resources\\fonts\\pixeltime\\PixelTimes.ttf");
	Button bt_lvl1(txt_lvl1, tm.PullTexture("resources\\buttons\\button_level.png"), {60, 5});

	f1 = window.getSize().x / 10;
	f2 = window.getSize().y / 10 + 50;
	bt_lvl1.SetPosition({ f1, f2 });

	Button bt_car_1(tm.PullTexture("resources\\cars\\car_1.png"));
	bt_car_1.SetScale({ 4,4 });
	f1 = window.getSize().x / 2 - bt_car_1.GetTexture().getSize().x / 2;
	f2 = window.getSize().y - window.getSize().y / 10 - 50;

	bt_car_1.SetPosition({ f1,f2 });

	Button bt_car_2(tm.PullTexture("resources\\cars\\car_2.png"));
	bt_car_2.SetScale({ 4,4 });
	f1 = window.getSize().x / 2 - bt_car_1.GetTexture().getSize().x / 2;
	f2 = window.getSize().y - window.getSize().y / 10 - 50;
	
	bt_car_2.SetPosition({ f1,f2 });

	Button bt_car_3(tm.PullTexture("resources\\cars\\car_police.png"));
	bt_car_3.SetScale({ 4,4 });
	f1 = window.getSize().x / 2 - bt_car_1.GetTexture().getSize().x / 2;
	f2 = window.getSize().y - window.getSize().y / 10 - 50;

	bt_car_3.SetPosition({ f1,f2 });

	Button bt_car_next(tm.PullTexture("resources\\buttons\\button_next.png"));
	f1 = window.getSize().x / 2 - bt_car_next.GetTexture().getSize().x / 2 + 170;
	f2 = window.getSize().y - window.getSize().y / 10 - 50;

	bt_car_next.SetPosition({ f1,f2 });

	Button bt_car_prev(tm.PullTexture("resources\\buttons\\button_next.png"));
	f1 = window.getSize().x / 2 - bt_car_next.GetTexture().getSize().x / 2 + 38;
	f2 = window.getSize().y - window.getSize().y / 10 - 50;

	bt_car_prev.SetPosition({ f1,f2 });
	bt_car_prev.Mirrored(180);
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
						if (levelStart(window, tm, carType, "levels\\level_test.lvl", "levels\\level_testcar.lvl", "levels\\level_testtypes.lvl"))
							return 1;
					
					if (isBelong(Mouse::getPosition(window), bt_car_next))
						if (carType < 2) carType++;
						else carType = 0;
					if (isBelong(Mouse::getPosition(window),
						{ bt_car_prev.GetPosition().x - bt_car_prev.GetTexture().getSize().x, bt_car_prev.GetPosition().y, float(bt_car_prev.GetTexture().getSize().x), float(bt_car_prev.GetTexture().getSize().y) }))
						if (carType > 0) carType--;
						else carType = 2;

					#pragma region RESIZING
					f1 = window.getSize().x / 10;
					f2 = window.getSize().y / 10 + 50;
					bt_lvl1.SetPosition({ f1, f2 });

					f1 = window.getSize().x / 2 - bt_car_1.GetTexture().getSize().x / 2;
					f2 = window.getSize().y - window.getSize().y / 10 - 50;
					bt_car_1.SetPosition({ f1,f2 });
					bt_car_2.SetPosition({ f1,f2 });

					f1 = window.getSize().x / 2 - bt_car_next.GetTexture().getSize().x / 2 + 170;
					f2 = window.getSize().y - window.getSize().y / 10 - 50;
					bt_car_next.SetPosition({ f1,f2 });

					f1 = window.getSize().x / 2 - bt_car_next.GetTexture().getSize().x / 2 + 38;
					f2 = window.getSize().y - window.getSize().y / 10 - 50;
					bt_car_prev.SetPosition({ f1,f2 });

					f1 = 3840 / 2 - window.getSize().x / 2;
					f2 = 2160 / 2 - window.getSize().y / 2;
					menu.SetPosition({ -f1,-f2 });
#pragma endregion
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

				f1 = window.getSize().x / 2 - bt_car_1.GetTexture().getSize().x / 2;
				f2 = window.getSize().y - window.getSize().y / 10 - 50;
				bt_car_1.SetPosition({ f1,f2 });
				bt_car_2.SetPosition({ f1,f2 });

				f1 = window.getSize().x / 2 - bt_car_next.GetTexture().getSize().x / 2 + 170;
				f2 = window.getSize().y - window.getSize().y / 10 - 50;
				bt_car_next.SetPosition({ f1,f2 });

				f1 = window.getSize().x / 2 - bt_car_next.GetTexture().getSize().x / 2 + 38;
				f2 = window.getSize().y - window.getSize().y / 10 - 50;
				bt_car_prev.SetPosition({ f1,f2 });

				f1 = 3840 / 2 - window.getSize().x / 2;
				f2 = 2160 / 2 - window.getSize().y / 2;
				menu.SetPosition({ -f1,-f2 });
				break;
			}
		}

		window.draw(menu.GetSprite());
		bt_lvl1.Draw(window);
		switch (carType) {
		case 0: bt_car_1.Draw(window); break;
		case 1: bt_car_2.Draw(window); break;
		case 2: bt_car_3.Draw(window); break;
		}
		bt_car_next.Draw(window);
		bt_car_prev.Draw(window);
		window.display();
	}

	return 0;
}
