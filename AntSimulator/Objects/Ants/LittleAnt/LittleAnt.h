#pragma once
#include "../../Object.h"
#include "../../../Animation/Animation.h"

class LittleAnt : public Object
{
public:
	LittleAnt(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position);
	~LittleAnt();
	sf::Vector2f randomPosition(sf::Vector2f position);
	void moveToFixedPosition(float deltaTime, sf::Vector2f movement);
	void initHealthBar();
	void setHealthBar(unsigned int health);
	void changeHealth(int change);
	void draw(sf::RenderWindow &window);
	const unsigned int getHealth() const;


public:
	sf::RectangleShape healthBarBackgroud;
	sf::RectangleShape healthBar;
	sf::Vector2f nextPosition;
	Animation animation;
	unsigned int row;
	unsigned int health;
	float speed;
	char direction;
	unsigned int age;
};

