#pragma once
#include"Player.h"
#include"Declaration.h"
void Player::free()
{
	//Free texture if it exists
	if (P_Texture != NULL)
	{
		SDL_DestroyTexture(P_Texture);
		P_Texture = NULL;
		P_Width = 0;
		P_Height = 0;
	}
}
Player::~Player()
{
	free();
}
bool Player::loadFromFile(string path) {
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
			P_Width = loadedSurface->w / 4;
			P_Height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	P_Texture = newTexture;
	return P_Texture != NULL;
}

void Player::loadFrame(int x1, int y1, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	SDL_Rect cutPlayer[4];
	for (int i = 0; i <= 3; i++) {
		cutPlayer[i] = { i * 102,0,102,124 };
	}
	P_x = x1 - P_Width / 2;
	P_y = y1 - P_Height / 2;
	dem = (dem + 1) % 16;
	photostatus = (photostatus + (dem) / 15) % 4;
	SDL_Rect renderQuad = { P_x, P_y , P_Width, P_Height };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	exist = true;
	SDL_RenderCopyEx(gRenderer, P_Texture, &cutPlayer[photostatus], &renderQuad, angle, center, flip);
	loadShoot(x1, y1, bullet_type);
	shoot();
}
void Player::loadShoot(int x1, int y1, int bullet_type) {
	if (bullet_type == BULLET_SIMPLE) {
		load_bullet_simple_time = (load_bullet_simple_time + 1) % 31;
		load_bullet_x7_time = 0;
		load_bullet_x5_time = 0;
		if (thbullet_simple == 300) {
			thbullet_simple = 0;
		}
		if (load_bullet_simple_time == 30) {
			bullet_simple[thbullet_simple][0].B_x = P_x + (P_Width - bullet_simple[thbullet_simple][0].B_Width) / 2 - 15;
			bullet_simple[thbullet_simple][0].B_y = P_y - bullet_simple[thbullet_simple][0].B_Height + 50;
			bullet_simple[thbullet_simple][0].exist = true;
			//
			bullet_simple[thbullet_simple][1].B_x = P_x + (P_Width - bullet_simple[thbullet_simple][1].B_Width) / 2 + 15;
			bullet_simple[thbullet_simple][1].B_y = P_y - bullet_simple[thbullet_simple][1].B_Height + 50;
			bullet_simple[thbullet_simple][1].exist = true;
			thbullet_simple++;
		}
	}
	else if (bullet_type == BULLET_X7) {
		load_bullet_x7_time = (load_bullet_x7_time + 1) % 31;
		load_bullet_simple_time = 0;
		load_bullet_x5_time = 0;
		if (thbullet_x7 == 300) {
			thbullet_x7 = 0;
		}
		if (load_bullet_x7_time == 30) {
			int a = -30;
			for (int i = 0; i <= 6; i++) {
				bullet_x7[thbullet_x7][i].B_x = P_x + (P_Width - bullet_x7[thbullet_x7][i].B_Width) / 2;
				bullet_x7[thbullet_x7][i].B_y = P_y - bullet_x7[thbullet_x7][i].B_Height + 50;
				bullet_x7[thbullet_x7][i].start_x = P_x + (P_Width - bullet_x7[thbullet_x7][i].B_Width) / 2;
				bullet_x7[thbullet_x7][i].start_y = P_y - bullet_x7[thbullet_x7][i].B_Height + 50;
				bullet_x7[thbullet_x7][i].exist = true;
				bullet_x7[thbullet_x7][i].angle = a;
				bullet_x7[thbullet_x7][i].slope = tan((bullet_x7[thbullet_x7][i].angle) * PI / 180);
				a += 10;
			}
			thbullet_x7++;
		}
	}
	else if (bullet_type == BULLET_X5) {
		load_bullet_x5_time = (load_bullet_x5_time + 1) % 31;
		load_bullet_simple_time = 0;
		load_bullet_x7_time = 0;
		if (thbullet_x5 == 300) {
			thbullet_x5 = 0;
		}
		if (load_bullet_x5_time == 30) {
			int a = -4;
			int b = -20;
			int c = 0;
			for (int i = 0; i <= 4; i++) {
				bullet_x5[thbullet_x5][i].B_x = P_x + (P_Width - bullet_x5[thbullet_x5][i].B_Width) / 2 + b;
				bullet_x5[thbullet_x5][i].B_y = P_y - bullet_x5[thbullet_x5][i].B_Height + c;
				bullet_x5[thbullet_x5][i].start_x = P_x + (P_Width - bullet_x5[thbullet_x5][i].B_Width) / 2 + b;
				bullet_x5[thbullet_x5][i].start_y = P_y - bullet_x5[thbullet_x5][i].B_Height + c;
				bullet_x5[thbullet_x5][i].exist = true;
				bullet_x5[thbullet_x5][i].angle = a;
				bullet_x5[thbullet_x5][i].slope = tan((bullet_x5[thbullet_x5][i].angle) * PI / 180);
				a += 2;
				b += 10;
				if (i >= 2) {
					c += 10;
				}
				else c -= 10;
			}
			thbullet_x5++;
		}
	}
	if (lazer_bool == true) {
		lazer.exist = true;
		lazer.O_x = x1-72;
		lazer.O_y = y1-1325;
		loadLazer();
	}
	if (support_bool == true) {
		support_1.exist = true;
		support_2.exist = true;
		loadSupport();
	}
}
void Player::loadLazer() {
	load_bullet_simple_time = 0;
	load_bullet_x7_time = 0;
	load_bullet_x5_time = 0;
	SDL_Rect cutLazer[12];
	for (int i = 0; i <= 11; i++) {
		cutLazer[i] = { i * 145,0,145,1300 };
	}
	lazer.render(lazer.O_x, lazer.O_y, &cutLazer[load_lazer_time / 5]);
	load_lazer_time++;
	if (load_lazer_time == 61)
	{
		load_lazer_time = 0;
		lazer.exist = false;
		lazer_bool = false;
	}
}
void Player::loadSupport() {

	SDL_Rect cutSupport[4];
	for (int i = 0; i <= 3; i++) {
		cutSupport[i] = { i * 72,0,72,92 };
	}
	support_1.render(support_1.O_x, support_1.O_y, &cutSupport[load_support_time / 5]);
	support_2.render(support_2.O_x, support_2.O_y, &cutSupport[load_support_time / 5]);
	load_support_time++;
	if (load_support_time == 16) {
		load_support_time = 0;
	}
	support_1.O_x = P_x + 51 - 72 / 2 + dis_player_support;
	support_2.O_x = P_x + 51 - 72 / 2 - dis_player_support;
	support_1.O_y = P_y + 62 - 30;
	support_2.O_y = P_y + 62 - 30;
	if (dis_player_support < 100) {
		dis_player_support += 1;
	}
	else {
		loadBulletSupport();
		shoot1();
	}
}
void Player::loadBulletSupport() {
	int x1 = -10; int y1 = -10;
	int x2 = -10; int y2 = -10;
	determineTheTarget(x1, y1, x2, y2);
	if (thbullet_support == 300) {
		thbullet_support = 0;
	}
	load_bullet_support_time = (load_bullet_support_time + 1) % 31;
	if (load_bullet_support_time == 30) {
		if (!(x1 < 0 && y1 < 0 && x2 < 0 && y2 < 0)) {
			bullet_support_1[thbullet_support].B_x = support_1.O_x + (support_1.O_Width / 4 - bullet_support_1[thbullet_support].B_Width) / 2;
			bullet_support_1[thbullet_support].B_y = support_1.O_y - bullet_support_1[thbullet_support].B_Height;
			bullet_support_1[thbullet_support].start_x = support_1.O_x + (support_1.O_Width / 4 - bullet_support_1[thbullet_support].B_Width) / 2;
			bullet_support_1[thbullet_support].start_y = support_1.O_y - bullet_support_1[thbullet_support].B_Height;
			bullet_support_1[thbullet_support].denta_x = 1.00000000 * (x1 - (bullet_support_1[thbullet_support].start_x + bullet_support_1[thbullet_support].B_Width / 2));
			bullet_support_1[thbullet_support].denta_y = 1.00000000 * (y1 - (bullet_support_1[thbullet_support].start_y + bullet_support_1[thbullet_support].B_Height / 2));
			bullet_support_1[thbullet_support].slope = 1.00000000 * bullet_support_1[thbullet_support].denta_y / bullet_support_1[thbullet_support].denta_x;
			if (bullet_support_1[thbullet_support].denta_y >= 0)
				bullet_support_1[thbullet_support].angle = -1.00000000 * atan(1.00000 / bullet_support_1[thbullet_support].slope) * 180 / PI;
			else bullet_support_1[thbullet_support].angle = -(180.0000 + (1.00000000 * atan(1.00000 / bullet_support_1[thbullet_support].slope) * 180 / PI));
			bullet_support_1[thbullet_support].exist = true;
			/////

			bullet_support_2[thbullet_support].B_x = support_2.O_x + (support_2.O_Width / 4 - bullet_support_2[thbullet_support].B_Width) / 2;
			bullet_support_2[thbullet_support].B_y = support_2.O_y - bullet_support_2[thbullet_support].B_Height;
			bullet_support_2[thbullet_support].start_x = support_2.O_x + (support_2.O_Width / 4 - bullet_support_2[thbullet_support].B_Width) / 2;
			bullet_support_2[thbullet_support].start_y = support_2.O_y - bullet_support_2[thbullet_support].B_Height;
			bullet_support_2[thbullet_support].denta_x = 1.00000000 * (x2 - (bullet_support_2[thbullet_support].start_x + bullet_support_2[thbullet_support].B_Width / 2));
			bullet_support_2[thbullet_support].denta_y = 1.00000000 * (y2 - (bullet_support_2[thbullet_support].start_y + bullet_support_2[thbullet_support].B_Height / 2));
			bullet_support_2[thbullet_support].slope = 1.00000000 * bullet_support_2[thbullet_support].denta_y / bullet_support_2[thbullet_support].denta_x;
			if (bullet_support_2[thbullet_support].denta_y >= 0)
				bullet_support_2[thbullet_support].angle = -1.00000000 * atan(1.00000 / bullet_support_2[thbullet_support].slope) * 180 / PI;
			else bullet_support_2[thbullet_support].angle = -(180.0000 + (1.00000000 * atan(1.00000 / bullet_support_2[thbullet_support].slope) * 180 / PI));
			bullet_support_2[thbullet_support].exist = true;
			thbullet_support++;
		}
	}
}
void Player::shoot() {
	for (int i = 0; i < 300; i++)
	{
		for (int j = 0; j <= 1; j++) {
			if (bullet_simple[i][j].exist == true)
			{
				bullet_simple[i][j].render(bullet_simple[i][j].B_x, bullet_simple[i][j].B_y);
				bullet_simple[i][j].B_y -= BULLET_SPEED;
			}
		}
	}
	SDL_Point PointBulletPlayer;
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j <= 6; j++) {

			if (bullet_x7[i][j].exist == true)
			{
				PointBulletPlayer = { bullet_x7[i][j].B_Width / 2, bullet_x7[i][j].B_Height / 2 };
				bullet_x7[i][j].render(bullet_x7[i][j].B_x, bullet_x7[i][j].B_y, NULL, bullet_x7[i][j].angle, &PointBulletPlayer);
				bullet_x7[i][j].B_y -= round((BULLET_SPEED) / sqrt(1 + 1.00 * (bullet_x7[i][j].slope * bullet_x7[i][j].slope)));
				bullet_x7[i][j].B_x = round(bullet_x7[i][j].start_x + (1.000 * bullet_x7[i][j].start_y * bullet_x7[i][j].slope - bullet_x7[i][j].B_y * 1.000 * bullet_x7[i][j].slope));
			}
		}
	}
	for (int i = 0; i < 300; i++)
	{
		for (int j = 0; j <= 4; j++) {
			if (bullet_x5[i][j].exist == true)
			{
				PointBulletPlayer = { bullet_x5[i][j].B_Width / 2, bullet_x5[i][j].B_Height / 2 };
				bullet_x5[i][j].render(bullet_x5[i][j].B_x, bullet_x5[i][j].B_y, NULL, bullet_x5[i][j].angle, &PointBulletPlayer);
				bullet_x5[i][j].B_y -= round((BULLET_SPEED) / sqrt(1 + 1.00 * (bullet_x5[i][j].slope * bullet_x5[i][j].slope)));
				bullet_x5[i][j].B_x = round(bullet_x5[i][j].start_x + (1.000 * bullet_x5[i][j].start_y * bullet_x5[i][j].slope - bullet_x5[i][j].B_y * 1.000 * bullet_x5[i][j].slope));
			}
		}
	}
}
void Player::shoot1() {
	for (int i = 0; i < 300; i++)
	{
		if (bullet_support_1[i].exist == true)
		{
			bullet_support_1[i].render(bullet_support_1[i].B_x, bullet_support_1[i].B_y, NULL, bullet_support_1[i].angle);
			if (bullet_support_1[i].denta_y == 0 && bullet_support_1[i].denta_x > 0) {
				bullet_support_1[i].B_x += BULLET_SPEED_RIVAL;
			}
			else if (bullet_support_1[i].denta_y == 0 && bullet_support_1[i].denta_x < 0) {
				bullet_support_1[i].B_x -= BULLET_SPEED_RIVAL;
			}
			else if (bullet_support_1[i].denta_y > 0 && bullet_support_1[i].denta_x == 0) {
				bullet_support_1[i].B_y += BULLET_SPEED_RIVAL;
			}
			else if (bullet_support_1[i].denta_y < 0 && bullet_support_1[i].denta_x == 0) {
				bullet_support_1[i].B_y -= BULLET_SPEED_RIVAL;
			}
			else {
				if (bullet_support_1[i].slope >= 1) {
					bullet_support_1[i].B_y += round((BULLET_SPEED_RIVAL) /
						sqrt(1 + 1.00 / (bullet_support_1[i].slope * bullet_support_1[i].slope))) * bullet_support_1[i].denta_x / abs(bullet_support_1[i].denta_x);
					bullet_support_1[i].B_x = round((bullet_support_1[i].B_y + 1.000 * bullet_support_1[i].start_x * bullet_support_1[i].slope - bullet_support_1[i].start_y * 1.000) / bullet_support_1[i].slope);
				}
				else if ((bullet_support_1[i].slope <= 1) && (bullet_support_1[i].slope >= -1)) {
					bullet_support_1[i].B_x += round((BULLET_SPEED_RIVAL) /
						sqrt(1 + 1.00 * bullet_support_1[i].slope * bullet_support_1[i].slope)) * bullet_support_1[i].denta_x / abs(bullet_support_1[i].denta_x);
					bullet_support_1[i].B_y = round((bullet_support_1[i].B_x) * bullet_support_1[i].slope + bullet_support_1[i].start_y * 1.000 - 1.000 * bullet_support_1[i].start_x * bullet_support_1[i].slope);
				}
				else if ((bullet_support_1[i].slope <= -1)) {
					bullet_support_1[i].B_y -= round((BULLET_SPEED_RIVAL) /
						sqrt(1 + 1.00 / (bullet_support_1[i].slope * bullet_support_1[i].slope))) * bullet_support_1[i].denta_x / abs(bullet_support_1[i].denta_x);
					bullet_support_1[i].B_x = round((bullet_support_1[i].B_y + 1.000 * bullet_support_1[i].start_x * bullet_support_1[i].slope - bullet_support_1[i].start_y * 1.000) / bullet_support_1[i].slope);
				}
			}
		}
	}
	for (int i = 0; i < 300; i++)
	{
		if (bullet_support_2[i].exist == true)
		{
			bullet_support_2[i].render(bullet_support_2[i].B_x, bullet_support_2[i].B_y, NULL, bullet_support_2[i].angle);
			if (bullet_support_2[i].denta_y == 0 && bullet_support_2[i].denta_x > 0) {
				bullet_support_2[i].B_x += BULLET_SPEED_RIVAL;
			}
			else if (bullet_support_2[i].denta_y == 0 && bullet_support_2[i].denta_x < 0) {
				bullet_support_2[i].B_x -= BULLET_SPEED_RIVAL;
			}
			else if (bullet_support_2[i].denta_y > 0 && bullet_support_2[i].denta_x == 0) {
				bullet_support_2[i].B_y += BULLET_SPEED_RIVAL;
			}
			else if (bullet_support_2[i].denta_y < 0 && bullet_support_2[i].denta_x == 0) {
				bullet_support_2[i].B_y -= BULLET_SPEED_RIVAL;
			}
			else {
				if (bullet_support_2[i].slope >= 1) {
					bullet_support_2[i].B_y += round((BULLET_SPEED_RIVAL) /
						sqrt(1 + 1.00 / (bullet_support_2[i].slope * bullet_support_2[i].slope))) * bullet_support_2[i].denta_x / abs(bullet_support_2[i].denta_x);
					bullet_support_2[i].B_x = round((bullet_support_2[i].B_y + 1.000 * bullet_support_2[i].start_x * bullet_support_2[i].slope - bullet_support_2[i].start_y * 1.000) / bullet_support_2[i].slope);
				}
				else if ((bullet_support_2[i].slope <= 1) && (bullet_support_2[i].slope >= -1)) {
					bullet_support_2[i].B_x += round((BULLET_SPEED_RIVAL) /
						sqrt(1 + 1.00 * bullet_support_2[i].slope * bullet_support_2[i].slope)) * bullet_support_2[i].denta_x / abs(bullet_support_2[i].denta_x);
					bullet_support_2[i].B_y = round((bullet_support_2[i].B_x) * bullet_support_2[i].slope + bullet_support_2[i].start_y * 1.000 - 1.000 * bullet_support_2[i].start_x * bullet_support_2[i].slope);
				}
				else if ((bullet_support_2[i].slope <= -1)) {
					bullet_support_2[i].B_y -= round((BULLET_SPEED_RIVAL) /
						sqrt(1 + 1.00 / (bullet_support_2[i].slope * bullet_support_2[i].slope))) * bullet_support_2[i].denta_x / abs(bullet_support_2[i].denta_x);
					bullet_support_2[i].B_x = round((bullet_support_2[i].B_y + 1.000 * bullet_support_2[i].start_x * bullet_support_2[i].slope - bullet_support_2[i].start_y * 1.000) / bullet_support_2[i].slope);
				}
			}
		}
	}
}
void Player::determineTheTarget(int& x1, int& y1, int& x2, int& y2) {
	double min1 = 1000000000;
	for (int i = 0; i < 4; i++) {
		if ((((ennemies_1[i].E_x + ennemies_1[i].E_Width / 2 - support_1.O_x - support_1.O_Width / 8) * (ennemies_1[i].E_x + ennemies_1[i].E_Width / 2 - support_1.O_x - support_1.O_Width / 8) +
			(ennemies_1[i].E_y + ennemies_1[i].E_Height / 2 - support_1.O_y - support_1.O_Height / 2) * (ennemies_1[i].E_y + ennemies_1[i].E_Height / 2 - support_1.O_y - support_1.O_Height / 2)) <= min1)
			&& ennemies_1[i].exist == true)
		{
			min1 = ((ennemies_1[i].E_x + ennemies_1[i].E_Width / 2 - support_1.O_x - support_1.O_Width / 8) * (ennemies_1[i].E_x + ennemies_1[i].E_Width / 2 - support_1.O_x - support_1.O_Width / 8) +
				(ennemies_1[i].E_y + ennemies_1[i].E_Height / 2 - support_1.O_y - support_1.O_Height / 2) * (ennemies_1[i].E_y + ennemies_1[i].E_Height / 2 - support_1.O_y - support_1.O_Height / 2));
			x1 = ennemies_1[i].E_x + ennemies_1[i].E_Width / 2;
			y1 = ennemies_1[i].E_y + ennemies_1[i].E_Width / 2;
		}
	}
	double min2 = 1000000000;
	for (int i = 0; i < 4; i++) {
		if ((((ennemies_1[i].E_x + ennemies_1[i].E_Width / 2 - support_2.O_x - support_2.O_Width / 8) * (ennemies_1[i].E_x + ennemies_1[i].E_Width / 2 - support_2.O_x - support_2.O_Width / 8) +
			(ennemies_1[i].E_y + ennemies_1[i].E_Height / 2 - support_2.O_y - support_2.O_Height / 2) * (ennemies_1[i].E_y + ennemies_1[i].E_Height / 2 - support_2.O_y - support_2.O_Height / 2)) <= min2)
			&& ennemies_1[i].exist == true)
		{
			min2 = ((ennemies_1[i].E_x + ennemies_1[i].E_Width / 2 - support_2.O_x - support_2.O_Width / 8) * (ennemies_1[i].E_x + ennemies_1[i].E_Width / 2 - support_2.O_x - support_2.O_Width / 8) +
				(ennemies_1[i].E_y + ennemies_1[i].E_Height / 2 - support_2.O_y - support_2.O_Height / 2) * (ennemies_1[i].E_y + ennemies_1[i].E_Height / 2 - support_2.O_y - support_2.O_Height / 2));
			x2 = ennemies_1[i].E_x + ennemies_1[i].E_Width / 2;
			y2 = ennemies_1[i].E_y + ennemies_1[i].E_Width / 2;
		}
	}
}
