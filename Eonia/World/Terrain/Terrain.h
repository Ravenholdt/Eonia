#pragma once

#include <SFML\Graphics.hpp>
#include <string>

class Terrain
{
public:
	Terrain();
	~Terrain();

	std::string getType();

	bool isPassable();

protected:
	std::string type;

	bool passable;
	bool cutable;

	float walkingSpeed;
};


class Grass : public Terrain
{
public:
	Grass();
	~Grass();
};


class Water : public Terrain
{
public:
	Water();
	~Water();
};