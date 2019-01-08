#pragma once
#include "../definitions.h"

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	Animation();
	~Animation();

	void update(int row, float deltaTime, char direction);

public:
	sf::IntRect aRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};