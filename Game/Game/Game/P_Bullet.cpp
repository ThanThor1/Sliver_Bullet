
#pragma once
#include "Bullet.h"
#include "Declaration.h"
void Bullet::free()
{
	//Free texture if it exists
	if (B_Texture != NULL)
	{
		SDL_DestroyTexture(B_Texture);
		B_Texture = NULL;
		B_Width = 0;
		B_Height = 0;
	}
}
Bullet::Bullet()
{
	exist = false;
	B_Texture = NULL;
	B_Width = 0;
	B_Height = 0;
}
Bullet::~Bullet()
{
	free();
}
void Bullet::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(B_Texture, red, green, blue);
}
void Bullet::setBlendMode(SDL_BlendMode blending)
{

	SDL_SetTextureBlendMode(B_Texture, blending);
}
void Bullet::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(B_Texture, alpha);
}
bool Bullet::loadFromFile(string path) {
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
			B_Width = loadedSurface->w;
			B_Height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	B_Texture = newTexture;
	return B_Texture != NULL;
}
void Bullet::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	exist = true;
	SDL_Rect renderQuad = { x, y , B_Width, B_Height };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(gRenderer, B_Texture, clip, &renderQuad, angle, center, flip);
}
