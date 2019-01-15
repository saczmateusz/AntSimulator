#pragma once
#include "../../Object.h"

class TextField : public Object
{
public:
	TextField(sf::Font &font, sf::Vector2f position);
	~TextField();
	TextField();
	void draw(sf::RenderWindow &window);

public:
	sf::Text textField;
	
};

