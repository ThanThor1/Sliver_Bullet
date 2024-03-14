#pragma once
#include "E_Bullet.h"
void E_Bullet::free()
{
	//Free texture if it exists
	if (E_B_Texture != NULL)
	{
		SDL_DestroyTexture(E_B_Texture);
		E_B_Texture = NULL;
		E_B_Width = 0;
		E_B_Height = 0;
	}
}
E_Bullet::E_Bullet()
{
	E_B_Texture = NULL;
	E_B_Width = 0;
	E_B_Height = 0;
}
E_Bullet::~E_Bullet()
{
	free();
}
void E_Bullet::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(E_B_Texture, red, green, blue);
}
void E_Bullet::setBlendMode(SDL_BlendMode blending)
{

	SDL_SetTextureBlendMode(E_B_Texture, blending);
}
void E_Bullet::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(E_B_Texture, alpha);
}
bool E_Bullet::loadFromFile(string path, SDL_Renderer* screen) {
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
		newTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			E_B_Width = loadedSurface->w;
			E_B_Height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	E_B_Texture = newTexture;
	return E_B_Texture != NULL;
}
void E_Bullet::render(int x, int y, SDL_Renderer* screen, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y , E_B_Width, E_B_Height };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(screen, E_B_Texture, clip, &renderQuad, angle, center, flip);
}
