#include <SFML/Graphics.hpp>
#include <math.h>
#include "help.cpp"
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"

using namespace sf;

bool isBelong(Vector2i a, DrivableCell cell)
{
	if (a.x >= cell.GetPosition().x &&
		a.x <= cell.GetPosition().x + 101 &&
		a.y >= cell.GetPosition().y &&
		a.y <= cell.GetPosition().y + 101)
		return true;
	return false;
}

void SetPath(DrivableCell* mas, const int N, int straight, int turned, int threeway, int fourway)
{
	for (int i = 0; i < N; i++)
		mas[i].SetType(straight, turned, threeway, fourway);
}

int main()
{
	srand(time(0));
	const int N = 11;

#pragma region INITIALIZATION

	int window_width = 1200, window_height = 800;

	RenderWindow window(VideoMode(window_width, window_height), "RoadWay");

	DrivableCell cell[N];
	SetPath(cell, N, 11, 0, 0, 0);

#pragma endregion

	while (window.isOpen()) //���� ���������
	{
		Event event;
		while (window.pollEvent(event)) //���� �������
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::MouseButtonPressed:
				for (int i = 0; i < N; i++)
					if (isBelong(Mouse::getPosition(window), cell[i]))
					{
						cell[i].Rotation();
					}
				break;
			}
		}

		for (int i = 0; i < N - 1; i++)
			cell[i].SetPosition(i * 101, 0);
		cell[10].SetPosition(0, 101);

		window.clear();
		for (int i = 0; i < N; i++)
			window.draw(cell[i].GetCellSprite());
		window.display();
	}

	return 0;
}