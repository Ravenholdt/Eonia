#include "mob.h"

mob::mob()
{
}


mob::~mob()
{
}

int mob::getMana()
{
	return mana;
}

int mob::getHealth()
{
	return health;
}

float mob::getSpeed()
{
	return moveSpeed;
}

void mob::getPos(int& x, int& y)
{
	x = posX;
	y = posY;
}

void mob::move(int x, int y)
{
	posX += x;
	posY += y;
}