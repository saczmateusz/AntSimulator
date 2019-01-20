#pragma once
#include "../Object.h"

class Terrain : public Object
{
public:
	Terrain();
	void createMap(Texture *texture);
	void drawMap(RenderWindow &window);
	void updateMap();
	bool checkTile();
	list<Terrain> &getMap();

private:
	Terrain(Texture *texture, Vector2f position);
	void switchTile(bool factor);
	bool texRand();

private:
	list<Terrain> terrainMap;
	IntRect tRect;
	int cooldown;
};