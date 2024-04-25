#pragma once
#ifndef PLAYER
#define PLAYER

#include "Library.h"
#include "SomeConst.h"
#include "Bullet_Straight.h"
#include "Object.h"
#include "Item.h"
class Ennemies;
class Player : public Object
{
public:
	Object death[10];
	int dem_death = 0;
	int delay_bullet = 120;
	double pause_screen_sensitivity[3];
	int  sensitivity_index = 0;
	int  support_dem = 0;
	int  shield_dem = 0;
	int  x5_dem = 0;
	int  x7_dem = 0;
	int  bullet_type = 0;
	//
	Object shield[5];
	int thshield = 0;
	//support
	Bullet_Straight bullet_support_1[NUMBER_BULLET];
	Bullet_Straight bullet_support_2[NUMBER_BULLET];
	int load_support_time = 0;
	int load_bullet_support_time = 0;
	int thbullet_support = 0;
	int dis_player_support = 0;
	//bullet
	Bullet_Straight bullet_simple[NUMBER_BULLET][2];
	int thbullet_simple = 0;
	Bullet_Straight bullet_x7[NUMBER_BULLET][7];
	int thbullet_x7 = 0;
	Bullet_Straight bullet_x5[NUMBER_BULLET][5];
	int thbullet_x5 = 0;
	int load_bullet_time = 0;
	//
	bool behit = false;
	int behit_dem = 0;
	int doichieu = 1;
	// khiên
	bool buff_shield = false;
	// hỗ trợ
	bool buff_support = false;
	// lazer
	bool buff_lazer = false;
	//
	bool buff_speed_bullet = false;
	// trang thai anh
	int number_of_hearts = 3;
	// hàm 
	double calculateDis(int E_x, int E_y, Object& b);
	void shootSupport();
	void determineTheTarget(int& x1, int& y1, int& x2, int& y2);
	void loadBulletSupport();
	void loadSupport();
	void loadShoot();
	void shoot();
	void loadFrame(SDL_Rect* clip = NULL,double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	bool checkLazer();
	bool checkBoom();
	bool checkHit();
	bool checkImpactBullet(Bullet_Straight& a);
	void checkImpactItem(Item& a);
	bool checkImpactShield(Bullet_Straight& a);
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	Player();
	~Player();
	void free();
};
#endif