#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <iostream>

int main(int argv, char** argc)
{
	std::cout << "Hello World!\n";

	sf::RenderWindow window{ sf::VideoMode{ { 200, 200 } }, "SFML Hello World!"};
	sf::CircleShape circle{ 100.0f };
	circle.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		while (const auto event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		window.clear();
		window.draw(circle);
		window.display();
	}

	std::cout << "Window Closed!\n";

	return EXIT_SUCCESS;
}