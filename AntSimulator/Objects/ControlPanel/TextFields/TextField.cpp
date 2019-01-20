#include "TextField.h"

TextField::TextField(Font &font, Vector2f position, unsigned int parameter)
{
	textField.setFont(font);
	textField.setFillColor(Color(255, 255, 255, 255));
	textField.setString(String(to_string(parameter)));
	textField.setOrigin(Vector2f(-30.0f, 0.0f));
	textField.setPosition(position);
}

TextField::TextField()
{
}

TextField::~TextField()
{
}

void TextField::update(unsigned int parameter)
{
	textField.setString(String(to_string(parameter)));
}

void TextField::draw(RenderWindow &window)
{
	window.draw(textField);
}
