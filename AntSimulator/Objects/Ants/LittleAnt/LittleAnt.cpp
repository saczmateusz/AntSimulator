#include "LittleAnt.h"

LittleAnt::LittleAnt(sf::Texture * texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position)
	: animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	health = ___ANT_MAX_HEALTH___;
	direction = ___UP___;
	body.setSize(sf::Vector2f(50.0f, 50.0f));
	body.setPosition(position);
	body.setTexture(texture);
	nextPosition = body.getPosition();
	initHealthBar();
	age = 0;
}

LittleAnt::~LittleAnt()
{
}

void LittleAnt::moveToFixedPosition(float deltaTime, sf::Vector2f movement)
{
	sf::Vector2f position(getPosition());
	if (position.x < movement.x)
	{
		position.x += speed * deltaTime;
		row = 1;
		direction = ___RIGHT___;
		if (position.x > movement.x)
			position.x = movement.x;
	}
	else if (position.x > movement.x)
	{
		position.x -= speed * deltaTime;
		row = 1;
		direction = ___LEFT___;
		if (position.x < movement.x)
			position.x = movement.x;
	}
	else if (position.y < movement.y)
	{
		position.y += speed * deltaTime;
		row = 0;
		direction = ___DOWN___;
		if (position.y > movement.y)
			position.y = movement.y;
	}
	else if (position.y > movement.y)
	{
		position.y -= speed * deltaTime;
		row = 0;
		direction = ___UP___;
		if (position.y < movement.y)
			position.y = movement.y;
	}
	else
	{
		if (direction == ___DOWN___ || direction == ___UP___)
			row = 2;
		else
			row = 3;
	}

	animation.update(row, deltaTime, direction);
	body.setTextureRect(animation.aRect);
	body.setPosition(position);
	healthBarBackgroud.setPosition(sf::Vector2f(getPosition().x + 5, getPosition().y + 1));
	healthBar.setPosition(sf::Vector2f(getPosition().x + 5, getPosition().y + 1));
}

sf::Vector2f LittleAnt::randomPosition(sf::Vector2f position)
{
	unsigned int random = rand() % 8;
	sf::Vector2f newPosition(position);
	switch (random)
	{
	case 0:
		if (position.x >= 50)
			newPosition.x -= 50;
		if (position.y >= 50)
			newPosition.y -= 50;
		break;
	case 1:
		if (position.y >= 50)
			newPosition.y -= 50;
		break;
	case 2:
		if (position.x <= ___WIDTH___ - 100)
			newPosition.x += 50;
		if (position.y >= 50)
			newPosition.y -= 50;
		break;
	case 3:
		if (position.x >= 50)
			newPosition.x -= 50;
		break;
	case 4:
		if (position.x <= ___WIDTH___ - 100)
			newPosition.x += 50;
		break;
	case 5:
		if (position.x >= 50)
			newPosition.x -= 50;
		if (position.y <= ___HEIGHT___ - 100)
			newPosition.y += 50;
		break;
	case 6:
		if (position.y <= ___HEIGHT___ - 100)
			newPosition.y += 50;
		break;
	case 7:
		if (position.x <= ___WIDTH___ - 100)
			newPosition.x += 50;
		if (position.y <= ___HEIGHT___ - 100)
			newPosition.y += 50;
		break;
	}

	if (position == newPosition)
		return randomPosition(position);
	else return newPosition;
}

void LittleAnt::changeHealth(int change)
{
	health += change;
}

void LittleAnt::draw(sf::RenderWindow & window)
{
	window.draw(body);
	window.draw(healthBarBackgroud);
	window.draw(healthBar);
}

void LittleAnt::initHealthBar()
{
	healthBarBackgroud.setPosition(sf::Vector2f(getPosition().x + 5, getPosition().y + 1));
	healthBarBackgroud.setSize(sf::Vector2f(___ANT_HEALTH_BAR_WIDTH___, ___ANT_HEALTH_BAR_HEIGHT___));
	healthBarBackgroud.setOutlineThickness(1.0f);
	healthBarBackgroud.setOutlineColor(sf::Color(0, 0, 0));
	healthBarBackgroud.setFillColor(sf::Color(255, 0, 0));
	healthBar.setPosition(sf::Vector2f(getPosition().x + 5, getPosition().y + 1));
	healthBar.setFillColor(sf::Color(50, 150, 50));
	setHealthBar(___ANT_MAX_HEALTH___);
}

void LittleAnt::setHealthBar(unsigned int health)
{
	healthBar.setSize(sf::Vector2f(health * (___ANT_HEALTH_BAR_WIDTH___ / ___ANT_MAX_HEALTH___), ___ANT_HEALTH_BAR_HEIGHT___));
}

const unsigned int LittleAnt::getHealth() const
{
	return health;
}