#pragma once
#include "Object.h"
#include "Declaration.h"
void Object::free()
{
	 flip = SDL_FLIP_NONE;
	 photo = 0;
	 damage = 0;
	// tỉ lệ in ra màn hình
	 ratio = 0.0;
	// độ trong suốt
	 alpha = 255;
	// có tồn tại hay không
	 exist = false;
	// mot so tinh chat
	 x = 0;
	 y = 0;
	 start_x = 0;
	 start_y = 0;
	 finish_x = 0;
	 finish_y = 0;
	 delta_x = 0;
	 delta_y = 0;
	 slope = 0;
	 angle = 0;
	//Texture
	 dem = 0;
	//Texture
}
Object::Object()
{
	Texture = NULL;
	width = 0;
	height = 0;
}
void Object::setColor(Uint8 red, Uint8 green, Uint8 blue)
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
bool Object::loadFromFile(string path) {
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
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	Texture = newTexture;
	return Texture != NULL;
}
void Object :: render(int x1, int y1, SDL_Rect* clip1 ,double angle1, SDL_Point* center1, SDL_RendererFlip flip1){
	SDL_Rect renderQuad = { x1, y1 , width, height };
	if (clip1 != NULL)
	{
		renderQuad.w = clip1->w;
		renderQuad.h = clip1->h;
	}
	SDL_RenderCopyEx(gRenderer, Texture, clip1, &renderQuad, angle1, center1, flip1);
}
void Object::renderbackground()
{
	dem = (dem + 1) % 3;
	photo = (photo + dem / 2) % (SCREEN_HEIGHT + 1);
	SDL_Rect renderQuad = { 0, 0 , SCREEN_WIDTH , SCREEN_HEIGHT };
	SDL_Rect cut = { 0,photo, SCREEN_WIDTH , SCREEN_HEIGHT };
	SDL_RenderCopy(gRenderer, Texture, &cut, &renderQuad);
}
