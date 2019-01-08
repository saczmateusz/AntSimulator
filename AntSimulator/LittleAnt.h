#pragma once
#include "Ant.h"

class LittleAnt : public Ant
{
public:
	LittleAnt(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position);
	~LittleAnt();

public:
	unsigned int age;
};

