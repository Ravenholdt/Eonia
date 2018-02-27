#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include "Render\Engine.h"
#include "World\World.h"

#include <iostream>
#include <future> // std::async

int main()
{
	int screenWidth = 800, screenHeight = 600;

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Eonia");;

	// Create the world
	World world;
	world.setSquare(50, 50);

	// Initiate the game engine
	Engine engine;
	engine.init(window, world);

	int posX, posY;

	bool renderLoopBool = false;

	sf::Clock clock;

	// Game loop.
	while (window.isOpen())
	{
		clock.restart();
		world.nextTick();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//if (event.type == sf::Event::KeyPressed)
		}
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

		//world.getPlayerPos(posX, posY);
		//std::cout << posX << ", " << posY << std::endl;


		// Begin render
		window.clear();
		
		engine.RenderUI();

		// End render
		window.display();
		

		//std::cout << clock.getElapsedTime().asMilliseconds() << ", ";
		while ( clock.getElapsedTime().asMilliseconds() < world.getTickTime() ) {}
		//std::cout << clock.restart().asMilliseconds() << std::endl;
	}

	return 0;
}