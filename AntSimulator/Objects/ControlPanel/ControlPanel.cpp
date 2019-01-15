#include "ControlPanel.h"

ControlPanel::ControlPanel()
{
	texture.loadFromFile("Resources\\textures\\control.png");
	font.loadFromFile("Resources\\fonts\\DJB_Chalk_It_Up.ttf");

	body.setSize(sf::Vector2f(300.0f, ___HEIGHT___));
	body.setPosition(sf::Vector2f(___WIDTH___, 0.0f));
	body.setTexture(&texture);



	parameter = TextField(font, sf::Vector2f(910, 45));
}

ControlPanel::~ControlPanel()
{
}

void ControlPanel::draw(sf::RenderWindow & window)
{
	window.draw(body);
	

	parameter.draw(window);

}
