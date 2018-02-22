#pragma once

#include <SFML\Graphics.hpp>

#include <map>

class Texture
{
public:
	Texture();
	~Texture();

	sf::Texture& getTexture(std::string);
private:
	std::map <std::string, sf::Texture> texture;
};