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

#define changeParam(paramname, i, a, b) {              \
	if (change == 0)								\
		return;										\
													\
	auto& param = paramname;			\
	param = between(2, param + change, 15);			\
	parameters[i].update(param);					\
    }												\

void ControlPanel::changeMaxHealth(const int change)
{
	changeParam(Parameters::AntMaxHealth, 0, 2, 15);
}

void ControlPanel::changeLifeLenght(const int change)
{
	changeParam(Parameters::AntAvgLifeLength, 1, 20, 90);
}

void ControlPanel::changeAdulthoodAge(const int change)
{
	changeParam(Parameters::AntAdulthoodAge, 2, 2, 30);
}

void ControlPanel::changeTransformAge(const int change)
{
	changeParam(Parameters::LarvaTransformAge, 3, 2, 30);
}

void ControlPanel::changeMaxBrood(const int change)
{
	changeParam(Parameters::LarvaMaxBrood, 4, 2, 10);
}

void ControlPanel::changeFertility(const int change)
{
	changeParam(Parameters::AntMinFertility, 5, 2, 10);
}

void ControlPanel::changeTerrainRegTime(const int change)
{
	changeParam(Parameters::TerrainRegTime, 6, 1, 10);
}

void ControlPanel::draw(RenderWindow & window)
{
	window.draw(body);

	for (size_t i = 0; i < 7; ++i)
	{
		parameters[i].draw(window);

	}

}
