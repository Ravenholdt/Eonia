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
	void getPlayerPos(int& x, int& y);

	void moveSquare(int x, int y);
	void setSquare(int x, int y);

private:

	Player player;

	int posX;
	int posY;

	Terrain map[100][100];
	//std::map<std::string, Terrain> Map;
};