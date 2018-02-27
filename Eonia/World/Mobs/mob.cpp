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

void Mob::getLastPos(int& x, int& y)
{
	x = lastPosX;
	y = lastPosY;
}

void Mob::getFloatPos(float& x, float& y, int tick)
{
	float DxInt = posX - lastPosX;
	float DyInt = posY - lastPosY;

	if (DxInt || DyInt)
	{
		// Player Movement rendering logic.
		if (EndMoveBy > tick)
		{
			x = posX + DxInt * (EndMoveBy - tick) / (EndMoveBy - BeginMoveBy);
			y = posY + DyInt * (EndMoveBy - tick) / (EndMoveBy - BeginMoveBy);
		}
		else {
			x = posX;
			y = posY;
		}
	}
}

int Mob::getEndMoveBy()
{
	return EndMoveBy;
}

bool Mob::move(int x, int y, int tick, int moveDelay)
{
	if (EndMoveBy <= tick)
	{
		lastPosX = posX;
		lastPosY = posY;


		posX += x;
		posY += y;

		//if (!moveDelay) { lastPosX = posX, lastPosY = posY; } // If teleporting, don't keep last pos

		EndMoveBy = tick + moveSpeed * moveDelay;
		BeginMoveBy = tick;
		return true;
	}
	return false;
}

std::string Mob::getTexture()
{
	return texture;
}

// Player -----------------------------
Player::Player()
{
	healthMax = 50, manaMax = 50;
	health = 50, mana = 50;
	moveSpeed = 0.5f;

	texture = "player";
}

Player::~Player() {}

// Rat --------------------------------
Rat::Rat()
{
	health = 5, mana = 0;
}

Rat::~Rat() {}