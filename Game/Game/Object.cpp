#pragma once
#include "Object.h"
#include "Declaration.h"
void Object::free()
{
	//Free texture if it exists
	if (O_Texture != NULL)
	{
		SDL_DestroyTexture(O_Texture);
		O_Texture = NULL;
		O_Width = 0;
		O_Height = 0;
	}
}
Object::Object()
{
	O_Texture = NULL;
	O_Width = 0;
	O_Height = 0;
}
Object::~Object()
{
	free();
}
void Object::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(O_Texture, red, green, blue);
}
void Object::setBlendMode(SDL_BlendMode blending)
{

	SDL_SetTextureBlendMode(O_Texture, blending);
}
void Object::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(O_Texture, alpha);
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
			O_Width = loadedSurface->w;
			O_Height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	O_Texture = newTexture;
	return O_Texture != NULL;
}
void Object::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	exist = true;
	SDL_Rect renderQuad = { x, y , O_Width, O_Height };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(gRenderer, O_Texture, clip, &renderQuad, angle, center, flip);
}
