
#include <string>
#include <iostream> //Debug
#include <SFML\System.hpp> //Debug - Time

#include "Engine.h"
#include "..\Textures\Texture.h"
//#include "Textures\Sprite.h"

#include "..\World\World.h"
#include "..\World\Terrain\Terrain.h"

Engine::Engine() 
{
	posX = 0; posY = 0; 
	playerOffsetX = 8, playerOffsetY = 6;
}

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

	tickrate = world->getTickRate();

	/*playerSprite = sf::Sprite();
	playerSprite.setTexture(texture.getTexture(world->getPlayerTexture()));
	playerSprite.setTextureRect(sf::IntRect(0, 40, 40, 40));*/

	playerSprite = sf::Sprite();
}

void Engine::RenderUI()
{
	//world->getPlayerPos(posX, posY);

	terrainUpdate(); // Update the terrain an player position

	RenderWorld(); // Render the center screen
	RenderCharacter(); // Rener the right screen
	
	
	RenderDebug(); // Debug interface.

	// Render inventory

}

void Engine::RenderWorld()
{
	sf::Clock clock;
	clock.restart();

	//std::cout << clock.restart().asMilliseconds() << ", ";

	sf::Text text("Test", font);
	text.setCharacterSize(30);

	world->getSquare(posX, posY);

	//terrainLoad();

	float tileSize = 40;

	int _y = 0;

	int tilesX = 17, tilesY = 13; // NUmber of tiles in X and Y

	//std::string stringX = std::to_string(posX);
	//std::string stringY = std::to_string(posY);

	// Render the game map
	for (int y = tilesY - 1; y >= 0; y--) // Needs to be inverted to start the logic position from bottom left.
	{
		for (int x = 0; x < tilesX; x++)
		{
			_y = tilesY - 1 - y;

			//sprite.setTexture(texture.getTexture());
			terrain[x][y].setPosition(sf::Vector2f( (x - 1 + Dx)*tileSize, (_y - 1 - Dy)*tileSize) );
			window->draw(terrain[x][y]);

			/*// Cord text
			std::string stringX = std::to_string(x + posX - 8);
			std::string stringY = std::to_string(y + posY - 6);
			sf::Text text(stringX + "," + stringY, font);
			text.setPosition(sf::Vector2f((x - 1 + Dx)*tileSize, (_y - 1 - Dy)*tileSize));
			text.setCharacterSize(9);

			window->draw(text);*/
		}
	}

	playerSprite.setTexture(texture.getTexture(world->getPlayerTexture()));
	playerSprite.setTextureRect(sf::IntRect(0, 0, 40, 40));

	// Render the player.
	_y = tilesY - 1 - tilesY / 2;
	playerSprite.setPosition(sf::Vector2f((tilesX / 2 - 1)*tileSize, (_y - 1)*tileSize));
	window->draw(playerSprite);
}

void Engine::RenderDebug()
{
	// Render Position for bebug.
	std::string stringX = std::to_string(posX);
	std::string stringY = std::to_string(posY);

	sf::Text text(stringX, font);
	text.setCharacterSize(30);
	text.setPosition(sf::Vector2f(640, 70));
	window->draw(text);

	text = sf::Text(stringY, font);
	text.setPosition(sf::Vector2f(640, 110));
	window->draw(text);

	std::string stringTick = std::to_string(world->getTick());
	text = sf::Text (stringTick, font);
	text.setPosition(sf::Vector2f(640, 150));
	window->draw(text);

	text = sf::Text(std::to_string(Dx), font);
	text.setPosition(sf::Vector2f(640, 190));
	text.setCharacterSize(10);
	window->draw(text);

	text = sf::Text(std::to_string(Dy), font);
	text.setPosition(sf::Vector2f(640, 210));
	text.setCharacterSize(10);
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
	float tileSize = 40;
	int tile = 0;

	for (int x = 0; x < 17; x++)
	{
		for (int y = 0; y < 13; y++)
		{
			terrain[x][y].setTexture( texture.getTexture( world->getSquare(x + posX - playerOffsetX, y + posY - playerOffsetY) ) );
			terrain[x][y].setTextureRect( sf::IntRect(tileSize*(tile), 0, tileSize, tileSize) );
		}
	}
}

// Check if the players has moved and reload the map if they have.
void Engine::terrainUpdate()
{
	float tick = world->getTick();

	//lastPosX = posX, lastPosY = posY; // Save old players position


	// Update player position
	world->getPlayerPos(posX, posY);
	//world->getPlayerLastPos(lastPosX, lastPosY);


	terrainLoad(); // Always update the map.

	world->getPlayerFloatPos(Dx, Dy);
	Dx -= posX;
	Dy -= posY;
}