#include "TextField.h"

TextField::TextField(sf::Font &font, sf::Vector2f position, unsigned int parameter)
{
	textField.setFont(font);
	textField.setFillColor(sf::Color(255, 255, 255, 255));
	textField.setString(sf::String(std::to_string(parameter)));
	textField.setOrigin(sf::Vector2f(-30.0f, 0.0f));
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
	textField.setString(sf::String(std::to_string(parameter)));
}

void TextField::draw(sf::RenderWindow &window)
{
	window.draw(textField);
}
