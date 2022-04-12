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
#include "Level_Menu.h"
#include "TextureManager.h"

using namespace sf;

int main()
{
	srand(time(0));

#pragma region INITIALIZATION
	
	int window_width = 1600, window_height = 900;

	float volume = 10;

	TextureManager tm;
	//tm.IncludeCellTextures();

	RenderWindow window(VideoMode(window_width, window_height), "RoadWay");

	Image icon;
	if (!icon.loadFromFile("resources\\icon.png")) exit(1);
	window.setIcon(101, 101, icon.getPixelsPtr());
	
	Music song_menu_bg;
	song_menu_bg.openFromFile("resources\\sounds\\menu.ogg");
	song_menu_bg.setLoop(true);
	song_menu_bg.setVolume(volume);

	Background menu(tm.PullTexture("resources\\menu.png"));

	float f1 = 3840 / 2 - window.getSize().x / 2;
	float f2 = 2160 / 2 - window.getSize().y / 2;
	menu.SetPosition({ -f1,-f2 });

	FText txt_play("PLAY", 76, "resources\\fonts\\pixeltime\\PixelTimes.ttf");
	Button bt_play(txt_play, tm.PullTexture("resources\\buttons\\button_small.png"), {20,24});
	
	f1 = window.getSize().x / 10;
	f2 = window.getSize().y / 10 + 50;
	bt_play.SetPosition({ f1, f2 });

	FText txt_settings("SETTINGS", 76, "resources\\fonts\\pixeltime\\PixelTimes.ttf");
	Button bt_settings(txt_settings, tm.PullTexture("resources\\buttons\\button_settings.png"), {30,24});
	
	f1 = window.getSize().x / 2 - bt_settings.GetTexture().getSize().x / 2;
	f2 = window.getSize().y / 2 - bt_settings.GetTexture().getSize().y / 2;
	bt_settings.SetPosition({ f1,f2 });

	FText txt_exit("EXIT", 76, "resources\\fonts\\pixeltime\\PixelTimes.ttf");
	Button bt_exit(txt_exit, tm.PullTexture("resources\\buttons\\button_small.png"), { 30,24 });

	f1 = window.getSize().x - window.getSize().x / 10 - bt_exit.GetTexture().getSize().x;
	f2 = window.getSize().y - window.getSize().y / 10 - bt_exit.GetTexture().getSize().y;
	bt_exit.SetPosition({ f1,f2 });

	window.setFramerateLimit(60);

	bool isOpened = true;

#pragma endregion

	if (playlogo(window))
		isOpened = false;


	f1 = 3840 / 2 - window.getSize().x / 2;
	f2 = 2160 / 2 - window.getSize().y / 2;
	menu.SetPosition({ -f1,-f2 });

	f1 = window.getSize().x / 10;
	f2 = window.getSize().y / 10 + 50;
	bt_play.SetPosition({ f1, f2 });
	
	f1 = window.getSize().x / 2 - bt_settings.GetTexture().getSize().x / 2;
	f2 = window.getSize().y / 2 - bt_settings.GetTexture().getSize().y / 2;
	bt_settings.SetPosition({ f1,f2 });

	f1 = window.getSize().x - window.getSize().x / 10 - bt_exit.GetTexture().getSize().x;
	f2 = window.getSize().y - window.getSize().y / 10 - bt_exit.GetTexture().getSize().y;
	bt_exit.SetPosition({ f1,f2 });

	song_menu_bg.play();

	while (isOpened) //Цикл программы
	{
		Event event;
		while (window.pollEvent(event)) //Цикл событий
		{
			switch (event.type)
			{
			case Event::Closed:
				isOpened = false;
				break;
			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Button::Left)) //Левая кнопка мыши
				{
					if (isBelong(Mouse::getPosition(window), bt_play))
					{
						if (levelStart(window, tm, "levels\\level_test.lvl", "levels\\level_testcar.lvl", "levels\\level_testtypes.lvl"))
							isOpened = false;
						//if (levelMenu(window))
							//isOpened = false;
						f1 = 3840 / 2 - window.getSize().x / 2;
						f2 = 2160 / 2 - window.getSize().y / 2;
						menu.SetPosition({ -f1,-f2 });

						f1 = window.getSize().x / 10;
						f2 = window.getSize().y / 10 + 50;
						bt_play.SetPosition({ f1, f2 });

						f1 = window.getSize().x / 2 - bt_settings.GetTexture().getSize().x / 2;
						f2 = window.getSize().y / 2 - bt_settings.GetTexture().getSize().y / 2;
						bt_settings.SetPosition({ f1,f2 });

						f1 = window.getSize().x - window.getSize().x / 10 - bt_exit.GetTexture().getSize().x;
						f2 = window.getSize().y - window.getSize().y / 10 - bt_exit.GetTexture().getSize().y;
						bt_exit.SetPosition({ f1,f2 });
					}
					if (isBelong(Mouse::getPosition(window), bt_settings))
					{
						if (settings(window, tm, volume))
							isOpened = false;
						song_menu_bg.setVolume(volume);
					}
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

				f1 = (3840 / 2 - window.getSize().x / 2);
				f2 = (2160 / 2 - window.getSize().y / 2);
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