#pragma once
#include "RenewAll.h"
#include "Declaration.h"
void renewAll() {
	renewAllPlayer();
	renewAllEnnemies();
	renewAllBullet();
	renewAllItem();
	MAP = 1;
	loadmap_bool = false;
	number_ennemies_A = number_ennemies_B = number_ennemies_C = number_ennemies_D = number_ennemies_E = 0;
	fight_screen_start.free();
	fight_screen_gameover.free();
}
void renewAllPlayer() {
	player.free();
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 2; j++) {
			player.bullet_simple[i][j].free();
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 7; j++) {
			player.bullet_x7[i][j].free();
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 5; j++) {
			player.bullet_x5[i][j].free();
		}
	}
	support_1.free();
	support_2.free();
	player.bullet_support_1[0].free();
	player.bullet_support_2[0].free();
	for (int i = 0; i < NUMBER_BULLET; i++) {
		player.bullet_support_1[i].free();
		player.bullet_support_2[i].free();
	}
}
void renewAllEnnemies() {
	//ennemies
	for (int i = 1; i < NUMBER_ENNEMIES; i++) {
		ennemies_A[i].free();
		ennemies_A[i].death.free();
	}
	for (int i = 1; i < NUMBER_ENNEMIES; i++) {
		ennemies_B[i].free();
		ennemies_B[i].death.free();
	}
	for (int i = 1; i < NUMBER_ENNEMIES; i++) {
		ennemies_C[i].free();
		ennemies_C[i].death.free();
	}
	for (int i = 1; i < NUMBER_ENNEMIES; i++) {
		ennemies_D[i].free();
		ennemies_D[i].death.free();
	}
	for (int i = 1; i < NUMBER_ENNEMIES; i++) {
		ennemies_E[i].free();
		ennemies_E[i].death.free();
	}
}
void renewAllBullet() {
	for (int j = 0; j < NUMBER_BULLET; j++) {
		bullet_ennemies_A[j].free();
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		for (int k = 0; k < 3; k++) {
			bullet_ennemies_B[j][k].free();
		}
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		for (int k = 0; k < 4; k++) {
			bullet_ennemies_C[j][k].free();
		}
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		bullet_ennemies_D[j].free();
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		bullet_ennemies_E[j].free();
	}
}
void renewAllItem() {
	for (int i = 0; i < NUMBER_ITEM; i++) {
		item[i].free();
	}
}


