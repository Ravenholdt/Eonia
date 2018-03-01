#include "World.h"

#include <iostream>

World::World()
{
	Grass grass;
	Water water;

	// Generate world map.
	for (int x = 0; x < 100; x++)
	{
		for (int y = 0; y < 100; y++)
		{
			map[x][y] = grass;
			if ( abs(x+y-110) > 10 ) { map[x][y] = water; }
		}
	}

	// Load caracter.
	player = Player();

	// Set up tick rate.
	tickrate = 60; // Ticks per second.
	ticktime = 1000 / tickrate; // Time per tick.
	currentTick = 0;
}

World::~World()
{
}


std::string World::getSquare(int x, int y)
{
	return map[x][y].getType(); //Return the type of terrain
}

void World::getPlayerPos(int& x, int& y)
{
	player.getPos(x, y);
}

/*void World::getPlayerLastPos(int& x, int& y)
{
	player.getLastPos(x, y);
}

int World::getPlayerEndMoveBy()
{
	return player.getEndMoveBy();
}*/

void World::getPlayerFloatPos(float& x, float& y)
{
	player.getFloatPos(x, y, currentTick);
}

bool World::moveSquare(int x, int y)
{
	std::cout << "Moving: " << std::to_string(x) << ", " << std::to_string(y) << std::endl;
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