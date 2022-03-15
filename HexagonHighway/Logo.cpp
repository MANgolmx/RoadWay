#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Assistant.h"
#include "Car.h"
#include "FText.h"
#include "Button.h"
#include "Level.h"

using namespace sf;

int playlogo(RenderWindow& window)
{
	srand(time(0));

#pragma region INITIALIZATION

	Color col = { 255,255,255,0 };

	int phase = 0;

	FText ms("   MS\nSTUDIO", 80, "resources\\fonts\\msstudio\\MSstudio.ttf", col);

	float f1 = window.getSize().x / 2 - ms.GetText().getGlobalBounds().width  / 2;
	float f2 = window.getSize().y / 2 - ms.GetText().getGlobalBounds().height / 2;

	ms.SetPosition({f1,f2});

	window.setFramerateLimit(200);

	Music song_logo_bg;
	song_logo_bg.openFromFile("resources\\sounds\\logo_short.ogg");
	song_logo_bg.setVolume(0);

	bool isOpen = true;

#pragma endregion

	song_logo_bg.play();

	while (isOpen) //Цикл лого
	{
		Event event;
		while (window.pollEvent(event)) //Цикл событий
		{
			switch (event.type)
			{
			case Event::Closed:
				return 1;
			case Event::KeyPressed:
				return 0;
			case Event::Resized:
				Vector2f windowSize = Vector2f(event.size.width, event.size.height);
				window.setView(View(Vector2f(windowSize.x / 2.f,
					windowSize.y / 2.f), Vector2f(windowSize)));
				f1 = window.getSize().x / 2 - ms.GetText().getGlobalBounds().width / 2;
				f2 = window.getSize().y / 2 - ms.GetText().getGlobalBounds().height / 2;
				ms.SetPosition({ f1,f2 });
				break;
			}
		}

		ms.ChangeColor(col);
		if (phase == 0) {
			song_logo_bg.setVolume(75 - 37.5 + col.a / 6);
			col.a++;
			if (col.a == 225)
				phase++;
		}
		if (phase == 1) {
			song_logo_bg.setVolume(75);
			Time t = seconds(1.f);
			sleep(t);
			phase++;
		}
		if (phase == 2)
		{
			song_logo_bg.setVolume(75 - 75 + col.a / 3);
			col.a--;
			if (col.a == 0) {
				phase++;
				ms.SetPosition({ 10000,10000 });
			}
		}
		
		window.clear(Color::Black);
		window.draw(ms.GetText());
		window.display();

		if (phase == 3)
		{
			col.a = 0;
			Time t = seconds(1.f);
			sleep(t);
			isOpen = false;
		}

		window.clear(Color::Black);
		window.draw(ms.GetText());
		window.display();
	}

	song_logo_bg.stop();
	return 0;
}