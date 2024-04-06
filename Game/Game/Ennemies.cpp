#pragma once
#include"Ennemies.h"
#include"Declaration.h"
void Ennemies::getStart(int start_x, int start_y) {
	E_x = E_start_x = start_x;
	E_y = E_start_y = start_y;
}
void Ennemies::getFinish(int finish_x, int finish_y) {
	E_finish_x = finish_x;
	E_finish_y = finish_y;
}
void  Ennemies::getSlopeAngle(double slope, double angle) {
	E_slope = slope;
	E_angle = angle;
}
void  Ennemies::getDeltaxy() {
	E_denta_x = E_finish_x - E_start_x;
	E_denta_y = E_finish_y - E_start_y;
}
bool Ennemies::loadFromFile(string path) {
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
void Ennemies::checkHit(int &health) {
	if (health > 0) {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 2; j++) {
				if (player.bullet_simple[i][j].B_exist == true) {
					if (checkImpact(player.bullet_simple[i][j])) {
						health -= player.bullet_simple[i][j].B_damage;
						player.bullet_simple[i][j].B_exist = false;
					}
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 5; j++) {
				if (player.bullet_x5[i][j].B_exist == true) {
					if (checkImpact(player.bullet_x5[i][j])) {
						health -= player.bullet_x5[i][j].B_damage;
						player.bullet_x5[i][j].B_exist = false;
					}
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 7; j++) {
				if (player.bullet_x7[i][j].B_exist == true) {
					if (checkImpact(player.bullet_x7[i][j])) {
						health -= player.bullet_x7[i][j].B_damage;
						player.bullet_x7[i][j].B_exist = false;
					}
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			if (player.bullet_support_1[i].B_exist == true) {
				if (checkImpact(player.bullet_support_1[i])) {
					health -= player.bullet_support_1[i].B_damage;
					player.bullet_support_1[i].B_exist = false;
				}
			}
			if (player.bullet_support_2[i].B_exist == true) {
				if (checkImpact(player.bullet_support_2[i])) {
					health -= player.bullet_support_2[i].B_damage;
					player.bullet_support_2[i].B_exist = false;
				}
			}
		}
		if (player.lazer.exist == true) {
			if (checkLazer()) {
				health -= player.lazer.damage;
			}
		}
	}
	if (death.exist==false && health<=0) {
		SDL_Rect a[7];
		for (int i = 0; i < 7; i++) {
			a[i] = {i * 140, 0, 140, 140};
		}
		death.render(E_x+E_Width/2-70, E_y + E_Height / 2 - 70, &a[death.photo / 10]);
		death.photo = (death.photo + 1) % 72;
		if (death.photo > 70) {
			death.exist = true;
		}
	}
}
bool Ennemies::checkImpact(Bullet& a) {
	if ((a.B_x + a.B_Width / 2) > E_x && (a.B_x + a.B_Width / 2) < (E_x + E_Width) && (a.B_y + a.B_Height / 2) > E_y && (a.B_y + a.B_Height / 2) < (E_y + E_Height)) {
		return true;
	}
	return false;
}
bool Ennemies::checkLazer() {
	if (E_x > (player.lazer.O_x + player.lazer.O_Width / 12 - 39) || player.lazer.O_x + 39 > (E_x + E_Width)) {
		return false;
	}
	if (E_y > player.P_y) {
		return false;
	}
	return true;
}
