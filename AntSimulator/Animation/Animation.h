#pragma once
#include "../definitions.h"

class Animation
{
public:
	Animation(Texture* texture, Vector2u imageCount, float switchTime);
	Animation();
	~Animation();

	void update(int row, float deltaTime, char direction);

public:
	IntRect aRect;

private:
	Vector2u imageCount;
	Vector2u currentImage;

	float totalTime;
	float switchTime;
};