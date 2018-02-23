#include "mob.h"

Mob::Mob()
{
}


Mob::~Mob()
{
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

void Mob::move(int x, int y)
{
	posX += x;
	posY += y;
}


Player::Player()
{
}

Player::~Player()
{
}