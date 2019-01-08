#pragma once
#include "Object.h"
#include "Animation.h"

class Ant : public Object
{
	//TYMCZASOWO wszystko na PUBLIC
public:
	Ant(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position);
	Ant(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Ant();
	sf::Vector2f randomPosition();
	sf::Vector2f randomPosition(sf::Vector2f position);
	void moveToFixedPosition(float deltaTime, sf::Vector2f movement);
	void initHealthBar();
	void setHealthBar(unsigned int health);
	void changeHealth(int change);
	const int getHealth() const;

public:
	sf::RectangleShape healthBarBackgroud;
	sf::RectangleShape healthBar;
	sf::Vector2f nextPosition;
	Animation animation;
	unsigned int row;
	unsigned int fertility;
	int health;
	float speed;
	char direction;
};