#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Assistant.h"
#include "Car.h"
#include "FText.h"
#include "Button.h"
#include "Level.h"
#include "Logo.h"

using namespace sf;

int main()
{
	srand(time(0));

#pragma region INITIALIZATION

	int window_width = 1212, window_height = 808;

	Texture texture;
	Sprite sprite;

	if (!texture.loadFromFile("resources\\menu.png")) {
		std::cout << "[ERROR OCURRED] Can not open menu texture" << std::endl;
		exit(1);
	}

	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	RenderWindow window(VideoMode(window_width, window_height), "RoadWay");

	FText play_txt("PLAY", 76, "resources\\fonts\\pixeltime\\PixelTimes.ttf");
	Button bt_play(play_txt, "resources\\buttons\\button_play.png", {20,24});
	bt_play.SetPosition({500, 400});

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
			}
		}

		window.draw(sprite);
		window.draw(bt_play.GetSprite());
		window.draw(bt_play.GetFText().GetText());
		window.display();
	}

	return 0;
}