#pragma once

#include <map>
#include <string>

#include "Terrain\Terrain.h"
#include "Mobs\Mob.h"

const int worldWidth = 100, worldHeight = 100;

class World
{
public:
	World();
	~World();

	std::string getSquare(int x, int y);
	void getPlayerPos(int& x, int& y);
	void getPlayerFloatPos(float& x, float& y);

	bool moveSquare(int x, int y);
	void setSquare(int x, int y);

	int nextTick();
	int getTick();
	int getTickTime();
	int getTickRate();

	std::string getPlayerTexture();

private:

	Player player;

	int posX, posY;

	// Frames per second settings
	int tickrate;
	int currentTick;
	int ticktime;

	Terrain map[worldWidth][worldHeight];
	//std::map<std::string, Terrain> Map;

	// Terrain types
	Grass grass;
	Water water;
};