#pragma once
#ifndef ENNEMIES
#define ENNEMIES
#include "Object.h"
#include "Library.h"
#include "Bullet.h"
class Ennemies
{
public:
	//
	Bullet bullet_simple[1000];
	int thbullet_simple = 0;
	int load_bullet_simple_time = 0;
	//
	int thu = 1;
	//
	double slope = 0;
	double angle = 0;
	//
	bool exist = false;
	// d?a ch? tr�n m�n h�nh l�c render ra
	int E_x = 0;
	int E_y = 0;
	// d?a ch? di?m b?t d?u (chua c?n d�ng)
	double E_Start_x = 0;
	double E_Start_y = 0;
	//chi?u ngang v� d?c
	int E_Width = 0;
	int E_Height = 0;
	// type
	int type;
	//Texture
	SDL_Texture* E_Texture = NULL;
	int photostatus = 0;
	int dem = 0;
	int health = 10;
	// h�m 
	void loadFrame(int x, int y);
	bool loadFromFile(string path);
	void free();
	Ennemies();
	~Ennemies();
	bool checkImpact(Bullet &a);
	bool checkLazer();
	void checkHit();
	void loadShoot();
	void shoot();
};

#endif