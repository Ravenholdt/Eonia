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
	player.move(x, y);
	//posX += x;
	//posY += y;
}

void World::setSquare(int x, int y)
{
	player.move(x, y);
	//posX = x;
	//posY = y;
}