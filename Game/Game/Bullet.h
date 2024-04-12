#pragma once
#ifndef P_BULLET
#define P_BULLET
#include "Library.h"
#include "Object.h"
class Bullet
{
public:
	bool phandan=false;
	Object hit;
	SDL_Point* Center = NULL;
	SDL_Rect* Clip = NULL;
	bool hit_bool = false;
	int B_damage = 0;
	int B_speed = 0;
	int B_speedPlus = 0;
	bool B_follow = true;
	//
	double B_denta_x = 0;
	double B_denta_y = 0;
	//
	bool B_exist = false;
	//
	double B_start_x = 0;
	double B_start_y = 0;
	// dia chi trên màn hình lúc render ra
	int B_x = 0;
	int B_y = 0;
	// dia chi diem bat dau (chua can dùng)
	//chieu ngang và doc
	int B_Width = 0;
	int B_Height = 0;
	//Texture
	SDL_Texture* B_Texture = NULL;
	double B_slope = 0;
	double B_angle = 0;
	bool loadFromFile(string path);
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void render(int x, int y, SDL_Rect* clip = NULL,
		double angle = 0.0, SDL_Point* center = NULL,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	Bullet();
	~Bullet();
	void free();
	void RenderBulletSlope();
	void RenderBulletAngle();
	void RenderBulletStraight();
};
#endif
