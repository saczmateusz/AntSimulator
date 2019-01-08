#pragma once
#include "definitions.h"

class Object
{
public:
	void draw(sf::RenderWindow &window);
	const sf::Vector2f getPosition() const;

protected:
	sf::RectangleShape body;
};