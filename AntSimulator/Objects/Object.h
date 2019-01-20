#pragma once
#include "../definitions.h"

class Object
{
public:
	void draw(RenderWindow &window);
	const Vector2f getPosition() const;

protected:
	RectangleShape body;
};