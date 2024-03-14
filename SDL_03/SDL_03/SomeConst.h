#pragma once

#ifndef SOME_CONST_H
#define SOME_CONST_H


#include "Library.h"
#define NUMBER_BULLET 1000
#define NUMBER_ENNEMIES 50
#define BULLET_SPEED 5
#define BULLET_MOVE_HORIRONTAL 1
#define BULLET_SPEED_RIVAL 5
#define PI 3.141592

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1100;



enum bullet {
	BULLET_SIMPLE,
	BULLET_X5,
	BULLET_X7,
};
enum ennemies {
	ENNEMIES_1,
    ENNEMIES_2,
	ENNEMIES_3,
	ENNEMIES_4,
};
#endif