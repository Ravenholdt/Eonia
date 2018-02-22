#include "Terrain.h"



Terrain::Terrain()
{
	type = "none";

	passable = false;
	cutable = false;

	walkingSpeed = 1;
}

Terrain::~Terrain()
{
}

std::string Terrain::getType()
{
	return type;
}


// Grass Terrain
Grass::Grass()
{
	type = "grass";
	passable = true;
}


Grass::~Grass()
{
}
