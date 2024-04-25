#pragma once
#include"Player.h"
#include "Declaration.h"
#include "Ennemies.h"
#include "FindAngle.h"
void Player::free()
{
	death[0].photo = 0;
	death[1].photo = 0;
	death[2].photo = 0;
	death[3].photo = 0;
	death[0].exist = true;
	death[1].exist = true;
	death[2].exist = true;
	death[3].exist = true;
	death[1].center_delta_x = 40;
	death[3].center_delta_x = -40;
	death[0].center_delta_y = 30;
	death[2].center_delta_y = -25;
	//support
	support_1;
	support_2;
	load_support_time = 0;
	load_bullet_support_time = 0;
	thbullet_support = 0;
	dis_player_support = 0;
	//bullet
	thbullet_simple = 0;
	//
	thbullet_x7 = 0;
	//
	thbullet_x5 = 0;
	//loại đạn
	bullet_type = 10;
	// địa chỉ trên màn hình lúc render ra
	center_x = 350;
	center_y = 700;
	// địa chỉ điểm bắt đầu (chưa cần dùng) (có thể là địa chỉ tâm)
	center_start_x = 0;
	center_start_y = 0;
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
	pause_screen_sensitivity[0] = 0.7;
	pause_screen_sensitivity[1] = 1;
	pause_screen_sensitivity[2] = 1.3;
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
				alpha = 255;
			}
			checkHit();
		}
		if (nhanchuot == true) {
			SDL_GetMouseState(&now_x, &now_y);
			if (center_x <= (SCREEN_WIDTH - width) && center_x>= 0 &&center_y>= 0 &&center_y<= (SCREEN_HEIGHT - height)) {
				if (center_x <= (SCREEN_WIDTH) &&center_x>= 0) {
					center_x += round((now_x - pre_x) * pause_screen_sensitivity[sensitivity_index]);
				}
				if (center_y <= (SCREEN_HEIGHT) &&center_y>= 0) {
					center_y += round((now_y - pre_y) * pause_screen_sensitivity[sensitivity_index]);
				}
				if (center_x <= 0) {
					center_x = 0;
				}
				if (center_x >= (SCREEN_WIDTH - width)) {
					center_x = (SCREEN_WIDTH - width);
				}
				if (center_y <= 0) {
					center_y = 0;
				}
				if (center_y >= (SCREEN_HEIGHT - height)) {
					center_y = (SCREEN_HEIGHT - height);
				}
			}
			pre_x = now_x;
			pre_y = now_y;
		}
		else {
			SDL_GetMouseState(&pre_x, &pre_y);
		}
		render();
		loadShoot();
		shoot();
		shootSupport();
		exist = true;
	}
	else if (number_of_hearts <= 0 && fight_screen_gameover.exist == false) {
		fight_screen_gameover.photo++;
		cout << fight_screen_gameover.photo << endl;
		SDL_Rect a = { SCREEN_WIDTH / 2 - fight_screen_gameover.width * fight_screen_gameover.ratio * 1 / 2, SCREEN_HEIGHT / 2 - fight_screen_gameover.height * fight_screen_gameover.ratio * 1 / 2, fight_screen_gameover.width * fight_screen_gameover.ratio,  fight_screen_gameover.height * fight_screen_gameover.ratio };
		SDL_RenderCopy(gRenderer, fight_screen_gameover.Texture, NULL, &a);
		if (fight_screen_gameover.ratio < 1) {
			fight_screen_gameover.ratio += 0.0025;
		}
		if (fight_screen_gameover.photo >= 500) {
			screen_status = GAMEOVER;
		}
		dem_death = (dem_death + 1) % 2;
		for (int i = 0; i < 4; i++) {
			if (death[i].exist == true) {
				death[i].frameth = death[i].photo / 10 + 1;
				death[i].alpha = 255 - death[i].photo * 3;
				death[i].center_x = center_x + death[i].center_delta_x;
				death[i].center_y = center_y + death[i].center_delta_y;
				death[i].render();
				if (dem_death == 0) {
					death[i].photo = (death[i].photo + 1) % 72;
					if (death[i].photo > 70) {
						death[i].alpha = 255;
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
			bullet_simple[thbullet_simple][0].center_x =center_x - 15;
			bullet_simple[thbullet_simple][0].center_y =center_y;
			bullet_simple[thbullet_simple][0].exist = true;
			//
			bullet_simple[thbullet_simple][1].center_x =center_x + 15;
			bullet_simple[thbullet_simple][1].center_y =center_y ;
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
				bullet_x7[thbullet_x7][i].center_x = bullet_x7[thbullet_x7][i].center_start_x = center_x + b;
				bullet_x7[thbullet_x7][i].center_y = bullet_x7[thbullet_x7][i].center_start_y = center_y + c;
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
				bullet_x5[thbullet_x5][i].center_x = bullet_x5[thbullet_x5][i].center_start_x =center_x + b;
				bullet_x5[thbullet_x5][i].center_y = bullet_x5[thbullet_x5][i].center_start_y =center_y + c;
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
		if (shield_dem % 50 == 0) {
			shield[thshield].exist = true;
			shield[thshield].ratio = 0.0;
			shield[thshield].alpha = 255;
			shield[thshield].red = 255;
			shield[thshield].green = 255;
			shield[thshield].blue = 255;
			shield[thshield].center_x = center_x;
			shield[thshield].center_y = center_y;
			thshield++;
			if (thshield == 5) {
				thshield = 0;
			}
		}
		for (int i = 0; i < 5; i++) {
			if (shield[i].exist == true) {
				shield[i].center_x = center_x;
				shield[i].center_y = center_y;
				shield[i].renderRatio();
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
			buff_shield = false;
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
void Player::loadSupport() {
	support_1.render();
	support_2.render();
	support_1.center_x =center_x + dis_player_support;
	support_2.center_x =center_x - dis_player_support;
	support_1.center_y =center_y - support_1.height / 2;
	support_2.center_y =center_y - support_2.height / 2;
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
			bullet_support_1[thbullet_support].center_x = bullet_support_1[thbullet_support].center_start_x = support_1.center_x ;
			bullet_support_1[thbullet_support].center_y = bullet_support_1[thbullet_support].center_start_y = support_1.center_y - bullet_support_1[thbullet_support].height/2;
			bullet_support_1[thbullet_support].center_delta_x = 1.00000000 * (x1 - bullet_support_1[thbullet_support].center_start_x );
			bullet_support_1[thbullet_support].center_delta_y = 1.00000000 * (y1 - bullet_support_1[thbullet_support].center_start_y );
			bullet_support_1[thbullet_support].slope = 1.00000000 * bullet_support_1[thbullet_support].center_delta_x / bullet_support_1[thbullet_support].center_delta_y;
			bullet_support_1[thbullet_support].exist = true;
			/////
			bullet_support_2[thbullet_support].center_x = bullet_support_2[thbullet_support].center_start_x = support_2.center_x ;
			bullet_support_2[thbullet_support].center_y = bullet_support_2[thbullet_support].center_start_y = support_2.center_y - bullet_support_2[thbullet_support].height/2;
			bullet_support_2[thbullet_support].center_delta_x = 1.00000000 * (x2 - bullet_support_2[thbullet_support].center_start_x);
			bullet_support_2[thbullet_support].center_delta_y = 1.00000000 * (y2 - bullet_support_2[thbullet_support].center_start_y);
			bullet_support_2[thbullet_support].slope = 1.00000000 * bullet_support_2[thbullet_support].center_delta_x / bullet_support_2[thbullet_support].center_delta_y;
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
				bullet_simple[i][j].render();
				bullet_simple[i][j].center_y -= BULLET_SPEED;
			}
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j <= 6; j++) {
			if (bullet_x7[i][j].exist == true) {
				bullet_x7[i][j].RenderBullet_StraightAngle();
			}
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++)
	{
		for (int j = 0; j <= 4; j++) {
			if (bullet_x5[i][j].exist == true) {
				bullet_x5[i][j].RenderBullet_StraightAngle();
			}
		}
	}
}
void Player::shootSupport() {
	for (int i = 0; i < NUMBER_BULLET; i++)
	{
		if(bullet_support_1[i].exist==true)
		bullet_support_1[i].RenderBullet_StraightSlope();
	}
	for (int i = 0; i < NUMBER_BULLET; i++)
	{
		if (bullet_support_2[i].exist == true)
		bullet_support_2[i].RenderBullet_StraightSlope();
	}
}
void Player::determineTheTarget(int& x1, int& y1, int& x2, int& y2) {
	double min1 = 1000000000;
	for (int i = 1; i <= number_ennemies_A; i++) {
		if ((calculateDis(ennemies_A[i].center_x, ennemies_A[i].center_y, support_1) <= min1) && ennemies_A[i].exist == true)
		{
			min1 = calculateDis(ennemies_A[i].center_x, ennemies_A[i].center_y, support_1);
			x1 = ennemies_A[i].center_x;
			y1 = ennemies_A[i].center_y;
		}
	}
	for (int i = 1; i <= number_ennemies_B; i++) {
		if ((calculateDis(ennemies_B[i].center_x, ennemies_B[i].center_y, support_1) <= min1) && ennemies_B[i].exist == true)
		{
			min1 = calculateDis(ennemies_B[i].center_x, ennemies_B[i].center_y, support_1);
			x1 = ennemies_B[i].center_x;
			y1 = ennemies_B[i].center_y;
		}
	}
	for (int i = 1; i <= number_ennemies_C; i++) {
		if ((calculateDis(ennemies_C[i].center_x, ennemies_C[i].center_y, support_1) <= min1) && ennemies_C[i].exist == true)
		{
			min1 = calculateDis(ennemies_C[i].center_x, ennemies_C[i].center_y, support_1);
			x1 = ennemies_C[i].center_x;
			y1 = ennemies_C[i].center_y;
		}
	}
	for (int i = 1; i <= number_ennemies_D; i++) {
		if ((calculateDis(ennemies_D[i].center_x, ennemies_D[i].center_y, support_1) <= min1) && ennemies_D[i].exist == true)
		{
			min1 = calculateDis(ennemies_D[i].center_x, ennemies_D[i].center_y, support_1);
			x1 = ennemies_D[i].center_x;
			y1 = ennemies_D[i].center_y;
		}
	}
	for (int i = 1; i <= number_ennemies_E; i++) {
		if ((calculateDis(ennemies_E[i].center_x, ennemies_E[i].center_y, support_2) <= min1) && ennemies_E[i].exist == true)
		{
			min1 = calculateDis(ennemies_E[i].center_x, ennemies_E[i].center_y, support_2);
			x1 = ennemies_E[i].center_x;
			y1 = ennemies_E[i].center_y;
		}
	}
	double min2 = 1000000000;
	for (int i = 1; i <= number_ennemies_A; i++) {
		if ((calculateDis(ennemies_A[i].center_x, ennemies_A[i].center_y, support_2) <= min2) && ennemies_A[i].exist == true)
		{
			min2 = calculateDis(ennemies_A[i].center_x, ennemies_A[i].center_y, support_2);
			x2 = ennemies_A[i].center_x;
			y2 = ennemies_A[i].center_y;
		}
	}
	for (int i = 1; i <= number_ennemies_B; i++) {
		if ((calculateDis(ennemies_B[i].center_x, ennemies_B[i].center_y, support_2) <= min2) && ennemies_B[i].exist == true)
		{
			min2 = calculateDis(ennemies_B[i].center_x, ennemies_B[i].center_y, support_2);
			x2 = ennemies_B[i].center_x;
			y2 = ennemies_B[i].center_y;
		}
	}
	for (int i = 1; i <= number_ennemies_C; i++) {
		if ((calculateDis(ennemies_C[i].center_x, ennemies_C[i].center_y, support_2) <= min2) && ennemies_C[i].exist == true)
		{
			min2 = calculateDis(ennemies_C[i].center_x, ennemies_C[i].center_y, support_2);
			x2 = ennemies_C[i].center_x;
			y2 = ennemies_C[i].center_y;
		}
	}
	for (int i = 1; i <= number_ennemies_D; i++) {
		if ((calculateDis(ennemies_D[i].center_x, ennemies_D[i].center_y, support_2) <= min2) && ennemies_D[i].exist == true)
		{
			min2 = calculateDis(ennemies_D[i].center_x, ennemies_D[i].center_y, support_2);
			x2 = ennemies_D[i].center_x;
			y2 = ennemies_D[i].center_y;
		}
	}
	for (int i = 1; i <= number_ennemies_E; i++) {
		if ((calculateDis(ennemies_E[i].center_x, ennemies_E[i].center_y, support_2) <= min2) && ennemies_E[i].exist == true)
		{
			min2 = calculateDis(ennemies_E[i].center_x, ennemies_E[i].center_y, support_2);
			x2 = ennemies_E[i].center_x;
			y2 = ennemies_E[i].center_y;
		}
	}
}
double Player::calculateDis(int center_x, int center_y, Object& b) {
	return ((center_x - b.center_x ) * (center_x - b.center_x ) + (center_y - b.center_y) * (center_y  - b.center_y));
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
		for (int k = 0; k < NUMBER_BULLET; k++) {
			if (buff_shield == true) {
				if (checkImpactShield(bullet_round[k].bullet_virtual)) {
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							bullet_round[k].bullet_around[i][j].good = true;
						}
					}
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (bullet_round[k].bullet_around[i][j].exist == true) {
						if (checkImpactBullet(bullet_round[k].bullet_around[i][j]) && bullet_round[k].bullet_around[i][j].good == false && behit == false) {
							bullet_round[k].bullet_around[i][j].free();
							number_of_hearts--;
							return true;
						}
					}
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < NUMBER_BULLET * 25; j++) {
				if (bullet_level[i][j].exist == true) {
					if (buff_shield == true) {
						checkImpactShield(bullet_level[i][j]);
					}
					if (checkImpactBullet(bullet_level[i][j]) && bullet_level[i][j].good == false && behit == false) {
						bullet_level[i][j].free();
						number_of_hearts--;
						return true;
					}
				}
			}
		}
		for (int i = 0; i < 1000; i++) {
			if (star[i].exist == true) {
					if (buff_shield == true) {
						checkImpactShield(star[i]);
					}
					if (checkImpactBullet(star[i]) && star[i].good == false && behit == false) {
						star[i].free();
						number_of_hearts--;
						return true;
					}
			}
		}
		checkLazer();
		checkBoom();
		// check item
		for (int j = 0; j < NUMBER_ITEM; j++) {
			if (item[j].exist == true) {
				checkImpactItem(item[j]);
			}
		}
		return false;
}


bool Player::checkImpactBullet(Bullet_Straight& a) {
	if ((a.center_x) > (center_x - width / 2) && (a.center_x) < (center_x + width / 2)
		&& (a.center_y) > (center_y - height / 2) && (a.center_y) < (center_y + height / 2)) {
		return true;
	}
	return false;
}
bool Player::checkImpactShield(Bullet_Straight& a) {
	int center_delta_x = a.center_x -  center_x;
	int center_delta_y = a.center_y  - center_y;
	if ((center_delta_x * center_delta_x + center_delta_y * center_delta_y <= 16900) )
	{
		
		if (a.good == false) {
			double angle1 = FindAngle(a.center_x, a.center_y ,center_x ,center_y );
			a.angle = (angle1) * 2 - a.angle + 180;
			while (a.angle >= 360) {
				a.angle = a.angle - 360;
			}
			a.center_start_x = a.center_x;
			a.center_start_y = a.center_y;
			a.good = true;
		}
	}
	return true;
}
void Player::checkImpactItem(Item& a) {
	if ((a.center_x) > (center_x - width / 2) && (a.center_x) < (a.center_x + width / 2)
		&& (a.center_y) > (center_y - height / 2) && (a.center_y) < (a.center_y + height / 2))
	{
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
	for (int i = 0; i < 2; i++) {
		if (lazer[0].exist == true) {
			int delta_x1 = (lazer[i].width / abs(cos(lazer[i].angle * PI / 180)) + abs(height * tan(lazer[i].angle * PI / 180)) + width) / 2;
			int center_x1 = lazer[i].center_x - (center_y - lazer[i].center_y) * tan(lazer[i].angle * PI / 180);
			item_example[3].center_x = center_x1;
			item_example[3].center_y = center_y;
			item_example[3].render();
			bool a = (((lazer[i].angle <= 0) && (lazer[i].angle >= -90)) ||((lazer[i].angle >= 0) && (lazer[i].angle <= 90)) || ((lazer[i].angle >= 270) && (lazer[i].angle <= 360))) && (center_y) > (boss.center_y + boss.height / 2);
			bool b = (((lazer[i].angle >= 90) && (lazer[i].angle <= 270)) && (center_y) < (boss.center_y + boss.height / 2));
			if (a || b) {
				if ((center_x < center_x1 + delta_x1 - 10) && (center_x > center_x1 - delta_x1 +10)) {
					success = true;
				}
			}
		}
	}
	return success;
}
bool Player::checkBoom() {
	bool success = false;
	for (int i = 0; i < 10; i++) {
		if (boom[i].explode_bool == true) {
			if ((center_x - boom[i].explode.center_x)*(center_x - boom[i].explode.center_x) + (center_y - boom[i].explode.center_y)*(center_y - boom[i].explode.center_y)
				<= (20+boom[i].explode.height/2* boom[i].explode.ratio)* (20+boom[i].explode.height / 2 * boom[i].explode.ratio) ){
				number_of_hearts--;
				success = true;
			}
		}
	}
	return success;
}