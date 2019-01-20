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
		Ant ant(&antTexture, Vector2u(4, 4), 0.1f, ___MOVEMENT_SPEED___, randomPosition());
		antList.push_back(ant);
	}
}

void AntColony::antListGetNewPosition(list<Terrain>& map)
{
	list<Ant>::iterator it = antList.begin();
	while (it != antList.end())
	{
		if (it->getHealth() > Parameters::AntMaxHealth)
			it->health = Parameters::AntMaxHealth;
		list<Terrain>::iterator tile = map.begin();
		advance(tile, ((___WIDTH___ / 50) * (it->getPosition().y / 50) + (it->getPosition().x / 50)));
		if (tile->checkTile())
			it->changeHealth(-1);
		else if (it->getHealth() < Parameters::AntMaxHealth)
			it->changeHealth(1);
		it->setHealthBar(it->getHealth());
		if (it->getHealth() > 0)
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
				it = antList.erase(it);
			}
		}
		else
			it = antList.erase(it);
	}
}

void AntColony::antListReproduce()
{
	for (list<Ant>::iterator it = antList.begin(); it != antList.end(); ++it)
	{
		if (it->fertility >= Parameters::AntMinFertility)
		{
			for (list<Ant>::iterator prev = antList.begin(); prev != it; ++prev)
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
	for (list<Ant>::iterator it = antList.begin(); it != antList.end(); it++)
		it->moveToFixedPosition(deltaTime, it->nextPosition);
}

void AntColony::antListDraw(RenderWindow & window)
{
	for (list<Ant>::iterator it = antList.begin(); it != antList.end(); it++)
	{
		it->draw(window);
	}
}

void AntColony::larvaListAdd(Vector2f position)
{
	Larva larva(&larvaTexture, position);
	larvaList.push_back(larva);
}

void AntColony::larvaListUpdate()
{
	list<Larva>::iterator it = larvaList.begin();
	while (it != larvaList.end())
	{
		if (it->nextStage())
		{
			for (size_t i = 0; i < it->getNewAntsCount(); ++i)
			{
				LittleAnt littleAnt(&littleAntTexture, Vector2u(4, 4), 0.1f, ___MOVEMENT_SPEED___, it->getPosition());
				littleAntList.push_back(littleAnt);
			}
			it = larvaList.erase(it);
		}
		else 
			++it;
	}
}

void AntColony::larvaListDraw(RenderWindow & window)
{
	for (list<Larva>::iterator it = larvaList.begin(); it != larvaList.end(); it++)
	{
		it->draw(window);
	}
}

void AntColony::littleAntListGetNewPosition(list<Terrain>& map)
{
	list<LittleAnt>::iterator it = littleAntList.begin();
	while (it != littleAntList.end())
	{
		if (it->getHealth() > Parameters::AntMaxHealth)
			it->health = Parameters::AntMaxHealth;
		list<Terrain>::iterator tile = map.begin();
		advance(tile, ((___WIDTH___ / 50) * (it->getPosition().y / 50) + (it->getPosition().x / 50)));
		if (tile->checkTile())
			it->changeHealth(-1);
		else if (it->getHealth() < Parameters::AntMaxHealth)
			it->changeHealth(1);
		it->setHealthBar(it->getHealth());
		if (it->getHealth() > 0)
		{
			it->nextPosition = it->randomPosition(it->getPosition());
			++(it->age);
			if (it->age > Parameters::AntAdulthoodAge)
			{
				Ant ant(&antTexture, Vector2u(4, 4), 0.1f, ___MOVEMENT_SPEED___, it->getPosition());
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
	for (list<LittleAnt>::iterator it = littleAntList.begin(); it != littleAntList.end(); it++)
		it->moveToFixedPosition(deltaTime, it->nextPosition);
}

void AntColony::littleAntListDraw(RenderWindow & window)
{
	for (list<LittleAnt>::iterator it = littleAntList.begin(); it != littleAntList.end(); it++)
	{
		it->draw(window);
	}
}

Vector2f AntColony::randomPosition()
{
	return Vector2f(float((rand() % (___WIDTH___ / 50)) * 50), float((rand() % (___HEIGHT___ / 50)) * 50));
}