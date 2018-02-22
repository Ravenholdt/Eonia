#include <SFML\Graphics.hpp>

#include "Texture.h"

Texture::Texture()
{
	// Items

	// Mobs

	// Structures

	// Terrain
	texture["grass"].loadFromFile("Textures/Terrain/grass.png");

	// UI
}

Texture::~Texture()
{
}

sf::Texture& Texture::getTexture(std::string type)
{
	return texture[type];
}