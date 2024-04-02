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
				ennemies_A[stoi(map[i][j+1])].getStart(j * EDGE_LENGTH_BLOCK, (i-12) * EDGE_LENGTH_BLOCK);
				ennemies_A[stoi(map[i][j + 1])].health = -100;
				number_ennemies_A++;
			}
			if (map[i][j] == "A") {
				ennemies_A[stoi(map[i][j+1])].getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
			}
			if (map[i][j] == "b") {
				ennemies_B[stoi(map[i][j+1])].getStart(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				ennemies_B[stoi(map[i][j + 1])].health = -100;
				number_ennemies_B++;
			}
			if (map[i][j] == "B") {
				ennemies_B[stoi(map[i][j+1])].getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
			}
			if (map[i][j] == "c") {
				ennemies_C[stoi(map[i][j+1])].getStart(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				ennemies_C[stoi(map[i][j + 1])].health = -100;
				number_ennemies_C++;
			}
			if (map[i][j] == "C") {
				ennemies_C[stoi(map[i][j+1])].getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
			}
			if (map[i][j] == "d") {
				ennemies_D[stoi(map[i][j + 1])].getStart(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
				ennemies_D[stoi(map[i][j + 1])].health = -100;
				number_ennemies_D++;
			}
			if (map[i][j] == "D") {
				ennemies_D[stoi(map[i][j + 1])].getFinish(j * EDGE_LENGTH_BLOCK, (i - 12) * EDGE_LENGTH_BLOCK);
			}
		}
	}

}
void loadAllSound() {
	music_menu = Mix_LoadMUS("C:/Users/Lenovo/Desktop/nhacgame/music_menu.mp3");
	music_fight = Mix_LoadMUS("C:/Users/Lenovo/Desktop/nhacgame/music_fight.mp3");
}
void loadAllEnnemies() {
	// ennemies
	ennemies_A[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/1.png");
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_A[i].E_Texture = ennemies_A[0].E_Texture;
		ennemies_A[i].E_Width = ennemies_A[0].E_Width;
		ennemies_A[i].E_Height = ennemies_A[0].E_Height;
	}
	ennemies_B[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/2.png");
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_B[i].E_Texture = ennemies_B[0].E_Texture;
		ennemies_B[i].E_Width = ennemies_B[0].E_Width;
		ennemies_B[i].E_Height = ennemies_B[0].E_Height;
	}
	ennemies_C[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/4.png");
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_C[i].E_Texture = ennemies_C[0].E_Texture;
		ennemies_C[i].E_Width = ennemies_C[0].E_Width;
		ennemies_C[i].E_Height = ennemies_C[0].E_Height;
	}
	ennemies_D[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/4.png");
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
			ennemies_D[i].E_Texture = ennemies_D[0].E_Texture;
			ennemies_D[i].E_Width = ennemies_D[0].E_Width;
			ennemies_D[i].E_Height = ennemies_D[0].E_Height;
	}
	// đạn cho ennemies
	ennemies_A[0].bullet_simple[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Bullet_ennemies/1.png");
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		for (int j = 0; j < NUMBER_BULLET; j++) {
			ennemies_A[i].bullet_simple[j].B_Texture = ennemies_A[0].bullet_simple[0].B_Texture;
			ennemies_A[i].bullet_simple[j].B_Width = ennemies_A[0].bullet_simple[0].B_Width;
			ennemies_A[i].bullet_simple[j].B_Height = ennemies_A[0].bullet_simple[0].B_Height;
		}
	}
	ennemies_B[0].bullet_x3[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Bullet_ennemies/2.png");
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		for (int j = 0; j < NUMBER_BULLET; j++) {
			for (int k = 0; k < 3; k++) {
				ennemies_B[i].bullet_x3[j][k].B_Texture = ennemies_B[0].bullet_x3[0][0].B_Texture;
				ennemies_B[i].bullet_x3[j][k].B_Width = ennemies_B[0].bullet_x3[0][0].B_Width;
				ennemies_B[i].bullet_x3[j][k].B_Height = ennemies_B[0].bullet_x3[0][0].B_Height;
			}
		}
	}
	ennemies_C[0].bullet_x4[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Bullet_ennemies/3.png");
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		for (int j = 0; j < NUMBER_BULLET; j++) {
			for (int k = 0; k < 4; k++) {
				ennemies_C[i].bullet_x4[j][k].B_Texture = ennemies_C[0].bullet_x4[0][0].B_Texture;
				ennemies_C[i].bullet_x4[j][k].B_Width = ennemies_C[0].bullet_x4[0][0].B_Width;
				ennemies_C[i].bullet_x4[j][k].B_Height = ennemies_C[0].bullet_x4[0][0].B_Height;
			}
		}
	}
	ennemies_D[0].bullet_follow[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Bullet_ennemies/4.png");
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		for (int j = 0; j < NUMBER_BULLET; j++) {
			ennemies_D[i].bullet_follow[j].B_Texture = ennemies_D[0].bullet_follow[0].B_Texture;
			ennemies_D[i].bullet_follow[j].B_Width = ennemies_D[0].bullet_follow[0].B_Width;
			ennemies_D[i].bullet_follow[j].B_Height = ennemies_D[0].bullet_follow[0].B_Height;
		}
	}
}
void loadAllPlayer() {
	//player
	player.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/player.png");
	//bulletplayer
	player.bullet_simple[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet1.png");
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 2; j++) {
			player.bullet_simple[i][j].B_Texture = player.bullet_simple[0][0].B_Texture;
			player.bullet_simple[i][j].B_Width = player.bullet_simple[0][0].B_Width;
			player.bullet_simple[i][j].B_Height = player.bullet_simple[0][0].B_Height;
			player.bullet_simple[i][j].B_damage = 2;
		}
	}
	player.bullet_x7[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bulletplayer.png");
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 7; j++) {
			player.bullet_x7[i][j].B_Texture = player.bullet_x7[0][0].B_Texture;
			player.bullet_x7[i][j].B_Width = player.bullet_x7[0][0].B_Width;
			player.bullet_x7[i][j].B_Height = player.bullet_x7[0][0].B_Height;
			player.bullet_x7[i][j].B_damage = 2;
		}
	}
	player.bullet_x5[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet2.png");
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j < 5; j++) {
			player.bullet_x5[i][j].B_Texture = player.bullet_x5[0][0].B_Texture;
			player.bullet_x5[i][j].B_Width = player.bullet_x5[0][0].B_Width;
			player.bullet_x5[i][j].B_Height = player.bullet_x5[0][0].B_Height;
			player.bullet_x7[i][j].B_damage = 2;
		}
	}
	player.lazer.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/lazer/lazer.png");
	player.support_1.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/support.png");
	player.support_2.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/support.png");
	player.bullet_support_1[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet3.png");
	player.bullet_support_2[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet3.png");
	for (int i = 0; i < NUMBER_BULLET; i++) {
		player.bullet_support_1[i].B_Texture = player.bullet_support_1[0].B_Texture;
		player.bullet_support_1[i].B_Width = player.bullet_support_1[0].B_Width;
		player.bullet_support_1[i].B_Height = player.bullet_support_1[0].B_Height;
		player.bullet_support_1[i].B_damage = 2;
		//
		player.bullet_support_2[i].B_Texture = player.bullet_support_2[0].B_Texture;
		player.bullet_support_2[i].B_Width = player.bullet_support_2[0].B_Width;
		player.bullet_support_2[i].B_Height = player.bullet_support_2[0].B_Height;
		player.bullet_support_2[i].B_damage = 2;
	}
}
void loadAllIcon() {
	home.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/home.png");
	press_start.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/press_start.png");
	home.O_x = 0;
	home.O_y = 0;
	press_start.O_x = 52;
	press_start.O_y = 442;
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
	pause_menu.O_x = 67;
	pause_menu.O_y = 60;
	continue_pause.O_x = 409 + pause_menu.O_x;
	continue_pause.O_y = 614 + pause_menu.O_y;
	home_pause.O_x = 101 + pause_menu.O_x;
	home_pause.O_y = 614 + pause_menu.O_y;
	sensitivity_down_pause.O_x = 157 + pause_menu.O_x;
	sensitivity_down_pause.O_y = 445 + pause_menu.O_y;
	sensitivity_up_pause.O_x = 463 + pause_menu.O_x;
	sensitivity_up_pause.O_y = 445 + pause_menu.O_y;
	music_pause.O_x = 435 + pause_menu.O_x;
	music_pause.O_y = 192 + pause_menu.O_y;
	unmusic_pause.O_x = 435 + pause_menu.O_x;
	unmusic_pause.O_y = 192 + pause_menu.O_y;
	sound_pause.O_x = 144 + pause_menu.O_x;
	sound_pause.O_y = 182 + pause_menu.O_y;
	unsound_pause.O_x = 144 + pause_menu.O_x;
	unsound_pause.O_y = 182 + pause_menu.O_y;
	sensitivity[0].O_x = 210 + pause_menu.O_x;
	sensitivity[0].O_y = 445 + pause_menu.O_y;
	sensitivity[1].O_x = 210 + pause_menu.O_x;
	sensitivity[1].O_y = 445 + pause_menu.O_y;
	sensitivity[2].O_x = 210 + pause_menu.O_x;
	sensitivity[2].O_y = 445 + pause_menu.O_y;
	////
	////
	pause_button.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/pausebutton.png");
	for (int i = 0; i <= 2; i++) {
		Heart[i].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Heart.png");
	}
	Heart[0].O_x = 30;
	Heart[0].O_y = 30;
	for (int i = 0; i <= 1; i++) {
		Heart[i + 1].O_x = Heart[i].O_x + 70;
		Heart[i + 1].O_y = Heart[0].O_y;
	}
	BackGround.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/BackGround.png");
}











void renewAll() {
	renewAllPlayer();
	renewAllEnnemies();
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
	player.support_1.free();
	player.support_2.free();
	player.bullet_support_1[0].free();
	player.bullet_support_2[0].free();
	for (int i = 0; i < 100; i++) {
		player.bullet_support_1[i].free();
		player.bullet_support_2[i].free();
	}
}
void renewAllEnnemies() {
	//ennemies
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_A[i].free();
	}
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_B[i].free();
	}
	for (int i = 0; i < NUMBER_ENNEMIES; i++) {
		ennemies_C[i].free();
	}
}





