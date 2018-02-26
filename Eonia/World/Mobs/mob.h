#pragma once

#include <SFML\System.hpp>

class Mob
{
public:
	Mob();
	~Mob();

	void initiate(int id);
	void getPos(int& x, int& y);
	void getFloatPos(float& x, float& y, int tick, int tickrate);

	int getMana();
	int getHealth();

	float getSpeed();

	bool move(int x, int y, int tick, int moveDelay);

protected:
	int mobID;

	int posX = 0, posY = 0;
	int lastPosX = 0, lastPosY = 0;

	int health, mana;
	int healthMax, manaMax;

	// Move logic
	float moveSpeed;
	int BeginMoveBy;
	int EndMoveBy;

	bool hostile;
};


class Player : public Mob
{
public:
	Player();
	~Player();

private:

};

class Rat : public Mob
{
public:
	Rat();
	~Rat();

private:
};