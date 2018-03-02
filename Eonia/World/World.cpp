#include "World.h"

#include <iostream>

World::World()
{
	// Generate world map.
	for (int x = 0; x < worldWidth; x++)
	{
		for (int y = 0; y < worldHeight; y++)
		{
			map[x][y] = grass;
			if ( x < 45 ) { map[x][y] = water; }
		}
	}

	// Load caracter.
	player = Player();
	player.getPos(posX, posY);


	// Set up tick rate.
	tickrate = 60; // Ticks per second.
	ticktime = 1000 / tickrate; // Time per tick.
	currentTick = 0;
}

World::~World() {}


std::string World::getSquare(int x, int y)
{
	return map[x][y].getType(); //Return the type of terrain
}

void World::getPlayerPos(int& x, int& y)
{
	player.getPos(x, y);
}

void World::getPlayerFloatPos(float& x, float& y)
{
	player.getFloatPos(x, y, currentTick);
}

bool World::moveSquare(int x, int y)
{
	player.getPos(posX, posY);
	//std::cout << "Moving: " << std::to_string(posX + x) << ", " << std::to_string(posY + y) << std::endl;
	//std::cout << map[posX + x][posX + x].getType() << std::endl;
	if (map[posX + x][posY + y].isPassable())
	{
		return player.move(x, y, currentTick, tickrate);
	}
	else {
		return false;
	}
}

void World::setSquare(int x, int y)
{
	player.move(x, y, currentTick, 0);
	//posX = x;
	//posY = y;
}

int World::nextTick()
{
	currentTick++;
	return currentTick;
}

int World::getTick()
{
	return currentTick;
}

int World::getTickTime()
{
	return ticktime;
}

int World::getTickRate()
{
	return tickrate;
}

std::string World::getPlayerTexture()
{
	return player.getTexture();
}