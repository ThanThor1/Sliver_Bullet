#pragma once
#include "LoadAll.h"
#include "Wave.h"
#include"Declaration.h"
#include"fstream"
void  loadAll() {
	loadAllSound();
	loadAllEnnemies();
	loadAllPlayer();
	loadAllIcon();
	loadAllItem();
	loadAllText();
}
void loadAllText() {
	score_fight_screen_text.loadFont("font//font.ttf", 30);
	wave_number_gameover_screen_text.loadFont("font//font.ttf", 33);
	score_gameover_menu_screen_text.loadFont("font//font.ttf", 33);
	aliens_defeated_gameover_screen_text.loadFont("font//font.ttf", 33);
}
void loadAllMap() {
	cout << MAP;
	ifstream get_map;
	switch (MAP) {
	case WAVE_1:
		get_map.open("wave//wave1.txt");
		break;
	case WAVE_2:
		get_map.open("wave//wave2.txt");
		break;
	case WAVE_3:
		get_map.open("wave//wave3.txt");
		break;
	case WAVE_4:
		get_map.open("wave//wave4.txt");
		break;
	}
	for (int i = 0; i < NUMBER_MAX_HEIGHT; i++) {
		for (int j = 0; j < NUMBER_MAX_WIDTH; j++) {
			get_map >> map[i][j];
		}
	}
	get_map.close();
	for (int i = 0; i < NUMBER_MAX_HEIGHT; i++) {
		for (int j = 0; j < NUMBER_MAX_WIDTH; j++) {
			if (map[i][j] == "a") {
				ennemies_A[stoi(map[i][j + 1])].getStart(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				number_ennemies_A++;
			}
			else if (map[i][j] == "A") {
				ennemies_A[stoi(map[i][j + 1])].getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				ennemies_A[stoi(map[i][j + 1])].getDeltaxy();
			}
			else if (map[i][j] == "b") {
				ennemies_B[stoi(map[i][j + 1])].getStart(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				number_ennemies_B++;
			}
			else if (map[i][j] == "B") {
				ennemies_B[stoi(map[i][j + 1])].getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				ennemies_B[stoi(map[i][j + 1])].getDeltaxy();
			}
			else if (map[i][j] == "c") {
				ennemies_C[stoi(map[i][j + 1])].getStart(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				number_ennemies_C++;
			}
			else if (map[i][j] == "C") {
				ennemies_C[stoi(map[i][j + 1])].getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				ennemies_C[stoi(map[i][j + 1])].getDeltaxy();
			}
			else if (map[i][j] == "d") {
				ennemies_D[stoi(map[i][j + 1])].getStart(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				number_ennemies_D++;
			}
			else if (map[i][j] == "D") {
				ennemies_D[stoi(map[i][j + 1])].getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				ennemies_D[stoi(map[i][j + 1])].getDeltaxy();
			}
			else if (map[i][j] == "e") {
				ennemies_E[stoi(map[i][j + 1])].getStart(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				number_ennemies_E++;
			}
			else if (map[i][j] == "E") {
				ennemies_E[stoi(map[i][j + 1])].getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				ennemies_E[stoi(map[i][j + 1])].getDeltaxy();
			}
			else if (map[i][j] == "s") {
				boss.getStart(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
			}
			else if (map[i][j] == "S") {
				boss.getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
			}
		}
	}
}
void loadAllItem() {
	item_example[SHIELD].loadFromFile("picture//item/buff_shield.png",1);
	item_example[SHIELD].buff_type = SHIELD;
	item_example[SUPPORT].loadFromFile("picture//item/buff_support.png",1);
	item_example[SUPPORT].buff_type = SUPPORT;
	item_example[SPEED_BULLET].loadFromFile("picture//item/buff_speed.png",1);
	item_example[SPEED_BULLET].buff_type = SPEED_BULLET;
	item_example[BULLET_X5].loadFromFile("picture//item/buff_x5.png",1);
	item_example[BULLET_X5].buff_type = BULLET_X5;
	item_example[BULLET_X7].loadFromFile("picture//item/buff_x7.png",1);
	item_example[BULLET_X7].buff_type = BULLET_X7;
}
void loadAllSound() {
	chunk_gameover = Mix_LoadWAV("sound_and_music//chunk_gameover.mp3");
	music_menu = Mix_LoadMUS("sound_and_music//music_menu.mp3");
	music_fight = Mix_LoadMUS("sound_and_music//music_fight.mp3");
	chunk_mouse = Mix_LoadWAV("sound_and_music//chunk_mouse.mp3");
	chunk_shoot = Mix_LoadWAV("sound_and_music//chunk_shoot.mp3");
	chunk_explode1 = Mix_LoadWAV("sound_and_music//chunk_explode1.mp3");
	chunk_explode2 = Mix_LoadWAV("sound_and_music//chunk_explode2.mp3");
	chunk_item = Mix_LoadWAV("sound_and_music//chunk_item.mp3");
}
void loadAllEnnemies() {
	
	// đạn cho ennemies
	bullet_ennemies_A[0].loadFromFile("picture//Bullet_ennemies/1.png",1);
	bullet_ennemies_A[0].damage = 3;
	for (int j = 0; j < NUMBER_BULLET; j++) {
		bullet_ennemies_A[j] = bullet_ennemies_A[0];
	}
	bullet_ennemies_B[0][0].loadFromFile("picture//Bullet_ennemies/2.png",1);
	bullet_ennemies_B[0][0].damage = 3;
	for (int j = 0; j < NUMBER_BULLET; j++) {
		for (int k = 0; k < 3; k++) {
			bullet_ennemies_B[j][k] = bullet_ennemies_B[0][0];
		}
	}
	bullet_ennemies_C[0][0].loadFromFile("picture//Bullet_ennemies/3.png",1);
	bullet_ennemies_C[0][0].damage = 3;
	for (int j = 0; j < NUMBER_BULLET; j++) {
		for (int k = 0; k < 4; k++) {
			bullet_ennemies_C[j][k] = bullet_ennemies_C[0][0];
		}
	}
	bullet_ennemies_D[0].loadFromFile("picture//Bullet_ennemies/4.png",1);
	bullet_ennemies_D[0].damage = 3;
	for (int j = 0; j < NUMBER_BULLET; j++) {
		bullet_ennemies_D[j] = bullet_ennemies_D[0];
	}
	bullet_ennemies_E[0].loadFromFile("picture//Bullet_ennemies/5.png",1);
	bullet_ennemies_E[0].damage = 3;
	for (int j = 0; j < NUMBER_BULLET; j++) {
		bullet_ennemies_E[j] = bullet_ennemies_E[0];
	}
	// ennemies
	ennemies_A[0].loadFromFile("picture//Ennemies/1.png", 2);
	ennemies_A[0].death.loadFromFile("picture//Ennemies/death1.png", 7);
	ennemies_A[0].plus_score.loadFont("font//font.ttf", 20);
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_A[i] = ennemies_A[0];
	}
	ennemies_B[0].loadFromFile("picture//Ennemies/2.png", 2);
	ennemies_B[0].death.loadFromFile("picture//Ennemies/death2.png", 7);
	ennemies_B[0].plus_score.loadFont("font//font.ttf", 20);
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_B[i] = ennemies_B[0];
	}
	ennemies_C[0].loadFromFile("picture//Ennemies/3.png", 1);
	ennemies_C[0].death.loadFromFile("picture//Ennemies/death3.png", 7);
	ennemies_C[0].plus_score.loadFont("font//font.ttf", 20);
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_C[i] = ennemies_C[0];
	}
	ennemies_D[0].loadFromFile("picture//Ennemies/4.png", 4);
	ennemies_D[0].death.loadFromFile("picture//Ennemies/death4.png", 7);
	ennemies_D[0].plus_score.loadFont("font//font.ttf", 20);
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_D[i] = ennemies_D[0];
	}
	ennemies_E[0].loadFromFile("picture//Ennemies/5.png", 3);
	ennemies_E[0].death.loadFromFile("picture//Ennemies/death5.png", 7);
	ennemies_E[0].plus_score.loadFont("font//font.ttf", 20);
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_E[i] = ennemies_E[0];
	}
	// boss
	star[0].loadFromFile("picture//Boss/star.png", 1);
	for (int i = 0; i < 1000; i++) {
		star[i] = star[0];
	}
	int a = -100;
	for (int i = 0; i < 7; i++) {
		star_coordinates[i][0] = -100;
		star_coordinates[i][1] = a;
		star_coordinates[i][2] = -1;
		a += 270;
	}
	int b = 0;
	for (int i = 7; i < 15; i++) {
		star_coordinates[i][1] = -100;
		star_coordinates[i][0] = b;
		star_coordinates[i][2] = -1;
		b += 100;
	}
	mini_boss_center_1.loadFromFile("picture//Boss/mini_boss_1.png", 2);
	staff_mini_boss_1.loadFromFile("picture//Boss/staff_mini_boss_1.png", 1);
	mini_boss_center_2.loadFromFile("picture//Boss/mini_boss_2.png", 2);
	//
	boom[0].warning.loadFromFile("picture//Boss/warning.png", 1);
	boom[0].explode.loadFromFile("picture//Boss/boom.png", 1);
	boom[0].warning_around[0].loadFromFile("picture//Boss/round_warning.png", 1);
	for (int i = 0; i < 5; i++) {
		boom[0].warning_around[i] = boom[0].warning_around[0];
	}
	for (int i = 0; i < NUMBER_BULLET; i++) {
		boom[i] = boom[0];
	}
	boss.loadFromFile("picture//Boss/boss.png", 1);
	lazer_warning_green[0].loadFromFile("picture//Boss/lazer_warning_green.png", 1);
	lazer_warning_green[1] = lazer_warning_green[0];
	lazer_warning_red[0].loadFromFile("picture//Boss/lazer_warning_red.png", 1);
	lazer_warning_red[1] = lazer_warning_red[0];
	head_lazer[0].loadFromFile("picture//Boss/head_lazer.png", 1);
	head_lazer[1] = head_lazer[0];
	lazer[0].loadFromFile("picture//Boss/lazer.png", 1);
	lazer[1] = lazer[0];
	bullet_triangle[0].bullet_virtual.loadFromFile("picture//Boss/bullet_virtual.png", 1);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			bullet_triangle[0].bullet_around[i][j].loadFromFile("picture//Boss/bullet_around.png", 1);
		}
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		bullet_triangle[j] = bullet_triangle[0];
	}
	bullet_level[0][0].loadFromFile("picture//Boss/bullet_level_0.png", 1);
	bullet_level[1][0].loadFromFile("picture//Boss/bullet_level_1.png", 1);
	bullet_level[2][0].loadFromFile("picture//Boss/bullet_level_2.png", 1);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < NUMBER_BULLET * 25; j++) {
			if (i == 0) {
				bullet_level[i][j] = bullet_level[0][0];
			}
			else if (i == 1) {
				bullet_level[i][j] = bullet_level[1][0];
			}
			else if (i == 2) {
				bullet_level[i][j] = bullet_level[2][0];
			}
		}
	}
}
void loadAllPlayer() {
	player.shield[0].loadFromFile("picture//Player/shield.png", 1);
	for (int i = 0; i < 5; i++) {
		player.shield[i] = player.shield[0];
	}
	player.death[0].loadFromFile("picture//Player/death.png", 7);
	player.death[1].loadFromFile("picture//Player/death1.png", 7);
	player.death[2].loadFromFile("picture//Player/death2.png", 7);
	player.death[3].loadFromFile("picture//Player/death3.png", 7);
	//player
	player.loadFromFile("picture//Player/player.png", 1);
	//bulletplayer
	player.bullet_simple[0][0].loadFromFile("picture//Player/bullet1.png", 1);
	player.bullet_simple[0][0].hit.loadFromFile("picture//Player/hit1.png", 6);
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 2; j++) {
			player.bullet_simple[i][j] = player.bullet_simple[0][0];
			player.bullet_simple[i][j].damage = 2;
		}
	}
	player.bullet_x5[0][0].loadFromFile("picture//Player/bullet2.png", 1);
	player.bullet_x5[0][0].hit.loadFromFile("picture//Player/hit2.png", 6);
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 5; j++) {
			player.bullet_x5[i][j] = player.bullet_x5[0][0];
			player.bullet_x5[i][j].damage = 2;
		}
	}
	player.bullet_x7[0][0].loadFromFile("picture//Player/bullet3.png", 1);
	player.bullet_x7[0][0].hit.loadFromFile("picture//Player/hit3.png", 6);
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 7; j++) {
			player.bullet_x7[i][j] = player.bullet_x7[0][0];
			player.bullet_x7[i][j].damage = 2;
		}
	}

	support_1.loadFromFile("picture//Player/support.png", 1);
	support_2.loadFromFile("picture//Player/support.png", 1);
	player.bullet_support_1[0].loadFromFile("picture//Player/bullet_support.png", 1);
	player.bullet_support_2[0].loadFromFile("picture//Player/bullet_support.png", 1);
	player.bullet_support_1[0].hit.loadFromFile("picture//Player/hit_support.png", 6);
	player.bullet_support_2[0].hit.loadFromFile("picture//Player/hit_support.png", 6);
	for (int i = 0; i < NUMBER_BULLET; i++) {
		player.bullet_support_1[i] = player.bullet_support_1[0];
		player.bullet_support_1[i].damage = 2;
		//
		player.bullet_support_2[i] = player.bullet_support_2[0];
		player.bullet_support_2[i].damage = 2;
	}
}
void loadAllIcon() {
	gameover_screen_home.loadFromFile("picture//gameover_screen/gameover_screen_home.png", 1);
	gameover_screen_home.center_x = 392;
	gameover_screen_home.center_y = 820;
	gameover_screen_background.loadFromFile("picture//gameover_screen/gameover_screen_background.png", 1);
	gameover_screen_background.center_x = SCREEN_WIDTH / 2;
	gameover_screen_background.center_y = SCREEN_HEIGHT / 2;
	//
	fight_screen_gameover.loadFromFile("picture//fight_screen/fight_screen_gameover.png", 1);
	fight_screen_start.loadFromFile("picture//fight_screen/fight_screen_start.png", 1);
	fight_screen_score.loadFromFile("picture//fight_screen/fight_screen_score.png", 1);
	pause_button.loadFromFile("picture//fight_screen/pause_button.png", 1);
	pause_button.center_x = 700;
	pause_button.center_y = 75;
	for (int i = 0; i <= 2; i++) {
		Heart[i].loadFromFile("picture//fight_screen/Heart.png", 1);
	}
	Heart[0].center_x = 75;
	Heart[0].center_y = 75;
	for (int i = 0; i <= 1; i++) {
		Heart[i + 1].center_x = Heart[i].center_x + 70;
		Heart[i + 1].center_y = Heart[0].center_y;
	}
	fight_screen_background.loadFromFile("picture//fight_screen/fight_screen_background.png", 1);
	///
	///
	/// 
	home_background.loadFromFile("picture//home_screen/home_screen_background.png", 1);
	home_screen_press_start.loadFromFile("picture//home_screen/home_screen_press_start.png", 1);
	home_background.center_x = SCREEN_WIDTH / 2;;
	home_background.center_y = SCREEN_HEIGHT / 2;
	home_screen_press_start.center_x = 400;
	home_screen_press_start.center_y = 500;
	///
	///
	pause_screen_continue.loadFromFile("picture//pause_screen/pause_screen_continue.png", 1);
	pause_screen_home.loadFromFile("picture//pause_screen/pause_screen_home.png", 1);
	pause_screen_sensitivity_down.loadFromFile("picture//pause_screen/pause_screen_sensitivity_down.png", 1);
	pause_screen_sensitivity_up.loadFromFile("picture//pause_screen/pause_screen_sensitivity_up.png", 1);
	pause_screen_sensitivity[0].loadFromFile("picture//pause_screen/pause_screen_sensitivity_0.png", 1);
	pause_screen_sensitivity[1].loadFromFile("picture//pause_screen/pause_screen_sensitivity_1.png", 1);
	pause_screen_sensitivity[2].loadFromFile("picture//pause_screen/pause_screen_sensitivity_2.png", 1);
	pause_screen_sound_pause.loadFromFile("picture//pause_screen/pause_screen_sound.png", 1);
	pause_screen_unsound_pause.loadFromFile("picture//pause_screen/pause_screen_unsound.png", 1);
	pause_screen_music_pause.loadFromFile("picture//pause_screen/pause_screen_music.png", 1);
	pause_screen_unmusic_pause.loadFromFile("picture//pause_screen/pause_screen_unmusic.png", 1);
	pause_background.loadFromFile("picture//pause_screen/pause_screen_background.png", 1);
	///
	///
	pause_background.center_x = SCREEN_WIDTH / 2;
	pause_background.center_y = SCREEN_HEIGHT / 2;
	pause_screen_continue.center_x = 556;
	pause_screen_continue.center_y = 830;
	pause_screen_home.center_x = 260;
	pause_screen_home.center_y = 830;
	pause_screen_sensitivity_down.center_x = 247;
	pause_screen_sensitivity_down.center_y = 650;
	pause_screen_sensitivity_up.center_x = 578;
	pause_screen_sensitivity_up.center_y = 650;
	pause_screen_music_pause.center_x = 554;
	pause_screen_music_pause.center_y = 380;
	pause_screen_unmusic_pause.center_x = 554;
	pause_screen_unmusic_pause.center_y = 380;
	pause_screen_sound_pause.center_x = 270;
	pause_screen_sound_pause.center_y = 380;
	pause_screen_unsound_pause.center_x = 270;
	pause_screen_unsound_pause.center_y = 380;
	pause_screen_sensitivity[0].center_x = 420;
	pause_screen_sensitivity[0].center_y = 650;
	pause_screen_sensitivity[1].center_x = 420;
	pause_screen_sensitivity[1].center_y = 650;
	pause_screen_sensitivity[2].center_x = 420;
	pause_screen_sensitivity[2].center_y = 650;
	////
	////
	
}

