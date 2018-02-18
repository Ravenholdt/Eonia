#pragma once
class World
{
public:
	World();
	~World();

	void MoveCamera(int _x, int _y);

private:

	int posX;
	int posY;
};

