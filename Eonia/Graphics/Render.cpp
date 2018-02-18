
#include "Render.h"

void Render(sf::RenderWindow &window)
{

	// Render the game map

	float tileSize = 40;
	sf::RectangleShape tile(sf::Vector2f(40.f, 40.f));
	for (int y = 0; y < 11; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			tile.setPosition(sf::Vector2f(x*tileSize, y*tileSize));
			tile.setFillColor(sf::Color(x*5 + y*5, 50 , 120));
			window.draw(tile);
		}
	}


	// Render Health and Mana bar

	sf::RectangleShape barHealth(sf::Vector2f(120, 10));
	barHealth.setPosition(sf::Vector2f(625, 30));
	barHealth.setFillColor(sf::Color::Red);

	sf::RectangleShape barMana(sf::Vector2f(120, 10));
	barMana.setPosition(sf::Vector2f(625, 50));
	barMana.setFillColor(sf::Color::Blue);

	window.draw(barHealth);
	window.draw(barMana);


	// Render inventory
}