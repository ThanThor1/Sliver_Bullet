#pragma once
#include"Ennemies.h"
#include"Declaration.h"
#include "LoadAll.h"
void Ennemies::getStart(int start_x, int start_y) {
	E_x = E_start_x = start_x;
	E_y = E_start_y = start_y;
	int a;
	a = Rand(0, 1000) % 10;
	if (a <= 5) {
		a = 0;
	}
	else a -= 5;
	buff.buff_type = a;
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
void Ennemies::checkHit(int &health) {
	if (health > 0) {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 2; j++) {
				if (player.bullet_simple[i][j].B_exist == true) {
					if (checkImpact(player.bullet_simple[i][j])) {
						health -= player.bullet_simple[i][j].B_damage;
						player.bullet_simple[i][j].B_exist = false;
						player.bullet_simple[i][j].hit_bool = true;
					}
				}
				if (player.bullet_simple[i][j].hit_bool == true) {
					loadExplode(player.bullet_simple[i][j]);
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 5; j++) {
				if (player.bullet_x5[i][j].B_exist == true) {
					if (checkImpact(player.bullet_x5[i][j])) {
						health -= player.bullet_x5[i][j].B_damage;
						player.bullet_x5[i][j].B_exist  = false;
						player.bullet_x5[i][j].hit_bool = true;
					}
				}
				if (player.bullet_x5[i][j].hit_bool == true) {
					loadExplode(player.bullet_x5[i][j]);
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 7; j++) {
				if (player.bullet_x7[i][j].B_exist == true) {
					if (checkImpact(player.bullet_x7[i][j])) {
						health -= player.bullet_x7[i][j].B_damage;
						player.bullet_x7[i][j].B_exist = false;
						player.bullet_x7[i][j].hit_bool = true;
					}
				}
				if (player.bullet_x7[i][j].hit_bool == true) {
					loadExplode(player.bullet_x7[i][j]);
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			if (player.bullet_support_1[i].B_exist == true) {
				if (checkImpact(player.bullet_support_1[i])) {
					health -= player.bullet_support_1[i].B_damage;
					player.bullet_support_1[i].B_exist = false;
					player.bullet_support_1[i].hit_bool = true;
				}
			}
			if (player.bullet_support_2[i].B_exist == true) {
				if (checkImpact(player.bullet_support_2[i])) {
					health -= player.bullet_support_2[i].B_damage;
					player.bullet_support_2[i].B_exist = false;
					player.bullet_support_2[i].hit_bool = true;
				}
			}
			if (player.bullet_support_1[i].hit_bool == true) {
				loadExplode(player.bullet_support_1[i]);
			}
			if (player.bullet_support_2[i].hit_bool == true) {
				loadExplode(player.bullet_support_2[i]);
			}
		}
		if (player.lazer.exist == true) {
			if (checkLazer()) {
				health -= player.lazer.damage;
			}
		}
		// check đạn phản ngược.
		for (int i = 1; i <= number_ennemies_A; i++) {
			for (int j = 0; j < NUMBER_BULLET; j++) {
				if (ennemies_A[i].bullet_simple[j].B_exist == true && ennemies_A[i].bullet_simple[j].phandan == true) {
					if (checkImpact(ennemies_A[i].bullet_simple[j])) {
						ennemies_A[i].bullet_simple[j].B_exist = false;
						health -= ennemies_A[i].bullet_simple[j].B_damage;
				
					}
				}
			}
		}
		for (int i = 1; i <= number_ennemies_B; i++) {
			for (int j = 0; j < NUMBER_BULLET; j++) {
				for (int k= 0; k < 3; k++) {
					if (ennemies_B[i].bullet_x3[j][k].B_exist == true && ennemies_B[i].bullet_x3[j][k].phandan == true) {
						if (checkImpact(ennemies_B[i].bullet_x3[j][k])) {
							ennemies_B[i].bullet_x3[j][k].B_exist = false;
							health -= ennemies_B[i].bullet_x3[j][k].B_damage;
						}
					}
					
				}
			}
		}
		for (int i = 1; i <= number_ennemies_C; i++) {
			for (int j = 0; j < NUMBER_BULLET; j++) {
				for (int k = 0; k < 4; k++) {
					if (ennemies_C[i].bullet_x4[j][k].B_exist == true && ennemies_C[i].bullet_x4[j][k].phandan == true) {
						if (checkImpact(ennemies_C[i].bullet_x4[j][k])) {
							ennemies_C[i].bullet_x4[j][k].B_exist = false;
							health -= ennemies_C[i].bullet_x4[j][k].B_damage;
						}
					}
				}
			}
		}
		for (int i = 1; i <= number_ennemies_D; i++) {
			for (int j = 0; j < NUMBER_BULLET; j++) {
				if (ennemies_D[i].bullet_follow[j].B_exist == true && ennemies_D[i].bullet_follow[j].phandan == true) {
					if (checkImpact(ennemies_D[i].bullet_follow[j])) {
						ennemies_D[i].bullet_follow[j].B_exist = false;
						health -= ennemies_D[i].bullet_follow[j].B_damage;
					}
				}
			}
		}
	}
	if (death.exist==false && health<=0) {
		SDL_Rect a;
		a = { (death.photo / 10) * death.O_Width / 7, 0, death.O_Width /7, death.O_Height};
		death.setAlpha(255- death.photo*2);
		if (death.photo == 0) {
			if (sound_bool == true)
			Mix_PlayChannel(-1, chunk_explode1, 0);
		}
		death.render(E_x+E_Width/2 - death.O_Width/14, E_y + E_Height / 2 - death.O_Height/2, &a);
		death.photo = (death.photo + 1) % 72;
		if (death.photo > 70) {
			loadBuff();
			death.exist = true;
			death.setAlpha(255);
		}
	}
	if (health <= 0) {
		if (buff.exist == true) {
			buff.renderBuff(buff.O_x, buff.O_y);
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
void Ennemies::loadExplode(Bullet& b) {
	SDL_Rect a[7];
	for (int i = 0; i < 6; i++) {
		a[i] = { i * b.hit.O_Width / 6, 0, b.hit.O_Width / 6, b.hit.O_Height };
	}
	b.hit.setAlpha(255 - b.hit.photo * 4);
	b.hit.render(b.B_x + b.B_Width / 2 - b.hit.O_Width / 12, b.B_y + b.B_Height / 2 - b.hit.O_Height / 2, &a[b.hit.photo / 10]);
	b.hit.photo = (b.hit.photo + 1) % 72;
	if (b.hit.photo > 70) {
		b.hit_bool = false;
		b.hit.setAlpha(255);
	}
}
void Ennemies::loadBuff() {
	if (!(buff.buff_type == NONE)) {
		buff.O_x = E_x;
		buff.O_y = E_y;
		buff.exist = true;
	}
}
