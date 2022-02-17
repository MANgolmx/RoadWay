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

using namespace sf;

int main()
{
	srand(time(0));

#pragma region INITIALIZATION

	int window_width = 1212, window_height = 808;

	Background menu("resources\\menu.png");

	RenderWindow window(VideoMode(window_width, window_height), "RoadWay");

	FText play_txt("PLAY", 76, "resources\\fonts\\pixeltime\\PixelTimes.ttf");
	Button bt_play(play_txt, "resources\\buttons\\button_play.png", {20,24});
	bt_play.SetPosition({ 100, 150 });

	window.setFramerateLimit(60);

#pragma endregion

	playlogo(window);

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
			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Button::Left)) //Левая кнопка мыши
					if (isBelong(Mouse::getPosition(window), bt_play))
						levelStart(window);
				break;
			case Event::Resized:
				Vector2f windowSize = Vector2f(event.size.width, event.size.height);
				window.setView(View(Vector2f(windowSize.x / 2.f,
					windowSize.y / 2.f), Vector2f(windowSize)));
				break;
			}
		}

		window.draw(menu.GetSprite());
		window.draw(bt_play.GetSprite());
		window.draw(bt_play.GetFText().GetText());
		window.display();
	}

	return 0;
}