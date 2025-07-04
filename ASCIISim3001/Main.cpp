#include "Monolith/Rendering/Glyphs.h"

#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <iostream>

void createWorld(int width, int height, sf::Sprite& glyph_set, sf::RenderTexture& world);

int main(int argv, char** argc)
{
	sf::RenderWindow window{ sf::VideoMode{ { 800, 600 } }, "SFML Hello World!" };

	sf::Texture glyph_set_texture{};
	if (!glyph_set_texture.loadFromFile("Assets/Textures/Haowan_Curses_1440x450.png"))
	{
		std::cout << "Error loading texture.\n";
		exit(EXIT_FAILURE);
	}

	sf::Sprite glyph_set{ glyph_set_texture };

	sf::RenderTexture render_texture{ { 288, 288 } };

	createWorld(288, 288, glyph_set, render_texture);

	sf::Texture display_texture{ render_texture.getTexture() };
	sf::Sprite display_sprite{ display_texture };

	sf::FloatRect bounds{ display_sprite.getGlobalBounds() };
	display_sprite.setPosition({ 400.0f - bounds.size.x / 2, 300.0f - bounds.size.y / 2 });	
	sf::Vector2f worldPos{ display_sprite.getPosition() };

	glyph_set.setTextureRect(Glyphs::DWARF_FACE1);
	glyph_set.setPosition({ worldPos.x + 288 / 2.0f, worldPos.y + 288 / 2.0f });
	glyph_set.setColor({ 255, 0, 0 });

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
		window.draw(glyph_set);
		window.display();
	}

	std::cout << "Window Closed!\n";

	return EXIT_SUCCESS;
}

void createWorld(int width, int height, sf::Sprite& glyph_set, sf::RenderTexture& world)
{
	glyph_set.setTextureRect(Glyphs::TILDE);
	glyph_set.setColor({ 0, 0, 255 });

	world.clear();
	for (int i = 0; i < height; i += 18)
	{
		for (int j = 0; j < width; j += 18)
		{
			glyph_set.setPosition(sf::Vector2f{ (float)i, (float)j });
			world.draw(glyph_set);
		}
	}
	world.display();
}
