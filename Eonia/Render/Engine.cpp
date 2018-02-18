
#include "Engine.h"
#include "Textures\Texture.h"

Texture texture;

Engine::Engine() { posX = 0; posY = 0; }

Engine::~Engine(){}

void Engine::init(sf::RenderWindow &screen)
{
	window = &screen;
}

void Engine::RenderUI()
{

	RenderWorld(); // Render the center screen
	RenderCharacter(); // Rener the right screen
	

	// Render inventory
}

void Engine::RenderWorld()
{
	sf::Sprite sprite;
	sprite.setTexture(texture.grass);
	
	// Render the game map

	float tileSize = 40;
	for (int y = 0 + posY; y < 11 + posY; y++)
	{
		for (int x = 0 + posX; x < 15 + posX; x++)
		{
			float f1, f2;
			f1 = float((((x) + 2)%5)*0.63 + y);
			f2 = float((((y) + 1)%3)*0.77 + 2 - x);
			int tile = (abs( int( pow( f1 , f2 ) ) * 31) % 23) % 5;
			sprite.setPosition(sf::Vector2f((x-posX)*tileSize, (y-posY)*tileSize));
			sprite.setTextureRect(sf::IntRect(tileSize*(tile), 0, tileSize, tileSize));
			window->draw(sprite);
		}
	}
}

void Engine::RenderCharacter()
{
	// Render Health and Mana bar

	RenderCharacterHealth();
	RenderCharacterMana();

}

void Engine::RenderCharacterHealth()
{
	sf::RectangleShape barHealth(sf::Vector2f(120, 10));
	barHealth.setPosition(sf::Vector2f(625, 30));
	barHealth.setFillColor(sf::Color::Red);

	window->draw(barHealth);
}

void Engine::RenderCharacterMana()
{
	sf::RectangleShape barMana(sf::Vector2f(120, 10));
	barMana.setPosition(sf::Vector2f(625, 50));
	barMana.setFillColor(sf::Color::Blue);

	window->draw(barMana);
}