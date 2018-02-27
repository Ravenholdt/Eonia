#pragma once

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

class Mob
{
public:
	Mob();
	~Mob();

	void initiate(int id);
	void getPos(int& x, int& y);
	void getLastPos(int& x, int& y);
	void getFloatPos(float& x, float& y, int tick);
	int getEndMoveBy();

	int getMana();
	int getHealth();

	float getSpeed();

	bool move(int x, int y, int tick, int moveDelay);

	std::string getTexture();

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

	// Texture
	std::string texture;

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