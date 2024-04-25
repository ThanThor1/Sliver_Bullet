#pragma once
#include "Library.h"
class Text
{
public:
	int start_count = 0;
	int photo = 0;
	int x;
	int y;
	int width;
	int height;
	TTF_Font* font;
	SDL_Texture* textTexture;
	string text;
	SDL_Color TextColor = {255,255,255};
	void loadText(string a, int x, int y);
	void loadFont(string location, int size);
};

