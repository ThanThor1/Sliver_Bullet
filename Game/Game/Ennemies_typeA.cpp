﻿#include "Ennemies_typeA.h"
#include"Declaration.h"
// di chuyển 
bool Ennemies_typeA::checkExist() {
	checkHit(health);
	if (health <= 0) {
		exist = false;
	}
	else exist = true;
	if (exist == true) {
		moveEnnemies();
	}
	return exist;
}
void Ennemies_typeA::moveEnnemies() {
	SDL_Rect cut;
	cut = { photo * width, 0, width , height };
	if (load_bullet_ennemies_A_time == 1000) {
		photo = 1;
	}
	else if (load_bullet_ennemies_A_time >= 150) {
		photo = 0;
		if (angle >= 15) { direction = -1; }
		if (angle <= -15) { direction = 1; }
		angle += 0.1 * direction;
	}
	SDL_Rect  renderQuad = { x, y , width, height };
	SDL_Point center = { width / 2 ,0 };
	SDL_RenderCopyEx(gRenderer, Texture, &cut, &renderQuad, angle, &center, SDL_FLIP_NONE);
	if (y != finish_y) {
		y++;
	}
	else {
		loadShoot();
	}
}
//sạc đạn
void Ennemies_typeA::loadShoot() {
	load_bullet_ennemies_A_time = (load_bullet_ennemies_A_time + 1) % 1001;
	if (bullet_ennemies_A_index == NUMBER_BULLET) {
		bullet_ennemies_A_index = 0;
	}
	if (load_bullet_ennemies_A_time == 1000) {
		bullet_ennemies_A[bullet_ennemies_A_index].start_x = bullet_ennemies_A[bullet_ennemies_A_index].x = x + width / 2 + (height + 10) * sin(-angle * PI / 180) - bullet_ennemies_A[bullet_ennemies_A_index].width / 2;
		bullet_ennemies_A[bullet_ennemies_A_index].start_y = bullet_ennemies_A[bullet_ennemies_A_index].y = y + (height + 10) * cos(-angle * PI / 180);
		bullet_ennemies_A[bullet_ennemies_A_index].angle = angle;
		bullet_ennemies_A[bullet_ennemies_A_index].exist = true;
		bullet_ennemies_A_index++;
	}
}

void Ennemies_typeA::free() {
	x = 0;
	y = 0;
	start_x = 0;
	start_y = 0;
	finish_x = 0;
	finish_y = 0;
	slope = 0;
	angle = 0;
	exist = false;
	health = 10;
	load_bullet_ennemies_A_time = Rand(0, 1000);
	speed = 1;
	direction = 1;
	photo = 0;
}
bool Ennemies_typeA::loadFromFile(string path) {
	//Get rid of preexisting texture
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
			width = loadedSurface->w / 2;
			height = loadedSurface->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	Texture = newTexture;
	return Texture != NULL;
}