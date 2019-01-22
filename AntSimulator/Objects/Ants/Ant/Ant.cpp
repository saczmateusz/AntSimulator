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
	const unsigned int random = rand() % (Parameters::AntAvgLifeLength * 2) + 1;
	return ((random > Parameters::AntAvgLifeLength - age / 20) && (random < Parameters::AntAvgLifeLength + age / 20));
}
