#pragma once
#include "LoadAll.h"
void  loadAllImage() {
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
	// 
	// 
	// 
	// 
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
	int heart_x = 30;
	int heart_y = 30;
	for (int i = 0; i <= 2; i++) {
		Heart[i].render(heart_x, heart_y);
		heart_x += 70;
	}
}