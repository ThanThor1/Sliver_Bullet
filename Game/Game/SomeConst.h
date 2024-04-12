#pragma once

#ifndef SOME_CONST_H
#define SOME_CONST_H


#include "Library.h"
#define NUMBER_ITEM 50
#define NUMBER_BULLET 100
#define NUMBER_ENNEMIES 50
#define BULLET_SPEED 5
#define BULLET_SPEED_SUPPORT 5
#define BULLET_SPEED_RIVAL 3
#define SPEED_RIVAL 4
#define PI 3.141592
#define NUMBER_MAX_WIDTH 40
#define NUMBER_MAX_HEIGHT 70
#define EDGE_LENGTH_BLOCK 20
#define DELAY_BULLET 120

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 1050;

enum screenstatus {
	PAUSE,
	HOME,
	FIGHT,
};
enum buff {
	NONE,
	SHIELD,
	SUPPORT,
	BULLET_X5,
	BULLET_X7,
};
enum Map {
	WAVE_1,
	WAVE_2,
	WAVE_3,
	WAVE_4,
};
enum ennemies {
	ENNEMIES_1,
	ENNEMIES_2,
	ENNEMIES_3,
	ENNEMIES_4,
};
#endif
