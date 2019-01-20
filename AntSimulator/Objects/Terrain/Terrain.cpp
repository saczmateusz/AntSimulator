#include "Terrain.h"

Terrain::Terrain(Texture *texture, Vector2f position)
{
	body.setSize(Vector2f(50.0f, 50.0f));
	body.setTexture(texture);
	body.setPosition(position);

	tRect.width = texture->getSize().x / 2;
	tRect.height = texture->getSize().y;
	tRect.left = 0;

	body.setTextureRect(tRect);
	cooldown = -1;
}

Terrain::Terrain()
{
	//konstruktor domyslny, obiekt utworzony za jego pomoca bedzie obslugiwal mape symulacji
}

void Terrain::createMap(Texture *texture)
{
	float x = 0, y = 0;
	for (size_t i = 0; i < ___HEIGHT___ / 50; ++i)
	{
		for (size_t j = 0; j < ___WIDTH___ / 50; ++j)
		{
			Terrain terrain(texture, Vector2f(x, y));
			terrainMap.push_back(terrain);
			x += 50;
		}
		y += 50;
		x = 0;
	}
}

void Terrain::drawMap(RenderWindow &window)
{
	for (list<Terrain>::iterator it = terrainMap.begin(); it != terrainMap.end(); it++)
		it->draw(window);
}

void Terrain::updateMap()
{
	for (list<Terrain>::iterator it = terrainMap.begin(); it != terrainMap.end(); it++)
	{
		if (it->cooldown == 0)
			it->switchTile(false);
		else if (it->cooldown > 0)
			--(it->cooldown);
	}
}

bool Terrain::checkTile()
{
	if (cooldown == -1)
	{
		switchTile(true);
		return false;
	}
	else return true;
}

list<Terrain> &Terrain::getMap()
{
	return terrainMap;
}

void Terrain::switchTile(bool factor)
{
	tRect.left = factor * tRect.width;
	body.setTextureRect(tRect);
	if (factor)
		cooldown = Parameters::TerrainRegTime;
	else cooldown = -1;
}

bool Terrain::texRand()
{
	return rand() % 2;
}
