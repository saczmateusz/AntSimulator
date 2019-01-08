#pragma once
#include "../../Object.h"

class Larva : public Object
{
public:
	Larva(sf::Texture *texture, sf::Vector2f position);
	~Larva();
	bool nextStage();
	unsigned int getNewAntsCount();

private:
	unsigned int age;
	unsigned int newAntsCount;
};