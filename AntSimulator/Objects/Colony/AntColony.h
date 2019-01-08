#pragma once
#include "../Ants/Ant/Ant.h"
#include "../Ants/Larva/Larva.h"
#include "../Ants/LittleAnt/LittleAnt.h"
#include "../Terrain/Terrain.h"

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
	sf::Vector2f randomPosition();

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

