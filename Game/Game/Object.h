#pragma once
#pragma once
#ifndef OBJECT
#define OBJECT
#include "Library.h"
#include "SomeConst.h"
class Object
{
public:
	int buff_type = NONE;
	double phongto = 0.0;
	int alpha = 255;
	//
	bool exist = false;
	//
	int dem1 = 0;
	int dem2 = 0;
	int dem3 = 0;
	//
	int damage = 5;
	//
	double start_x;
	double start_y;
	// dia chi trên màn hình lúc render ra
	int O_x = 0;
	int O_y = 0;
	// dia chi diem bat dau (chua can dùng)
	//chieu ngang và doc
	int O_Width = 0;
	int O_Height = 0;
	//Texture
	int dem = 0;
	int photo = 0;
	SDL_Texture* O_Texture = NULL;
	double slope = 0;
	double angle = 0;
	bool loadFromFile(string path);
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void render(int x, int y, SDL_Rect* clip = NULL,
		double angle = 0.0, SDL_Point* center = NULL,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	void renderBuff(int x, int y, SDL_Rect* clip = NULL,
		double angle = 0.0, SDL_Point* center = NULL,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	Object();
	void free();
	void renderbackground();
};
#endif