#pragma once
#ifndef ENNEMIES
#define ENNEMIES
#include "Library.h"
#include "Bullet.h"
#include "SomeConst.h"
#include "Object.h"
#include"LoadAll.h"
class Ennemies
{
public:
	Object buff;
	Object death;
	int photo = 0;
	bool exist = false;
	double E_slope = 0;
	double E_angle = 0;
	int E_x = 0;
	int E_y = 0;
	int E_start_x = 0;
	int E_start_y = 0;
	int E_denta_x = 0;
	int E_denta_y = 0;
	int E_finish_x = 0;
	int E_finish_y = 0;
	int E_Width = 0;
	int E_Height = 0;
	SDL_Texture* E_Texture = NULL;
	// hàm
	bool checkImpact(Bullet& a);
	bool checkLazer();
	void checkHit(int &health);
	void getStart(int start_x = 0, int start_y = 0);
	void getFinish(int finish_x = 0, int finish_y = 0);
	void getSlopeAngle(double slope = 0, double angle = 0);
	void getDeltaxy();
	void loadExplode(Bullet &a);
	void loadBuff();
};

#endif