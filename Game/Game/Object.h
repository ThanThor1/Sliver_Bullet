#pragma once
#ifndef OBJECT
#define OBJECT
#include "Library.h"
#include "SomeConst.h"
class Object
{
public:
	int direction = 1;
	SDL_Rect cut[10];
	SDL_Rect put;
	SDL_Point center;
	int red=0;
	int green=0;
	int blue=0;
	int dem1 = 0;
	int dem2 = 0;
	int frameth = 1;
	int frame = 1;
	double slope = 0;
	double angle = 0;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	int photo = 0;
	int damage = 5;
	// tỉ lệ in ra màn hình
	double ratio = 0.0;
	// độ trong suốt
	int alpha = 255;
	// có tồn tại hay không
	bool exist = false;
	// mot so tinh chat
	int center_x= 0;
	int center_y= 0;
	int center_start_x= 0;
	int center_start_y= 0;
	int center_finish_x= 0;
	int center_finish_y= 0;
	int center_delta_x = 0;
	int center_delta_y = 0;
	//chieu ngang và doc
	int width = 0;
	int height = 0;
	//Texture
	int dem = 0;
	//Texture
	SDL_Texture* Texture = NULL;
	bool loadFromFile(string path, int frame1);
	void setColor();
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void render(SDL_Point* a  = NULL);
	void renderRatio(SDL_Point* a = NULL);
	void renderFlexible(SDL_Rect* cut, SDL_Rect* put);
	Object();
	void free();
	void renderbackground();
};
#endif