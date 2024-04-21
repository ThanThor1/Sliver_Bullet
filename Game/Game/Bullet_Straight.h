#pragma once
#ifndef P_BULLET
#define P_BULLET
#include "Library.h"
#include "Object.h"
class Bullet_Straight : public Object
{
public:
	Object hit;
	SDL_Point* Center = NULL;
	SDL_Rect* Clip = NULL;
	bool good = false;
	bool hit_bool = false;
	int damage = 0;
	int speed = 10;
	int speedPlus = 3;
	bool follow = true;
	bool loadFromFile(string path);
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
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
