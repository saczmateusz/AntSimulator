#pragma once
#include "Object.h"

class Terrain : public Object
{
public:
	Terrain();
	void createMap(sf::Texture *texture);
	void drawMap(sf::RenderWindow &window);
	void updateMap();
	bool checkTile();
	std::list<Terrain> &getMap();

private:
	Terrain(sf::Texture *texture, sf::Vector2f position);
	void switchTile(bool factor);
	bool texRand();

private:
	std::list<Terrain> terrainMap;
	sf::IntRect tRect;
	int cooldown;
};