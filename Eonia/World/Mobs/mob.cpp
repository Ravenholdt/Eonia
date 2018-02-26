#include "mob.h"

Mob::Mob()
{
	healthMax = 10, manaMax = 10;
	health = 10, mana = 10;

	moveSpeed = 1;
	EndMoveBy = 0;
}

Mob::~Mob() {}


void Mob::initiate(int id)
{
	mobID = id;
}

int Mob::getMana()
{
	return mana;
}

int Mob::getHealth()
{
	return health;
}

float Mob::getSpeed()
{
	return moveSpeed;
}

void Mob::getPos(int& x, int& y)
{
	x = posX;
	y = posY;
}

void Mob::getFloatPos(float& x, float& y, int tick, int tickrate)
{
	if (EndMoveBy > tick)
	{
		float Dx = posX - lastPosX;
		float Dy = posY - lastPosY;

		x = posX - Dx * (EndMoveBy - tick) / tickrate;
		y = posY - Dy * (EndMoveBy - tick) / tickrate;
	}
	else 
	{
		x = posX;
		y = posY;
	}
}

bool Mob::move(int x, int y, int tick, int moveDelay)
{
	if (EndMoveBy <= tick)
	{
		lastPosX = posX;
		lastPosY = posY;

		posX += x;
		posY += y;
		EndMoveBy = tick + moveSpeed * moveDelay;
		BeginMoveBy = tick;
		return true;
	}
	return false;
}

// Player -----------------------------
Player::Player()
{
	healthMax = 50, manaMax = 50;
	health = 50, mana = 50;
	moveSpeed = 0.3f;
}

Player::~Player() {}

// Rat --------------------------------
Rat::Rat()
{
	health = 5, mana = 0;
}

Rat::~Rat() {}