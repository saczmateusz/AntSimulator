#pragma once
#include "../../Object.h"
#include <string>

class TextField : public Object
{
public:
	TextField(Font &font, Vector2f position, unsigned int parameter);
	TextField();
	~TextField();
	void update(unsigned int parameter);
	void draw(RenderWindow &window);

private:
	Text textField;
	
};

