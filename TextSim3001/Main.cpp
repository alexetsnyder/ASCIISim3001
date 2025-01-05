#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <iostream>

int main(int argv, char** argc)
{
	sf::RenderWindow window{ sf::VideoMode{ { 800, 600 } }, "SFML Hello World!" };

	sf::Texture glyph_texture{};
	if (!glyph_texture.loadFromFile("Assets/Textures/Haowan_Curses_1440x450.png"))
	{
		std::cout << "Error loading texture.\n";
		return EXIT_FAILURE;
	}

	sf::Sprite glyph_sprite{ glyph_texture };

	sf::RenderTexture render_texture{ { 288, 288 } };

	render_texture.clear();
	render_texture.draw(glyph_sprite);
	render_texture.display();

	sf::Texture display_texture{ render_texture.getTexture() };
	sf::Sprite display_sprite{ display_texture };

	sf::FloatRect bounds{ display_sprite.getGlobalBounds() };
	display_sprite.setPosition({ 400.0f - bounds.size.x / 2, 300.0f - bounds.size.y / 2 });	

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
		window.draw(display_sprite);
		window.display();
	}

	std::cout << "Window Closed!\n";

	return EXIT_SUCCESS;
}
