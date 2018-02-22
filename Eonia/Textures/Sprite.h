#pragma once

#include <SFML\Graphics.hpp>

class Sprite
{
public:
	Sprite();
	~Sprite();

	void setTexture(sf::Texture texture);
	sf::Sprite* getSprite();
private:
	sf::Sprite sprite;
};