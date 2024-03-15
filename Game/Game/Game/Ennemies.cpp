#pragma once
#include"Ennemies.h"
#include"Bullet.h"
#include"Player.h"
#include"Declaration.h"
void Ennemies::free()
{
	//Free texture if it exists
	if (E_Texture != NULL)
	{
		SDL_DestroyTexture(E_Texture);
		E_Texture = NULL;
		E_Width = 0;
		E_Height = 0;
	}
}
Ennemies::Ennemies()
{
	exist = false;
	E_x = 0;
	E_y = 0;
	double E_Start_x = 0;
	double E_Start_y = 0;
	int E_Width = 0;
	int E_Height = 0;
	int type = -1;
	SDL_Texture* E_Texture = NULL;
	int photostatus = 0;
	int dem = 0;
}
Ennemies::~Ennemies()
{
	free();
}
bool Ennemies::loadFromFile(string path) {
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
			E_Width = loadedSurface->w;
			E_Height = loadedSurface->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	E_Texture = newTexture;
	return E_Texture != NULL;
}
void Ennemies::loadFrame(int x1, int y1, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	checkHit();
	if (type == ENNEMIES_1 && health > 0) {
		E_x = x1;
		E_y = y1;
		SDL_Rect renderQuad = { E_x, E_y , E_Width, E_Height };
		if (clip != NULL)
		{
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
		}
		SDL_RenderCopyEx(gRenderer, E_Texture, clip, &renderQuad, angle, center, flip);
		exist = true;
	}
}
void Ennemies::checkHit() {
	if (health > 0) {
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1; j++) {
				if (player.bullet_simple[i][j].exist == true) {
					if (checkImpact(player.bullet_simple[i][j])) {
						health -= player.bullet_simple[i][j].damage;
						player.bullet_simple[i][j].exist = false;
					}
				}
			}
		}
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 5; j++) {
				if (player.bullet_x5[i][j].exist == true) {
					if (checkImpact(player.bullet_x5[i][j])) {
						health -= player.bullet_x5[i][j].damage;
						player.bullet_x5[i][j].exist = false;
					}
				}
			}
		}
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 7; j++) {
				if (player.bullet_x7[i][j].exist == true) {
					if (checkImpact(player.bullet_x7[i][j])) {
						health -= player.bullet_x7[i][j].damage;
						player.bullet_x7[i][j].exist = false;
					}
				}
			}
		}
		for (int i = 0; i < 1000; i++) {
			if (player.bullet_support_1[i].exist == true) {
				if (checkImpact(player.bullet_support_1[i])) {
					health -= player.bullet_support_1[i].damage;
					player.bullet_support_1[i].exist = false;
				}
			}
			if (player.bullet_support_2[i].exist == true) {
				if (checkImpact(player.bullet_support_2[i])) {
					health -= player.bullet_support_2[i].damage;
					player.bullet_support_2[i].exist = false;
				}
			}
		}
		if (player.lazer.exist == true) {
			cout << E_y << " " << player.P_y << " ";
			if (checkLazer()) {
				health -= player.lazer.damage;
			}
		}
	}
}
bool Ennemies :: checkImpact(Bullet &a) {
	if ((a.B_x + a.B_Width / 2 )>E_x && (a.B_x + a.B_Width / 2)<(E_x + E_Width) && (a.B_y + a.B_Height / 2) > E_y && (a.B_y + a.B_Height / 2) < (E_y + E_Height)) {
		return true;
	}
	return false;
}
bool Ennemies::checkLazer() {
	if (E_x>(player.lazer.O_x+ player.lazer.O_Width/12) || player.lazer.O_x>(E_x + E_Width)) {
		
		return false;
	}
	if ( E_y > player.P_y) {
		return false;
	}
	return true;
}
