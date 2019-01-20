#include "Ant.h"

Ant::Ant(Texture* texture, Vector2u imageCount, float switchTime, float speed, Vector2f position)
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
	const unsigned int random = rand() % 100;
	const unsigned int outline = age < 90 ? unsigned int(100 - (2.5 * age - 60)) : 90;
	return random >= outline;
}
