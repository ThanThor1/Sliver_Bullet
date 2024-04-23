#pragma once
#include"Ennemies.h"
#include"Declaration.h"
#include "LoadAll.h"
void Ennemies::getStart(int start_x1, int start_y1) {
	x = start_x = start_x1;
	y = start_y = start_y1;
}
void Ennemies::getFinish(int finish_x1, int finish_y1) {
	finish_x = finish_x1;
	finish_y = finish_y1;
}
void  Ennemies::getSlopeAngle(double slope1, double angle1) {
	slope = slope1;
	angle = angle1;
}
void  Ennemies::getDeltaxy() {
	delta_x = finish_x - start_x;
	delta_y = finish_y - start_y;
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
		SDL_Rect a;
		a = { (death.photo / 10) * death.width / 7, 0, death.width / 7, death.height };
		death.setAlpha(255 - death.photo * 2);
		death.render(x + width / 2 - death.width / 14, y + height / 2 - death.height / 2, &a);
		death.photo = (death.photo + 1) % 72;
		if (death.photo > 70) {
			loadBuff();
			death.exist = true;
			death.setAlpha(255);
			free();
		}
	}
}
bool Ennemies::checkImpact(Bullet_Straight& a) {
	if ((a.x + a.width / 2) > x && (a.x + a.width / 2) < (x + width) && (a.y + a.height / 2) > y && (a.y + a.height / 2) < (y + height)) {
		return true;
	}
	return false;
}
void Ennemies::loadExplode(Bullet_Straight& b) {
	SDL_Rect a[7];
	for (int i = 0; i < 6; i++) {
		a[i] = { i * b.hit.width / 6, 0, b.hit.width / 6, b.hit.height };
	}
	b.hit.setAlpha(255 - b.hit.photo * 4);
	b.hit.render(b.x + b.width / 2 - b.hit.width / 12, b.y + b.height / 2 - b.hit.height / 2, &a[b.hit.photo / 10]);
	b.hit.photo = (b.hit.photo + 1) % 72;
	if (b.hit.photo > 70) {
		b.hit_bool = false;
		b.hit.setAlpha(255);
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
	item[item_index].x = x + width / 2 - item[item_index].width / 2;
	item[item_index].y = y + height / 2 - item[item_index].height / 2;
	item[item_index].exist = true;
	item_index++;
}
