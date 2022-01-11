#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	int window_width = 1200, window_height = 800;

	RenderWindow window(VideoMode(window_width, window_height), "SFMLworks");
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}