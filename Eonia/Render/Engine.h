#pragma once

#include <SFML\Graphics.hpp>

#include "Textures\Texture.h"

class Engine
{
public:
	Engine();
	~Engine();

	void RenderUI();

	void init(sf::RenderWindow &screen);

	int posX, posY;

private:
	sf::RenderWindow* window;

	void RenderWorld();
	void RenderCharacter();

	// Character Information
	void RenderCharacterHealth();
	void RenderCharacterMana();
};