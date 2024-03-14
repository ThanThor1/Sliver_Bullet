#pragma once
#ifndef PLAYER
#define PLAYER
#include "Object.h"
#include "Library.h"
#include"SomeConst.h"
#include "P_Bullet.h"
class Player
{
public:
	//support
	Object support_1;
	Object support_2;
	P_Bullet bullet_support_1[1000];
	P_Bullet bullet_support_2[1000];
	int load_support_time = 0;
	int load_bullet_support_time = 0;
	int thbullet_support = 0;
	int dis_player_support = 0;
	//lazer
    Object lazer;
	int load_lazer_time = 0;
	//bullet
	P_Bullet bullet_simple[1000][2];
	int thbullet_simple = 0;
	int load_bullet_simple_time = 0;
	//
	P_Bullet bullet_x7[1000][7];
	int thbullet_x7 = 0;
	int load_bullet_x7_time = 0;
	//
	P_Bullet bullet_x5[1000][5];
	int thbullet_x5 = 0;
	int load_bullet_x5_time = 0;
	//loại đạn
    int bullet_type = 10;
	// địa chỉ trên màn hình lúc render ra
	int P_x;
	int P_y;
	// địa chỉ điểm bắt đầu (chưa cần dùng) (có thể là địa chỉ tâm)
	double P_Start_x = 0;
	double P_Start_y = 0;
	//chiều ngang và dọc
	int P_Width  =0;
	int P_Height =0;
	//Texture
	SDL_Texture* P_Texture = NULL;
	// khiên
	bool shield_bool = false;
	// hỗ trợ
	bool support_bool = false;
	// lazer
	bool lazer_bool = false;
    // trang thai anh
	int photostatus = 0;
	int dem=0;
	//
	bool exist = false;
	// máu
	int health = 10;
	// hàm 
	void shoot1();
	void determineTheTarget( int &x1, int &y1, int &x2, int &y2);
	void loadBulletSupport();
	void loadSupport();
	void loadLazer();
	void loadShoot(int x, int y, int bullet_type);
	void shoot();
	void loadFrame(int x, int y, SDL_Rect* clip = NULL,
		double angle = 0.0, SDL_Point* center = NULL,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	bool loadFromFile(string path);
	~Player();
	void free();
};
#endif