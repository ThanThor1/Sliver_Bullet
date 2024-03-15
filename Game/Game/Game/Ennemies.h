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
	bool exist = false;
	// d?a ch? trên màn hình lúc render ra
	int E_x = 0;
	int E_y = 0;
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
	void loadFrame(int x, int y, SDL_Rect* clip = NULL,
		double angle = 0.0, SDL_Point* center = NULL,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	bool loadFromFile(string path);
	void free();
	Ennemies();
	~Ennemies();
	bool checkImpact(Bullet &a);
	bool checkLazer();
	void checkHit();

};

#endif