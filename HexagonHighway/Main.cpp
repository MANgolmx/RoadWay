#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Assistant.h"

using namespace sf;

int main()
{
	srand(time(0));
	const int N = 12;

#pragma region INITIALIZATION

	int window_width = 1212, window_height = 808;

	RenderWindow window(VideoMode(window_width, window_height), "RoadWay");

	DrivableCell cell[N];
	SetPath(cell, N, 6, 6, 0, 0);

	ReadMainPositions(N, cell);
	SetPositions(N, cell);

#pragma endregion

		//TODO: Добавить обнуление выбора после каждого клика

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
					for (int i = 0; i < N; i++)
						if (isBelong(Mouse::getPosition(window), cell[i]))
							cell[i].Rotation();
				if (Mouse::isButtonPressed(Mouse::Button::Right)) //Правая кнопка мыши
					CheckSwap(N, cell, window);
				break;
			}
		}
		

		window.clear();
		for (int i = 0; i < N; i++)
			window.draw(cell[i].GetCellSprite());
		window.display();
	}

	return 0;
}