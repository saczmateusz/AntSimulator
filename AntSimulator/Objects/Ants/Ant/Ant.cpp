#include "Ant.h"

Ant::Ant(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position)
	: LittleAnt(texture, imageCount, switchTime, speed, position)
{
	fertility = 0;
	age = 8;
}

Ant::~Ant()
{
}

bool Ant::isDying()
{
	unsigned int random = rand() % 100;
	unsigned int outline = age < 90 ? unsigned int(100 - (2.5 * age - 60)) : 90;
	if (random >= outline)
	{
		return true;
	}
	else
		return false;
}
