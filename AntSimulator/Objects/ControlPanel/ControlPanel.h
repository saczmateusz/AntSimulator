#pragma once
#include "../Object.h"
#include "TextFields/TextField.h"
class ControlPanel : public Object
{
public:
	ControlPanel();
	~ControlPanel();
	void healthUpdate(bool change);
	void lifeLengthUpdate(int change);
	void adulthoodUpdate(int change);
	void transformUpdate(int change);
	void broodUpdate(int change);
	void fertilityUpdate(int change);
	void terrainRegUpdate(int change);
	


	void draw(RenderWindow &window);

private:
	Font font;
	Texture texture;
	TextField parameters[7];
};