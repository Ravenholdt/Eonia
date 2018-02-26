#pragma once

#include <map>
#include <string>

#include "Terrain\Terrain.h"
#include "Mobs\Mob.h"

class World
{
public:
	World();
	~World();

	std::string getSquare(int x, int y);
	void getPlayerPosFloat(float& x, float& y);

	void moveSquare(int x, int y);
	void setSquare(int x, int y);

	int nextTick();
	int getTick();
	int getTickTime();

private:

	Player player;

	int posX;
	int posY;

	// Frames per second settings
	int tickrate;
	int currentTick;
	int ticktime;

	Terrain map[100][100];
	//std::map<std::string, Terrain> Map;
};