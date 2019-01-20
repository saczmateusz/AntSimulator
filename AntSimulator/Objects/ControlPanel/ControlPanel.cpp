#include "ControlPanel.h"

int between(int a, int b, int c)
{
	return max(a, min(b, c));
}

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

void ControlPanel::changeMaxHealth(const int change)
{
	if (change == 0)
		return;

	auto& param = Parameters::AntMaxHealth;
	param = between(2, param + change, 30);
	parameters[0].update(param);
}

void ControlPanel::changeLifeLenght(const int change)
{
	if (change == 0)
		return;

	auto& param = Parameters::AntAvgLifeLength;
	param = between(2, param + change, 30);
	parameters[1].update(param);
}

void ControlPanel::changeAdulthoodAge(const int change)
{
	if (change == 0)
		return;

	auto& param = Parameters::AntAdulthoodAge;
	param = between(2, param + change, 30);
	parameters[2].update(param);
}

void ControlPanel::changeTransformAge(const int change)
{
	if (change == 0)
		return;

	auto& param = Parameters::LarvaTransformAge;
	param = between(2, param + change, 30);
	parameters[3].update(param);
}

void ControlPanel::changeMaxBrood(const int change)
{
	if (change == 0)
		return;

	auto& param = Parameters::LarvaMaxBrood;
	param = between(2, param + change, 10);
	parameters[4].update(param);
}

void ControlPanel::changeFertility(const int change)
{
	if (change == 0)
		return;

	auto& param = Parameters::AntMinFertility;
	param = between(2, param + change, 10);
	parameters[5].update(param);
}

void ControlPanel::changeTerrainRegTime(const int change)
{
	auto& param = Parameters::TerrainRegTime;
	param = between(1, param + change, 30);
	parameters[6].update(param);
}

void ControlPanel::draw(RenderWindow & window)
{
	window.draw(body);
	
	for (size_t i = 0; i < 7; ++i)
	{
		parameters[i].draw(window);

	}

}
