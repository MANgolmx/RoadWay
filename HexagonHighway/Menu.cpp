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
#include "Settings.h" 

using namespace sf;

int main()
{
	srand(time(0));

#pragma region INITIALIZATION

	int window_width = 1212, window_height = 808;

	RenderWindow window(VideoMode(window_width, window_height), "RoadWay");

	Background menu("resources\\menu.png");
	
	Music song_menu_bg;
	song_menu_bg.openFromFile("resources\\sounds\\menu.ogg");
	song_menu_bg.setLoop(true);
	song_menu_bg.setVolume(20);

	float f1 = 1920 / 2 - window_width / 2;
	float f2 = 1080 / 2 - window_height / 2;
	menu.SetPosition({ -f1,-f2 });

	FText txt_play("PLAY", 76, "resources\\fonts\\pixeltime\\PixelTimes.ttf");
	Button bt_play(txt_play, "resources\\buttons\\button_small.png", {20,24});
	
	f1 = window.getSize().x / 10;
	f2 = window.getSize().y / 10 + 50;
	bt_play.SetPosition({ f1, f2 });

	FText txt_settings("SETTINGS", 76, "resources\\fonts\\pixeltime\\PixelTimes.ttf");
	Button bt_settings(txt_settings, "resources\\buttons\\button_settings.png", {30,24});
	
	f1 = window.getSize().x / 2 - bt_settings.GetTexture().getSize().x / 2;
	f2 = window.getSize().y / 2 - bt_settings.GetTexture().getSize().y / 2;
	bt_settings.SetPosition({ f1,f2 });

	FText txt_exit("EXIT", 76, "resources\\fonts\\pixeltime\\PixelTimes.ttf");
	Button bt_exit(txt_exit, "resources\\buttons\\button_small.png", { 30,24 });

	f1 = window.getSize().x - window.getSize().x / 10 - bt_exit.GetTexture().getSize().x;
	f2 = window.getSize().y - window.getSize().y / 10 - bt_exit.GetTexture().getSize().y;
	bt_exit.SetPosition({ f1,f2 });

	window.setFramerateLimit(60);

	bool isOpened = true;

#pragma endregion

	playlogo(window);

	f1 = window.getSize().x / 10;
	f2 = window.getSize().y / 10 + 50;
	bt_play.SetPosition({ f1, f2 });

	f1 = (1920 / 2 - window.getSize().x / 2);
	f2 = (1080 / 2 - window.getSize().y / 2);
	menu.SetPosition({ -f1,-f2 });
	
	song_menu_bg.play();

	while (isOpened) //Цикл программы
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
					if (isBelong(Mouse::getPosition(window), bt_play))
						levelStart(window);
					if (isBelong(Mouse::getPosition(window), bt_settings))
						settings(window);
					if (isBelong(Mouse::getPosition(window), bt_exit))
						isOpened = false;
				}
				break;
			case Event::Resized:
				Vector2f windowSize = Vector2f(event.size.width, event.size.height);
				window.setView(View(Vector2f(windowSize.x / 2.f,
					windowSize.y / 2.f), Vector2f(windowSize)));

				f1 = window.getSize().x / 10;
				f2 = window.getSize().y / 10 + 50;
				bt_play.SetPosition({ f1, f2 });

				f1 = window.getSize().x / 2 - bt_settings.GetTexture().getSize().x / 2;
				f2 = window.getSize().y / 2 - bt_settings.GetTexture().getSize().y / 2;
				bt_settings.SetPosition({ f1,f2 });
				
				f1 = window.getSize().x - window.getSize().x / 10 - bt_exit.GetTexture().getSize().x;
				f2 = window.getSize().y - window.getSize().y / 10 - bt_exit.GetTexture().getSize().y;
				bt_exit.SetPosition({ f1,f2 });

				f1 = (1920 / 2 - window.getSize().x / 2);
				f2 = (1080 / 2 - window.getSize().y / 2);
				menu.SetPosition({ -f1,-f2 });
				break;
			}
		}

		window.draw(menu.GetSprite());
		bt_play.Draw(window);
		bt_settings.Draw(window);
		bt_exit.Draw(window);
		window.display();
	}

	song_menu_bg.stop();
	window.close();
	return 0;
}