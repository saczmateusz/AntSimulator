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
	void antListGetNewPosition(list<Terrain> &map);
	void antListReproduce();
	void antListUpdatePosition(float deltaTime);
	void antListDraw(RenderWindow &window);
	void larvaListAdd(Vector2f position);
	void larvaListUpdate();
	void larvaListDraw(RenderWindow &window);
	void littleAntListGetNewPosition(list<Terrain> &map);
	void littleAntListUpdatePosition(float deltaTime);
	void littleAntListDraw(RenderWindow &window);
	Vector2f randomPosition();

private:
	void antListCreate();

private:
	list<Ant> antList;
	list<LittleAnt> littleAntList;
	list<Larva> larvaList;
	Texture antTexture;
	Texture littleAntTexture;
	Texture larvaTexture;
};