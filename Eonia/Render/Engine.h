#pragma once

#include <SFML\Graphics.hpp>

#include "..\Textures\Texture.h"
#include "..\World\Mobs\mob.h"
//#include "Textures\Sprite.h"

#include "..\World\World.h"

class Engine
{
public:
	Engine();
	~Engine();

	void RenderUI();

	void init(sf::RenderWindow &screen, World &world);

	void terrainLoad();
	void terrainUpdate();

private:
	sf::RenderWindow* window;
	World* world;

	Texture texture;

	sf::Sprite sprite;

	void RenderWorld();
	void RenderCharacter();

	sf::Sprite terrain[17][13] = { sf::Sprite() };

	// Character Information
	Player player;

	void RenderCharacterHealth();
	void RenderCharacterMana();

	int posX, posY;
};