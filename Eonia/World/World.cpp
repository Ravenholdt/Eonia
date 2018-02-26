#include "World.h"

#include <iostream>

World::World()
{
	// Generate world map.
	for (int x = 0; x < 100; x++)
	{
		for (int y = 0; y < 100; y++)
		{
			Grass grass;
			map[x][y] = grass;
			if (y == 50 && x == 50) { Terrain none; map[x][y] = none; }
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

void World::moveSquare(int x, int y)
{
	player.move(x, y, currentTick, tickrate);
	//posX += x;
	//posY += y;
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