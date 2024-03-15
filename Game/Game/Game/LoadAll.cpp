#pragma once
#include "LoadAll.h"
void  loadall() {
	ennemies_1[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet.png");
	for (int i = 0; i <= 999; i++) {
		ennemies_1[i].type = ENNEMIES_1;
		ennemies_1[i].E_Texture = ennemies_1[0].E_Texture;
		ennemies_1[i].E_Width = ennemies_1[0].E_Width;
		ennemies_1[i].E_Height = ennemies_1[0].E_Height;
	}
	player.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/player/player.png");
	player.bullet_simple[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet/1.png");
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 2; j++) {
			player.bullet_simple[i][j].B_Texture = player.bullet_simple[0][0].B_Texture;
			player.bullet_simple[i][j].B_Width = player.bullet_simple[0][0].B_Width;
			player.bullet_simple[i][j].B_Height = player.bullet_simple[0][0].B_Height;
		}
	}
	player.bullet_x7[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet/1.png");
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 7; j++) {
			player.bullet_x7[i][j].B_Texture = player.bullet_x7[0][0].B_Texture;
			player.bullet_x7[i][j].B_Width = player.bullet_x7[0][0].B_Width;
			player.bullet_x7[i][j].B_Height = player.bullet_x7[0][0].B_Height;
		}
	}
	player.bullet_x5[0][0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet/1.png");
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 5; j++) {
			player.bullet_x5[i][j].B_Texture = player.bullet_x5[0][0].B_Texture;
			player.bullet_x5[i][j].B_Width = player.bullet_x5[0][0].B_Width;
			player.bullet_x5[i][j].B_Height = player.bullet_x5[0][0].B_Height;
		}
	}
	player.lazer.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/lazer/lazer.png");
	player.support_1.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/support/support.png");
	player.support_2.loadFromFile("C:/Users/Lenovo/Desktop/anhgame/support/support.png");
	player.bullet_support_1[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet/1.png");
	player.bullet_support_2[0].loadFromFile("C:/Users/Lenovo/Desktop/anhgame/bullet/1.png");
	for (int i = 0; i < 1000; i++) {
		player.bullet_support_1[i].B_Texture = player.bullet_x5[0][0].B_Texture;
		player.bullet_support_1[i].B_Width = player.bullet_x5[0][0].B_Width;
		player.bullet_support_1[i].B_Height = player.bullet_x5[0][0].B_Height;
		player.bullet_support_2[i].B_Texture = player.bullet_x5[0][0].B_Texture;
		player.bullet_support_2[i].B_Width = player.bullet_x5[0][0].B_Width;
		player.bullet_support_2[i].B_Height = player.bullet_x5[0][0].B_Height;
	}
}