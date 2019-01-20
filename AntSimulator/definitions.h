#pragma once
#include <SFML\Graphics.hpp>
#include <cstdlib>
#include <list>
#include <ctime>
#include <iostream>
#include "Parameters.h"

using namespace std;
using namespace sf;

enum direction{
	___UP___,
	___DOWN___,
	___LEFT___,
	___RIGHT___
};

constexpr unsigned int ___WIDTH___ = 800;
constexpr unsigned int ___HEIGHT___ = 600;

constexpr unsigned int ___ANTS_COUNT___ = 10;
constexpr unsigned int ___SPEED___ = 70;
constexpr float ___MOVEMENT_SPEED___ = 100.0;
constexpr float ___ANT_HEALTH_BAR_WIDTH___ = 40;
constexpr float ___ANT_HEALTH_BAR_HEIGHT___ = 2;