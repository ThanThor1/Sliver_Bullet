#pragma once
#include "Bullet_Straight.h"
class Bullet_Round :public Bullet_Straight
{
public:

	Bullet_Straight  bullet_virtual;
	Bullet_Straight  bullet_around[3][3];
	//Bullet_Straight  bullet_in_edge[]
	int R=0;
	int R_increase_time = 0;
	double angle_first;
	void set();
	void RenderBullet_Round();
};

