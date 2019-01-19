#include "ControlPanel.h"

ControlPanel::ControlPanel()
{
	texture.loadFromFile("Resources\\textures\\control.png");
	font.loadFromFile("Resources\\fonts\\DJB_Chalk_It_Up.ttf");

	body.setSize(sf::Vector2f(300.0f, ___HEIGHT___));
	body.setPosition(sf::Vector2f(___WIDTH___, 0.0f));
	body.setTexture(&texture);


	parameters[0] = TextField(font, sf::Vector2f(910, 110), Parameters::AntMaxHealth);
	parameters[1] = TextField(font, sf::Vector2f(910, 180), Parameters::AntAvgLifeLength);
	parameters[2] = TextField(font, sf::Vector2f(910, 260), Parameters::AntAdulthoodAge);
	parameters[3] = TextField(font, sf::Vector2f(910, 330), Parameters::LarvaTransformAge);
	parameters[4] = TextField(font, sf::Vector2f(910, 400), Parameters::LarvaMaxBrood);
	parameters[5] = TextField(font, sf::Vector2f(910, 480), Parameters::AntMinFertility);
	parameters[6] = TextField(font, sf::Vector2f(910, 560), Parameters::TerrainRegTime);
}

ControlPanel::~ControlPanel()
{
}

void ControlPanel::healthUpdate(bool change)
{
	if (change && Parameters::AntMaxHealth < 15)
	{
		++Parameters::AntMaxHealth;
		parameters[0].update(Parameters::AntMaxHealth);
	}
	else
	{
		if (Parameters::AntMaxHealth >= 2)
		{
			--Parameters::AntMaxHealth;
			parameters[0].update(Parameters::AntMaxHealth);
		}
	}
}

void ControlPanel::lifeLengthUpdate(int change)
{
	if (change && Parameters::AntAvgLifeLength < 90)
	{
		++Parameters::AntAvgLifeLength;
		parameters[1].update(Parameters::AntAvgLifeLength);
	}
	else
	{
		if (Parameters::AntAvgLifeLength >= 20)
		{
			--Parameters::AntAvgLifeLength;
			parameters[1].update(Parameters::AntAvgLifeLength);
		}
	}
}

void ControlPanel::terrainRegUpdate(int change)
{
	if (change && Parameters::TerrainRegTime < 30)
	{
		++Parameters::TerrainRegTime;
		parameters[6].update(Parameters::TerrainRegTime);
	}
	else
	{
		if (Parameters::TerrainRegTime >= 1)
		{
			--Parameters::TerrainRegTime;
			parameters[6].update(Parameters::TerrainRegTime);
		}
	}
}

void ControlPanel::draw(sf::RenderWindow & window)
{
	window.draw(body);
	
	for (size_t i = 0; i < 7; ++i)
	{
		parameters[i].draw(window);

	}

}
