#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Assistant.h"

using namespace sf;

int main()
{
	srand(time(0));
	const int roadSize = 12;

#pragma region INITIALIZATION

	int window_width = 1212, window_height = 808;

	RenderWindow window(VideoMode(window_width, window_height), "RoadWay");

	NonDrivableCell chosen;
	chosen.SetCellSprite("resources\\cells\\chosen.png");

	DrivableCell roads[roadSize];
	SetDrivablePath(roads, roadSize, 4, 4, 4, 0);

	ReadMainPositions(roadSize, roads);
	SetPositions(roadSize, roads);

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
			case Event::MouseButtonPressed: //Нажата кнопка мыши
				if (Mouse::isButtonPressed(Mouse::Button::Left)) //Левая кнопка мыши
				{
					SetIsChosen(false, roadSize, roads);
					for (int i = 0; i < roadSize; i++)
						if (isBelong(Mouse::getPosition(window), roads[i]))
							roads[i].Rotation();
				}
				if (Mouse::isButtonPressed(Mouse::Button::Right)) //Правая кнопка мыши
					CheckSwap(roadSize, roads, window);
				break;
			}
		}
		
		window.clear({ 181, 230, 29, 255 });
		DrawCells(window, roads, chosen, roadSize);
		window.display();
	}

	return 0;
}