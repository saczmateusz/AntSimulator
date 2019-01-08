#include "Larva.h"

Larva::Larva(sf::Texture * texture, sf::Vector2f position)
{
	body.setSize(sf::Vector2f(50.0f, 50.0f));
	body.setPosition(position);
	body.setTexture(texture);
	age = 0;
	newAntsCount = rand() % ___MAX_TRANSFORM_COUNT___ + 1;
}


Larva::~Larva()
{
}

bool Larva::nextStage()
{
	++age;
	if (age >= ___LARVA_TRANSFORM_TIME___)
		return true;
	else return false;
}

unsigned int Larva::getNewAntsCount()
{
	return newAntsCount;
}
