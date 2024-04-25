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
	void checkHit(int& health);
	void getStart(int center_start_x = 0, int center_start_y = 0);
	void getFinish(int center_finish_x = 0, int center_finish_y = 0);
	void getSlopeAngle(double slope = 0, double angle = 0);
	void getDeltaxy();
	void loadExplode(Bullet_Straight& a);
	void loadBuff();
};

#endif