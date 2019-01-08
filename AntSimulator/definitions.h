#pragma once
#include <SFML\Graphics.hpp>
#include <cstdlib>
#include <list>
#include <ctime>
#include <iostream>
constexpr char ___UP___ = 0;
constexpr char ___DOWN___ = 1;
constexpr char ___LEFT___ = 2;
constexpr char ___RIGHT___ = 3;

constexpr unsigned int ___WIDTH___ = 800;
constexpr unsigned int ___HEIGHT___ = 600;

constexpr unsigned int ___ANTS_COUNT___ = 10;
constexpr unsigned int ___LARVA_TRANSFORM_TIME___ = 5;
constexpr unsigned int ___MAX_TRANSFORM_COUNT___ = 3;
constexpr unsigned int ___ADULTHOOD___ = 7;
constexpr unsigned int ___MIN_FERTILITY___ = 3;
constexpr int ___ANT_MAX_HEALTH___ = 5;
constexpr float ___ANT_HEALTH_BAR_WIDTH___ = 40;
constexpr float ___ANT_HEALTH_BAR_HEIGHT___ = 2;