#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include "Render\Engine.h"
#include "World\World.h"

#include <iostream>

int main()
{
	// Initiate window.
	int width, height;
	width = 800;
	height = 600;

	sf::RenderWindow window(sf::VideoMode(width, height), "Eonia");

	// Create the world
	World world;
	world.setSquare(50, 50);

	// Initiate the game engine
	Engine engine;
	engine.init(window, world);

	int posX, posY;

	int framerate = 120;
	int frametime = 1000 / 120; //Render takes too long for this rate.
	sf::Clock clock;

	// Game loop.
	while (window.isOpen())
	{
		clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					world.moveSquare(0, 1);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					world.moveSquare(0, -1);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					world.moveSquare(-1, 0);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					world.moveSquare(1, 0);

				world.getPlayerPos(posX, posY);
				std::cout << posX << ", " << posY << std::endl;
			}

		}

		window.clear();
		engine.RenderUI();
		window.display();


		while (clock.getElapsedTime().asMilliseconds() <  )
	}

	return 0;
}