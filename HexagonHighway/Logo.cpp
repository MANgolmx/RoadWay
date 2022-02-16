#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Assistant.h"
#include "Car.h"
#include "FText.h"
#include "Button.h"
#include "Level.h"

using namespace sf;

void playlogo(RenderWindow& window)
{
	srand(time(0));

#pragma region INITIALIZATION

	Color col = { 255,255,255,0 };

	int phase = 0;

	FText ms("   MS\nSTUDIO", 80, "resources\\fonts\\msstudio\\MSstudio.ttf", col);

	float f1 = window.getSize().x / 2 - ms.GetText().getGlobalBounds().width  / 2;
	float f2 = window.getSize().y / 2 - ms.GetText().getGlobalBounds().height / 2;

	ms.SetPosition({f1,f2});

	window.setFramerateLimit(90);

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
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Enter)
					return;
			}
		}

		ms.ChangeColor(col);
		if (phase == 0)
		{
			col.a++;
			if (col.a == 225)
				phase++;
		}
		if (phase == 1)
		{
			Time t = seconds(2.f);
			sleep(t);
			phase++;
		}
		if (phase == 2)
		{
			col.a--;
			if (col.a == 0)
				phase++;
		}
		if (phase == 3)
		{
			col.a--;
			Time t = seconds(1.5f);
			sleep(t);
			return;
		}

		window.clear(Color::Black);
		window.draw(ms.GetText());
		window.display();
	}

	return;
}