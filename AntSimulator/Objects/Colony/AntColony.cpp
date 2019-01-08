#include "AntColony.h"

AntColony::AntColony()
{
	antTexture.loadFromFile("Resources\\textures\\ant.png");
	littleAntTexture.loadFromFile("Resources\\textures\\little_ant.png");
	larvaTexture.loadFromFile("Resources\\textures\\larva.png");
	antListCreate();
}

AntColony::~AntColony()
{
}

void AntColony::antListCreate()
{
	for (size_t i = 0; i < ___ANTS_COUNT___; ++i)
	{
		Ant ant(&antTexture, sf::Vector2u(4, 4), 0.1f, 100.0f, randomPosition());
		antList.push_back(ant);
	}
}

void AntColony::antListGetNewPosition(std::list<Terrain>& map)
{
	std::list<Ant> newAnts;

	for (std::list<Ant>::iterator it = antList.begin(); it != antList.end(); ++it)
	{
		std::cout << "Ant pos: " << it->getPosition().x << " " << it->getPosition().y << std::endl;
		std::list<Terrain>::iterator tile = map.begin();
		std::advance(tile, ((___WIDTH___ / 50) * (it->getPosition().y / 50) + (it->getPosition().x / 50)));
		if (tile->checkTile())
			it->changeHealth(-1);
		else if (it->getHealth() < ___ANT_MAX_HEALTH___)
			it->changeHealth(1);
		it->setHealthBar(it->getHealth());
		std::cout << "Ant HP: " << it->getHealth() << std::endl;
		if (it->getHealth() >= 0)
		{
			it->nextPosition = it->randomPosition(it->getPosition());
			++(it->fertility);
			newAnts.push_back(*it);
		}
	}
	antList = newAnts;
}

void AntColony::antListReproduce()
{
	for (std::list<Ant>::iterator it = antList.begin(); it != antList.end(); ++it)
	{
		if (it->fertility >= ___MIN_FERTILITY___)
		{
			for (std::list<Ant>::iterator prev = antList.begin(); prev != it; ++prev)
			{
				if (it->getPosition() == prev->getPosition() && prev->fertility >= ___MIN_FERTILITY___)
				{
					larvaListAdd(it->getPosition());
					it->fertility = 0;
					prev->fertility = 0;
				}
			}
		}
	}
}

void AntColony::antListUpdatePosition(float deltaTime)
{
	for (std::list<Ant>::iterator it = antList.begin(); it != antList.end(); it++)
		it->moveToFixedPosition(deltaTime, it->nextPosition);
}

void AntColony::antListDraw(sf::RenderWindow & window)
{
	for (std::list<Ant>::iterator it = antList.begin(); it != antList.end(); it++)
	{
		it->draw(window);
		window.draw(it->healthBarBackgroud);
		window.draw(it->healthBar);
	}
}

void AntColony::larvaListAdd(sf::Vector2f position)
{
	Larva larva(&larvaTexture, position);
	larvaList.push_back(larva);
}

void AntColony::larvaListUpdate()
{
	std::list<Larva> newLarvas;
	for (std::list<Larva>::iterator it = larvaList.begin(); it != larvaList.end(); it++)
	{
		if (it->nextStage())
		{
			for (size_t i = 0; i < it->getNewAntsCount(); ++i)
			{
				LittleAnt littleAnt(&littleAntTexture, sf::Vector2u(4, 4), 0.1f, 100.0f, it->getPosition());
				littleAntList.push_back(littleAnt);
			}
		}
		else newLarvas.push_back(*it);
	}
	larvaList = newLarvas;
}

void AntColony::larvaListDraw(sf::RenderWindow & window)
{
	for (std::list<Larva>::iterator it = larvaList.begin(); it != larvaList.end(); it++)
	{
		it->draw(window);
	}
}

void AntColony::littleAntListGetNewPosition(std::list<Terrain>& map)
{
	std::list<LittleAnt> newLittleAnts;

	for (std::list<LittleAnt>::iterator it = littleAntList.begin(); it != littleAntList.end(); ++it)
	{
		std::cout << "Little ant pos: " << it->getPosition().x << " " << it->getPosition().y << std::endl;
		std::list<Terrain>::iterator tile = map.begin();
		std::advance(tile, ((___WIDTH___ / 50) * (it->getPosition().y / 50) + (it->getPosition().x / 50)));
		if (tile->checkTile())
			it->changeHealth(-1);
		else if (it->getHealth() < ___ANT_MAX_HEALTH___)
			it->changeHealth(1);
		it->setHealthBar(it->getHealth());
		std::cout << "Little ant HP: " << it->getHealth() << std::endl;
		if (it->getHealth() >= 0)
		{
			it->nextPosition = it->randomPosition(it->getPosition());
			++(it->age);
			if (it->age > ___ADULTHOOD___)
			{
				Ant ant(&antTexture, sf::Vector2u(4, 4), 0.1f, 100.0f, it->getPosition());
				antList.push_back(ant);
			}
			else
				newLittleAnts.push_back(*it);
		}
	}
	littleAntList = newLittleAnts;
}

void AntColony::littleAntListUpdatePosition(float deltaTime)
{
	for (std::list<LittleAnt>::iterator it = littleAntList.begin(); it != littleAntList.end(); it++)
		it->moveToFixedPosition(deltaTime, it->nextPosition);
}

void AntColony::littleAntListDraw(sf::RenderWindow & window)
{
	for (std::list<LittleAnt>::iterator it = littleAntList.begin(); it != littleAntList.end(); it++)
	{
		it->draw(window);
		window.draw(it->healthBarBackgroud);
		window.draw(it->healthBar);
	}
}

sf::Vector2f AntColony::randomPosition()
{
	return sf::Vector2f(float((rand() % (___WIDTH___ / 50)) * 50), float((rand() % (___HEIGHT___ / 50)) * 50));
}