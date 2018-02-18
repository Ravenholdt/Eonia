#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include "Render\Engine.h"
#include "World\World.h"

#include <iostream>

int main()
{
	int width, height;
	width = 800;
	height = 600;

	sf::RenderWindow window(sf::VideoMode(width, height), "GOOD STUFF!");

	Engine engine;
	engine.init(window);

	World world;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					engine.posY--;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					engine.posY++;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
					engine.posX--;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
					engine.posX++;
			}

		}

		window.clear();
		engine.RenderUI();
		window.display();

		std::cout << engine.posX << ", " << engine.posY << std::endl;

	}

	return 0;
}