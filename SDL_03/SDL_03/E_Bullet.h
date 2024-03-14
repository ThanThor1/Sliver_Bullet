#pragma once
#ifndef E_BULLET
#define E_BULLET
#include "Library.h"
#include"SomeConst.h"
class E_Bullet
{
public:
	bool exist;
	//
	int bullettype = 0;
	// d?a ch? trên màn hình lúc render ra
	int E_B_x;
	int E_B_y;
	// d?a ch? di?m b?t d?u (chua c?n dùng)
	double E_B_Start_x = 0;
	double E_B_Start_y = 0;
	//chi?u ngang và d?c
	int E_B_Width = 0;
	int E_B_Height = 0;
	//Texture
	SDL_Texture* E_B_Texture = NULL;
	bool loadFromFile(string path,SDL_Renderer* screen);
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void render(int x, int y, SDL_Renderer* screen, SDL_Rect* clip = NULL,
		double angle = 0.0, SDL_Point* center = NULL,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	E_Bullet();
	~E_Bullet();
	void free();
	void checkdistance();
};
#endif
