#include "Simulation.h"



Simulation::Simulation()
	: window(VideoMode(___WIDTH___ + 300, ___HEIGHT___), "Ant Simulator", Style::Close)
{
	window.setFramerateLimit(60);
	timer = 0;
	state = false;
	mpos = Vector2f(0.0f, 0.0f);
	deltaTime = 0.0f;
	currDirection = ___LEFT___;
	terrainTexture.loadFromFile("Resources\\textures\\terrain.png");
	terrain.createMap(&terrainTexture);
}


Simulation::~Simulation()
{
}

void Simulation::run()
{
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}

			if (e.type == Event::KeyPressed)
			{
				switch (e.key.code)
				{
				case Keyboard::Escape:
					window.close();
					break;

				case Keyboard::Space:
					state = !state;
					break;

				case Keyboard::Home:
					controlPanel.healthUpdate(false);
					break;

				case Keyboard::End:
					controlPanel.healthUpdate(true);
					break;

				case Keyboard::PageUp:
					controlPanel.lifeLengthUpdate(false);
					break;

				case Keyboard::PageDown:
					controlPanel.lifeLengthUpdate(true);
					break;

				case Keyboard::Divide:
					controlPanel.adulthoodUpdate(false);
					break;

				case Keyboard::Multiply:
					controlPanel.adulthoodUpdate(true);
					break;

				case Keyboard::Numpad8:
					controlPanel.transformUpdate(false);
					break;

				case Keyboard::Numpad9:
					controlPanel.transformUpdate(true);
					break;

				case Keyboard::Numpad5:
					controlPanel.broodUpdate(false);
					break;

				case Keyboard::Numpad6:
					controlPanel.broodUpdate(true);
					break;

				case Keyboard::Numpad2:
					controlPanel.fertilityUpdate(false);
					break;

				case Keyboard::Numpad3:
					controlPanel.fertilityUpdate(true);
					break;

				case Keyboard::Subtract:
					controlPanel.terrainRegUpdate(false);
					break;

				case Keyboard::Add:
					controlPanel.terrainRegUpdate(true);
					break;
				}
			}
		}

		if (timer >= ___SPEED___ && timer % ___SPEED___ == 0 && state == true)
		{
			cout << "Round #" << timer / ___SPEED___ << endl;
			antColony.antListGetNewPosition(terrain.getMap());
			antColony.antListReproduce();
			antColony.littleAntListGetNewPosition(terrain.getMap());
			terrain.updateMap();
			antColony.larvaListUpdate();
			cout << endl << endl;
		}

		antColony.littleAntListUpdatePosition(deltaTime);
		antColony.antListUpdatePosition(deltaTime);

		window.clear(Color(150, 150, 150));
		terrain.drawMap(window);
		antColony.larvaListDraw(window);
		antColony.littleAntListDraw(window);
		antColony.antListDraw(window);
		controlPanel.draw(window);
		window.display();
		++timer;
	}
}
