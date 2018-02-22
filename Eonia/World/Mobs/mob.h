#pragma once

class mob
{
public:
	mob();
	~mob();

	void getPos(int& x, int& y);

	int getMana();
	int getHealth();

	float getSpeed();

	void move(int x, int y);

protected:
	int posX, posY;
	
	int health, mana;

	float moveSpeed;

};

