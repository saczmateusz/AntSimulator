#include "LittleAnt.h"

LittleAnt::LittleAnt(sf::Texture * texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position)
	: Ant(texture, imageCount, switchTime, speed, position)
{
	age = 0;
}

LittleAnt::~LittleAnt()
{
}
