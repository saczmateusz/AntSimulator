#pragma once
#include "../Object.h"
#include "TextFields/TextField.h"
class ControlPanel : public Object
{
public:
	ControlPanel();
	~ControlPanel();
	void draw(sf::RenderWindow &window);


	//temp
	TextField parameters[6];

private:
	sf::Font font;
	sf::Texture texture;
	//std::list<TextField> parameters;
};

