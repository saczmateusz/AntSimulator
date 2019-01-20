#pragma once
#include "../Object.h"
#include "TextFields/TextField.h"

class ControlPanel : public Object
{
public:
	ControlPanel();
	~ControlPanel();
	void changeMaxHealth(int change);
	void changeLifeLenght(int change);
	void changeAdulthoodAge(int change);
	void changeTransformAge(int change);
	void changeMaxBrood(int change);
	void changeFertility(int change);
	void changeTerrainRegTime(int change);
	void draw(RenderWindow &window);

private:
	Font font;
	Texture texture;
	TextField parameters[7];
};

