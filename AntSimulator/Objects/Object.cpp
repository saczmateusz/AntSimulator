#include "Object.h"

void Object::draw(RenderWindow &window)
{
	window.draw(body);
}

Vector2f Object::getPosition() const
{
	return body.getPosition();
}
