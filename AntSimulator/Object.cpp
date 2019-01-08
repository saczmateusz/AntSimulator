#include "Object.h"

void Object::draw(sf::RenderWindow &window)
{
	window.draw(body);
}

const sf::Vector2f Object::getPosition() const
{
	return body.getPosition();
}
