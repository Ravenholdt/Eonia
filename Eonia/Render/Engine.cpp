
#include <string>
#include <iostream> //Debug
#include <SFML\System.hpp> //Debug - Time

#include "Engine.h"
#include "..\Textures\Texture.h"
//#include "Textures\Sprite.h"

#include "..\World\World.h"
//#include "..\World\Terrain\Terrain.h"

Engine::Engine() { posX = 0; posY = 0; }

Engine::~Engine(){}

void Engine::init(sf::RenderWindow &_window, World &_world)
{
	window = &_window;
	world = &_world;

	world->getPlayerPos(posX, posY);
	Texture texture;

	// Load text font
	font.loadFromFile("Render/Roboto.ttf");

	terrainLoad();

}

void Engine::RenderUI()
{
	RenderWorld(); // Render the center screen
	RenderCharacter(); // Rener the right screen
	
	
	RenderDebug(); // Debug interface.

	// Render inventory

}

void Engine::RenderWorld()
{
	sf::Clock clock;
	clock.restart();


	terrainUpdate();
	//std::cout << clock.restart().asMilliseconds() << ", ";

	sf::Text text("Test", font);
	text.setCharacterSize(30);

	world->getSquare(posX, posY);

	//terrainLoad();

	float tileSize = 40;

	int _y = 0;

	int tilesX = 17, tilesY = 13; // NUmber of tiles in X and Y

	std::string stringX = std::to_string(posX);
	std::string stringY = std::to_string(posY);

	// Render the game map
	for (int y = tilesY - 1; y >= 0; y--) // Needs to be inverted to start the logic position from bottom left.
	{
		for (int x = 0; x < tilesX; x++)
		{
			_y = tilesY - 1 - y;

			//sprite.setTexture(texture.getTexture());
			terrain[x][y].setPosition(sf::Vector2f((x - 1)*tileSize, (_y - 1)*tileSize));
			window->draw(terrain[x][y]);

			// Cord text
			/*stringX = std::to_string(x + posX - 8);
			stringY = std::to_string(y + posY - 6);
			sf::Text text(stringX + "," + stringY, font);
			text.setPosition(sf::Vector2f((x - 1)*tileSize, (_y - 1)*tileSize));
			text.setCharacterSize(9);

			window->draw(text);*/
		}
	}

	// Render the player.
}

void Engine::RenderDebug()
{
	// Render Position for bebug.
	std::string stringX = std::to_string(posX);
	std::string stringY = std::to_string(posY);

	sf::Text text(stringX + "," + stringY, font);
	text.setCharacterSize(30);
	text.setPosition(sf::Vector2f(640, 70));
	window->draw(text);

	std::string stringTick = std::to_string(world->getTick());
	text = sf::Text (stringTick, font);
	text.setPosition(sf::Vector2f(640, 110));
	window->draw(text);
}

void Engine::RenderCharacter()
{
	// Render the right parth of the screen.


	// Render Health and Mana bar
	RenderCharacterHealth();
	RenderCharacterMana();

}

// Render health bar.
void Engine::RenderCharacterHealth()
{
	sf::RectangleShape barHealth(sf::Vector2f(120, 10));
	barHealth.setPosition(sf::Vector2f(625, 30));
	barHealth.setFillColor(sf::Color::Red);

	window->draw(barHealth);
}

// Render mana bar.
void Engine::RenderCharacterMana()
{
	sf::RectangleShape barMana(sf::Vector2f(120, 10));
	barMana.setPosition(sf::Vector2f(625, 50));
	barMana.setFillColor(sf::Color::Blue);

	window->draw(barMana);
}

// Load the terrain
void Engine::terrainLoad()
{
	world->getPlayerPos(posX, posY);

	float tileSize = 40;
	int tile = 2;

	for (int x = 0; x < 17; x++)
	{
		for (int y = 0; y < 13; y++)
		{
			terrain[x][y].setTexture( texture.getTexture( world->getSquare(x + posX, y + posY) ) );
			terrain[x][y].setTextureRect( sf::IntRect(tileSize*(tile), 0, tileSize, tileSize) );
		}
	}
}

// Check if the players has moved and reload the map if they have.
void Engine::terrainUpdate()
{
	terrainLoad(); // Always update the map.

	/*int x = posX, y=posY;
	world->getPlayerPos(posX, posY);
	x = posX - x;
	y = posY - y;
	if (x || y)
	{
		std::cout << "Moved" << std::endl;
		terrainLoad();
	}*/
}