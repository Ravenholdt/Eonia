
#include <string>
#include <iostream> //Debug

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
	terrainLoad();
}

void Engine::RenderUI()
{

	RenderWorld(); // Render the center screen
	RenderCharacter(); // Rener the right screen
	

	// Render inventory
}

void Engine::RenderWorld()
{

	terrainUpdate();

	sf::Font font;
	font.loadFromFile("Render/Roboto.ttf");

	sf::Text text("Test", font);
	text.setCharacterSize(30);

	//sf::Texture text;
	//text.loadFromFile("Textures/Terrain/grass.png");
	//sprite.setTexture(text);

	world->getSquare(posX, posY);

	//sprite.setTexture( texture.getTexture(std::string("grass")) );

	//terrainLoad();

	int rend = 0;
	float tileSize = 40;

	int _y = 0;

	// Render the game map
	for (int y = 12; y >= 0; y--) // Needs to be inverted to start the logic position from bottom left.
	{
		for (int x = 0; x < 17; x++)
		{
			_y = 12 - y;
			std::string stringX = std::to_string(x + posX - 8);
			std::string stringY = std::to_string(y + posY - 6);
			sf::Text text(stringX + "," + stringY, font);
			text.setPosition(sf::Vector2f((x - 1)*tileSize, (_y - 1)*tileSize));
			text.setCharacterSize(9);
			//sprite.setTexture(texture.getTexture());
			terrain[x][y].setPosition(sf::Vector2f((x - 1)*tileSize, (_y - 1)*tileSize));
			window->draw(terrain[x][y]);
			window->draw(text);
			rend++;
		}
	}
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
			terrain[x][y].setTextureRect(sf::IntRect(tileSize*(tile), 0, tileSize, tileSize));
		}
	}
}

// Check if the players has moved and reload the map if they have.
void Engine::terrainUpdate()
{
	int x = posX, y=posY;
	world->getPlayerPos(posX, posY);
	x = posX - x;
	y = posY - y;
	if (x || y)
	{
		std::cout << "Moved" << std::endl;
		terrainLoad();
	}
}