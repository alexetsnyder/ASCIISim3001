#include "Monolith/Rendering/Glyphs.h"

#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <iostream>

constexpr int WINDOW_WIDTH{ 1600 };
constexpr int WINDOW_HEIGHT{ 1200 };

void createGrid(int width, int height, sf::VertexArray& lines);
void createWorld(int width, int height, sf::Sprite& glyph_set, sf::RenderTexture& world);

int main(int argv, char** argc)
{
	sf::RenderWindow window{ sf::VideoMode{ { WINDOW_WIDTH, WINDOW_HEIGHT } }, "SFML Hello World!" };

	sf::Texture glyph_set_texture{};
	if (!glyph_set_texture.loadFromFile("Assets/Textures/Haowan_Curses_1440x450.png"))
	{
		std::cout << "Error loading texture.\n";
		exit(EXIT_FAILURE);
	}

	sf::VertexArray lines{ sf::PrimitiveType::Lines };

	createGrid(WINDOW_WIDTH, WINDOW_HEIGHT, lines);

	sf::Sprite glyph_set{ glyph_set_texture };

	sf::RenderTexture render_texture{ { WINDOW_WIDTH, WINDOW_HEIGHT } };

	createWorld(WINDOW_WIDTH, WINDOW_HEIGHT, glyph_set, render_texture);

	sf::Texture display_texture{ render_texture.getTexture() };
	sf::Sprite display_sprite{ display_texture };

	/*sf::FloatRect bounds{ display_sprite.getGlobalBounds() };
	display_sprite.setPosition({ (WINDOW_WIDTH / 2.0f) - bounds.size.x / 2, (WINDOW_HEIGHT / 2.0f) - bounds.size.y / 2 });
	sf::Vector2f worldPos{ display_sprite.getPosition() };*/

	glyph_set.setTextureRect(Glyphs::DWARF_FACE1);
	glyph_set.setPosition({ WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f });
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

		window.clear({ 51, 77, 77 });
		window.draw(lines);
		window.draw(display_sprite);
		window.draw(glyph_set);
		window.display();
	}

	std::cout << "Window Closed!\n";

	return EXIT_SUCCESS;
}

void createGrid(int width, int height, sf::VertexArray& lines)
{
	for (int i = 0; i < height; i += 18)
	{
		lines.append(sf::Vertex{ sf::Vector2f{ 0.0f, (float)i }, sf::Color::Green });
		lines.append(sf::Vertex{ sf::Vector2f{ (float)width, (float)i }, sf::Color::Green });
	}

	for (int j = 0; j < width; j += 18)
	{
		lines.append(sf::Vertex{ sf::Vector2f{ (float)j, 0.0f }, sf::Color::Green });
		lines.append(sf::Vertex{ sf::Vector2f{ (float)j, (float)height }, sf::Color::Green });
	}
}

void createWorld(int width, int height, sf::Sprite& glyph_set, sf::RenderTexture& world)
{
	glyph_set.setTextureRect(Glyphs::TILDE);
	glyph_set.setColor({ 0, 0, 255 });

	world.clear({ 0, 0, 0, 0 });
	for (int i = 0; i < height; i += 18)
	{
		for (int j = 0; j < width; j += 18)
		{
			glyph_set.setPosition(sf::Vector2f{ (float)j, (float)i });
			world.draw(glyph_set);
		}
	}
	world.display();
}
