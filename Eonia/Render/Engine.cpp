
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
}

void Engine::RenderUI()
{

	RenderWorld(); // Render the center screen
	RenderCharacter(); // Rener the right screen
	

	// Render inventory
}

void Engine::RenderWorld()
{

	//sf::Texture text;
	//text.loadFromFile("Textures/Terrain/grass.png");
	//sprite.setTexture(text);

	world->getSquare(posX, posY);

	//sprite.setTexture( texture.getTexture(std::string("grass")) );

	terrainLoad();

	// Render the game map
	for (int y = 0; y < 13; y++)
	{
		for (int x = 0; x < 17; x++)
		{
			//sprite.setTexture(texture.getTexture());
			window->draw(terrain[x][y]);
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
			std::string tmp = "grass";
			if (x + posX == 58 && y + posY == 56) { tmp = "none"; }
			terrain[x][y].setTexture( texture.getTexture(tmp) );
			terrain[x][y].setPosition(sf::Vector2f((x - 1)*tileSize, (y - 1)*tileSize ) );
			terrain[x][y].setTextureRect(sf::IntRect(tileSize*(tile), 0, tileSize, tileSize));
		}
	}
}

void Engine::terrainUpdate()
{
	int x = posX, y=posY;
	world->getPlayerPos(posX, posY);
	x = posX - x;
	y = posY - y;
	if (x) // Move up or down
	{

	}
	if (y) // Move right or left
	{

	}
}