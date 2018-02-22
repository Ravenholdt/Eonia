#pragma once

#include <SFML\Graphics.hpp>
#include <string>

class Terrain
{
public:
	Terrain();
	~Terrain();

	std::string getType();

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