#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Assistant.h"
#include "Car.h"
#include "Level.h"
#include "StructureCell.h"

using namespace sf;

void levelStart(RenderWindow& window)
{

#pragma region INITIALIZATION

	int roadSize = ReadSizes("").x;
	int decorationSize = ReadSizes("").y;

	int window_width = 1212, window_height = 808;

	Clock clock;

	NonDrivableCell chosen("resources\\cells\\chosen.png");

	DrivableCell* roads = new DrivableCell[roadSize];
	SetDrivablePath(roads, roadSize, 4, 4, 4, 0);
	roads[72].SetCellSprite("resources\\cells\\finish.png");
	roads[72].SetMainPosition({ 6,4 });

	NonDrivableCell* decorations = new NonDrivableCell[decorationSize];
	SetNonDrivablePath(decorations, decorationSize, 80, 56, 0);

	StructureCell park("resources\\cells\\structures\\structure_park.png");

	Car car("resources\\cars\\car_1.png");

	ReadCarPosition(car, "levels\\level_testcar.lvl", window);
	
	//GenerateDecoration(roads, roadSize, decorations, decorationSize);

	ReadMainPositions(roadSize, roads, decorationSize, decorations);
	SetPositions(window, roadSize, roads, decorationSize, decorations);

	window.setFramerateLimit(60);

#pragma endregion

	while (window.isOpen()) //Цикл игры
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
			case Event::Resized:
				Vector2f windowSize = Vector2f(event.size.width, event.size.height);
				window.setView(View(Vector2f(windowSize.x / 2.f,
					windowSize.y / 2.f), Vector2f(windowSize)));
				SetPositions(window, roadSize, roads, decorationSize, decorations);
				ReadCarPosition(car, "levels\\level_testcar.lvl", window);
				break;
			}
		}

		car.Move(clock.restart(), roads, roadSize, decorations, decorationSize);

		window.clear({ 181, 230, 29, 255 });
		DrawCells(window, roads, chosen, roadSize, decorations, decorationSize, park);
		car.Draw(window);
		window.display();
	}
}