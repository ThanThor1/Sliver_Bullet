#pragma once
#ifndef ENNEMIES
#define ENNEMIES
#include "Object.h"
#include "Library.h"
#include "Bullet.h"
#include "SomeConst.h"
class Ennemies
{
public:
	//
	Bullet bullet_simple[NUMBER_BULLET];
	int thbullet_simple = 0;
	int load_bullet_simple_time = 0;
	Bullet bullet_x3[NUMBER_BULLET][3];
	int thbullet_x3 = 0;
	int load_bullet_x3_time = 0;
	Bullet bullet_x4[NUMBER_BULLET][4];
	int thbullet_x4 = 0;
	int load_bullet_x4_time = 0;
	//
	int thu = 1;
	int thu2 = 1;
	//
	double slope = 0;
	double angle = 0;
	//
	bool exist = false;
	// d?a ch? trên màn hình lúc render ra
	int E_x = 0;
	int E_y = 0;
	//
	int start_x = 0;
	int start_y = 0;
	int denta_x = 0;
	int denta_y = 0;
	// d?a ch? di?m b?t d?u (chua c?n dùng)
	double E_Start_x = 0;
	double E_Start_y = 0;
	//chi?u ngang và d?c
	int E_Width = 0;
	int E_Height = 0;
	// type
	int type;
	//Texture
	SDL_Texture* E_Texture = NULL;
	int photostatus = 0;
	int dem = 0;
	int health = 10;
	// hàm 
	void loadFrame(int x, int y);
	void loadEnnemies();
	bool loadFromFile(string path);
	void free();
	Ennemies();
	~Ennemies();
	bool checkImpact(Bullet& a);
	bool checkLazer();
	void checkHit();
	void loadShoot();
	void shoot();
};

#endif