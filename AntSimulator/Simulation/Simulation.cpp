#include "Simulation.h"



Simulation::Simulation()
	: window(sf::VideoMode(___WIDTH___ + 300, ___HEIGHT___), "Ant Simulator", sf::Style::Close)
{
	window.setFramerateLimit(60);
	timer = 0;
	state = false;
	mpos = sf::Vector2f(0.0f, 0.0f);
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

		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}

			if (e.type == sf::Event::KeyPressed)
			{
				switch (e.key.code)
				{
				case sf::Keyboard::Escape:
					window.close();
					break;

				case sf::Keyboard::Space:
					state = !state;
					break;

				case sf::Keyboard::Home:
					controlPanel.healthUpdate(false);
					break;

				case sf::Keyboard::End:
					controlPanel.healthUpdate(true);
					break;

				case sf::Keyboard::PageUp:
					controlPanel.lifeLengthUpdate(false);
					break;

				case sf::Keyboard::PageDown:
					controlPanel.lifeLengthUpdate(true);
					break;

				case sf::Keyboard::Subtract:
					controlPanel.terrainRegUpdate(false);
					break;

				case sf::Keyboard::Add:
					controlPanel.terrainRegUpdate(true);
					break;
				}
			}
		}

		if (timer >= ___SPEED___ && timer % ___SPEED___ == 0 && state == true)
		{
			std::cout << "Round #" << timer / ___SPEED___ << std::endl;
			antColony.antListGetNewPosition(terrain.getMap());
			antColony.antListReproduce();
			antColony.littleAntListGetNewPosition(terrain.getMap());
			terrain.updateMap();
			antColony.larvaListUpdate();
			std::cout << std::endl << std::endl;
		}

		antColony.littleAntListUpdatePosition(deltaTime);
		antColony.antListUpdatePosition(deltaTime);

		window.clear(sf::Color(150, 150, 150));
		terrain.drawMap(window);
		antColony.larvaListDraw(window);
		antColony.littleAntListDraw(window);
		antColony.antListDraw(window);
		controlPanel.draw(window);
		window.display();
		++timer;
	}
}
