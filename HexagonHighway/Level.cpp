#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "StructureCell.h"
#include "Assistant.h"
#include "Car.h"
#include "Level.h"

using namespace sf;

void levelStart(RenderWindow& window)
{

#pragma region INITIALIZATION

	int roadSize = 12;
	int decorationSize = 1;
	int structuresSize = 1;

	int window_width = 1212, window_height = 808;

	Clock clock;

	NonDrivableCell chosen("resources\\cells\\chosen.png");

	DrivableCell* roads = new DrivableCell[roadSize];
	SetDrivablePath(roads, roadSize, 4, 4, 4, 0);

	NonDrivableCell* decorations = new NonDrivableCell[decorationSize];
	SetNonDrivablePath(decorations, decorationSize, 0, 1, 0);

	StructureCell* structures = new StructureCell[structuresSize];
	structures[0].SetCellSprite("resources\\cells\\straight\\straight_flowers_1.png");

	Car car("resources\\cars\\car_1.png");
	ReadCarPosition(car, "");
	car.ReCalcPosition(window);

	ReadMainPositions(roadSize, roads, decorationSize, decorations,
		structuresSize, structures);
	SetPositions(roadSize, roads, decorationSize, decorations,
		structuresSize, structures, window);

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
				SetPositions(roadSize, roads, decorationSize, decorations,
					structuresSize, structures, window);
				ReadCarPosition(car, "");
				car.ReCalcPosition(window);
				break;
			}
		}

		car.Move(clock.restart(), roads, roadSize, decorations, decorationSize);

		window.clear({ 181, 230, 29, 255 });
		DrawCells(window, roads, chosen, roadSize, decorations, decorationSize, structures, structuresSize);
		car.Draw(window);
		window.display();
	}
}