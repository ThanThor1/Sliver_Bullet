#pragma once
#ifndef P_BULLET
#define P_BULLET
#include "Library.h"
class Bullet
{
public:
	//damage
	int damage=2;
	//
	double denta_x = 0;
	double denta_y = 0;
	//
	bool exist = false;
	//
	double start_x;
	double start_y;
	// dia chi trên màn hình lúc render ra
	int B_x;
	int B_y;
	// dia chi diem bat dau (chua can dùng)
	//chieu ngang và doc
	int B_Width = 0;
	int B_Height = 0;
	//Texture
	SDL_Texture* B_Texture = NULL;
	double slope = 0;
	double angle = 0;
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
};

#endif