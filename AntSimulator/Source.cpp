#include "definitions.h"
#include "Objects/Terrain/Terrain.h"
#include "Objects/Colony/AntColony.h"
#include "Objects/ControlPanel/ControlPanel.h"

int main()
{
	srand(unsigned int (time(NULL)));
	sf::Clock clock, clock2;
	clock2.restart();
	unsigned long long timer = 0;
	sf::RenderWindow window(sf::VideoMode(___WIDTH___ + 300, ___HEIGHT___), "Ant Simulator", sf::Style::Close);
	window.setFramerateLimit(60);

	sf::Texture terrainTexture;
	terrainTexture.loadFromFile("Resources\\textures\\terrain.png");
	//rysowanie mapy
	Terrain terrain;
	terrain.createMap(&terrainTexture);

	//rysowanie mrowkow
	AntColony antColony;
	//ants.createList(&antTexture);

	ControlPanel controlPanel;

	sf::Vector2f mpos(0.0f, 0.0f);

	float deltaTime = 0.0f;
	char currDirection = ___LEFT___;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		sf::Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			sf::sleep(sf::seconds(deltaTime));
		}


		if (timer >= 70 && timer % 70 == 0)
		{
			std::cout << "Round #" << timer / 70 << std::endl;
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

	return 0;
}