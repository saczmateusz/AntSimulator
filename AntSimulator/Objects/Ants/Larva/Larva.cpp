#include "Larva.h"

Larva::Larva(Texture * texture, Vector2f position)
{
	body.setSize(Vector2f(50.0f, 50.0f));
	body.setPosition(position);
	body.setTexture(texture);
	age = 0;
	newAntsCount = rand() % Parameters::LarvaMaxBrood + 1;
}


Larva::~Larva()
{
}

bool Larva::nextStage()
{
	++age;
	return age >= Parameters::LarvaTransformAge;
}

unsigned int Larva::getNewAntsCount()
{
	return newAntsCount;
}
