#pragma once

#include <SFML\System.hpp>

class Mob
{
public:
	Mob();
	~Mob();

	void getPos(int& x, int& y);

	int getMana();
	int getHealth();

	float getSpeed();

	void move(int x, int y);

protected:
	int posX = 0, posY = 0;
	int health, mana;

	float moveSpeed;
	sf::Time moveDelay;

};


class Player : public Mob
{
public:
	Player();
	~Player();

private:

};