#pragma once
#include "../LittleAnt/LittleAnt.h"


class Ant : public LittleAnt
{
	//TYMCZASOWO wszystko na PUBLIC
public:
	Ant(Texture *texture, Vector2u imageCount, float switchTime, float speed, Vector2f position);
	~Ant();
	bool isDying();

public:
	unsigned int fertility;
};