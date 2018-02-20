#pragma once
class Terrain
{
public:
	Terrain();
	~Terrain();

private:
	bool passable;
	bool cutable;

	int walkingSpeed;
};

