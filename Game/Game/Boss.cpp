#include "Boss.h"
#include "FindAngle.h"
#include "Declaration.h"
// di chuyển 
bool Boss::checkExist() {
	checkHit(health);
	if (health <= 0) {
		exist = false;
	}
	else exist = true;
	if (exist == true) {
		moveEnnemies();
	}
	return exist;
}
void Boss::moveEnnemies() {
	SDL_Rect  renderQuad1 = { x, y , width, height };
	SDL_RenderCopyEx(gRenderer, Texture, NULL, &renderQuad1, 0, NULL, SDL_FLIP_NONE);
	mini_boss_center_1.x = x + width / 4 + 200;
	mini_boss_center_2.x = x + width / 4 - 200;
	mini_boss_center_1.y = y - 100;
	mini_boss_center_2.y = y - 100;
	RenderMiniBoss();
	if (y != finish_y) {
		y++;
	}
	else {
		loadShoot();
	}
}
//sạc đạn
void Boss::loadShoot() {
	/*SDL_Point a1 = { lazer_warning_green[0].width / 2, 0 };
	load_lazer_time = (load_lazer_time + 1) % 1001;
	lazer_warning_green[0].center_x = lazer[0].center_x = head_lazer[0].center_x = lazer_warning_green[0].center_x = boss.x + boss.width / 2 - 30;
	lazer_warning_green[0].center_y = lazer[0].center_y = head_lazer[0].center_y = lazer_warning_green[0].center_y = boss.y + boss.height / 2;
	if (load_lazer_time < 400) {
		lazer[0].angle = head_lazer[0].angle = lazer_warning_green[0].angle = FindAngle(lazer_warning_green[0].center_x, lazer_warning_green[0].center_y, player.x + player.width / 2 -30, player.y + player.height / 2);
		lazer_warning_green[0].render(lazer_warning_green[0].center_x - lazer_warning_green[0].width / 2, lazer_warning_green[0].center_y, NULL, lazer_warning_green[0].angle, &a1);
	}
	else if (load_lazer_time < 450) {
		lazer_warning_red[0].render(lazer_warning_green[0].center_x - lazer_warning_green[0].width / 2, lazer_warning_green[0].center_y, NULL, lazer_warning_green[0].angle, &a1);
	}
	else if (load_lazer_time < 550) {
		
		SDL_Point a2 = { lazer[0].width / 2 * head_lazer[0].ratio,(head_lazer[0].height / 2) * head_lazer[0].ratio };
		SDL_Rect b = { head_lazer[0].center_x - (head_lazer[0].width / 2) * head_lazer[0].ratio, head_lazer[0].center_y - (head_lazer[0].height / 2) * head_lazer[0].ratio, head_lazer[0].width * head_lazer[0].ratio, head_lazer[0].height * head_lazer[0].ratio };
		SDL_RenderCopyEx(gRenderer, head_lazer[0].Texture, NULL, &b, head_lazer[0].angle, &a2, SDL_FLIP_NONE);
		head_lazer[0].ratio += 0.01;
		if (head_lazer[0].ratio >= 1) {
			head_lazer[0].ratio = 1;
		}
		if (head_lazer[0].angle > 180) {
			direction_rotation_lazer = 1;
		}
		else direction_rotation_lazer = -1;
	}
	else if (load_lazer_time < 650) {
		lazer[0].exist = true;
		head_lazer[0].ratio = 0;
		lazer[0].angle += 0.3 * direction_rotation_lazer;
		SDL_Point a2 = { lazer[0].width / 2,(head_lazer[0].height / 2) };
		SDL_Rect c = { lazer[0].center_x - (lazer[0].width / 2) , lazer[0].center_y - (head_lazer[0].height / 2) , lazer[0].width , lazer[0].height };
		SDL_RenderCopyEx(gRenderer, lazer[0].Texture, NULL, &c, lazer[0].angle, &a2, SDL_FLIP_NONE);
	}
	else if (load_lazer_time < 750) {
		SDL_Point a2 = { lazer[0].width / 2,(head_lazer[0].height / 2) };
		SDL_Rect c = { lazer[0].center_x - (lazer[0].width / 2) , lazer[0].center_y - (head_lazer[0].height / 2) , lazer[0].width , lazer[0].height };
		SDL_RenderCopyEx(gRenderer, lazer[0].Texture, NULL, &c, lazer[0].angle, &a2, SDL_FLIP_NONE);
	}
	else if (load_lazer_time >= 750) {
		lazer[0].exist = false;
	}
	///
	lazer_warning_green[1].center_x = lazer[1].center_x = head_lazer[1].center_x = lazer_warning_green[1].center_x = boss.x + boss.width / 2 + 30;
	lazer_warning_green[1].center_y = lazer[1].center_y = head_lazer[1].center_y = lazer_warning_green[1].center_y = boss.y + boss.height / 2;
	if (load_lazer_time < 400) {
		lazer[1].angle = head_lazer[1].angle = lazer_warning_green[1].angle = FindAngle(lazer_warning_green[1].center_x, lazer_warning_green[1].center_y, player.x + player.width / 2 + 30 , player.y + player.height / 2);
		lazer_warning_green[1].render(lazer_warning_green[1].center_x - lazer_warning_green[1].width / 2, lazer_warning_green[1].center_y, NULL, lazer_warning_green[1].angle, &a1);
	}
	else if (load_lazer_time < 450) {
		lazer_warning_red[1].render(lazer_warning_green[1].center_x - lazer_warning_green[1].width / 2, lazer_warning_green[1].center_y, NULL, lazer_warning_green[1].angle, &a1);
	}
	else if (load_lazer_time < 550) {
		SDL_Point a2 = { lazer[1].width / 2 * head_lazer[1].ratio,(head_lazer[1].height / 2) * head_lazer[1].ratio };
		SDL_Rect b = { head_lazer[1].center_x - (head_lazer[1].width / 2) * head_lazer[1].ratio, head_lazer[1].center_y - (head_lazer[1].height / 2) * head_lazer[1].ratio, head_lazer[1].width * head_lazer[1].ratio, head_lazer[1].height * head_lazer[1].ratio };
		SDL_RenderCopyEx(gRenderer, head_lazer[1].Texture, NULL, &b, head_lazer[1].angle, &a2, SDL_FLIP_NONE);
		head_lazer[1].ratio += 0.01;
		if (head_lazer[1].ratio >= 1) {
			head_lazer[1].ratio = 1;
		}
		if (head_lazer[1].angle > 180) {
			direction_rotation_lazer = 1;
		}
		else direction_rotation_lazer = -1;
	}
	else if (load_lazer_time < 650) {
		lazer[1].exist = true;
		head_lazer[1].ratio = 0;
		lazer[1].angle += 0.3 * direction_rotation_lazer;
		SDL_Point a2 = { lazer[1].width / 2,(head_lazer[1].height / 2) };
		SDL_Rect c = { lazer[1].center_x - (lazer[1].width / 2) , lazer[1].center_y - (head_lazer[1].height / 2) , lazer[1].width , lazer[1].height };
		SDL_RenderCopyEx(gRenderer, lazer[1].Texture, NULL, &c, lazer[1].angle, &a2, SDL_FLIP_NONE);
	}
	else if (load_lazer_time < 750) {
		SDL_Point a2 = { lazer[1].width / 2,(head_lazer[1].height / 2) };
		SDL_Rect c = { lazer[1].center_x - (lazer[1].width / 2) , lazer[1].center_y - (head_lazer[1].height / 2) , lazer[1].width , lazer[1].height };
		SDL_RenderCopyEx(gRenderer, lazer[1].Texture, NULL, &c, lazer[1].angle, &a2, SDL_FLIP_NONE);
	}
	else if (load_lazer_time >= 750) {
		lazer[1].exist = false;
	}*/
	//
	//
	//
	//
	//
	//

	/*load_bullet_round_time = (load_bullet_round_time + 1) % 501;
	if (bullet_round_index == NUMBER_BULLET) {
		bullet_round_index = 0;
	}
	if (load_bullet_round_time == 500) {
		bullet_round[bullet_round_index].bullet_virtual.start_x = bullet_round[bullet_round_index].bullet_virtual.x = x + width / 2;
		bullet_round[bullet_round_index].bullet_virtual.start_y = bullet_round[bullet_round_index].bullet_virtual.y = y + height / 2;
		bullet_round[bullet_round_index].bullet_virtual.angle = FindAngle(x + width / 2, y + height / 2, player.x + player.width / 2, player.y + player.height / 2);
		bullet_round[bullet_round_index].exist = true;
		bullet_round[bullet_round_index].bullet_virtual.exist = true;
		bullet_round[bullet_round_index].set();
		bullet_round_index++;
	}*/

	
	load_boom_time = (load_boom_time + 1) % 7002;
		if (load_boom_time == 1800) {
			for (int i = 0; i < boom_index-1; i++) {
				boom[i].explode_bool = true;
			}
			boom_index = 0;
			load_boom_time = 0; 
		}
		if (boom_index < 6) {
			if (load_boom_time % 200 == 0 && load_boom_time <=1600 && load_boom_time >= 400) {
				boom[boom_index].SetBoom();
				boom[boom_index].warning_bool = true;
				boom_index++;
				cout << boom_index << endl;
			}
		}
		else {
			for (int i = 0; i < boom_index; i++) {
				boom[i].warning_bool = false;
			}
		}
}
void Boss::free() {

}
bool Boss::loadFromFile(string path) {
	//Get rid of preexisting texture
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 180, 180, 180));
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			bool_load_bullet_level[0] = bool_load_bullet_level[1] = bool_load_bullet_level[2] = true;
			//Get image dimensions
			width  = loadedSurface->w;
			height = loadedSurface->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	
	Texture = newTexture;
	return Texture != NULL;
}
void Boss::RenderMiniBoss() {
	//int a = 0;
	//if (bool_load_bullet_level[0] == true) {
	//	bullet_level[0][bullet_level_index[0]].start_x = bullet_level[0][bullet_level_index[0]].x = mini_boss_center_1.x + mini_boss_center_1.width / 4 + R_mini_boss * cos((angle_first_mini_boss + a + 90) * PI / 180) - bullet_level_ratio[0] * bullet_level[0][bullet_level_index[0]].width / 2;
	//	bullet_level[0][bullet_level_index[0]].start_y = bullet_level[0][bullet_level_index[0]].y = mini_boss_center_1.y + mini_boss_center_1.height / 2 + R_mini_boss * sin((angle_first_mini_boss + a + 90) * PI / 180) - bullet_level_ratio[0] * bullet_level[0][bullet_level_index[0]].height / 2;
	//	SDL_Rect b = { bullet_level[0][bullet_level_index[0]].x,  bullet_level[0][bullet_level_index[0]].y, bullet_level[0][bullet_level_index[0]].width * bullet_level_ratio[0], bullet_level[0][bullet_level_index[0]].height * bullet_level_ratio[0] };
	//	SDL_RenderCopy(gRenderer, bullet_level[0][bullet_level_index[0]].Texture, NULL, &b);
	//	bullet_level_ratio[0] += 0.001;
	//	if (bullet_level_ratio[0] >= 1.0) {
	//		bullet_level_ratio[0] = 1;
	//	}
	//}
	//a += 120;
	//if (bool_load_bullet_level[1] == true) {
	//	bullet_level[0][bullet_level_index[0] + 1].start_x = bullet_level[0][bullet_level_index[0] + 1].x = mini_boss_center_1.x + mini_boss_center_1.width / 4 + R_mini_boss * cos((angle_first_mini_boss + a + 90) * PI / 180) - bullet_level_ratio[2] * bullet_level[0][bullet_level_index[0] + 1].width / 2;
	//	bullet_level[0][bullet_level_index[0] + 1].start_y = bullet_level[0][bullet_level_index[0] + 1].y = mini_boss_center_1.y + mini_boss_center_1.height / 2 + R_mini_boss * sin((angle_first_mini_boss + a + 90) * PI / 180) - bullet_level_ratio[2] * bullet_level[0][bullet_level_index[0] + 1].height / 2;
	//	SDL_Rect d = { bullet_level[0][bullet_level_index[0] + 1].x,  bullet_level[0][bullet_level_index[0] + 1].y, bullet_level[0][bullet_level_index[0] + 1].width * bullet_level_ratio[2], bullet_level[0][bullet_level_index[0] + 1].height * bullet_level_ratio[2] };
	//	SDL_RenderCopy(gRenderer, bullet_level[0][bullet_level_index[0] + 1].Texture, NULL, &d);
	//	bullet_level_ratio[1] += 0.001;
	//	if (bullet_level_ratio[1] >= 1) {
	//		bullet_level_ratio[1] = 1.0;
	//	}
	//}
	//a += 120;
	//if (bool_load_bullet_level[2] == true) {
	//	bullet_level[0][bullet_level_index[0] + 2].start_x = bullet_level[0][bullet_level_index[0] + 2].x = mini_boss_center_1.x + mini_boss_center_1.width / 4 + R_mini_boss * cos((angle_first_mini_boss + a + 90) * PI / 180) - bullet_level_ratio[2] * bullet_level[0][bullet_level_index[0] + 2].width / 2;
	//	bullet_level[0][bullet_level_index[0] + 2].start_y = bullet_level[0][bullet_level_index[0] + 2].y = mini_boss_center_1.y + mini_boss_center_1.height / 2 + R_mini_boss * sin((angle_first_mini_boss + a + 90) * PI / 180) - bullet_level_ratio[2] * bullet_level[0][bullet_level_index[0] + 2].height / 2;
	//	SDL_Rect d = { bullet_level[0][bullet_level_index[0] + 2].x,  bullet_level[0][bullet_level_index[0] + 2].y, bullet_level[0][bullet_level_index[0] + 2].width * bullet_level_ratio[2], bullet_level[0][bullet_level_index[0] + 2].height * bullet_level_ratio[2] };
	//	SDL_RenderCopy(gRenderer, bullet_level[0][bullet_level_index[0] + 2].Texture, NULL, &d);
	//	bullet_level_ratio[2] += 0.001;
	//	if (bullet_level_ratio[2] >= 1) {
	//		bullet_level_ratio[2] = 1.0;
	//		start_dem_time = true;
	//	}
	//}
	//SDL_Rect a4 = { mini_boss_center_1.x, mini_boss_center_1.y,  mini_boss_center_1.width / 2,mini_boss_center_1.height };
	//SDL_Rect b4 = { mini_boss_center_1.width / 2  , 0 ,  mini_boss_center_1.width / 2, mini_boss_center_1.height };
	//SDL_Rect a3 = { mini_boss_center_1.x + mini_boss_center_1.width / 2, mini_boss_center_1.y + 10, staff_mini_boss_1.width, staff_mini_boss_1.height };
	//SDL_Point b = { staff_mini_boss_1.width / 2,  staff_mini_boss_1.height / 2 };

	//if (load_bullet_level_time > 400 && load_bullet_level_time < 500) {
	//	staff_mini_boss_1.angle -= 0.5;
	//}
	//else if (load_bullet_level_time > 500 && load_bullet_level_time < 600) {
	//	staff_mini_boss_1.angle += 0.5;
	//}
	//else if (load_bullet_level_time > 900 && load_bullet_level_time < 1000) {
	//	staff_mini_boss_1.angle -= 0.5;
	//}
	//else if (load_bullet_level_time > 1000 && load_bullet_level_time < 1100) {
	//	staff_mini_boss_1.angle += 0.5;
	//}
	//else if (load_bullet_level_time > 1400 && load_bullet_level_time < 1500) {
	//	staff_mini_boss_1.angle -= 0.5;
	//}
	//else if (load_bullet_level_time > 1500 && load_bullet_level_time < 1600) {
	//	staff_mini_boss_1.angle += 0.5;
	//}
	//else {
	//	b4 = { 0, 0 ,  mini_boss_center_1.width / 2, mini_boss_center_1.height };
	//}
	//SDL_RenderCopy(gRenderer, mini_boss_center_1.Texture, &b4, &a4);
	//SDL_RenderCopyEx(gRenderer, staff_mini_boss_1.Texture, NULL, &a3, staff_mini_boss_1.angle, &b, SDL_FLIP_NONE);
	//if (start_dem_time == true) {
	//	load_bullet_level_time = (load_bullet_level_time + 1) % 1801;
	//}
	//if (load_bullet_level_time == 500) {
	//	bullet_level[0][bullet_level_index[0]].angle = 1.0 * Rand(0, 700) / 10;
	//	bullet_level[0][bullet_level_index[0]].exist = true;
	//	bool_load_bullet_level[0] = false;
	//}
	//else if (load_bullet_level_time == 1000) {
	//	staff_mini_boss_1.angle -= 0.1;
	//	bullet_level[0][bullet_level_index[0] + 1].angle = 1.0 * Rand(0, 700) / 10;
	//	bullet_level[0][bullet_level_index[0] + 1].exist = true;
	//	bool_load_bullet_level[1] = false;
	//}
	//else if (load_bullet_level_time == 1500) {
	//	bullet_level[0][bullet_level_index[0] + 2].angle = 1.0 * Rand(0, 700) / 10;
	//	bullet_level[0][bullet_level_index[0] + 2].exist = true;
	//	bool_load_bullet_level[2] = false;
	//}
	//else if (load_bullet_level_time == 1800) {
	//	bullet_level_index[0] += 3;
	//	bullet_level_ratio[0] = 0.0;
	//	bullet_level_ratio[1] = 0.0;
	//	bullet_level_ratio[2] = 0.0;
	//	bool_load_bullet_level[0] = bool_load_bullet_level[1] = bool_load_bullet_level[2] = true;
	//	load_bullet_level_time = 0;
	//	start_dem_time = false;
	//}
	//for (int i = 0; i < 2; i++) {
	//	for (int j = 0; j < NUMBER_BULLET * 25; j++) {
	//		if (bullet_level[i][j].exist == true) {
	//			if (bullet_level[i][j].y >= SCREEN_HEIGHT) {
	//				int a = 90 + 36;
	//				for (int h = 1; h <= 4; h++) {
	//					bullet_level[i + 1][bullet_level_index[i + 1]].start_x = bullet_level[i + 1][bullet_level_index[i + 1]].x = bullet_level[i][j].x;
	//					bullet_level[i + 1][bullet_level_index[i + 1]].start_y = bullet_level[i + 1][bullet_level_index[i + 1]].y = bullet_level[i][j].y - 10;
	//					bullet_level[i + 1][bullet_level_index[i + 1]].angle = a;
	//					bullet_level[i + 1][bullet_level_index[i + 1]].exist = true;
	//					a += 36;
	//					bullet_level_index[i + 1] += 1;
	//				}
	//				bullet_level[i][j].exist = false;
	//			}
	//			if (bullet_level[i][j].y <= 0) {
	//				int a = 270 + 36;
	//				for (int h = 1; h <= 4; h++) {
	//					bullet_level[i + 1][bullet_level_index[i + 1]].start_x = bullet_level[i + 1][bullet_level_index[i + 1]].x = bullet_level[i][j].x;
	//					bullet_level[i + 1][bullet_level_index[i + 1]].start_y = bullet_level[i + 1][bullet_level_index[i + 1]].y = bullet_level[i][j].y + 10;
	//					bullet_level[i + 1][bullet_level_index[i + 1]].angle = a;
	//					bullet_level[i + 1][bullet_level_index[i + 1]].exist = true;
	//					a += 36;
	//					bullet_level_index[i + 1] += 1;
	//				}
	//				bullet_level[i][j].exist = false;
	//			}
	//			if (bullet_level[i][j].x >= SCREEN_WIDTH) {
	//				int a = 36;
	//				for (int h = 1; h <= 4; h++) {
	//					bullet_level[i + 1][bullet_level_index[i + 1]].start_x = bullet_level[i + 1][bullet_level_index[i + 1]].x = bullet_level[i][j].x - 10;
	//					bullet_level[i + 1][bullet_level_index[i + 1]].start_y = bullet_level[i + 1][bullet_level_index[i + 1]].y = bullet_level[i][j].y;
	//					bullet_level[i + 1][bullet_level_index[i + 1]].angle = a;
	//					bullet_level[i + 1][bullet_level_index[i + 1]].exist = true;
	//					a += 36;
	//					bullet_level_index[i + 1] += 1;
	//				}
	//				bullet_level[i][j].exist = false;
	//			}
	//			if (bullet_level[i][j].x <= 0) {
	//				int a = 180 + 36;
	//				for (int h = 1; h <= 4; h++) {
	//					bullet_level[i + 1][bullet_level_index[i + 1]].start_x = bullet_level[i + 1][bullet_level_index[i + 1]].x = bullet_level[i][j].x + 10;
	//					bullet_level[i + 1][bullet_level_index[i + 1]].start_y = bullet_level[i + 1][bullet_level_index[i + 1]].y = bullet_level[i][j].y;
	//					bullet_level[i + 1][bullet_level_index[i + 1]].angle = a;
	//					bullet_level[i + 1][bullet_level_index[i + 1]].exist = true;
	//					a += 36;
	//					bullet_level_index[i + 1] += 1;
	//				}
	//				bullet_level[i][j].exist = false;
	//			}
	//		}
	//	}
	//}


 //   SDL_Rect b5 = { mini_boss_center_2.width / 2  , 0 ,  mini_boss_center_2.width / 2, mini_boss_center_2.height };
	//SDL_Rect a5 = { mini_boss_center_2.x, mini_boss_center_2.y,  mini_boss_center_2.width / 2,mini_boss_center_2.height };
   /* star_dem_time= (star_dem_time+1)%5000;
	if (star_dem_time <= 2500) {
		if (star_dem_time % 20 == 0) {
			int a10 = 0;
			int a9 = Rand(0, 2);
			if (star_dem_time % 100 == 0) {
				for (int i = 0; i < 18; i++) {
					star_coordinates[i][2] = -1;
				}
			}
			for (int i = 0; i < a9; i++) {
				while (true) {
					a10 = Rand(0, 15);
					if (star_coordinates[a10][2] == -1) {
						star[star_index].start_x = star[star_index].x = star_coordinates[a10][0];
						star[star_index].start_y = star[star_index].y = star_coordinates[a10][1];
						star[star_index].angle = -20;
						star[star_index].exist = true;
						star_index++;
						if (star_index == 1000) {
							star_index = 0;
						}
						star_coordinates[a10][2] = 1;
						break;
					}
				}
			}
		}
	}
	else {
		b5 = {0 , 0 ,  mini_boss_center_2.width / 2, mini_boss_center_2.height };
	}*/
	/*SDL_RenderCopy(gRenderer, mini_boss_center_2.Texture, &b5, &a5);*/
	angle_first_mini_boss += 0.5;
}
