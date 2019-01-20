#pragma once
#include "../../Object.h"
#include "../../../Animation/Animation.h"

class LittleAnt : public Object
{
public:
	LittleAnt(Texture *texture, Vector2u imageCount, float switchTime, float speed, Vector2f position);
	~LittleAnt();
	Vector2f randomPosition(Vector2f position);
	void moveToFixedPosition(float deltaTime, Vector2f movement);
	void initHealthBar();
	void setHealthBar(unsigned int health);
	void changeHealth(int change);
	void draw(RenderWindow &window);
	const int getHealth() const;


public:
	RectangleShape healthBarBackgroud;
	RectangleShape healthBar;
	Vector2f nextPosition;
	Animation animation;
	unsigned int row;
	int health;
	float speed;
	char direction;
	unsigned int age;
};

