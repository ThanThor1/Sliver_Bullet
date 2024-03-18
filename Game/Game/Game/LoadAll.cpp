#pragma once
#include "LoadAll.h"
void  loadAllImage() {
	sensitivity[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sensitivity/sensitivity_0.png");
	sensitivity[1].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sensitivity/sensitivity_1.png");
	sensitivity[2].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sensitivity/sensitivity_2.png");
	sound.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sound_and_music/sound.png");
	unsound.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sound_and_music/unsound.png");
	music.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sound_and_music/music.png");
	unmusic.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/sound_and_music/unmusic.png");
	pause_menu.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/PauseMenu.png");
	////
	//
	//
	//
	//
	//
	//
	//
	////
	pause_menu.O_x = 67;
	pause_menu.O_y = 60;
	music.O_x = 435 + pause_menu.O_x;
	music.O_y = 192 + pause_menu.O_y;
	unmusic.O_x = 435 + pause_menu.O_x;
	unmusic.O_y = 192 + pause_menu.O_y;
	sound.O_x = 144 + pause_menu.O_x;
	sound.O_y = 182 + pause_menu.O_y;
	unsound.O_x = 144 + pause_menu.O_x;
	unsound.O_y = 182 + pause_menu.O_y;
	sensitivity[0].O_x = 210 + pause_menu.O_x;
	sensitivity[0].O_y = 445 + pause_menu.O_y;
	sensitivity[1].O_x = 210 + pause_menu.O_x;
	sensitivity[1].O_y = 445 + pause_menu.O_y;
	sensitivity[2].O_x = 210 + pause_menu.O_x;
	sensitivity[2].O_y = 445 + pause_menu.O_y;
	////
	//
	//
	//
	//
	//
	//
	//
	////
	pause_button.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/pausebutton.png");
	for (int i = 0; i <=2; i++) {
		Heart[i].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Heart.png");
	}
	BackGround.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/BackGround.png");
	ennemies_1[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/1.png");
	for (int i = 0; i <= 999; i++) {
		ennemies_1[i].type = ENNEMIES_1;
		ennemies_1[i].E_Texture = ennemies_1[0].E_Texture;
		ennemies_1[i].E_Width   = ennemies_1[0].E_Width;
		ennemies_1[i].E_Height  = ennemies_1[0].E_Height;
	}
	ennemies_2[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/2.png");
	for (int i = 0; i <= 999; i++) {
		ennemies_2[i].type = ENNEMIES_2;
		ennemies_2[i].E_Texture = ennemies_2[0].E_Texture;
		ennemies_2[i].E_Width   = ennemies_2[0].E_Width;
		ennemies_2[i].E_Height  = ennemies_2[0].E_Height;
	}
	ennemies_3[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/Ennemies/3.png");
	for (int i = 0; i <= 999; i++) {
		ennemies_3[i].type = ENNEMIES_3;
		ennemies_3[i].E_Texture = ennemies_3[0].E_Texture;
		ennemies_3[i].E_Width   = ennemies_3[0].E_Width;
		ennemies_3[i].E_Height  = ennemies_3[0].E_Height;
	}
	ennemies_4[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet.png");
	for (int i = 0; i <= 999; i++) {
		ennemies_4[i].type = ENNEMIES_4;
		ennemies_4[i].E_Texture = ennemies_4[0].E_Texture;
		ennemies_4[i].E_Width   = ennemies_4[0].E_Width;
		ennemies_4[i].E_Height  = ennemies_4[0].E_Height;
	}
	ennemies_1[0].bullet_simple[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bulletennemies/1.png");
	for (int i = 0; i < 1000; i++) {
			ennemies_1[0].bullet_simple[i].B_Texture = ennemies_1[0].bullet_simple[0].B_Texture;
			ennemies_1[0].bullet_simple[i].B_Width = ennemies_1[0].bullet_simple[0].B_Width;
			ennemies_1[0].bullet_simple[i].B_Height = ennemies_1[0].bullet_simple[0].B_Height;
	}
	////////////
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	// 
	////////////
	player.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/player.png");
	player.bullet_simple[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet1.png");
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 2; j++) {
			player.bullet_simple[i][j].B_Texture = player.bullet_simple[0][0].B_Texture;
			player.bullet_simple[i][j].B_Width   = player.bullet_simple[0][0].B_Width;
			player.bullet_simple[i][j].B_Height  = player.bullet_simple[0][0].B_Height;
		}
	}
	player.bullet_x7[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bulletplayer.png");
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 7; j++) {
			player.bullet_x7[i][j].B_Texture = player.bullet_x7[0][0].B_Texture;
			player.bullet_x7[i][j].B_Width   = player.bullet_x7[0][0].B_Width;
			player.bullet_x7[i][j].B_Height  = player.bullet_x7[0][0].B_Height;
		}
	}
	player.bullet_x5[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet2.png");
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 5; j++) {
			player.bullet_x5[i][j].B_Texture = player.bullet_x5[0][0].B_Texture;
			player.bullet_x5[i][j].B_Width   = player.bullet_x5[0][0].B_Width;
			player.bullet_x5[i][j].B_Height  = player.bullet_x5[0][0].B_Height;
		}
	}
	player.lazer.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/lazer/lazer.png");
	player.support_1.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/support.png");
	player.support_2.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/support.png");
	player.bullet_support_1[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet3.png");
	player.bullet_support_2[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet3.png");
	for (int i = 0; i < 1000; i++) {
		player.bullet_support_1[i].B_Texture = player.bullet_support_1[0].B_Texture;
		player.bullet_support_1[i].B_Width   = player.bullet_support_1[0].B_Width;
		player.bullet_support_1[i].B_Height  = player.bullet_support_1[0].B_Height;
		player.bullet_support_2[i].B_Texture = player.bullet_support_2[0].B_Texture;
		player.bullet_support_2[i].B_Width   = player.bullet_support_2[0].B_Width;
		player.bullet_support_2[i].B_Height  = player.bullet_support_2[0].B_Height;
	}
}
void loadBackGround() {
	BackGround.renderbackground();
	Heart[0].O_x = 30;
	Heart[0].O_y = 30;
	for (int i = 0; i <= 1; i++) {
		Heart[i + 1].O_x = Heart[i].O_x + 70;
		Heart[i + 1].O_y = Heart[0].O_y;
	}
	for (int i = 0; i <= 2; i++) {
		Heart[i].render(Heart[i].O_x, Heart[i].O_y);
	}
	if (prepare_to_press_pause == false) {
		pause_button.O_x = 700;
		pause_button.O_y = 30;
	}
	else {
		pause_button.O_x = 700 -(48-31)/2;
		pause_button.O_y = 30 -(63-51)/2;
	}
	pause_button.render(pause_button.O_x, pause_button.O_y);
}
void loadPause() {
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
void loadPauseMenu() {
	SDL_RenderClear(gRenderer);
	SDL_Rect rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	SDL_RenderCopy(gRenderer, texture, NULL, &rect);
	pause_menu.render(pause_menu.O_x, pause_menu.O_y);
	if (music_bool == true) {
		MUSIC = music;
	}
	else { MUSIC = unmusic; }
	if (sound_bool == true) {
		SOUND = sound;
	}
	else { SOUND =unsound; }
	MUSIC.render(MUSIC.O_x, MUSIC.O_y);
	SOUND.render(SOUND.O_x, SOUND.O_y);
	sensitivity[player.sensitivity_index].render(sensitivity[player.sensitivity_index].O_x, sensitivity[player.sensitivity_index].O_y);
	SDL_RenderPresent(gRenderer);

}