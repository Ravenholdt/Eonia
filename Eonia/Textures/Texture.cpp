#include <SFML\Graphics.hpp>

#include "Texture.h"

Texture::Texture()
{
	// Items

	// Mobs
	texture["player"].loadFromFile("Textures/Mobs/player.png");
	texture["snake"].loadFromFile("Textures/Mobs/snake.png");
	texture["rat"].loadFromFile("Textures/Mobs/rat.png");

	// Structures

	// Terrain
	texture["grass"].loadFromFile("Textures/Terrain/grass.png");
	texture["water"].loadFromFile("Textures/Terrain/water.png");

	// UI
}

Texture::~Texture()
{
}

sf::Texture& Texture::getTexture(std::string type)
{
	return texture[type];
}