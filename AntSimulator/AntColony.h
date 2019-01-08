#pragma once
#include "Ant.h"
#include "LittleAnt.h"
#include "Larva.h"
#include "Terrain.h"

class AntColony
{
public:
	AntColony();
	~AntColony();
	void antListGetNewPosition(std::list<Terrain> &map);
	void antListReproduce();
	void antListUpdatePosition(float deltaTime);
	void antListDraw(sf::RenderWindow &window);
	void larvaListAdd(sf::Vector2f position);
	void larvaListUpdate();
	void larvaListDraw(sf::RenderWindow &window);
	void littleAntListGetNewPosition(std::list<Terrain> &map);
	void littleAntListUpdatePosition(float deltaTime);
	void littleAntListDraw(sf::RenderWindow &window);

private:
	void antListCreate();

private:
	std::list<Ant> antList;
	std::list<LittleAnt> littleAntList;
	std::list<Larva> larvaList;
	sf::Texture antTexture;
	sf::Texture littleAntTexture;
	sf::Texture larvaTexture;
};

