#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"
#include "FText.h"
#include "Button.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "StructureCell.h"
#include "Assistant.h"
#include "Car.h"
#include "Level.h"
#include "TextureManager.h"

using namespace sf;

int levelStart(RenderWindow& window, TextureManager& tm, int carType, const char level_path[], const char level_carpath[], const char level_typespath[])
{

#pragma region INITIALIZATION

	int roadSize, decorationSize, structureSize;
	ReadLevelFile(level_path, roadSize, decorationSize, structureSize);

	int straight, turned, threeway, fourway, fin, flowers, privateResidence, apartments;
	ReadCellsTypes(level_typespath, straight, turned, threeway, fourway, fin, flowers, privateResidence, apartments);

	Clock clock;

	NonDrivableCell chosen(tm.PullTexture("resources\\cells\\chosen.png"));

	DrivableCell* roads = new DrivableCell[roadSize];
	SetDrivablePath(tm, roads, roadSize, straight, turned, threeway, fourway);

	NonDrivableCell* decorations = new NonDrivableCell[decorationSize];
	SetNonDrivablePath(tm, decorations, decorationSize, flowers, privateResidence, apartments);

	StructureCell* structures = new StructureCell[structureSize];
	structures[0].SetCellSprite(tm.PullTexture("resources\\cells\\structures\\structure_park.png"));

	std::string carPath;
	switch (carType) {
	case 0: carPath = "resources\\cars\\car_1.png"; break;
	case 1: carPath = "resources\\cars\\car_2.png"; break;
	case 2: carPath = "resources\\cars\\car_police.png"; break;
	}
	Car car(tm.PullTexture(carPath));
	ReadCarPosition(car, level_carpath);
	car.ReCalcPosition(window);

	ReadMainPositions(level_path, roads, roadSize, decorations, decorationSize,
		structures, structureSize);
	SetPositions(roadSize, roads, decorationSize, decorations,
		structureSize, structures, window);
	SetIsChosen(false, roads, roadSize);

	FText txt_win("YOU WIN!", 80, "resources\\fonts\\pixeltime\\PixelTimes.ttf");
	Button bt_win(txt_win, tm.PullTexture("resources\\buttons\\button_win.png"), {float(800 / 2 - txt_win.GetText().getCharacterSize() * 5 / 2), 130});

	float f1 = window.getSize().x - window.getSize().x / 2 - bt_win.GetTexture().getSize().x / 2;
	float f2 = window.getSize().y - window.getSize().y / 2 - bt_win.GetTexture().getSize().y / 2;
	bt_win.SetPosition({ f1,f2 });

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
					if (car.IsFinished() && isBelong(Mouse::getPosition(window), bt_win))
						isPlaying = false;

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
				if (event.key.code == Keyboard::R)
					return 909;
				break;
			case Event::Resized:
				Vector2f windowSize = Vector2f(event.size.width, event.size.height);
				window.setView(View(Vector2f(windowSize.x / 2.f,
					windowSize.y / 2.f), Vector2f(windowSize)));
				SetPositions(roadSize, roads, decorationSize, decorations,
					structureSize, structures, window);
				ReadCarPosition(car, level_carpath);
				car.ReCalcPosition(window);

				f1 = window.getSize().x - window.getSize().x / 2 - bt_win.GetTexture().getSize().x / 2;
				f2 = window.getSize().y - window.getSize().y / 2 - bt_win.GetTexture().getSize().y / 2;
				bt_win.SetPosition({ f1,f2 });

				break;
			}
		}
		
		car.Move(clock.restart(), roads, roadSize, decorations, decorationSize);

		window.clear({ 181, 230, 29, 255 });
		DrawCells(window, roads, chosen, roadSize, decorations, decorationSize, structures, structureSize);
		car.Draw(window);
		if (car.IsFinished())
			bt_win.Draw(window);
		window.display();
	}

	delete[] roads;
	delete[] decorations;
	delete[] structures;

	return 0;
}