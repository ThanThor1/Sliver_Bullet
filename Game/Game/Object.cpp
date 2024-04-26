#pragma once
#include "Object.h"
#include "Declaration.h"
void Object::free()
{
	direction = 1;
	red = 0;
	green = 0;
	blue = 0;
	dem1 = 0;
	dem2 = 0;
	frameth = 1;
	frame = 1;
	slope = 0;
	angle = 0;
	flip = SDL_FLIP_NONE;
	photo = 0;
	damage = 5;
	// tỉ lệ in ra màn hình
	ratio = 0.0;
	// độ trong suốt
	alpha = 255;
	// có tồn tại hay không
    exist = false;
	// mot so tinh chat
	center_x = 0;
	center_y = 0;
	center_start_x = 0;
	center_start_y = 0;
	center_finish_x = 0;
	center_finish_y = 0;
	center_delta_x = 0;
	center_delta_y = 0;
	//chieu ngang và doc
	dem = 0;
	//Texture
}
Object::Object()
{
	Texture = NULL;
	width = 0;
	height = 0;
}
void Object::setColor()
{
	SDL_SetTextureColorMod(Texture, red, green, blue);
}
void Object::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(Texture, blending);
}
void Object::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(Texture, alpha);
}
bool Object::loadFromFile(string path, int frame1) {
	//Get rid of preexisting texture
	free();
	//The final texture
	SDL_Texture* newTexture = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 180, 180, 180));
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			frame = frame1;
			width = loadedSurface->w/frame;
			height = loadedSurface->h;
			for (int i = 1; i <=frame; i++) {
				cut[i] = { (i-1)*width,0, width, height};
			}
			center = { width / 2, height / 2 };
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	Texture = newTexture;
	return Texture != NULL;
}
void Object :: render(SDL_Point* a){
	setAlpha(alpha);
	if (a == NULL) {
		center = { int(width / 2 ),int(height / 2) };
	}
	else center = *a;
	put = { center_x - center.x, center_y - center.y,width,height };
	SDL_RenderCopyEx(gRenderer, Texture, &cut[frameth], &put, angle, &center, flip);
}
void Object::renderRatio(SDL_Point* a) {
	setAlpha(alpha);
	if (a == NULL) {
		center = { int(width / 2 * ratio),int(height / 2 * ratio)};
	}
	else center = *a;
	put = { int(center_x - center.x ), int(center_y - center.y ),int(width * ratio),int(height * ratio) };
	SDL_RenderCopyEx(gRenderer, Texture, &cut[frameth], &put, angle, &center, flip);
}
void Object::renderFlexible(SDL_Rect* cut1, SDL_Rect* put1) {

	SDL_RenderCopyEx(gRenderer, Texture,cut1, put1, angle, &center, flip);
}
void Object::renderbackground()
{
	dem = (dem + 1) % 3;
	photo = (photo - dem / 2)% (SCREEN_HEIGHT + 1);
	if (photo == -1) {
		photo = SCREEN_HEIGHT - 1;
	}
	SDL_Rect renderQuad = { 0, 0 , SCREEN_WIDTH , SCREEN_HEIGHT };
	SDL_Rect cut = { 0,photo, SCREEN_WIDTH , SCREEN_HEIGHT };
	SDL_RenderCopy(gRenderer, Texture, &cut, &renderQuad);
}

