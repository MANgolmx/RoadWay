#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Assistant.h"
#include "Car.h"
#include "FText.h"
#include "Button.h"
#include "Level.h"

using namespace sf;

int main()
{
	srand(time(0));

#pragma region INITIALIZATION

	int window_width = 1212, window_height = 808;

	RenderWindow window(VideoMode(window_width, window_height), "RoadWay");

	Button play = CreateButton("resources\\buttons\\button_play.png", "PLAY", 100, "resources\\fonts\\roboto\\Roboto-Light.ttf");
	//Is not working

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
		window.draw(play.GetSprite());
		window.draw(play.GetFText().GetText());
		window.display();
	}

	return 0;
}