#pragma once
#ifndef PLAYER
#define PLAYER

#include "Library.h"
#include "SomeConst.h"
#include "Bullet.h"
#include "Object.h"
class Ennemies;
class Player
{
public:
	double sensitivity[3];
	int sensitivity_index = 0;
	int  support_dem = 0;
	int  shield_dem = 0;
	int  x5_dem = 0;
	int  x7_dem = 0;
	int bullet_type = 0;
	//
	Object shield[5];
	int thshield = 0;
	//support
	Object support_1;
	Object support_2;
	Bullet bullet_support_1[ NUMBER_BULLET];
	Bullet bullet_support_2[ NUMBER_BULLET];
	int load_support_time = 0;
	int load_bullet_support_time = 0;
	int thbullet_support = 0;
	int dis_player_support = 0;
	//lazer
	Object lazer;
	int load_lazer_time = 0;
	//bullet
	Bullet bullet_simple[ NUMBER_BULLET][2];
	int thbullet_simple = 0;
	Bullet bullet_x7[ NUMBER_BULLET][7];
	int thbullet_x7 = 0;
	Bullet bullet_x5[ NUMBER_BULLET][5];
	int thbullet_x5 = 0;
	int load_bullet_time = 0;
	// địa chỉ trên màn hình lúc render ra
	int P_x = 350;
	int P_y = 700;
	// địa chỉ điểm bắt đầu (chưa cần dùng) (có thể là địa chỉ tâm)
	double P_Start_x = 0;
	double P_Start_y = 0;
	//chiều ngang và dọc
	int P_Width = 0;
	int P_Height = 0;
	//Texture
	SDL_Texture* P_Texture = NULL;
	// khiên
	bool buff_shield = false;
	// hỗ trợ
	bool buff_support = false;
	// lazer
	bool buff_lazer = false;
	// trang thai anh
	int photostatus = 0;
	int number_of_hearts = 1;
	// 
	bool exist = false;
	// hàm 
	double calculateDis(int E_x, int E_y, int E_Width, int E_Height, Object& b);
	void shootSupport();
	void determineTheTarget(int& x1, int& y1, int& x2, int& y2);
	void loadBulletSupport();
	void loadSupport();
	void loadLazer();
	void loadShoot();
	void shoot();
	void loadFrame(SDL_Rect* clip = NULL,
		double angle = 0.0, SDL_Point* center = NULL,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	bool loadFromFile(string path);
	void checkHit();
	bool checkImpactBullet(Bullet& a);
	bool checkImpactItem(Object& a);
	bool checkImpactShield(Bullet& a);
	Player();
	~Player();
	void free();
};
#endif