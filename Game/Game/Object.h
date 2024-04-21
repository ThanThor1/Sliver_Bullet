#pragma once
#ifndef OBJECT
#define OBJECT
#include "Library.h"
#include "SomeConst.h"
class Object
{
public:
	int dem1 = 0;
	int dem2 = 0;
	int dem3 = 0;
	int flip = SDL_FLIP_NONE;
	int photo = 0;
	int damage = 5;
	// tỉ lệ in ra màn hình
	double ratio = 0.0;
	// độ trong suốt
	int alpha = 255;
	// có tồn tại hay không
	bool exist = false;
	// mot so tinh chat
	int x = 0;
	int y = 0;
	int start_x=0;
	int start_y=0;
	int finish_x=0;
	int finish_y=0;
	int delta_x = 0;
	int delta_y = 0;
	int center_y = 0;
	int center_x = 0;
	double slope = 0;
	double angle = 0;
	//chieu ngang và doc
	int width = 0;
	int height = 0;
	//Texture
	int dem = 0;
	//Texture
	SDL_Texture* Texture = NULL;
	bool loadFromFile(string path);
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void render(int x1, int y1, SDL_Rect* clip1 = NULL,
		double angle1 = 0.0, SDL_Point* center1 = NULL,
		 double ratio =0.0, SDL_RendererFlip flip1 = SDL_FLIP_NONE);
	Object();
	void free();
	void renderbackground();
};
#endif