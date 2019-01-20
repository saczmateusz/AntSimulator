#include "Object.h"

void Object::draw(RenderWindow &window)
{
	window.draw(body);
}

const Vector2f Object::getPosition() const
{
	return body.getPosition();
}
