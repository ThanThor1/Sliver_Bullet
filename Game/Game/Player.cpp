#pragma once
#include"Player.h"
#include "Declaration.h"
#include "Ennemies.h"
#include "FindAngle.h"
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
	//
	thbullet_x7 = 0;
	//
	thbullet_x5 = 0;
	//loại đạn
	bullet_type = 10;
	// địa chỉ trên màn hình lúc render ra
	x = 350;
	y = 700;
	// địa chỉ điểm bắt đầu (chưa cần dùng) (có thể là địa chỉ tâm)
	start_x = 0;
	start_y = 0;
	// khiên
	buff_shield = false;
	// hỗ trợ
	buff_support = false;
	// lazer
	buff_lazer = false;
	// trang thai anh
	photo = 0;
	number_of_hearts = 3;
	//
	exist = true;
}
void Player::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(Texture, red, green, blue);
}
void Player::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(Texture, blending);
}
void Player::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(Texture, alpha);
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
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	death[0].photo = 0;
	death[1].photo = 0;
	death[2].photo = 0;
	death[3].photo = 0;
	death[0].exist = true;
	death[1].exist = true;
	death[2].exist = true;
	death[3].exist = true;
	death[1].delta_x = 40;
	death[3].delta_x = -40;
	death[0].delta_y = 30;
	death[2].delta_y = -25;
	//Return success
	Texture = newTexture;
	return Texture != NULL;
}
void Player::loadFrame(SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	if  (number_of_hearts > 0) {
		if (behit == false) {
			behit = checkHit();
		}
		else {
			behit_dem++;
			if (alpha == 255) {
				doichieu = -1;
			}
			if (alpha == 100) {
				doichieu = 1;
			}
			alpha += doichieu;
			setAlpha(alpha);
			if (behit_dem == 500) {
				behit_dem = 0;
				behit = false;
				setAlpha(255);
			}
			checkHit();
		}
		if (nhanchuot == true) {
			SDL_GetMouseState(&now_x, &now_y);
			if (x <= (SCREEN_WIDTH - width) && x >= 0 && y >= 0 && y <= (SCREEN_HEIGHT - height)) {
				if (x <= (SCREEN_WIDTH) && x >= 0) {
					x += round((now_x - pre_x) * sensitivity[sensitivity_index]);
				}
				if (y <= (SCREEN_HEIGHT) && y >= 0) {
					y += round((now_y - pre_y) * sensitivity[sensitivity_index]);
				}
				if (x <= 0) {
					x = 0;
				}
				if (x >= (SCREEN_WIDTH - width)) {
					x = (SCREEN_WIDTH - width);
				}
				if (y <= 0) {
					y = 0;
				}
				if (y >= (SCREEN_HEIGHT - height)) {
					y = (SCREEN_HEIGHT - height);
				}
			}
			pre_x = now_x;
			pre_y = now_y;
		}
		else {
			SDL_GetMouseState(&pre_x, &pre_y);
		}
		SDL_Rect renderQuad = { x, y , width, height };
		SDL_RenderCopyEx(gRenderer, Texture, NULL, &renderQuad, angle, center, flip);
		loadShoot();
		shoot();
		shootSupport();
		exist = true;
	}
	else if (number_of_hearts <= 0 && gameover.exist == false) {
		SDL_Rect a = { SCREEN_WIDTH / 2 - gameover.width * gameover.ratio * 1 / 2, SCREEN_HEIGHT / 2 - gameover.height * gameover.ratio * 1 / 2, gameover.width * gameover.ratio,  gameover.height * gameover.ratio };
		SDL_RenderCopy(gRenderer, gameover.Texture, NULL, &a);
		if (gameover.ratio < 1) {
			gameover.ratio += 0.0025;
		}
		dem_death = (dem_death + 1) % 2;
		for (int i = 0; i < 4; i++) {
				if (death[i].exist == true) {
					a = { (death[i].photo / 10) * death[i].width / 7, 0, death[i].width / 7, death[i].height };
					death[i].setAlpha(255 - death[i].photo * 3);
					death[i].render(x + death[i].delta_x + width / 2 - death[i].width / 14, y + death[i].delta_y + height / 2 - death[i].height / 2, &a);
					if (dem_death == 0) {
						death[i].photo = (death[i].photo + 1) % 72;
						if (death[i].photo > 70) {
							death[i].setAlpha(255);
							death[i].exist = false;
						}
					}
				}
		}
	}
}
void Player::loadShoot() {
	load_bullet_time = (load_bullet_time + 1) % (delay_bullet + 1);
	if (load_bullet_time == delay_bullet) {
		if (bullet_type == NONE) {
			if (thbullet_simple == NUMBER_BULLET) {
				thbullet_simple = 0;
			}
			bullet_simple[thbullet_simple][0].x = x + (width - bullet_simple[thbullet_simple][0].width) / 2 - 15;
			bullet_simple[thbullet_simple][0].y = y - bullet_simple[thbullet_simple][0].height + 50;
			bullet_simple[thbullet_simple][0].exist = true;
			//
			bullet_simple[thbullet_simple][1].x = x + (width - bullet_simple[thbullet_simple][1].width) / 2 + 15;
			bullet_simple[thbullet_simple][1].y = y - bullet_simple[thbullet_simple][1].height + 50;
			bullet_simple[thbullet_simple][1].exist = true;
			thbullet_simple++;
		}
		if (bullet_type == BULLET_X7) {
			if (thbullet_x7 == NUMBER_BULLET) {
				thbullet_x7 = 0;
			}
			int a = -30 + 180;
			int b = -30;
			int c = 0;
			for (int i = 0; i <= 6; i++) {
				bullet_x7[thbullet_x7][i].x = bullet_x7[thbullet_x7][i].start_x = x + (width - bullet_x7[thbullet_x7][i].width) / 2 + b;
				bullet_x7[thbullet_x7][i].y = bullet_x7[thbullet_x7][i].start_y = y - bullet_x7[thbullet_x7][i].height + 50 + c;
				bullet_x7[thbullet_x7][i].exist = true;
				bullet_x7[thbullet_x7][i].angle = a;
				a += 10;
				b += 10;
				if (i >= 3) {
					c += 15;
				}
				else c -= 15;
			}
			thbullet_x7++;
			x7_dem++;
			if (x7_dem >= 20) {
				bullet_type = NONE;
				x7_dem = 0;
			}
		}
		if (bullet_type == BULLET_X5) {
			if (thbullet_x5 == NUMBER_BULLET) {
				thbullet_x5 = 0;
			}
			int a = -10 + 180;
			int b = -20;
			int c = 0;
			for (int i = 0; i <= 4; i++) {
				bullet_x5[thbullet_x5][i].x = bullet_x5[thbullet_x5][i].start_x = x + (width - bullet_x5[thbullet_x5][i].width) / 2 + b;
				bullet_x5[thbullet_x5][i].y = bullet_x5[thbullet_x5][i].start_y = y - bullet_x5[thbullet_x5][i].height + c;
				bullet_x5[thbullet_x5][i].exist = true;
				bullet_x5[thbullet_x5][i].angle = a;
				a += 5;
				b += 10;
				if (i >= 2) {
					c += 10;
				}
				else c -= 10;
			}
			thbullet_x5++;
			x5_dem++;
			if (x5_dem >= 20) {
				bullet_type = NONE;
				x5_dem = 0;
			}
		}
		if (sound_bool == true) {
			Mix_PlayChannel(-1, chunk_shoot, 0);
		}
	}
	if (buff_lazer == true) {
		lazer.exist = true;
		lazer.x = x + width / 2 - 72;
		lazer.y = y + height / 2 - 1325;
		loadLazer();
	}
	if (buff_support == true) {
		support_1.exist = true;
		support_2.exist = true;
		loadSupport();
		support_dem++;
		if (support_dem == 2000) {
			buff_support = false;
			support_dem = 0;
		}
	}
	if (buff_shield == true) {
		SDL_Rect a;
		if (shield_dem % 50 == 0) {
			shield[thshield].exist = true;
			shield[thshield].ratio = 0.0;
			shield[thshield].alpha = 255;
			thshield++;
			if (thshield == 5) {
				thshield = 0;
			}
		}
		for (int i = 0; i < 5; i++) {
			if (shield[i].exist == true) {
				shield[i].setAlpha(shield[i].alpha);
				a = { int(x + width / 2 - shield[i].width * shield[i].ratio * 1 / 2),  int(y + height / 2 - shield[i].height * shield[i].ratio * 1 / 2), int(shield[i].width * shield[i].ratio),  int(shield[i].height * shield[i].ratio) };
				SDL_RenderCopy(gRenderer, shield[i].Texture, NULL, &a);
				if (shield[i].ratio < 1) {
					shield[i].ratio += 1.0 / 254;
					shield[i].alpha--;
				}
				else {
					shield[i].exist = false;
				}
			}
		}
		shield_dem++;
		if (shield_dem == 2000) {
			buff_shield = true;
			shield_dem = 0;
		}
	}
	if (buff_speed_bullet == true) {
		if (delay_bullet >=40) {
			delay_bullet -= 7;
		}
		buff_speed_bullet = false;
	}
}
void Player::loadLazer() {
	load_bullet_time = 0;
	SDL_Rect cutLazer[12];
	for (int i = 0; i <= 11; i++) {
		cutLazer[i] = { i * 145,0,145,1300 };
	}
	lazer.render(lazer.x, lazer.y, &cutLazer[load_lazer_time / 5]);
	load_lazer_time++;
	if (load_lazer_time == 61)
	{
		load_lazer_time = 0;
		lazer.exist = false;
		buff_lazer = false;
	}
}
void Player::loadSupport() {
	support_1.render(support_1.x, support_1.y);
	support_2.render(support_2.x, support_2.y);
	support_1.x = x + width / 2 - support_1.width / 2 + dis_player_support;
	support_2.x = x + width / 2 - support_2.width / 2 - dis_player_support;
	support_1.y = y + height / 2 - support_1.height / 2;
	support_2.y = y + height / 2 - support_2.height / 2;
	if (dis_player_support < 60) {
		dis_player_support += 1;
	}
	else {
		loadBulletSupport();
	}
}
void Player::loadBulletSupport() {
	int x1 = -10; int y1 = -10;
	int x2 = -10; int y2 = -10;
	determineTheTarget(x1, y1, x2, y2);
	if (thbullet_support == NUMBER_BULLET) {
		thbullet_support = 0;
	}
	load_bullet_support_time = (load_bullet_support_time + 1) % DELAY_BULLET + 1;
	if (load_bullet_support_time == DELAY_BULLET) {
		if (x1 > 0 && y1 > 0 && x2 > 0 && y2 > 0) {
			bullet_support_1[thbullet_support].x = bullet_support_1[thbullet_support].start_x = support_1.x + (support_1.width - bullet_support_1[thbullet_support].width) / 2;
			bullet_support_1[thbullet_support].y = bullet_support_1[thbullet_support].start_y = support_1.y - bullet_support_1[thbullet_support].height;
			bullet_support_1[thbullet_support].delta_x = 1.00000000 * (x1 - (bullet_support_1[thbullet_support].start_x + bullet_support_1[thbullet_support].width / 2));
			bullet_support_1[thbullet_support].delta_y = 1.00000000 * (y1 - (bullet_support_1[thbullet_support].start_y + bullet_support_1[thbullet_support].height / 2));
			bullet_support_1[thbullet_support].slope = 1.00000000 * bullet_support_1[thbullet_support].delta_x / bullet_support_1[thbullet_support].delta_y;
			bullet_support_1[thbullet_support].exist = true;
			/////
			bullet_support_2[thbullet_support].x = bullet_support_2[thbullet_support].start_x = support_2.x + (support_2.width - bullet_support_2[thbullet_support].width) / 2;
			bullet_support_2[thbullet_support].y = bullet_support_2[thbullet_support].start_y = support_2.y - bullet_support_2[thbullet_support].height;
			bullet_support_2[thbullet_support].delta_x = 1.00000000 * (x2 - (bullet_support_2[thbullet_support].start_x + bullet_support_2[thbullet_support].width / 2));
			bullet_support_2[thbullet_support].delta_y = 1.00000000 * (y2 - (bullet_support_2[thbullet_support].start_y + bullet_support_2[thbullet_support].height / 2));
			bullet_support_2[thbullet_support].slope = 1.00000000 * bullet_support_2[thbullet_support].delta_x / bullet_support_2[thbullet_support].delta_y;
			bullet_support_2[thbullet_support].exist = true;
			thbullet_support++;
			if (sound_bool == true) {
				Mix_PlayChannel(-1, chunk_shoot, 0);
			}
		}
	}
}
void Player::shoot() {
	for (int i = 0; i < NUMBER_BULLET; i++)
	{
		for (int j = 0; j <= 1; j++) {
			if (bullet_simple[i][j].exist == true)
			{
				bullet_simple[i][j].render(bullet_simple[i][j].x, bullet_simple[i][j].y);
				bullet_simple[i][j].y -= BULLET_SPEED;
			}
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j <= 6; j++) {
			bullet_x7[i][j].RenderBullet_StraightAngle();
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++)
	{
		for (int j = 0; j <= 4; j++) {
			bullet_x5[i][j].RenderBullet_StraightAngle();
		}
	}
}
void Player::shootSupport() {
	for (int i = 0; i < NUMBER_BULLET; i++)
	{
		bullet_support_1[i].RenderBullet_StraightSlope();
	}
	for (int i = 0; i < NUMBER_BULLET; i++)
	{
		bullet_support_2[i].RenderBullet_StraightSlope();
	}
}
void Player::determineTheTarget(int& x1, int& y1, int& x2, int& y2) {
	double min1 = 1000000000;
	for (int i = 1; i <= number_ennemies_A; i++) {
		if ((calculateDis(ennemies_A[i].x, ennemies_A[i].y, ennemies_A[i].width, ennemies_A[i].height, support_1) <= min1) && ennemies_A[i].exist == true)
		{
			min1 = calculateDis(ennemies_A[i].x, ennemies_A[i].y, ennemies_A[i].width, ennemies_A[i].height, support_1);
			x1 = ennemies_A[i].x + ennemies_A[i].width / 2;
			y1 = ennemies_A[i].y + ennemies_A[i].width / 2;
		}
	}
	for (int i = 1; i <= number_ennemies_B; i++) {
		if ((calculateDis(ennemies_B[i].x, ennemies_B[i].y, ennemies_B[i].width, ennemies_B[i].height, support_1) <= min1) && ennemies_B[i].exist == true)
		{
			min1 = calculateDis(ennemies_B[i].x, ennemies_B[i].y, ennemies_B[i].width, ennemies_B[i].height, support_1);
			x1 = ennemies_B[i].x + ennemies_B[i].width / 2;
			y1 = ennemies_B[i].y + ennemies_B[i].width / 2;
		}
	}
	for (int i = 1; i <= number_ennemies_C; i++) {
		if ((calculateDis(ennemies_C[i].x, ennemies_C[i].y, ennemies_C[i].width, ennemies_C[i].height, support_1) <= min1) && ennemies_C[i].exist == true)
		{
			min1 = calculateDis(ennemies_C[i].x, ennemies_C[i].y, ennemies_C[i].width, ennemies_C[i].height, support_1);
			x1 = ennemies_C[i].x + ennemies_C[i].width / 2;
			y1 = ennemies_C[i].y + ennemies_C[i].width / 2;
		}
	}
	for (int i = 1; i <= number_ennemies_D; i++) {
		if ((calculateDis(ennemies_D[i].x, ennemies_D[i].y, ennemies_D[i].width, ennemies_D[i].height, support_1) <= min1) && ennemies_D[i].exist == true)
		{
			min1 = calculateDis(ennemies_D[i].x, ennemies_D[i].y, ennemies_D[i].width, ennemies_D[i].height, support_1);
			x1 = ennemies_D[i].x + ennemies_D[i].width / 2;
			y1 = ennemies_D[i].y + ennemies_D[i].width / 2;
		}
	}
	for (int i = 1; i <= number_ennemies_E; i++) {
		if ((calculateDis(ennemies_E[i].x, ennemies_E[i].y, ennemies_E[i].width, ennemies_E[i].height, support_2) <= min1) && ennemies_E[i].exist == true)
		{
			min1 = calculateDis(ennemies_E[i].x, ennemies_E[i].y, ennemies_E[i].width, ennemies_E[i].height, support_2);
			x1 = ennemies_E[i].x + ennemies_E[i].width / 2;
			y1 = ennemies_E[i].y + ennemies_E[i].width / 2;
		}
	}
	double min2 = 1000000000;
	for (int i = 1; i <= number_ennemies_A; i++) {
		if ((calculateDis(ennemies_A[i].x, ennemies_A[i].y, ennemies_A[i].width, ennemies_A[i].height, support_2) <= min2) && ennemies_A[i].exist == true)
		{
			min2 = calculateDis(ennemies_A[i].x, ennemies_A[i].y, ennemies_A[i].width, ennemies_A[i].height, support_2);
			x2 = ennemies_A[i].x + ennemies_A[i].width / 2;
			y2 = ennemies_A[i].y + ennemies_A[i].width / 2;
		}
	}
	for (int i = 1; i <= number_ennemies_B; i++) {
		if ((calculateDis(ennemies_B[i].x, ennemies_B[i].y, ennemies_B[i].width, ennemies_B[i].height, support_2) <= min2) && ennemies_B[i].exist == true)
		{
			min2 = calculateDis(ennemies_B[i].x, ennemies_B[i].y, ennemies_B[i].width, ennemies_B[i].height, support_2);
			x2 = ennemies_B[i].x + ennemies_B[i].width / 2;
			y2 = ennemies_B[i].y + ennemies_B[i].width / 2;
		}
	}
	for (int i = 1; i <= number_ennemies_C; i++) {
		if ((calculateDis(ennemies_C[i].x, ennemies_C[i].y, ennemies_C[i].width, ennemies_C[i].height, support_2) <= min2) && ennemies_C[i].exist == true)
		{
			min2 = calculateDis(ennemies_C[i].x, ennemies_C[i].y, ennemies_C[i].width, ennemies_C[i].height, support_2);
			x2 = ennemies_C[i].x + ennemies_C[i].width / 2;
			y2 = ennemies_C[i].y + ennemies_C[i].width / 2;
		}
	}
	for (int i = 1; i <= number_ennemies_D; i++) {
		if ((calculateDis(ennemies_D[i].x, ennemies_D[i].y, ennemies_D[i].width, ennemies_D[i].height, support_2) <= min2) && ennemies_D[i].exist == true)
		{
			min2 = calculateDis(ennemies_D[i].x, ennemies_D[i].y, ennemies_D[i].width, ennemies_D[i].height, support_2);
			x2 = ennemies_D[i].x + ennemies_D[i].width / 2;
			y2 = ennemies_D[i].y + ennemies_D[i].width / 2;
		}
	}
	for (int i = 1; i <= number_ennemies_E; i++) {
		if ((calculateDis(ennemies_E[i].x, ennemies_E[i].y, ennemies_E[i].width, ennemies_E[i].height, support_2) <= min2) && ennemies_E[i].exist == true)
		{
			min2 = calculateDis(ennemies_E[i].x, ennemies_E[i].y, ennemies_E[i].width, ennemies_E[i].height, support_2);
			x2 = ennemies_E[i].x + ennemies_E[i].width / 2;
			y2 = ennemies_E[i].y + ennemies_E[i].width / 2;
		}
	}
}
double Player::calculateDis(int x, int y, int width, int height, Object& b) {
	return ((x + width / 2 - b.x - b.width / 2) * (x + width / 2 - b.x - b.width / 2) + (y + height / 2 - b.y - b.height / 2) * (y + height / 2 - b.y - b.height / 2));
}
bool Player::checkHit() {
		for (int j = 0; j < NUMBER_BULLET; j++) {
			if (bullet_ennemies_A[j].exist == true) {
				if (buff_shield == true) {
					checkImpactShield(bullet_ennemies_A[j]);
				}
				if (checkImpactBullet(bullet_ennemies_A[j]) && bullet_ennemies_A[j].good == false && behit==false) {
					bullet_ennemies_A[j].free();
					number_of_hearts--;
					return true;
				}
			}
		}
		for (int j = 0; j < NUMBER_BULLET; j++) {
			for (int k = 0; k < 3; k++) {
				if (bullet_ennemies_B[j][k].exist == true) {
					if (buff_shield == true) {
						checkImpactShield(bullet_ennemies_B[j][k]);
					}
					if (checkImpactBullet(bullet_ennemies_B[j][k]) && bullet_ennemies_B[j][k].good == false && behit == false) {
						bullet_ennemies_B[j][k].free();
						number_of_hearts--;
						return true;
					}
				}
			}
		}
		for (int j = 0; j < NUMBER_BULLET; j++) {
			for (int k = 0; k < 4; k++) {
				if (buff_shield == true) {
					checkImpactShield(bullet_ennemies_C[j][k]);
				}
				if (bullet_ennemies_C[j][k].exist == true && bullet_ennemies_C[j][k].good == false && behit == false) {
					if (checkImpactBullet(bullet_ennemies_C[j][k])) {
						bullet_ennemies_C[j][k].free();
						number_of_hearts--;
						return true;
					}
				}

			}
		}
		for (int j = 0; j < NUMBER_BULLET; j++) {
			if (bullet_ennemies_D[j].exist == true) {
				if (buff_shield == true) {
					checkImpactShield(bullet_ennemies_D[j]);
				}
				if (checkImpactBullet(bullet_ennemies_D[j]) && bullet_ennemies_D[j].good == false && behit == false) {
					bullet_ennemies_D[j].free();
					number_of_hearts--;
					return true;
				}
			}

		}
		for (int j = 0; j < NUMBER_BULLET; j++) {
			if (bullet_ennemies_E[j].exist == true) {
				if (buff_shield == true) {
					checkImpactShield(bullet_ennemies_E[j]);
				}
				if (checkImpactBullet(bullet_ennemies_E[j]) && bullet_ennemies_E[j].good == false && behit == false) {
					bullet_ennemies_E[j].free();
					number_of_hearts--;
					return true;
				}
			}
		}
		checkLazer();
			// check item
		for (int j = 0; j < NUMBER_ITEM; j++) {
			checkImpactItem(item[j]);
		}
		return false;
}
bool Player::checkImpactBullet(Bullet_Straight& a) {
	if ((a.x + a.width / 2) > x && (a.x + a.width / 2) < (x + width) && (a.y + a.height / 2) > y && (a.y + a.height / 2) < (y + height)) {
		return true;
	}
	return false;
}
bool Player::checkImpactShield(Bullet_Straight& a) {
	int delta_x = (a.x + a.width / 2) - (x + width / 2);
	int delta_y = (a.y + a.height / 2) - (y + height / 2);
	if ((delta_x * delta_x + delta_y * delta_y <= 16900) )
	{
		if (a.good == false) {
			double angle1 = FindAngle(a.x + a.width / 2, a.y + a.height / 2, x + width / 2, y + height / 2);
			a.angle = (angle1) * 2 - a.angle + 180;
			while (a.angle >= 360) {
				a.angle = a.angle - 360;
			}
			a.start_x = a.x;
			a.start_y = a.y;
			a.good = true;
		}
	}
	return true;
}
void Player::checkImpactItem(Item& a) {
	if ((a.x + a.width / 2) > x && (a.x + a.width / 2) < (x + width) && (a.y + a.height / 2) > y && (a.y + a.height / 2) < (y + height) && a.exist==true) {
		Mix_PlayChannel(-1, chunk_item, 0);
		if (a.buff_type == SHIELD) {
			buff_shield = true;
		}
		else if (a.buff_type == SUPPORT) {
			buff_support = true;
		}
		else if (a.buff_type == SPEED_BULLET) {
			buff_speed_bullet = true;
		}
		else if (a.buff_type == BULLET_X5) {
			bullet_type = BULLET_X5;
		}
		else if (a.buff_type == BULLET_X7) {
			bullet_type = BULLET_X7;
		}
		a.exist = false;
	}
}
bool Player:: checkLazer() {
	bool success = false;
	/*for (int i = 0; i < 3; i++) {
		int delta_x1 = (lazer_boss[i].width / abs(cos(lazer_boss[i].angle * PI / 180)) + abs(height * tan(lazer_boss[i].angle * PI / 180)) + width) / 2;
		int center_x1 = boss.x + boss.width / 2 - ((y + height / 2) - (boss.y + boss.height / 2)) * tan(lazer_boss[i].angle * PI / 180);
		bool a = (((lazer_boss[i].angle >= 0) && (lazer_boss[i].angle <= 90)) || ((lazer_boss[i].angle >= 270) && (lazer_boss[i].angle <= 360))) && (y + height / 2) > (boss.y + boss.height / 2);
		bool b = (((lazer_boss[i].angle >= 90) && (lazer_boss[i].angle <= 270)) && (y + height / 2) < (boss.y + boss.height / 2));
		if (a || b) {
			if (((x + width / 2) < center_x1 + delta_x1) && ((x + width / 2) > center_x1 - delta_x1)) {
				success = true;
			}
		}
	}*/
	return success;
}