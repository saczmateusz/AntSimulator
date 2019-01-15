#include "TextField.h"

TextField::TextField(sf::Font &font, sf::Vector2f position)
{
	textField.setFont(font);
	textField.setFillColor(sf::Color(255, 255, 255, 255));
	textField.setPosition(position);
	textField.setString("00");
}

TextField::~TextField()
{
}

TextField::TextField()
{
}

void TextField::draw(sf::RenderWindow &window)
{
	window.draw(textField);
}
