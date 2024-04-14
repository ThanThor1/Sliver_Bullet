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
}
void loadAllMap() {
	ifstream get_map;
	switch (MAP) {
	case WAVE_1:
		get_map.open("C:/Users/Lenovo/Desktop/mapgame/wave1.txt");
		break;
	case WAVE_2:
		get_map.open("C:/Users/Lenovo/Desktop/mapgame/wave2.txt");
		break;
	case WAVE_3:
		get_map.open("C:/Users/Lenovo/Desktop/mapgame/wave3.txt");
		break;
	case WAVE_4:
		get_map.open("C:/Users/Lenovo/Desktop/mapgame/wave4.txt");
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
			if (map[i][j] == "A") {
				ennemies_A[stoi(map[i][j + 1])].getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				ennemies_A[stoi(map[i][j + 1])].getDeltaxy();
			}
			if (map[i][j] == "b") {
				ennemies_B[stoi(map[i][j + 1])].getStart(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				number_ennemies_B++;
			}
			if (map[i][j] == "B") {
				ennemies_B[stoi(map[i][j + 1])].getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				ennemies_B[stoi(map[i][j + 1])].getDeltaxy();
			}
			if (map[i][j] == "c") {
				ennemies_C[stoi(map[i][j + 1])].getStart(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				number_ennemies_C++;
			}
			if (map[i][j] == "C") {
				ennemies_C[stoi(map[i][j + 1])].getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				ennemies_C[stoi(map[i][j + 1])].getDeltaxy();
			}
			if (map[i][j] == "d") {
				ennemies_D[stoi(map[i][j + 1])].getStart(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				number_ennemies_D++;
			}
			if (map[i][j] == "D") {
				ennemies_D[stoi(map[i][j + 1])].getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				ennemies_D[stoi(map[i][j + 1])].getDeltaxy();
			}
			if (map[i][j] == "e") {
				ennemies_E[stoi(map[i][j + 1])].getStart(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				number_ennemies_E++;
			}
			if (map[i][j] == "E") {
				ennemies_E[stoi(map[i][j + 1])].getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				ennemies_E[stoi(map[i][j + 1])].getDeltaxy();
			}
		}
	}
}
void loadAllItem() {
	item_example[SHIELD].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet.png");
	item_example[SHIELD].buff_type = SHIELD;
	item_example[SUPPORT].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet.png");
	item_example[SUPPORT].buff_type = SUPPORT;
	item_example[SPEED_BULLET].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet.png");
	item_example[SPEED_BULLET].buff_type = SPEED_BULLET;
	item_example[BULLET_X5].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet.png");
	item_example[BULLET_X5].buff_type = BULLET_X5;
	item_example[BULLET_X7].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet.png");
	item_example[BULLET_X7].buff_type = BULLET_X7;
}
void loadAllSound() {
	music_menu = Mix_LoadMUS("C:/Users/Lenovo/Desktop/nhacgame/music_menu.mp3");
	music_fight = Mix_LoadMUS("C:/Users/Lenovo/Desktop/nhacgame/music_fight.mp3");
	chunk_mouse = Mix_LoadWAV("C:/Users/Lenovo/Desktop/nhacgame/chunk_mouse.mp3");
	chunk_shoot = Mix_LoadWAV("C:/Users/Lenovo/Desktop/nhacgame/chunk_shoot.mp3");
	chunk_explode1 = Mix_LoadWAV("C:/Users/Lenovo/Desktop/nhacgame/chunk_explode1.mp3");
	chunk_explode2 = Mix_LoadWAV("C:/Users/Lenovo/Desktop/nhacgame/chunk_explode2.mp3");
}
void loadAllEnnemies() {
	// đạn cho ennemies
	bullet_ennemies_A[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Bullet_ennemies/1.png");
	bullet_ennemies_A[0].damage = 3;
	for (int j = 0; j < NUMBER_BULLET; j++) {
		bullet_ennemies_A[j] = bullet_ennemies_A[0];
	}
	bullet_ennemies_B[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Bullet_ennemies/2.png");
	bullet_ennemies_B[0][0].damage = 3;
	for (int j = 0; j < NUMBER_BULLET; j++) {
		for (int k = 0; k < 3; k++) {
			bullet_ennemies_B[j][k] = bullet_ennemies_B[0][0];
		}
	}
	bullet_ennemies_C[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Bullet_ennemies/3.png");
	bullet_ennemies_C[0][0].damage = 3;
	for (int j = 0; j < NUMBER_BULLET; j++) {
		for (int k = 0; k < 4; k++) {
			bullet_ennemies_C[j][k] = bullet_ennemies_C[0][0];
		}
	}
	bullet_ennemies_D[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Bullet_ennemies/4.png");
	bullet_ennemies_D[0].damage = 3;
	for (int j = 0; j < NUMBER_BULLET; j++) {
		bullet_ennemies_D[j] = bullet_ennemies_D[0];
	}
	bullet_ennemies_E[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Bullet_ennemies/5.png");
	bullet_ennemies_E[0].damage = 3;
	for (int j = 0; j < NUMBER_BULLET; j++) {
		bullet_ennemies_E[j] = bullet_ennemies_E[0];
	}
	// ennemies
	ennemies_A[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/1.png");
	ennemies_A[0].death.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/death1.png");
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_A[i] = ennemies_A[0];
	}
	ennemies_B[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/2.png");
	ennemies_B[0].death.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/death2.png");
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_B[i] = ennemies_B[0];
	}
	ennemies_C[0].death.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/death3.png");
	ennemies_C[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/3.png");
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_C[i] = ennemies_C[0];
	}
	ennemies_D[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/4.png");
	ennemies_D[0].death.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/death4.png");
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_D[i] = ennemies_D[0];
	}
	ennemies_E[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/5.png");
	ennemies_E[0].death.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/death5.png");
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_E[i] = ennemies_E[0];
	}
}
void loadAllPlayer() {
	player.shield[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/shield.png");
	for (int i = 0; i < 5; i++) {
		player.shield[i] = player.shield[0];
	}
	//player
	player.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/player.png");
	//bulletplayer
	player.bullet_simple[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/bullet1.png");
	player.bullet_simple[0][0].hit.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/hit1.png");
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 2; j++) {
			player.bullet_simple[i][j] = player.bullet_simple[0][0];
			player.bullet_simple[i][j].damage = 2;
		}
	}
	player.bullet_x5[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/bullet2.png");
	player.bullet_x5[0][0].hit.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/hit2.png");
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 5; j++) {
			player.bullet_x5[i][j] = player.bullet_x5[0][0];
			player.bullet_x5[i][j].damage = 2;
		}
	}
	player.bullet_x7[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/bullet3.png");
	player.bullet_x7[0][0].hit.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/hit3.png");
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 7; j++) {
			player.bullet_x7[i][j] = player.bullet_x7[0][0];
			player.bullet_x7[i][j].damage = 2;
		}
	}
	player.lazer.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/lazer.png");
	support_1.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/support.png");
	support_2.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/support.png");
	player.bullet_support_1[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/bullet_support.png");
	player.bullet_support_2[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/bullet_support.png");
	player.bullet_support_1[0].hit.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/hit_support.png");
	player.bullet_support_2[0].hit.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Player/hit_support.png");
	for (int i = 0; i < NUMBER_BULLET; i++) {
		player.bullet_support_1[i] = player.bullet_support_1[0];
		player.bullet_support_1[i].damage = 2;
		//
		player.bullet_support_2[i] = player.bullet_support_2[0];
		player.bullet_support_2[i].damage = 2;
	}
}
void loadAllIcon() {
	gameover.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/gameover.png");
	start.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/start.png");
	///
	///
	/// 
	home.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/home.png");
	press_start.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/press_start.png");
	home.x = 0;
	home.y = 0;
	press_start.x = 52;
	press_start.y = 442;
	///
	///
	continue_pause.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/continue_pause.png");
	home_pause.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/home_pause.png");
	sensitivity_down_pause.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sensitivity/-sensitivity.png");
	sensitivity_up_pause.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sensitivity/+sensitivity.png");
	sensitivity[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sensitivity/sensitivity_0.png");
	sensitivity[1].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sensitivity/sensitivity_1.png");
	sensitivity[2].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sensitivity/sensitivity_2.png");
	sound_pause.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sound_and_music/sound.png");
	unsound_pause.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sound_and_music/unsound.png");
	music_pause.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sound_and_music/music.png");
	unmusic_pause.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sound_and_music/unmusic.png");
	pause_menu.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/PauseMenu.png");
	///
	///
	pause_menu.x = 67;
	pause_menu.y = 60;
	continue_pause.x = 409 + pause_menu.x;
	continue_pause.y = 614 + pause_menu.y;
	home_pause.x = 101 + pause_menu.x;
	home_pause.y = 614 + pause_menu.y;
	sensitivity_down_pause.x = 157 + pause_menu.x;
	sensitivity_down_pause.y = 445 + pause_menu.y;
	sensitivity_up_pause.x = 463 + pause_menu.x;
	sensitivity_up_pause.y = 445 + pause_menu.y;
	music_pause.x = 435 + pause_menu.x;
	music_pause.y = 192 + pause_menu.y;
	unmusic_pause.x = 435 + pause_menu.x;
	unmusic_pause.y = 192 + pause_menu.y;
	sound_pause.x = 144 + pause_menu.x;
	sound_pause.y = 182 + pause_menu.y;
	unsound_pause.x = 144 + pause_menu.x;
	unsound_pause.y = 182 + pause_menu.y;
	sensitivity[0].x = 210 + pause_menu.x;
	sensitivity[0].y = 445 + pause_menu.y;
	sensitivity[1].x = 210 + pause_menu.x;
	sensitivity[1].y = 445 + pause_menu.y;
	sensitivity[2].x = 210 + pause_menu.x;
	sensitivity[2].y = 445 + pause_menu.y;
	////
	////
	pause_button.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/pausebutton.png");
	for (int i = 0; i <= 2; i++) {
		Heart[i].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Heart.png");
	}
	Heart[0].x = 30;
	Heart[0].y = 30;
	for (int i = 0; i <= 1; i++) {
		Heart[i + 1].x = Heart[i].x + 70;
		Heart[i + 1].y = Heart[0].y;
	}
	BackGround.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/BackGround.png");
}





void renewAll() {
	renewAllPlayer();
	renewAllEnnemies();
	renewAllBullet();
	renewAllItem();
	MAP = 0;
	loadmap_bool = false;
	number_ennemies_A = number_ennemies_B = number_ennemies_C = number_ennemies_D = number_ennemies_E = 0;
	start.free();
	gameover.free();
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
	player.lazer.free();
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



































void loadFightBackGround() {

	BackGround.renderbackground();
	loadPauseButton();
	for (int i = 0; i <= 2; i++) {
		if (i >= player.number_of_hearts) {
			Heart[i].setAlpha(100);
		}
		else Heart[i].setAlpha(255);
		Heart[i].render(Heart[i].x, Heart[i].y);
	}
	if (prepare_to_press_pause == false) {
		pause_button.x = 700;
		pause_button.y = 30;
	}
	else {
		pause_button.x = 700 - (48 - 31) / 2;
		pause_button.y = 30 - (63 - 51) / 2;
	}
	pause_button.render(pause_button.x, pause_button.y);
}
void loadPauseButton() {
	if (pre_x >= pause_button.x && pre_y >= pause_button.y && pre_x <= (pause_button.x + pause_button.width) && pre_y <= (pause_button.y + pause_button.height)) {
		pause_button.width = 48;
		pause_button.height = 63;
		prepare_to_press_pause = true;
	}
	else {
		pause_button.width = 31;
		pause_button.height = 51;
		prepare_to_press_pause = false;
	}
}
void loadPauseScreen() {
	SDL_RenderClear(gRenderer);
	SDL_Rect rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	SDL_RenderCopy(gRenderer, texture, NULL, &rect);
	pause_menu.render(pause_menu.x, pause_menu.y);
	continue_pause.render(continue_pause.x, continue_pause.y);
	home_pause.render(home_pause.x, home_pause.y);
	sensitivity_down_pause.render(sensitivity_down_pause.x, sensitivity_down_pause.y);
	sensitivity_up_pause.render(sensitivity_up_pause.x, sensitivity_up_pause.y);
	if (music_bool == true) {
		music_pause.render(music_pause.x, music_pause.y);
	}
	else {
		unmusic_pause.render(unmusic_pause.x, unmusic_pause.y);
	}
	if (sound_bool == true) {
		sound_pause.render(sound_pause.x, sound_pause.y);
	}
	else { unsound_pause.render(unsound_pause.x, unsound_pause.y); }

	sensitivity[player.sensitivity_index].render(sensitivity[player.sensitivity_index].x, sensitivity[player.sensitivity_index].y);
	SDL_RenderPresent(gRenderer);

}
void loadFightScreen() {

	SDL_RenderClear(gRenderer);
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	
	loadFightBackGround();
	/*if (start.exist == false){
		SDL_Rect a;
		if (start.phongto <= 1) {
			 a = { int(SCREEN_WIDTH / 2 - start.Width * start.phongto * 1 / 2),int(SCREEN_HEIGHT / 2 - start.Height * start.phongto * 1 / 2), int(start.Width *start.phongto),  int(start.Height * start.phongto) };
		}
		else
		{
			 a = { SCREEN_WIDTH / 2 - start.Width * 1 / 2, SCREEN_HEIGHT / 2 - start.Height *  1 / 2, start.Width,  start.Height};
		}
		SDL_RenderCopy(gRenderer, start.Texture, NULL, &a);
		start.phongto += 0.0025;
		if (start.phongto >= 2) {
			start.exist = true;
		}
	}*/
	/*else {*/
	Wave();
	//}
	player.loadFrame();
	SDL_RenderPresent(gRenderer);
}
void loadHomeScreen() {

	SDL_RenderClear(gRenderer);
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	BackGround.renderbackground();
	
	home.render(home.x, home.y);
	press_start.dem1 = (press_start.dem1 + 1) % 5;
	press_start.dem2 = (press_start.dem2 + press_start.dem1 / 4) % 30;
	if (press_start.dem2 <= 29 && press_start.dem2 >= 10) {
		press_start.render(press_start.x, press_start.y);
	}

	SDL_RenderPresent(gRenderer);
}
int Rand(int a, int b) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(a, b);
	return dis(gen);
}