#include "Ant.h"

Ant::Ant(sf::Texture * texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position)
	: LittleAnt(texture, imageCount, switchTime, speed, position)
{
	fertility = 0;
}

Ant::~Ant()
{
}