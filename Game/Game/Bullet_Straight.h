#pragma once
#ifndef P_BULLET
#define P_BULLET
#include "Library.h"
#include "Object.h"
class Bullet_Straight : public Object
{
public:
	Object hit;
	int delay_bullet = 0;
	SDL_Point* Center = NULL;
	SDL_Rect* Clip = NULL;
	bool good = false;
	bool hit_bool = false;
	int damage = 0;
	int speed = 1;
	int speedPlus = 3;
	bool follow = true;
	Bullet_Straight();
	~Bullet_Straight();
	void free();
	void RenderBullet_StraightSlope();
	void RenderBullet_StraightAngle();
	void RenderBullet_Straight();
	void RenderBullet_FollowSlope();
	int SolveDistance();
	void checkOutScreen();
};
#endif
