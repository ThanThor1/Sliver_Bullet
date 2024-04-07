﻿#pragma once
#include"Player.h"
#include "Declaration.h"
#include "Ennemies.h"
void Player::free()
{
	//support
	support_1;
	support_2;
	load_support_time = 0;
	load_bullet_support_time = 0;
	thbullet_support = 0;
	dis_player_support = 0;
	//lazer
	lazer;
	load_lazer_time = 0;
	//bullet
	thbullet_simple = 0;
	load_bullet_simple_time = 0;
	//
	thbullet_x7 = 0;
	load_bullet_x7_time = 0;
	//
	thbullet_x5 = 0;
	load_bullet_x5_time = 0;
	//loại đạn
	bullet_type = 10;
	// địa chỉ trên màn hình lúc render ra
	P_x = 350;
	P_y = 700;
	// địa chỉ điểm bắt đầu (chưa cần dùng) (có thể là địa chỉ tâm)
	P_Start_x = 0;
	P_Start_y = 0;
	// khiên
	shield_bool = false;
	// hỗ trợ
	support_bool = false;
	// lazer
	lazer_bool = false;
	// trang thai anh
	photostatus = 0;
	number_of_hearts = 3;
	//
	exist = true;
}
Player::~Player()
{
	free();
}
Player::Player() {
	sensitivity[0] = 0.7;
	sensitivity[1] = 1;
	sensitivity[2] = 1.3;
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
			P_Width = loadedSurface->w;
			P_Height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	P_Texture = newTexture;
	return P_Texture != NULL;
}
void Player::loadFrame(SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	checkHit();
	if (nhanchuot == true) {
		SDL_GetMouseState(&x, &y);
		if (P_x <= (SCREEN_WIDTH - P_Width) && P_x >= 0 && P_y >= 0 && P_y <= (SCREEN_HEIGHT - P_Height)) {
			if (x <= (SCREEN_WIDTH) && x >= 0) {
				P_x += round((x - pre_x) * sensitivity[sensitivity_index]);
			}
			if (y <= (SCREEN_HEIGHT) && y >= 0) {
				P_y += round((y - pre_y) * sensitivity[sensitivity_index]);
			}
			if (P_x <= 0) {
				P_x = 0;
			}
			if (P_x >= (SCREEN_WIDTH - P_Width)) {
				P_x = (SCREEN_WIDTH - P_Width);
			}
			if (P_y <= 0) {
				P_y = 0;
			}
			if (P_y >= (SCREEN_HEIGHT - P_Height)) {
				P_y = (SCREEN_HEIGHT - P_Height);
			}
		}
		pre_x = x;
		pre_y = y;
	}
	else {
		SDL_GetMouseState(&pre_x, &pre_y);
	}
	if (number_of_hearts > 0) {
		SDL_Rect renderQuad = { P_x, P_y , P_Width, P_Height };
		SDL_RenderCopyEx(gRenderer, P_Texture, NULL, &renderQuad, angle, center, flip);
		loadShoot(bullet_type);
		shoot();
		exist = true;
	}
}
void Player::loadShoot(int bullet_type) {
	if (bullet_type == BULLET_SIMPLE) {
		load_bullet_simple_time = (load_bullet_simple_time + 1) % 61;
		load_bullet_x7_time = 0;
		load_bullet_x5_time = 0;
		if (thbullet_simple == NUMBER_BULLET) {
			thbullet_simple = 0;
		}
		if (load_bullet_simple_time == 60) {

			bullet_simple[thbullet_simple][0].B_x = P_x + (P_Width - bullet_simple[thbullet_simple][0].B_Width) / 2 - 15;
			bullet_simple[thbullet_simple][0].B_y = P_y - bullet_simple[thbullet_simple][0].B_Height + 50;
			bullet_simple[thbullet_simple][0].B_exist = true;
			//
			bullet_simple[thbullet_simple][1].B_x = P_x + (P_Width - bullet_simple[thbullet_simple][1].B_Width) / 2 + 15;
			bullet_simple[thbullet_simple][1].B_y = P_y - bullet_simple[thbullet_simple][1].B_Height + 50;
			bullet_simple[thbullet_simple][1].B_exist = true;
			thbullet_simple++;
			Mix_PlayChannel(-1, chunk_shoot, 0);
		}

	}
	else if (bullet_type == BULLET_X7) {
		load_bullet_x7_time = (load_bullet_x7_time + 1) % 61;
		load_bullet_simple_time = 0;
		load_bullet_x5_time = 0;
		if (thbullet_x7 == NUMBER_BULLET) {
			thbullet_x7 = 0;
		}
		if (load_bullet_x7_time == 60) {
			int a = -30;
			int b = -30;
			int c = 0;
			for (int i = 0; i <= 6; i++) {
				bullet_x7[thbullet_x7][i].B_x = P_x + (P_Width - bullet_x7[thbullet_x7][i].B_Width) / 2 + b;
				bullet_x7[thbullet_x7][i].B_y = P_y - bullet_x7[thbullet_x7][i].B_Height + 50 + c;
				bullet_x7[thbullet_x7][i].B_start_x = P_x + (P_Width - bullet_x7[thbullet_x7][i].B_Width) / 2 + b;
				bullet_x7[thbullet_x7][i].B_start_y = P_y - bullet_x7[thbullet_x7][i].B_Height + 50 + c;
				bullet_x7[thbullet_x7][i].B_exist = true;
				bullet_x7[thbullet_x7][i].B_angle = a;
				bullet_x7[thbullet_x7][i].B_slope = tan((bullet_x7[thbullet_x7][i].B_angle) * PI / 180);
				a += 10;
				b += 10;
				if (i >= 3) {
					c += 15;
				}
				else c -= 15;
			}
			thbullet_x7++;
			Mix_PlayChannel(-1, chunk_shoot, 0);
		}
	}
	else if (bullet_type == BULLET_X5) {
		load_bullet_x5_time = (load_bullet_x5_time + 1) % 61;
		load_bullet_simple_time = 0;
		load_bullet_x7_time = 0;
		if (thbullet_x5 == NUMBER_BULLET) {
			thbullet_x5 = 0;
		}
		if (load_bullet_x5_time == 60) {
			int a = -10;
			int b = -20;
			int c = 0;
			for (int i = 0; i <= 4; i++) {
				bullet_x5[thbullet_x5][i].B_x = P_x + (P_Width - bullet_x5[thbullet_x5][i].B_Width) / 2 + b;
				bullet_x5[thbullet_x5][i].B_y = P_y - bullet_x5[thbullet_x5][i].B_Height + c;
				bullet_x5[thbullet_x5][i].B_start_x = P_x + (P_Width - bullet_x5[thbullet_x5][i].B_Width) / 2 + b;
				bullet_x5[thbullet_x5][i].B_start_y = P_y - bullet_x5[thbullet_x5][i].B_Height + c;
				bullet_x5[thbullet_x5][i].B_exist = true;
				bullet_x5[thbullet_x5][i].B_angle = a;
				bullet_x5[thbullet_x5][i].B_slope = tan((bullet_x5[thbullet_x5][i].B_angle) * PI / 180);
				a += 5;
				b += 10;
				if (i >= 2) {
					c += 10;
				}
				else c -= 10;
			}
			thbullet_x5++;
			Mix_PlayChannel(-1, chunk_shoot, 0);
		}
	}
	if (lazer_bool == true) {
		lazer.exist = true;
		lazer.O_x = P_x + P_Width / 2 - 72;
		lazer.O_y = P_y + P_Height / 2 - 1325;
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
	support_1.render(support_1.O_x, support_1.O_y);
	support_2.render(support_2.O_x, support_2.O_y);
	support_1.O_x = P_x + P_Width / 2 - support_1.O_Width / 2 + dis_player_support;
	support_2.O_x = P_x + P_Width / 2 - support_2.O_Width / 2 - dis_player_support;
	support_1.O_y = P_y + P_Height / 2 - support_1.O_Height / 2;
	support_2.O_y = P_y + P_Height / 2 - support_2.O_Height / 2;
	if (dis_player_support < 100) {
		dis_player_support += 1;
	}
	else {
		loadBulletSupport();
		shootSupport();
	}
}
void Player::loadBulletSupport() {
	int x1 = -10; int y1 = -10;
	int x2 = -10; int y2 = -10;
	determineTheTarget(x1, y1, x2, y2);
	if (thbullet_support ==  NUMBER_BULLET) {
		thbullet_support = 0;
	}
	load_bullet_support_time = (load_bullet_support_time + 1) % 31;
	if (load_bullet_support_time == 30) {
		if (x1 > 0 && y1 > 0 && x2 > 0 && y2 > 0) {
			bullet_support_1[thbullet_support].B_x = support_1.O_x + (support_1.O_Width - bullet_support_1[thbullet_support].B_Width) / 2;
			bullet_support_1[thbullet_support].B_y = support_1.O_y - bullet_support_1[thbullet_support].B_Height;
			bullet_support_1[thbullet_support].B_start_x = support_1.O_x + (support_1.O_Width - bullet_support_1[thbullet_support].B_Width) / 2;
			bullet_support_1[thbullet_support].B_start_y = support_1.O_y - bullet_support_1[thbullet_support].B_Height;
			bullet_support_1[thbullet_support].B_denta_x = 1.00000000 * (x1 - (bullet_support_1[thbullet_support].B_start_x + bullet_support_1[thbullet_support].B_Width / 2));
			bullet_support_1[thbullet_support].B_denta_y = 1.00000000 * (y1 - (bullet_support_1[thbullet_support].B_start_y + bullet_support_1[thbullet_support].B_Height / 2));
			bullet_support_1[thbullet_support].B_slope = 1.00000000 * bullet_support_1[thbullet_support].B_denta_y / bullet_support_1[thbullet_support].B_denta_x;
			if (bullet_support_1[thbullet_support].B_denta_y >= 0)
				bullet_support_1[thbullet_support].B_angle = -1.00000000 * atan(1.00000 / bullet_support_1[thbullet_support].B_slope) * 180 / PI;
			else bullet_support_1[thbullet_support].B_angle = -(180.0000 + (1.00000000 * atan(1.00000 / bullet_support_1[thbullet_support].B_slope) * 180 / PI));
			bullet_support_1[thbullet_support].B_exist = true;
			/////
			bullet_support_2[thbullet_support].B_x = support_2.O_x + (support_2.O_Width - bullet_support_2[thbullet_support].B_Width) / 2;
			bullet_support_2[thbullet_support].B_y = support_2.O_y - bullet_support_2[thbullet_support].B_Height;
			bullet_support_2[thbullet_support].B_start_x = support_2.O_x + (support_2.O_Width - bullet_support_2[thbullet_support].B_Width) / 2;
			bullet_support_2[thbullet_support].B_start_y = support_2.O_y - bullet_support_2[thbullet_support].B_Height;
			bullet_support_2[thbullet_support].B_denta_x = 1.00000000 * (x2 - (bullet_support_2[thbullet_support].B_start_x + bullet_support_2[thbullet_support].B_Width / 2));
			bullet_support_2[thbullet_support].B_denta_y = 1.00000000 * (y2 - (bullet_support_2[thbullet_support].B_start_y + bullet_support_2[thbullet_support].B_Height / 2));
			bullet_support_2[thbullet_support].B_slope = 1.00000000 * bullet_support_2[thbullet_support].B_denta_y / bullet_support_2[thbullet_support].B_denta_x;
			if (bullet_support_2[thbullet_support].B_denta_y >= 0)
				bullet_support_2[thbullet_support].B_angle = -1.00000000 * atan(1.00000 / bullet_support_2[thbullet_support].B_slope) * 180 / PI;
			else bullet_support_2[thbullet_support].B_angle = -(180.0000 + (1.00000000 * atan(1.00000 / bullet_support_2[thbullet_support].B_slope) * 180 / PI));
			bullet_support_2[thbullet_support].B_exist = true;
			thbullet_support++;
		}
	}
}
void Player::shoot() {
	for (int i = 0; i < NUMBER_BULLET; i++)
	{
		for (int j = 0; j <= 1; j++) {
			if (bullet_simple[i][j].B_exist == true)
			{
				bullet_simple[i][j].render(bullet_simple[i][j].B_x, bullet_simple[i][j].B_y);
				bullet_simple[i][j].B_y -= BULLET_SPEED;
			}
		}
	}
	SDL_Point PointBulletPlayer;
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j <= 6; j++) {

			if (bullet_x7[i][j].B_exist == true)
			{
				PointBulletPlayer = { bullet_x7[i][j].B_Width / 2, bullet_x7[i][j].B_Height / 2 };
				bullet_x7[i][j].render(bullet_x7[i][j].B_x, bullet_x7[i][j].B_y, NULL, bullet_x7[i][j].B_angle, &PointBulletPlayer);
				bullet_x7[i][j].B_y -= round((BULLET_SPEED) / sqrt(1 + 1.00 * (bullet_x7[i][j].B_slope * bullet_x7[i][j].B_slope)));
				bullet_x7[i][j].B_x = round(bullet_x7[i][j].B_start_x + (1.000 * bullet_x7[i][j].B_start_y * bullet_x7[i][j].B_slope - bullet_x7[i][j].B_y * 1.000 * bullet_x7[i][j].B_slope));
			}
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++)
	{
		for (int j = 0; j <= 4; j++) {
			if (bullet_x5[i][j].B_exist == true)
			{
				PointBulletPlayer = { bullet_x5[i][j].B_Width / 2, bullet_x5[i][j].B_Height / 2 };
				bullet_x5[i][j].render(bullet_x5[i][j].B_x, bullet_x5[i][j].B_y, NULL, bullet_x5[i][j].B_angle, &PointBulletPlayer);
				bullet_x5[i][j].B_y -= round((BULLET_SPEED) / sqrt(1 + 1.00 * (bullet_x5[i][j].B_slope * bullet_x5[i][j].B_slope)));
				bullet_x5[i][j].B_x = round(bullet_x5[i][j].B_start_x + (1.000 * bullet_x5[i][j].B_start_y * bullet_x5[i][j].B_slope - bullet_x5[i][j].B_y * 1.000 * bullet_x5[i][j].B_slope));
			}
		}
	}
}
void Player::shootSupport() {
	for (int i = 0; i < NUMBER_BULLET; i++)
	{
		if (bullet_support_1[i].B_exist == true)
		{
			bullet_support_1[i].render(bullet_support_1[i].B_x, bullet_support_1[i].B_y, NULL, bullet_support_1[i].B_angle);
			if (bullet_support_1[i].B_denta_y == 0 && bullet_support_1[i].B_denta_x > 0) {
				bullet_support_1[i].B_x += BULLET_SPEED_SUPPORT;
			}
			else if (bullet_support_1[i].B_denta_y == 0 && bullet_support_1[i].B_denta_x < 0) {
				bullet_support_1[i].B_x -= BULLET_SPEED_SUPPORT;
			}
			else if (bullet_support_1[i].B_denta_y > 0 && bullet_support_1[i].B_denta_x == 0) {
				bullet_support_1[i].B_y += BULLET_SPEED_SUPPORT;
			}
			else if (bullet_support_1[i].B_denta_y < 0 && bullet_support_1[i].B_denta_x == 0) {
				bullet_support_1[i].B_y -= BULLET_SPEED_SUPPORT;
			}
			else {
				if (bullet_support_1[i].B_slope >= 1) {
					bullet_support_1[i].B_y += round((BULLET_SPEED_SUPPORT) /
						sqrt(1 + 1.00 / (bullet_support_1[i].B_slope * bullet_support_1[i].B_slope))) * bullet_support_1[i].B_denta_x / abs(bullet_support_1[i].B_denta_x);
					bullet_support_1[i].B_x = round((bullet_support_1[i].B_y + 1.000 * bullet_support_1[i].B_start_x * bullet_support_1[i].B_slope - bullet_support_1[i].B_start_y * 1.000) / bullet_support_1[i].B_slope);
				}
				else if ((bullet_support_1[i].B_slope <= 1) && (bullet_support_1[i].B_slope >= -1)) {
					bullet_support_1[i].B_x += round((BULLET_SPEED_SUPPORT) /
						sqrt(1 + 1.00 * bullet_support_1[i].B_slope * bullet_support_1[i].B_slope)) * bullet_support_1[i].B_denta_x / abs(bullet_support_1[i].B_denta_x);
					bullet_support_1[i].B_y = round((bullet_support_1[i].B_x) * bullet_support_1[i].B_slope + bullet_support_1[i].B_start_y * 1.000 - 1.000 * bullet_support_1[i].B_start_x * bullet_support_1[i].B_slope);
				}
				else if ((bullet_support_1[i].B_slope <= -1)) {
					bullet_support_1[i].B_y -= round((BULLET_SPEED_SUPPORT) /
						sqrt(1 + 1.00 / (bullet_support_1[i].B_slope * bullet_support_1[i].B_slope))) * bullet_support_1[i].B_denta_x / abs(bullet_support_1[i].B_denta_x);
					bullet_support_1[i].B_x = round((bullet_support_1[i].B_y + 1.000 * bullet_support_1[i].B_start_x * bullet_support_1[i].B_slope - bullet_support_1[i].B_start_y * 1.000) / bullet_support_1[i].B_slope);
				}
			}
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++)
	{
		if (bullet_support_2[i].B_exist == true)
		{
			bullet_support_2[i].render(bullet_support_2[i].B_x, bullet_support_2[i].B_y, NULL, bullet_support_2[i].B_angle);
			if (bullet_support_2[i].B_denta_y == 0 && bullet_support_2[i].B_denta_x > 0) {
				bullet_support_2[i].B_x += BULLET_SPEED_SUPPORT;
			}
			else if (bullet_support_2[i].B_denta_y == 0 && bullet_support_2[i].B_denta_x < 0) {
				bullet_support_2[i].B_x -= BULLET_SPEED_SUPPORT;
			}
			else if (bullet_support_2[i].B_denta_y > 0 && bullet_support_2[i].B_denta_x == 0) {
				bullet_support_2[i].B_y += BULLET_SPEED_SUPPORT;
			}
			else if (bullet_support_2[i].B_denta_y < 0 && bullet_support_2[i].B_denta_x == 0) {
				bullet_support_2[i].B_y -= BULLET_SPEED_SUPPORT;
			}
			else {
				if (bullet_support_2[i].B_slope >= 1) {
					bullet_support_2[i].B_y += round((BULLET_SPEED_SUPPORT) /
						sqrt(1 + 1.00 / (bullet_support_2[i].B_slope * bullet_support_2[i].B_slope))) * bullet_support_2[i].B_denta_x / abs(bullet_support_2[i].B_denta_x);
					bullet_support_2[i].B_x = round((bullet_support_2[i].B_y + 1.000 * bullet_support_2[i].B_start_x * bullet_support_2[i].B_slope - bullet_support_2[i].B_start_y * 1.000) / bullet_support_2[i].B_slope);
				}
				else if ((bullet_support_2[i].B_slope <= 1) && (bullet_support_2[i].B_slope >= -1)) {
					bullet_support_2[i].B_x += round((BULLET_SPEED_SUPPORT) /
						sqrt(1 + 1.00 * bullet_support_2[i].B_slope * bullet_support_2[i].B_slope)) * bullet_support_2[i].B_denta_x / abs(bullet_support_2[i].B_denta_x);
					bullet_support_2[i].B_y = round((bullet_support_2[i].B_x) * bullet_support_2[i].B_slope + bullet_support_2[i].B_start_y * 1.000 - 1.000 * bullet_support_2[i].B_start_x * bullet_support_2[i].B_slope);
				}
				else if ((bullet_support_2[i].B_slope <= -1)) {
					bullet_support_2[i].B_y -= round((BULLET_SPEED_SUPPORT) /
						sqrt(1 + 1.00 / (bullet_support_2[i].B_slope * bullet_support_2[i].B_slope))) * bullet_support_2[i].B_denta_x / abs(bullet_support_2[i].B_denta_x);
					bullet_support_2[i].B_x = round((bullet_support_2[i].B_y + 1.000 * bullet_support_2[i].B_start_x * bullet_support_2[i].B_slope - bullet_support_2[i].B_start_y * 1.000) / bullet_support_2[i].B_slope);
				}
			}
		}
	}
}
void Player::determineTheTarget(int& x1, int& y1, int& x2, int& y2) {
	double min1 = 1000000000;
	for (int i = 1; i <= number_ennemies_A; i++) {
		if ((calculateDis(ennemies_A[i].E_x, ennemies_A[i].E_y, ennemies_A[i].E_Width, ennemies_A[i].E_Height, support_1) <= min1) && ennemies_A[i].exist == true)
		{
			min1 = calculateDis(ennemies_A[i].E_x, ennemies_A[i].E_y, ennemies_A[i].E_Width, ennemies_A[i].E_Height, support_1);
			x1 = ennemies_A[i].E_x + ennemies_A[i].E_Width / 2;
			y1 = ennemies_A[i].E_y + ennemies_A[i].E_Width / 2;
		}
	}
	for (int i = 1; i <= number_ennemies_B; i++) {
		if ((calculateDis(ennemies_B[i].E_x, ennemies_B[i].E_y, ennemies_B[i].E_Width, ennemies_B[i].E_Height, support_1) <= min1) && ennemies_B[i].exist == true)
		{
			min1 = calculateDis(ennemies_B[i].E_x, ennemies_B[i].E_y, ennemies_B[i].E_Width, ennemies_B[i].E_Height, support_1);
			x1 = ennemies_B[i].E_x + ennemies_B[i].E_Width / 2;
			y1 = ennemies_B[i].E_y + ennemies_B[i].E_Width / 2;
		}
	}
	for (int i = 1; i <= number_ennemies_C; i++) {
		if ((calculateDis(ennemies_C[i].E_x, ennemies_C[i].E_y, ennemies_C[i].E_Width, ennemies_C[i].E_Height, support_1) <= min1) && ennemies_C[i].exist == true)
		{
			min1 = calculateDis(ennemies_C[i].E_x, ennemies_C[i].E_y, ennemies_C[i].E_Width, ennemies_C[i].E_Height, support_1);
			x1 = ennemies_C[i].E_x + ennemies_C[i].E_Width / 2;
			y1 = ennemies_C[i].E_y + ennemies_C[i].E_Width / 2;
		}
	}
	for (int i = 1; i <= number_ennemies_D; i++) {
		if ((calculateDis(ennemies_D[i].E_x, ennemies_D[i].E_y, ennemies_D[i].E_Width, ennemies_D[i].E_Height, support_1) <= min1) && ennemies_D[i].exist == true)
		{
			min1 = calculateDis(ennemies_D[i].E_x, ennemies_D[i].E_y, ennemies_D[i].E_Width, ennemies_D[i].E_Height, support_1);
			x1 = ennemies_D[i].E_x + ennemies_D[i].E_Width / 2;
			y1 = ennemies_D[i].E_y + ennemies_D[i].E_Width / 2;
		}
	}
	double min2 = 1000000000;
	for (int i = 1; i <= number_ennemies_A; i++) {
		if ((calculateDis(ennemies_A[i].E_x, ennemies_A[i].E_y, ennemies_A[i].E_Width, ennemies_A[i].E_Height, support_2) <= min2) && ennemies_A[i].exist == true)
		{
			min2 = calculateDis(ennemies_A[i].E_x, ennemies_A[i].E_y, ennemies_A[i].E_Width, ennemies_A[i].E_Height, support_2);
			x2 = ennemies_A[i].E_x + ennemies_A[i].E_Width / 2;
			y2 = ennemies_A[i].E_y + ennemies_A[i].E_Width / 2;
		}
	}
	for (int i = 1; i <= number_ennemies_B; i++) {
		if ((calculateDis(ennemies_B[i].E_x, ennemies_B[i].E_y, ennemies_B[i].E_Width, ennemies_B[i].E_Height, support_2) <= min2) && ennemies_B[i].exist == true)
		{
			min2 = calculateDis(ennemies_B[i].E_x, ennemies_B[i].E_y, ennemies_B[i].E_Width, ennemies_B[i].E_Height, support_2);
			x2 = ennemies_B[i].E_x + ennemies_B[i].E_Width / 2;
			y2 = ennemies_B[i].E_y + ennemies_B[i].E_Width / 2;
		}
	}
	for (int i = 1; i <= number_ennemies_C; i++) {
		if ((calculateDis(ennemies_C[i].E_x, ennemies_C[i].E_y, ennemies_C[i].E_Width, ennemies_C[i].E_Height, support_2) <= min2) && ennemies_C[i].exist == true)
		{
			min2 = calculateDis(ennemies_C[i].E_x, ennemies_C[i].E_y, ennemies_C[i].E_Width, ennemies_C[i].E_Height, support_2);
			x2 = ennemies_C[i].E_x + ennemies_C[i].E_Width / 2;
			y2 = ennemies_C[i].E_y + ennemies_C[i].E_Width / 2;
		}
	}
	for (int i = 1; i <= number_ennemies_D; i++) {
		if ((calculateDis(ennemies_D[i].E_x, ennemies_D[i].E_y, ennemies_D[i].E_Width, ennemies_D[i].E_Height, support_2) <= min2) && ennemies_D[i].exist == true)
		{
			min2 = calculateDis(ennemies_D[i].E_x, ennemies_D[i].E_y, ennemies_D[i].E_Width, ennemies_D[i].E_Height, support_2);
			x2 = ennemies_D[i].E_x + ennemies_D[i].E_Width / 2;
			y2 = ennemies_D[i].E_y + ennemies_D[i].E_Width / 2;
		}
	}
}
double Player::calculateDis(int E_x, int E_y, int E_Width, int E_Height, Object& b) {
	return ((E_x + E_Width / 2 - b.O_x - b.O_Width / 2) * (E_x + E_Width / 2 - b.O_x - b.O_Width / 2) + (E_y + E_Height / 2 - b.O_y - b.O_Height / 2) * (E_y + E_Height / 2 - b.O_y - b.O_Height / 2));
}
void Player::checkHit() {
	if (number_of_hearts > 0) {
		for (int i = 1; i <= number_ennemies_A; i++) {
			for (int j = 0; j < NUMBER_BULLET; j++) {
				if (ennemies_A[i].bullet_simple[j].B_exist == true) {
					if (checkImpact(ennemies_A[i].bullet_simple[j])) {
						ennemies_A[i].bullet_simple[j].B_exist = false;
						number_of_hearts--;
					}
				}
			}
		}
		for (int i = 1; i <= number_ennemies_B; i++) {
			for (int j = 0; j < NUMBER_BULLET; j++) {
				for (int k= 0; k < 3; k++) {
					if (ennemies_B[i].bullet_x3[j][k].B_exist == true) {
						if (checkImpact(ennemies_B[i].bullet_x3[j][k])) {
							ennemies_B[i].bullet_x3[j][k].B_exist = false;
							number_of_hearts--;
						}
					}
				}
			}
		}
		for (int i = 1; i <= number_ennemies_C; i++) {
			for (int j = 0; j < NUMBER_BULLET; j++) {
				for (int k = 0; k < 4; k++) {
					if (ennemies_C[i].bullet_x4[j][k].B_exist == true) {
						if (checkImpact(ennemies_C[i].bullet_x4[j][k])) {
							ennemies_C[i].bullet_x4[j][k].B_exist = false;
							number_of_hearts--;
						}
					}
				}
			}
		}
		for (int i = 1; i <= number_ennemies_D; i++) {
			for (int j = 0; j < NUMBER_BULLET; j++) {
				if (ennemies_D[i].bullet_follow[j].B_exist == true) {
					if (checkImpact(ennemies_D[i].bullet_follow[j])) {
						ennemies_D[i].bullet_follow[j].B_exist = false;
						number_of_hearts--;
					}
				}
			}
		}
	}
	if (number_of_hearts <= 0 && loss.exist==false) {
		SDL_Rect a = { SCREEN_WIDTH / 2 - loss.O_Width * loss.phongto * 1 / 2, SCREEN_HEIGHT / 2 - loss.O_Height * loss.phongto * 1 / 2, loss.O_Width *loss.phongto,  loss.O_Height *loss.phongto };
		SDL_RenderCopy(gRenderer, loss.O_Texture, NULL, &a);
		if ( loss.phongto <1) {
			loss.phongto+=0.0025;
		}
	}
}
bool Player::checkImpact(Bullet& a) {
	if ((a.B_x + a.B_Width / 2) > P_x && (a.B_x + a.B_Width / 2) < (P_x + P_Width) && (a.B_y + a.B_Height / 2) > P_y && (a.B_y + a.B_Height / 2) < (P_y + P_Height)) {
		return true;
	}
	return false;
}