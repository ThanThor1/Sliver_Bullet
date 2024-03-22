#pragma once
#include"Ennemies.h"
#include"Bullet.h"
#include"Player.h"
#include"Declaration.h"
void Ennemies::free()
{
	if (E_Texture != NULL) {
		SDL_DestroyTexture(E_Texture);
		E_Texture != NULL;
	}
	E_Width = 0;
	E_Height = 0;
	thbullet_simple = 0;
	load_bullet_simple_time = 0;
	thu = 1;
	slope = 0;
	angle = 0;
	exist = false;
	E_x = 0;
	E_y = 0;
	E_Start_x = 0;
	E_Start_y = 0;
	int type = 0;
	photostatus = 0;
	dem = 0;
	health = 10;
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
	if (type == ENNEMIES_1 && health > 0) {
		E_x = x1;
		E_y = y1;
		SDL_Rect  renderQuad = { E_x, E_y , E_Width, E_Height };
		SDL_Point center = { E_Width / 2 ,0 };
		if (angle >= 15) { thu = -1; }
		if (angle <= -15) { thu = 1; }
		angle += 0.1 * thu;
		exist = true;
		SDL_RenderCopyEx(gRenderer, E_Texture, NULL, &renderQuad, angle, &center, SDL_FLIP_NONE);
		loadShoot();
	}
	if (type == ENNEMIES_2 && health > 0) {
		E_x = x1;
		E_y = y1;
		SDL_Rect  renderQuad = { E_x, E_y , E_Width, E_Height };
		SDL_Point center = { E_Width / 2 ,0 };
		if (angle >= 15) { thu = -1; }
		if (angle <= -15) { thu = 1; }
		angle += 0.1 * thu;
		exist = true;
		SDL_RenderCopyEx(gRenderer, E_Texture, NULL, &renderQuad, angle, &center, SDL_FLIP_NONE);
		loadShoot();
	}
	if (type == ENNEMIES_4 && health > 0 && (thu != -1)) {
		exist = true;
		start_x = E_x = x1;
		start_y = E_y = y1;
		denta_y = 2.0;
		denta_x = 6.0;
		slope = 1.0 * denta_y / denta_x;
		thu = -1;
	}
	loadEnnemies();
	shoot();
}
void Ennemies::loadEnnemies() {
	if (type == ENNEMIES_4) {
		SDL_Rect  renderQuad = { E_x, E_y , E_Width, E_Height };
		if (angle >= 360) { angle = 0; }
		angle += 0.1;
		SDL_RenderCopyEx(gRenderer, E_Texture, NULL, &renderQuad, angle, NULL, SDL_FLIP_NONE);
		loadShoot();
		if (E_x > 0 && E_x < (SCREEN_WIDTH - E_Width)) {
			if (E_y > 0 && E_y < (SCREEN_HEIGHT - E_Height)) {
				thu2 = 1;
			}
		}
		if ((E_x <= 0 || E_x >= SCREEN_WIDTH - E_Width) && thu2 == 1) {
			denta_x = -denta_x;
			start_x = E_x;
			start_y = E_y;
			thu2 = -1;
		}
		if ((E_y <= 0 || E_y >= SCREEN_HEIGHT - E_Height) && thu2 == 1) {
			denta_y = -denta_y;
			start_x = E_x;
			start_y = E_y;
			thu2 = -1;
		}
		/*cout << denta_x << " " << denta_y << " ";*/
		slope = 1.0 * (denta_y) / (denta_x);
		/*cout << E_x << " " << E_y<<" "<<slope << endl;*/
		if (denta_y == 0 && denta_x > 0) {
			E_x += SPEED_RIVAL;
		}
		else if (denta_y == 0 && denta_x < 0) {
			E_x -= SPEED_RIVAL;
		}
		else if (denta_y > 0 && denta_x == 0) {
			E_y += SPEED_RIVAL;
		}
		else if (denta_y < 0 && denta_x == 0) {
			E_y -= SPEED_RIVAL;
		}
		else {
			if (slope >= 1) {
				E_y += round((SPEED_RIVAL) / sqrt(1 + 1.00 / (slope * slope))) * denta_x / abs(denta_x);
				E_x = round((E_y + 1.000 * start_x * slope - start_y * 1.000) / slope);
			}
			else if ((slope <= 1) && (slope >= -1)) {
				E_x += round((SPEED_RIVAL) / sqrt(1 + 1.00 * slope * slope)) * denta_x / abs(denta_x);
				E_y = round((E_x)*slope + start_y * 1.000 - 1.000 * start_x * slope);
			}
			else if ((slope <= -1)) {
				E_y -= round((SPEED_RIVAL) / sqrt(1 + 1.00 / (slope * slope))) * denta_x / abs(denta_x);
				E_x = round((E_y + 1.000 * start_x * slope - start_y * 1.000) / slope);
			}
		}
		loadShoot();
	}
}
void Ennemies::checkHit() {
	if (health > 0) {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 1; j++) {
				if (player.bullet_simple[i][j].exist == true) {
					if (checkImpact(player.bullet_simple[i][j])) {
						health -= player.bullet_simple[i][j].damage;
						player.bullet_simple[i][j].exist = false;
					}
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 5; j++) {
				if (player.bullet_x5[i][j].exist == true) {
					if (checkImpact(player.bullet_x5[i][j])) {
						health -= player.bullet_x5[i][j].damage;
						player.bullet_x5[i][j].exist = false;
					}
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 7; j++) {
				if (player.bullet_x7[i][j].exist == true) {
					if (checkImpact(player.bullet_x7[i][j])) {
						health -= player.bullet_x7[i][j].damage;
						player.bullet_x7[i][j].exist = false;
					}
				}
			}
		}
		for (int i = 0; i < 100; i++) {
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
void Ennemies::loadShoot() {
	if (type == ENNEMIES_1) {
		load_bullet_simple_time = (load_bullet_simple_time + 1) % 1001;
		if (thbullet_simple == NUMBER_BULLET) {
			thbullet_simple = 0;
		}
		if (load_bullet_simple_time == 1000) {
			bullet_simple[thbullet_simple].start_x = bullet_simple[thbullet_simple].B_x = E_x + E_Width / 2 + (E_Height + 10) * sin(-angle * PI / 180) - bullet_simple[thbullet_simple].B_Width / 2;
			bullet_simple[thbullet_simple].start_y = bullet_simple[thbullet_simple].B_y = E_y + (E_Height + 10) * cos(-angle * PI / 180);
			bullet_simple[thbullet_simple].angle = angle;
			bullet_simple[thbullet_simple].slope = tan((bullet_simple[thbullet_simple].angle) * PI / 180);
			bullet_simple[thbullet_simple].exist = true;
			thbullet_simple++;
		}
	}
	if (type == ENNEMIES_2) {
		load_bullet_x3_time = (load_bullet_x3_time + 1) % 1001;
		if (thbullet_x3 == NUMBER_BULLET) {
			thbullet_x3 = 0;
		}
		if (load_bullet_x3_time == 1000) {
			int a = -20;
			for (int i = 0; i < 3; i++) {
				bullet_x3[thbullet_x3][i].start_x = bullet_x3[thbullet_x3][i].B_x = E_x + E_Width / 2 + (E_Height + 10) * sin(-angle * PI / 180) - bullet_x3[thbullet_x3][i].B_Width / 2;
				bullet_x3[thbullet_x3][i].start_y = bullet_x3[thbullet_x3][i].B_y = E_y + (E_Height + 10) * cos(-angle * PI / 180);
				bullet_x3[thbullet_x3][i].angle = angle + a;
				bullet_x3[thbullet_x3][i].slope = tan((bullet_x3[thbullet_x3][i].angle) * PI / 180);
				bullet_x3[thbullet_x3][i].exist = true;
				a += 20;
			}
			thbullet_x3++;
		}
	}
	if (type == ENNEMIES_4) {
		load_bullet_x4_time = (load_bullet_x4_time + 1) % 1001;
		if (thbullet_x4 == NUMBER_BULLET) {
			thbullet_x4 = 0;
		}
		if (load_bullet_x4_time == 1000) {
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> dis(-90, 90);
			int a = dis(gen);
			for (int i = 0; i < 4; i++) {
				bullet_x4[thbullet_x4][i].start_x = bullet_x4[thbullet_x4][i].B_x = E_x - 10;
				bullet_x4[thbullet_x4][i].start_y = bullet_x4[thbullet_x4][i].B_y = E_y - 90;
				bullet_x4[thbullet_x4][i].angle = a;
				if (a >= 0 && a <= 90) {
					bullet_x4[thbullet_x4][i].slope = 1.0 / tan(-a * 1.0 * PI / 180);
				}
				else if (a >= 90 && a <= 270) {
					bullet_x4[thbullet_x4][i].slope = 1.0 / tan((180 - a) * 1.0 * PI / 180);
				}
				else {
					bullet_x4[thbullet_x4][i].slope = 1.0 / tan((360 - a) * 1.0 * PI / 180);
				}
				//
				if (a == 0) {
					bullet_x4[thbullet_x4][i].denta_x = 0;
					bullet_x4[thbullet_x4][i].denta_y = 1;
				}
				else if (a == 90) {
					bullet_x4[thbullet_x4][i].denta_y = 0;
					bullet_x4[thbullet_x4][i].denta_x = -1;
				}
				else if (a == 180) {
					bullet_x4[thbullet_x4][i].denta_x = 0;
					bullet_x4[thbullet_x4][i].denta_y = -1;
				}
				else if (a == 270) {
					bullet_x4[thbullet_x4][i].denta_y = 0;
					bullet_x4[thbullet_x4][i].denta_x = 1;
				}
				//
				if (a > 0 && a < 180) {
					bullet_x4[thbullet_x4][i].denta_x = -1;
					bullet_x4[thbullet_x4][i].denta_y = 1;
				}
				else if (a > 180 && a < 360) {
					bullet_x4[thbullet_x4][i].denta_x = 1;
					bullet_x4[thbullet_x4][i].denta_y = 1;
				}
				a += 90;
				if (a >= 360) {
					a = a - 360;
				}
				bullet_x4[thbullet_x4][i].exist = true;
			}
			thbullet_x4++;
		}
	}
}
void Ennemies::shoot() {
	SDL_Point PointBullet1;
	for (int i = 0; i < NUMBER_BULLET; i++) {
		if (bullet_simple[i].exist == true)
		{
			PointBullet1 = { bullet_simple[i].B_Width / 2, 0 };
			bullet_simple[i].render(bullet_simple[i].B_x, bullet_simple[i].B_y, NULL, bullet_simple[i].angle, &PointBullet1);
		}
	}
	if (load_bullet_simple_time % 2 == 0) {
		for (int i = 0; i < NUMBER_BULLET; i++) {
			if (bullet_simple[i].exist == true)
			{
				bullet_simple[i].B_y += round((1) / sqrt(1 + 1.00 * (bullet_simple[i].slope * bullet_simple[i].slope)));
				bullet_simple[i].B_x = round(bullet_simple[i].start_x + (1.000 * bullet_simple[i].start_y * bullet_simple[i].slope - bullet_simple[i].B_y * 1.000 * bullet_simple[i].slope));
			}
		}
	}
	SDL_Point PointBullet2;
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j <= 2; j++) {
			if (bullet_x3[i][j].exist == true)
			{
				PointBullet2 = { bullet_x3[i][j].B_Width / 2, 0 };
				bullet_x3[i][j].render(bullet_x3[i][j].B_x, bullet_x3[i][j].B_y, NULL, bullet_x3[i][j].angle, &PointBullet2);
			}
		}
	}
	if (load_bullet_x3_time % 2 == 0) {
		for (int i = 0; i < NUMBER_BULLET; i++) {
			for (int j = 0; j <= 2; j++) {
				if (bullet_x3[i][j].exist == true)
				{
					bullet_x3[i][j].B_y += 2;
					bullet_x3[i][j].B_x = round(bullet_x3[i][j].start_x + (1.000 * bullet_x3[i][j].start_y * bullet_x3[i][j].slope - bullet_x3[i][j].B_y * 1.000 * bullet_x3[i][j].slope));
				}
			}
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (bullet_x4[i][j].exist == true)
			{
				bullet_x4[i][j].render(bullet_x4[i][j].B_x, bullet_x4[i][j].B_y, NULL, bullet_x4[i][j].angle);
				if (bullet_x4[i][j].denta_y == 0 && bullet_x4[i][j].denta_x > 0) {
					bullet_x4[i][j].B_x += BULLET_SPEED_RIVAL;
				}
				else if (bullet_x4[i][j].denta_y == 0 && bullet_x4[i][j].denta_x < 0) {
					bullet_x4[i][j].B_x -= BULLET_SPEED_RIVAL;
				}
				else if (bullet_x4[i][j].denta_y > 0 && bullet_x4[i][j].denta_x == 0) {
					bullet_x4[i][j].B_y += BULLET_SPEED_RIVAL;
				}
				else if (bullet_x4[i][j].denta_y < 0 && bullet_x4[i][j].denta_x == 0) {
					bullet_x4[i][j].B_y -= BULLET_SPEED_RIVAL;
				}
				else {
					if (bullet_x4[i][j].slope >= 1) {
						bullet_x4[i][j].B_y += round((BULLET_SPEED_RIVAL) /
							sqrt(1 + 1.00 / (bullet_x4[i][j].slope * bullet_x4[i][j].slope))) * bullet_x4[i][j].denta_x;
						bullet_x4[i][j].B_x = round((bullet_x4[i][j].B_y + 1.000 * bullet_x4[i][j].start_x * bullet_x4[i][j].slope - bullet_x4[i][j].start_y * 1.000) / bullet_x4[i][j].slope);
					}
					else if ((bullet_x4[i][j].slope <= 1) && (bullet_x4[i][j].slope >= -1)) {
						bullet_x4[i][j].B_x += round((BULLET_SPEED_RIVAL) /
							sqrt(1 + 1.00 * bullet_x4[i][j].slope * bullet_x4[i][j].slope)) * bullet_x4[i][j].denta_x;
						bullet_x4[i][j].B_y = round((bullet_x4[i][j].B_x) * bullet_x4[i][j].slope + bullet_x4[i][j].start_y * 1.000 - 1.000 * bullet_x4[i][j].start_x * bullet_x4[i][j].slope);
					}
					else if ((bullet_x4[i][j].slope <= -1)) {
						bullet_x4[i][j].B_y -= round((BULLET_SPEED_RIVAL) /
							sqrt(1 + 1.00 / (bullet_x4[i][j].slope * bullet_x4[i][j].slope))) * bullet_x4[i][j].denta_x;
						bullet_x4[i][j].B_x = round((bullet_x4[i][j].B_y + 1.000 * bullet_x4[i][j].start_x * bullet_x4[i][j].slope - bullet_x4[i][j].start_y * 1.000) / bullet_x4[i][j].slope);
					}
				}
			}
		}
	}
}