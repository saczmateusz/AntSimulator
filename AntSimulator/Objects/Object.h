#pragma once
#include "../definitions.h"

class Object
{
public:
	void draw(RenderWindow &window);
	Vector2f getPosition() const;

protected:
	RectangleShape body;
};