void loadFightBackGround() {
	BackGround.renderbackground();
	for (int i = 0; i <= 2; i++) {
		if (i >= player.number_of_hearts) {
			Heart[i].setAlpha(100);
		}
		else Heart[i].setAlpha(255);
		Heart[i].render(Heart[i].O_x, Heart[i].O_y);
	}
	if (prepare_to_press_pause == false) {
		pause_button.O_x = 700;
		pause_button.O_y = 30;
	}
	else {
		pause_button.O_x = 700 - (48 - 31) / 2;
		pause_button.O_y = 30 - (63 - 51) / 2;
	}
	pause_button.render(pause_button.O_x, pause_button.O_y);
}
void loadPauseButton() {
	if (pre_x >= pause_button.O_x && pre_y >= pause_button.O_y && pre_x <= (pause_button.O_x + pause_button.O_Width) && pre_y <= (pause_button.O_y + pause_button.O_Height)) {
		pause_button.O_Width = 48;
		pause_button.O_Height = 63;
		prepare_to_press_pause = true;
	}
	else {
		pause_button.O_Width = 31;
		pause_button.O_Height = 51;
		prepare_to_press_pause = false;
	}
}
void loadPauseScreen() {
	SDL_RenderClear(gRenderer);
	SDL_Rect rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	SDL_RenderCopy(gRenderer, texture, NULL, &rect);
	pause_menu.render(pause_menu.O_x, pause_menu.O_y);
	continue_pause.render(continue_pause.O_x, continue_pause.O_y);
	home_pause.render(home_pause.O_x, home_pause.O_y);
	sensitivity_down_pause.render(sensitivity_down_pause.O_x, sensitivity_down_pause.O_y);
	sensitivity_up_pause.render(sensitivity_up_pause.O_x, sensitivity_up_pause.O_y);
	if (music_bool == true) {
		music_pause.render(music_pause.O_x, music_pause.O_y);
	}
	else {
		unmusic_pause.render(unmusic_pause.O_x, unmusic_pause.O_y);
	}
	if (sound_bool == true) {
		sound_pause.render(sound_pause.O_x, sound_pause.O_y);
	}
	else { unsound_pause.render(unsound_pause.O_x, unsound_pause.O_y); }

	sensitivity[player.sensitivity_index].render(sensitivity[player.sensitivity_index].O_x, sensitivity[player.sensitivity_index].O_y);
	SDL_RenderPresent(gRenderer);

}
void loadFightScreen() {

	SDL_RenderClear(gRenderer);
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	loadFightBackGround();
	loadPauseButton();
	Wave();
	player.loadFrame();
	SDL_RenderPresent(gRenderer);
}
void loadHomeScreen() {
	SDL_RenderClear(gRenderer);
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	BackGround.renderbackground();
	home.render(home.O_x, home.O_y);
	press_start.dem1 = (press_start.dem1 + 1) % 5;
	press_start.dem2 = (press_start.dem2 + press_start.dem1 / 4) % 30;
	if (press_start.dem2 <= 29 && press_start.dem2 >= 10) {
		press_start.render(press_start.O_x, press_start.O_y);
	}
	SDL_RenderPresent(gRenderer);
}