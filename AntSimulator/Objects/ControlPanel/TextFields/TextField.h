#pragma once
#include "../../Object.h"
#include <string>

class TextField : public Object
{
public:
	TextField(sf::Font &font, sf::Vector2f position, unsigned int parameter);
	TextField();
	~TextField();
	void update(unsigned int parameter);
	void draw(sf::RenderWindow &window);

private:
	sf::Text textField;
	
};

