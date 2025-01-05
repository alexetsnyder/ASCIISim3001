#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <iostream>

int main(int argv, char** argc)
{
	std::cout << "Hello World!\n";

	sf::Texture texture{};
	if (!texture.loadFromFile("Assets/Textures/Haowan_Curses_1440x450.png"))
	{
		std::cout << "Error loading texture.\n";
		return EXIT_FAILURE;
	}

	sf::Sprite sprite{ texture };
	sf::FloatRect bounds{ sprite.getGlobalBounds() };
	
	sprite.setPosition({ 400.0f - bounds.size.x / 2, 300.0f - bounds.size.y / 2 });

	sf::RenderWindow window{ sf::VideoMode{ { 800, 600 } }, "SFML Hello World!"};


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
		window.draw(sprite);
		window.display();
	}

	std::cout << "Window Closed!\n";

	return EXIT_SUCCESS;
}