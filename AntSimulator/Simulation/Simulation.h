#pragma once
#include "../definitions.h"
#include "../Objects/Terrain/Terrain.h"
#include "../Objects/Colony/AntColony.h"
#include "../Objects/ControlPanel/ControlPanel.h"

class Simulation
{
public:
	Simulation();
	~Simulation();
	void run();

private:


public:
	unsigned long long timer = 0;
	RenderWindow window;
	Clock clock;
	Texture terrainTexture;

	bool state;

	Terrain terrain;
	ControlPanel controlPanel;
	AntColony antColony;

	Vector2f mpos;

	float deltaTime;
	char currDirection;

private:

};