#include "Animation.h"

Animation::Animation(sf::Texture * texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	aRect.width = texture->getSize().x / imageCount.x;
	aRect.height = texture->getSize().y / imageCount.y;
}

Animation::Animation()
{
	////konstruktor domyslny, potrzebny na uzytek domyslnego konstruktora obiektu klasy Ant, obslugujacej liste mrowek
}

Animation::~Animation()
{
}

void Animation::update(int row, float deltaTime, char direction)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		++currentImage.x;

		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}

	if (direction == ___RIGHT___)
	{
		aRect.left = currentImage.x * aRect.width;
		aRect.width = abs(aRect.width);
	}
	else
	{
		aRect.left = (currentImage.x + 1) * abs(aRect.width);
		aRect.width = -abs(aRect.width);
	}

	if (direction == ___UP___)
	{
		aRect.top = currentImage.y * aRect.height;
		aRect.height = abs(aRect.height);
	}
	else
	{
		aRect.top = (currentImage.y + 1) * abs(aRect.height);
		aRect.height = -abs(aRect.height);
	}
}
