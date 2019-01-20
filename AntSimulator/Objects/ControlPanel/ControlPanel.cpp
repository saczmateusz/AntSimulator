#include "ControlPanel.h"

ControlPanel::ControlPanel()
{
	texture.loadFromFile("Resources\\textures\\control.png");
	font.loadFromFile("Resources\\fonts\\DJB_Chalk_It_Up.ttf");

	body.setSize(Vector2f(300.0f, ___HEIGHT___));
	body.setPosition(Vector2f(___WIDTH___, 0.0f));
	body.setTexture(&texture);


	parameters[0] = TextField(font, Vector2f(910, 110), Parameters::AntMaxHealth);
	parameters[1] = TextField(font, Vector2f(910, 180), Parameters::AntAvgLifeLength);
	parameters[2] = TextField(font, Vector2f(910, 260), Parameters::AntAdulthoodAge);
	parameters[3] = TextField(font, Vector2f(910, 330), Parameters::LarvaTransformAge);
	parameters[4] = TextField(font, Vector2f(910, 400), Parameters::LarvaMaxBrood);
	parameters[5] = TextField(font, Vector2f(910, 480), Parameters::AntMinFertility);
	parameters[6] = TextField(font, Vector2f(910, 560), Parameters::TerrainRegTime);
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

void ControlPanel::adulthoodUpdate(int change)
{
	if (change && Parameters::AntAdulthoodAge < 30)
	{
		++Parameters::AntAdulthoodAge;
		parameters[2].update(Parameters::AntAdulthoodAge);
	}
	else
	{
		if (Parameters::AntAdulthoodAge >= 2)
		{
			--Parameters::AntAdulthoodAge;
			parameters[2].update(Parameters::AntAdulthoodAge);
		}
	}
}

void ControlPanel::transformUpdate(int change)
{
	if (change && Parameters::LarvaTransformAge < 30)
	{
		++Parameters::LarvaTransformAge;
		parameters[3].update(Parameters::LarvaTransformAge);
	}
	else
	{
		if (Parameters::LarvaTransformAge >= 2)
		{
			--Parameters::LarvaTransformAge;
			parameters[3].update(Parameters::LarvaTransformAge);
		}
	}
}

void ControlPanel::broodUpdate(int change)
{
	if (change && Parameters::LarvaMaxBrood < 10)
	{
		++Parameters::LarvaMaxBrood;
		parameters[4].update(Parameters::LarvaMaxBrood);
	}
	else
	{
		if (Parameters::LarvaMaxBrood >= 2)
		{
			--Parameters::LarvaMaxBrood;
			parameters[4].update(Parameters::LarvaMaxBrood);
		}
	}
}

void ControlPanel::fertilityUpdate(int change)
{
	if (change && Parameters::AntMinFertility < 20)
	{
		++Parameters::AntMinFertility;
		parameters[5].update(Parameters::AntMinFertility);
	}
	else
	{
		if (Parameters::AntMinFertility >= 1)
		{
			--Parameters::AntMinFertility;
			parameters[5].update(Parameters::AntMinFertility);
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

void ControlPanel::draw(RenderWindow & window)
{
	window.draw(body);
	
	for (size_t i = 0; i < 7; ++i)
	{
		parameters[i].draw(window);

	}

}
