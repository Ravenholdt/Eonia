#include "Terrain.h"


Terrain::Terrain()
{
	type = "none";

	passable = false;
	cutable = false;

	walkingSpeed = 1;
}

Terrain::~Terrain() {}

std::string Terrain::getType() {return type;}

bool Terrain::isPassable() {return passable;}


// Grass Terrain
Grass::Grass()
{
	type = "grass";
	passable = true;
}

Grass::~Grass() {}


// Water Terrain
Water::Water()
{
	type = "water";
	passable = false;
}

Water::~Water() {}