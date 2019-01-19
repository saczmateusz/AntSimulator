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
		Ant ant(&antTexture, sf::Vector2u(4, 4), 0.1f, ___MOVEMENT_SPEED___, randomPosition());
		antList.push_back(ant);
	}
}

void AntColony::antListGetNewPosition(std::list<Terrain>& map)
{
	std::list<Ant>::iterator it = antList.begin();
	while (it != antList.end())
	{
		std::cout << "Ant age: " << it->age << std::endl;
		std::list<Terrain>::iterator tile = map.begin();
		std::advance(tile, ((___WIDTH___ / 50) * (it->getPosition().y / 50) + (it->getPosition().x / 50)));
		if (tile->checkTile())
			it->changeHealth(-1);
		else if (it->getHealth() < Parameters::AntMaxHealth)
			it->changeHealth(1);
		it->setHealthBar(it->getHealth());
		if (it->getHealth() >= 0 && it->getHealth() <= Parameters::AntMaxHealth)
		{
			if (!(it->isDying()))
			{
				it->nextPosition = it->randomPosition(it->getPosition());
				++(it->fertility);
				++(it->age);
				++it;
			}
			else
			{
				std::cout << "ant died\n";
				it = antList.erase(it);
			}
		}
		else
			it = antList.erase(it);
	}
}

void AntColony::antListReproduce()
{
	for (std::list<Ant>::iterator it = antList.begin(); it != antList.end(); ++it)
	{
		if (it->fertility >= Parameters::AntMinFertility)
		{
			for (std::list<Ant>::iterator prev = antList.begin(); prev != it; ++prev)
			{
				if (it->getPosition() == prev->getPosition() && prev->fertility >= Parameters::AntMinFertility)
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
	}
}

void AntColony::larvaListAdd(sf::Vector2f position)
{
	Larva larva(&larvaTexture, position);
	larvaList.push_back(larva);
}

void AntColony::larvaListUpdate()
{
	std::list<Larva>::iterator it = larvaList.begin();
	while (it != larvaList.end())
	{
		if (it->nextStage())
		{
			for (size_t i = 0; i < it->getNewAntsCount(); ++i)
			{
				LittleAnt littleAnt(&littleAntTexture, sf::Vector2u(4, 4), 0.1f, ___MOVEMENT_SPEED___, it->getPosition());
				littleAntList.push_back(littleAnt);
			}
			it = larvaList.erase(it);
		}
		else 
			++it;
	}
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
	std::list<LittleAnt>::iterator it = littleAntList.begin();
	while (it != littleAntList.end())
	{
		std::list<Terrain>::iterator tile = map.begin();
		std::advance(tile, ((___WIDTH___ / 50) * (it->getPosition().y / 50) + (it->getPosition().x / 50)));
		if (tile->checkTile())
			it->changeHealth(-1);
		else if (it->getHealth() < Parameters::AntMaxHealth)
			it->changeHealth(1);
		it->setHealthBar(it->getHealth());
		if (it->getHealth() >= 0 && it->getHealth() <= Parameters::AntMaxHealth)
		{
			it->nextPosition = it->randomPosition(it->getPosition());
			++(it->age);
			if (it->age > Parameters::AntAdulthoodAge)
			{
				Ant ant(&antTexture, sf::Vector2u(4, 4), 0.1f, ___MOVEMENT_SPEED___, it->getPosition());
				antList.push_back(ant);
				it = littleAntList.erase(it);
			}
			else
				++it;
		}
		else
			it = littleAntList.erase(it);
	}
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
	}
}

sf::Vector2f AntColony::randomPosition()
{
	return sf::Vector2f(float((rand() % (___WIDTH___ / 50)) * 50), float((rand() % (___HEIGHT___ / 50)) * 50));
}