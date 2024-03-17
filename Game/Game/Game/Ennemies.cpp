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
void Ennemies::loadFrame(int x1, int y1) {
	checkHit();
	if (type == ENNEMIES_1 && health>0) {
	
		E_x = x1;
		E_y = y1;
		SDL_Rect  renderQuad = { E_x, E_y , E_Width, E_Height };
		SDL_Point center    = { E_Width/2 ,0 };
		if (angle >= 15) { thu = -1; }
		if (angle <=-15) { thu =  1; }
		angle += 0.1 * thu;
		exist = true;
		SDL_RenderCopyEx(gRenderer, E_Texture, NULL , &renderQuad, angle, &center, SDL_FLIP_NONE);
		loadShoot();
		shoot();
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
			if (checkLazer()) {
				health -= player.lazer.damage;
			}
		}
	}
	if (health == 0) exist = false;
}
bool Ennemies :: checkImpact(Bullet &a) {
	if ((a.B_x + a.B_Width / 2 )>E_x && (a.B_x + a.B_Width / 2)<(E_x + E_Width) && (a.B_y + a.B_Height / 2) > E_y && (a.B_y + a.B_Height / 2) < (E_y + E_Height)) {
		return true;
	}
	return false;
}
bool Ennemies::checkLazer() {
	if (E_x>(player.lazer.O_x+ player.lazer.O_Width/12 -39) || player.lazer.O_x+39>(E_x + E_Width)) {
		return false;
	}
	if ( E_y > player.P_y) {
		return false;
	}
	return true;
}
void Ennemies::loadShoot() {
	if (type == ENNEMIES_1) {
		load_bullet_simple_time = (load_bullet_simple_time + 1) % 1001;
		if (thbullet_simple == 300) {
			thbullet_simple = 0;
		}
		if (load_bullet_simple_time == 1000) {
			bullet_simple[thbullet_simple].start_x = bullet_simple[thbullet_simple].B_x = E_x + E_Width / 2 + (E_Height+10)*sin(-angle*PI/180) - bullet_simple[thbullet_simple].B_Width / 2;
			bullet_simple[thbullet_simple].start_y = bullet_simple[thbullet_simple].B_y = E_y + ( E_Height + 10) * cos(-angle * PI / 180);
			bullet_simple[thbullet_simple].angle = angle;
			bullet_simple[thbullet_simple].slope = tan((bullet_simple[thbullet_simple].angle) * PI / 180);
			bullet_simple[thbullet_simple].exist = true;
			thbullet_simple++;
		}
	}
}
void Ennemies::shoot() {
	SDL_Point PointBulletPlayer;
	for (int i = 0; i < 300; i++) {
		if (bullet_simple[i].exist == true)
		{
			PointBulletPlayer = { bullet_simple[i].B_Width / 2, 0 };
			bullet_simple[i].render(bullet_simple[i].B_x, bullet_simple[i].B_y, NULL, bullet_simple[i].angle, &PointBulletPlayer);
		}
	}
	if (load_bullet_simple_time%2 == 0) {
		for (int i = 0; i < 300; i++) {
			if (bullet_simple[i].exist == true)
			{
				bullet_simple[i].B_y += round((1) / sqrt(1 + 1.00 * (bullet_simple[i].slope * bullet_simple[i].slope)));
				bullet_simple[i].B_x = round(bullet_simple[i].start_x + (1.000 * bullet_simple[i].start_y * bullet_simple[i].slope - bullet_simple[i].B_y * 1.000 * bullet_simple[i].slope));
			}
		}
	}
}