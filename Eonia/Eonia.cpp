#include <SFML\Graphics.hpp>

#include "Graphics\Render.h"

int main()
{
	int width, height;
	width = 800;
	height = 600;

	sf::RenderWindow window(sf::VideoMode(width, height), "GOOD STUFF!");

	sf::RectangleShape worldScreen(sf::Vector2f(600.f, 440.f));
	worldScreen.setFillColor(sf::Color::Green);
	
	sf::RectangleShape menuScreen(sf::Vector2f(200.f, 600.f));
	menuScreen.setPosition(sf::Vector2f(600.f, 0.f));
	menuScreen.setFillColor(sf::Color(120, 60, 20));
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(worldScreen);
		window.draw(menuScreen);
		Render(window);
		window.display();
	}

	return 0;
}