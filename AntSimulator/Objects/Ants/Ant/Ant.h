#pragma once
#include "../LittleAnt/LittleAnt.h"


class Ant : public LittleAnt
{
	//TYMCZASOWO wszystko na PUBLIC
public:
	Ant(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position);
	~Ant();
	bool isDying();

public:
	unsigned int fertility;
};