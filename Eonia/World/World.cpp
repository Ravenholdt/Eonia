#include "World.h"

#include <iostream>

World::World()
{
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