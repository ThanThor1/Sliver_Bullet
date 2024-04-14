#pragma once
#ifndef ENNEMIES
#define ENNEMIES
#include "Library.h"
#include "Bullet_Straight.h"
#include "SomeConst.h"
#include "Object.h"
#include "LoadAll.h"
class Ennemies : public Object
{
public:
	Object death;
	int photo = 0;
	// hàm
	bool checkImpact(Bullet_Straight& a);
	bool checkLazer();
	void checkHit(int& health);
	void getStart(int start_x = 0, int start_y = 0);
	void getFinish(int finish_x = 0, int finish_y = 0);
	void getSlopeAngle(double slope = 0, double angle = 0);
	void getDeltaxy();
	void loadExplode(Bullet_Straight& a);
	void loadBuff();
};

#endif