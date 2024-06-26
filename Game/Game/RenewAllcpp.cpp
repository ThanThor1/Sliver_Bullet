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
	prepare_to_press_pause = false;
	nhanchuot = false;
	number_ennemies_A = number_ennemies_B = number_ennemies_C = number_ennemies_D = number_ennemies_E = 0;
	wave_number_gameover_screen_text.start_count = 0;
	aliens_defeated_gameover_screen_text.start_count = 0;
	score_gameover_menu_screen_text.start_count = 0;
	bullet_ennemies_A_index = 0;
	bullet_ennemies_B_index = 0;
	bullet_ennemies_C_index = 0;
	bullet_ennemies_D_index = 0;
    bullet_ennemies_E_index = 0;
	wave_number  =  0;
	score_number = 0;
    aliens_defeated_number = 0;
	fight_screen_start.free();
	fight_screen_gameover.free();
}
void renewAllPlayer() {
	player.free();
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 2; j++) {
			player.bullet_simple[i][j].free();
			player.bullet_simple[i][j].damage = DAMAGE_BULLET_PLAYER;
			player.bullet_simple[i][j].speed = SPEED_BULLET_PLAYER;
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 7; j++) {
			bullet_x7[i][j].free();
			bullet_x7[i][j].damage = DAMAGE_BULLET_PLAYER;
			bullet_x7[i][j].speed = SPEED_BULLET_PLAYER;
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 5; j++) {
			player.bullet_x5[i][j].free();
			player.bullet_x5[i][j].damage = DAMAGE_BULLET_PLAYER;
			player.bullet_x5[i][j].speed = SPEED_BULLET_PLAYER;
		}
	}
	support_1.free();
	support_2.free();
	for (int i = 0; i < NUMBER_BULLET; i++) {
		player.bullet_support_1[i].free();
		player.bullet_support_2[i].free();
		player.bullet_support_1[i].damage = DAMAGE_BULLET_PLAYER;
		player.bullet_support_2[i].damage = DAMAGE_BULLET_PLAYER;
		player.bullet_support_1[i].speed = SPEED_BULLET_PLAYER;
		player.bullet_support_2[i].speed = SPEED_BULLET_PLAYER;
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
	boss.free();
}
void renewAllBullet() {
	for (int j = 0; j < NUMBER_BULLET; j++) {
		bullet_ennemies_A[j].free();
		bullet_ennemies_A[j].damage = DAMAGE_BULLET_ENNEMIES;
		bullet_ennemies_A[j].speed = SPEED_BULLET_ENNEMIES_A;
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		for (int k = 0; k < 3; k++) {
			bullet_ennemies_B[j][k].free();
			bullet_ennemies_B[j][k].damage = DAMAGE_BULLET_ENNEMIES;
			bullet_ennemies_B[j][k].speed = SPEED_BULLET_ENNEMIES_B;
		}
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		for (int k = 0; k < 4; k++) {
			bullet_ennemies_C[j][k].free();
			bullet_ennemies_C[j][k].damage = DAMAGE_BULLET_ENNEMIES;
			bullet_ennemies_C[j][k].speed = SPEED_BULLET_ENNEMIES_C;
		}
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		bullet_ennemies_D[j].free();
		bullet_ennemies_D[j].damage = DAMAGE_BULLET_ENNEMIES;
		bullet_ennemies_D[j].speed = SPEED_BULLET_ENNEMIES_D;
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		bullet_ennemies_E[j].free();
		bullet_ennemies_E[j].damage = DAMAGE_BULLET_ENNEMIES;
		bullet_ennemies_E[j].speed = SPEED_BULLET_ENNEMIES_E;
	}
}
void renewAllItem() {
	for (int i = 0; i < NUMBER_ITEM; i++) {
		item[i].free();
	}
}


