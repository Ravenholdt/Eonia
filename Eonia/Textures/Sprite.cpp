#include "Sprite.h"
#include "Texture.h"

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
}

void Sprite::setTexture(sf::Texture texture)
{
	sprite.setTexture(texture);
}

sf::Sprite* Sprite::getSprite()
{
	return &sprite;
}