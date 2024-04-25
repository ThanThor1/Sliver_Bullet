#pragma once
#include"Ennemies.h"
#include"Declaration.h"
#include "LoadAll.h"
void Ennemies::getStart(int start_x1, int start_y1) {
	center_x = center_start_x = start_x1;
	center_y = center_start_y = start_y1;
}
void Ennemies::getFinish(int finish_x1, int finish_y1) {
	center_finish_x = finish_x1;
	center_finish_y = finish_y1;
}
void  Ennemies::getSlopeAngle(double slope1, double angle1) {
	slope = slope1;
	angle = angle1;
}
void  Ennemies::getDeltaxy() {
	center_delta_x = center_finish_x - center_start_x;
	center_delta_y = center_finish_y - center_start_y;
}
void Ennemies::checkHit(int& health) {
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 2; j++) {
			if (health > 0) {
				if (player.bullet_simple[i][j].exist == true) {
					if (checkImpact(player.bullet_simple[i][j])) {
						health -= player.bullet_simple[i][j].damage;
						player.bullet_simple[i][j].exist = false;
						player.bullet_simple[i][j].hit_bool = true;
					}
				}
			}
			if (player.bullet_simple[i][j].hit_bool == true) {
				loadExplode(player.bullet_simple[i][j]);
			}
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 5; j++) {
			if (health > 0) {
				if (player.bullet_x5[i][j].exist == true) {

					if (checkImpact(player.bullet_x5[i][j])) {
						health -= player.bullet_x5[i][j].damage;
						player.bullet_x5[i][j].exist = false;
						player.bullet_x5[i][j].hit_bool = true;
					}
				}
			}
			if (player.bullet_x5[i][j].hit_bool == true) {
				loadExplode(player.bullet_x5[i][j]);
			}
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 7; j++) {
			if (health > 0) {
				if (player.bullet_x7[i][j].exist == true) {
					if (checkImpact(player.bullet_x7[i][j])) {
						health -= player.bullet_x7[i][j].damage;
						player.bullet_x7[i][j].exist = false;
						player.bullet_x7[i][j].hit_bool = true;
					}
				}
			}
			if (player.bullet_x7[i][j].hit_bool == true) {
				loadExplode(player.bullet_x7[i][j]);
			}
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++) {
		if (health > 0) {
			if (player.bullet_support_1[i].exist == true) {
				if (checkImpact(player.bullet_support_1[i])) {
					health -= player.bullet_support_1[i].damage;
					player.bullet_support_1[i].exist = false;
					player.bullet_support_1[i].hit_bool = true;
				}
			}
			if (player.bullet_support_2[i].exist == true) {
				if (checkImpact(player.bullet_support_2[i])) {
					health -= player.bullet_support_2[i].damage;
					player.bullet_support_2[i].exist = false;
					player.bullet_support_2[i].hit_bool = true;
				}
			}
		}
		if (player.bullet_support_1[i].hit_bool == true) {
			loadExplode(player.bullet_support_1[i]);
		}
		if (player.bullet_support_2[i].hit_bool == true) {
			loadExplode(player.bullet_support_2[i]);
		}
	}
	// check đạn phản ngược.
	for (int j = 0; j < NUMBER_BULLET; j++) {
		if (bullet_ennemies_A[j].exist == true && bullet_ennemies_A[j].good == true) {
			if (health > 0) {
				if (checkImpact(bullet_ennemies_A[j])) {
					bullet_ennemies_A[j].free();
					health -= bullet_ennemies_A[j].damage;

				}
			}
		}
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		for (int k = 0; k < 3; k++) {
			if (bullet_ennemies_B[j][k].exist == true && bullet_ennemies_B[j][k].good == true) {
				if (health > 0) {
					if (checkImpact(bullet_ennemies_B[j][k])) {
						bullet_ennemies_B[j][k].free();
						health -= bullet_ennemies_B[j][k].damage;
					}
				}
			}
		}
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		for (int k = 0; k < 4; k++) {
			if (bullet_ennemies_C[j][k].exist == true && bullet_ennemies_C[j][k].good == true) {
				if (health > 0) {
					if (checkImpact(bullet_ennemies_C[j][k])) {
						bullet_ennemies_C[j][k].free();
						health -= bullet_ennemies_C[j][k].damage;
					}
				}
			}
		}
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		if (bullet_ennemies_D[j].exist == true && bullet_ennemies_D[j].good == true) {
			if (health > 0) {
				if (checkImpact(bullet_ennemies_D[j])) {
					bullet_ennemies_D[j].free();
					health -= bullet_ennemies_D[j].damage;
				}
			}
		}
	}

	for (int j = 0; j < NUMBER_BULLET; j++) {
		if (bullet_ennemies_E[j].exist == true && bullet_ennemies_E[j].good == true) {
			if (health > 0) {
				if (checkImpact(bullet_ennemies_E[j])) {
					bullet_ennemies_E[j].free();
					health -= bullet_ennemies_E[j].damage;
				}
			}
		}
	}
	if (death.exist == false && health <= 0) {
		if (death.photo == 0) {
			if (sound_bool == true)
				Mix_PlayChannel(-1, chunk_explode1, 0);
		}
		death.center_x = center_x;
		death.center_y = center_y;
		death.frameth =  death.photo / 10;
		death.alpha -= death.photo * 2;
		death.render();
		death.photo = (death.photo + 1) % 72;
		if (death.photo > 70) {
			aliens_defeated++;
			loadBuff();
			death.exist = true;
			death.alpha = 255;
			free();
		}
	}
}
bool Ennemies::checkImpact(Bullet_Straight& a) {
	if ((a.center_x) > (center_x-width/2) && (a.center_x) < (center_x + width/2) 
		&& (a.center_y) > (center_y - height/2) && (a.center_y) < (center_y + height / 2)) {
		return true;
	}
	return false;
}
void Ennemies::loadExplode(Bullet_Straight& b) {
	b.hit.frameth = b.hit.photo / 10 +1;
	b.hit.alpha  -= b.hit.photo * 4;
	b.hit.center_x = b.center_x;
	b.hit.center_y = b.center_y;
	b.hit.render();
	b.hit.photo = (b.hit.photo + 1) % 72;
	if (b.hit.photo > 70) {
		b.hit_bool = false;
		b.hit.alpha =255;
	}
}
void Ennemies::loadBuff() {
	int a;
	a = Rand(0, 1000) % 20;
	if (a <= 14) {
		a = 0;
	}
	else a -= 14;
	if (item_index == NUMBER_ITEM) {
		item_index = 0;
	}
	item[item_index] = item_example[a];
	item[item_index].center_x =center_x;
	item[item_index].center_y =center_y;
	item[item_index].exist = true;
	item_index++;
}
