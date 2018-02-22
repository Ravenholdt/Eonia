#include "World.h"

#include <iostream>

World::World()
{
	for (int x = 0; x < 100; x++)
	{
		for (int y = 0; y < 100; y++)
		{
			Grass grass;
			map[x][y] = grass;
			if (y == 50 && x == 50) { Terrain none; map[x][y] = none; }
		}
	}
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
	x = posX;
	y = posY;
}

void World::moveSquare(int x, int y)
{
	posX += x;
	posY += y;
}

void World::setSquare(int x, int y)
{
	posX = x;
	posY = y;
}