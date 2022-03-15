#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "StructureCell.h"
#include "Assistant.h"
#include "Car.h"
#include "Level.h"

using namespace sf;

int levelStart(RenderWindow& window)
{

#pragma region INITIALIZATION

	int roadSize, decorationSize, structureSize;
	ReadLevelFile("levels\\level_test.lvl", roadSize, decorationSize, structureSize);

	int straight, turned, threeway, fourway, finish, flowers, privateResidence, apartments;
	ReadCellsTypes("levels\\level_testtypes.lvl", straight, turned, threeway, fourway, finish, flowers, privateResidence, apartments);

	int window_width = 1200, window_height = 800;

	Clock clock;

	NonDrivableCell chosen("resources\\cells\\chosen.png");

	DrivableCell* roads = new DrivableCell[roadSize];
	SetDrivablePath(roads, roadSize, straight, turned, threeway, fourway);

	NonDrivableCell* decorations = new NonDrivableCell[decorationSize];
	SetNonDrivablePath(decorations, decorationSize, flowers, privateResidence, apartments);

	StructureCell* structures = new StructureCell[structureSize];
	structures[0].SetCellSprite("resources\\cells\\structures\\structure_park.png");

	Car car("resources\\cars\\car_1.png");
	ReadCarPosition(car, "levels\\level_testcar.lvl");
	car.ReCalcPosition(window);

	ReadMainPositions("levels\\level_test.lvl", roads, roadSize, decorations, decorationSize,
		structures, structureSize);
	SetPositions(roadSize, roads, decorationSize, decorations,
		structureSize, structures, window);

	window.setFramerateLimit(60);

	bool isPlaying = true;

#pragma endregion

	while (isPlaying) //Цикл игры
	{
		Event event;
		while (window.pollEvent(event)) //Цикл событий
		{
			switch (event.type)
			{
			case Event::Closed:
				return 1;
			case Event::MouseButtonPressed: //Нажата кнопка мыши
				if (Mouse::isButtonPressed(Mouse::Button::Left)) //Левая кнопка мыши
				{
					SetIsChosen(false, roads, roadSize);
					for (int i = 0; i < roadSize; i++)
						if (isBelong(Mouse::getPosition(window), roads[i]))
							roads[i].Rotation();
				}
				if (Mouse::isButtonPressed(Mouse::Button::Right)) //Правая кнопка мыши
					CheckSwap(window, roads, roadSize);
				break;
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Space)
					if (!car.IsMoving())
						car.StartMoving();
				break;
			case Event::Resized:
				Vector2f windowSize = Vector2f(event.size.width, event.size.height);
				window.setView(View(Vector2f(windowSize.x / 2.f,
					windowSize.y / 2.f), Vector2f(windowSize)));
				SetPositions(roadSize, roads, decorationSize, decorations,
					structureSize, structures, window);
				ReadCarPosition(car, "levels\\level_testcar.lvl");
				car.ReCalcPosition(window);
				break;
			}
		}

		car.Move(clock.restart(), roads, roadSize, decorations, decorationSize);

		window.clear({ 181, 230, 29, 255 });
		DrawCells(window, roads, chosen, roadSize, decorations, decorationSize, structures, structureSize);
		car.Draw(window);
		window.display();
	}
}