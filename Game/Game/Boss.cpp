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
	mini_boss_center_1.x = x + width / 2 + 200;
	mini_boss_center_2.x = x + width / 2 - 200;
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
	SDL_Point a1 = { lazer_warning_green.width / 2, 0};
	load_lazer_time = (load_lazer_time + 1) % 781;
	lazer_warning_green.center_x =lazer.center_x =  head_lazer.center_x = lazer_warning_green.center_x = boss.x + boss.width / 2;
	lazer_warning_green.center_y =lazer.center_y =  head_lazer.center_y =lazer_warning_green.center_y = boss.y + boss.height;
	if (load_lazer_time < 400) {
		lazer.angle = head_lazer.angle = lazer_warning_green.angle = FindAngle(lazer_warning_green.center_x, lazer_warning_green.center_y, player.x + player.width / 2, player.y + player.height / 2);
		lazer_warning_green.render(lazer_warning_green.center_x - lazer_warning_green.width / 2, lazer_warning_green.center_y, NULL, lazer_warning_green.angle, &a1);
	}
	else if (load_lazer_time < 450) {
		lazer_warning_red.render(lazer_warning_green.center_x - lazer_warning_green.width / 2, lazer_warning_green.center_y, NULL, lazer_warning_green.angle, &a1);
	}
	else if (load_lazer_time < 500) {
		SDL_Point a2 = { lazer.width / 2 * head_lazer.ratio,(head_lazer.height / 2) * head_lazer.ratio };
		SDL_Rect b = { head_lazer.center_x - (head_lazer.width / 2) * head_lazer.ratio, head_lazer.center_y - (head_lazer.height / 2) * head_lazer.ratio, head_lazer.width * head_lazer.ratio, head_lazer.height * head_lazer.ratio };
		SDL_RenderCopyEx(gRenderer, head_lazer.Texture, NULL, &b, head_lazer.angle, &a2, SDL_FLIP_NONE);
		head_lazer.ratio += 0.015;
		if (head_lazer.ratio >= 1) {
			head_lazer.ratio = 1;
		}
		if (head_lazer.angle > 180) {
			direction_rotation_lazer = 1;
		}
		else direction_rotation_lazer = -1;
	}
	else if (load_lazer_time < 600){
		head_lazer.ratio = 0;
		lazer.angle += 0.3 * direction_rotation_lazer;
		SDL_Point a2 = { lazer.width / 2,(head_lazer.height / 2) };
		SDL_Rect c = { lazer.center_x - (lazer.width / 2) , lazer.center_y - (head_lazer.height / 2) , lazer.width , lazer.height };
		SDL_RenderCopyEx(gRenderer, lazer.Texture, NULL, &c, lazer.angle, &a2, SDL_FLIP_NONE);
	}
	else if (load_lazer_time < 750) {
		SDL_Point a2 = { lazer.width / 2,(head_lazer.height / 2) };
		SDL_Rect c = { lazer.center_x - (lazer.width / 2) , lazer.center_y - (head_lazer.height / 2) , lazer.width , lazer.height };
		SDL_RenderCopyEx(gRenderer, lazer.Texture, NULL, &c, lazer.angle, &a2, SDL_FLIP_NONE);
	}
	/*load_bullet_round_time = (load_bullet_round_time + 1) % 501;
	if (bullet_round_index == NUMBER_BULLET) {
		bullet_round_index = 0;
	}
	if (load_bullet_round_time == 500) {
		cout << 1;
		bullet_round[bullet_round_index].bullet_virtual.start_x = bullet_round[bullet_round_index].bullet_virtual.x = x + width / 2;
		bullet_round[bullet_round_index].bullet_virtual.start_y = bullet_round[bullet_round_index].bullet_virtual.y = y + height / 2;
		bullet_round[bullet_round_index].bullet_virtual.angle = FindAngle(x + width / 2, y + height / 2, player.x + player.width / 2, player.y + player.height / 2);
		bullet_round[bullet_round_index].exist = true;
		bullet_round[bullet_round_index].bullet_virtual.exist = true;
		bullet_round[bullet_round_index].set();
		bullet_round_index++;
	}*/

	if (start_dem_time == true) {
		load_bullet_level_time = (load_bullet_level_time + 1) % 1801;
		
	}
	if (load_bullet_level_time == 500) {
		bullet_level[0][bullet_level_index[0]].angle = 1.0 * Rand(0, 700) / 10;
		bullet_level[0][bullet_level_index[0]].exist = true;
		bool_load_bullet_level[0] = false;
	}
	else if (load_bullet_level_time == 1000) {
		bullet_level[0][bullet_level_index[0]+1].angle = 1.0 * Rand(0, 700) / 10;
		bullet_level[0][bullet_level_index[0]+1].exist = true;
		bool_load_bullet_level[1] = false;
	}
	else if (load_bullet_level_time == 1500) {
		bullet_level[0][bullet_level_index[0]+2].angle = 1.0 * Rand(0, 700) / 10;
		bullet_level[0][bullet_level_index[0]+2].exist = true;
		bool_load_bullet_level[2] = false;
	}
	else if (load_bullet_level_time == 1800) {
		bullet_level_index[0] += 3;
		bullet_level_ratio[0] = 0.0;
		bullet_level_ratio[1] = 0.0;
		bullet_level_ratio[2] = 0.0;
		bool_load_bullet_level[0] = bool_load_bullet_level[1] = bool_load_bullet_level[2] = true;
		load_bullet_level_time = 0;
		start_dem_time = false;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < NUMBER_BULLET * 25; j++) {
			if (bullet_level[i][j].exist == true) {
				if (bullet_level[i][j].y >= SCREEN_HEIGHT) {
					int a = 90 + 36;
					for (int h = 1; h <= 4; h++) {
						bullet_level[i + 1][bullet_level_index[i + 1]].start_x = bullet_level[i + 1][bullet_level_index[i + 1]].x = bullet_level[i][j].x;
						bullet_level[i + 1][bullet_level_index[i + 1]].start_y = bullet_level[i + 1][bullet_level_index[i + 1]].y = bullet_level[i][j].y - 10;
						bullet_level[i + 1][bullet_level_index[i + 1]].angle = a;
						bullet_level[i + 1][bullet_level_index[i + 1]].exist = true;
						a += 36;
						bullet_level_index[i + 1] += 1;
					}
					bullet_level[i][j].exist = false;
				}
				if (bullet_level[i][j].y <=0 ) {
					int a = 270 + 36;
					for (int h = 1; h <= 4; h++) {
						bullet_level[i + 1][bullet_level_index[i + 1]].start_x = bullet_level[i + 1][bullet_level_index[i + 1]].x = bullet_level[i][j].x;
						bullet_level[i + 1][bullet_level_index[i + 1]].start_y = bullet_level[i + 1][bullet_level_index[i + 1]].y = bullet_level[i][j].y + 10;
						bullet_level[i + 1][bullet_level_index[i + 1]].angle = a;
						bullet_level[i + 1][bullet_level_index[i + 1]].exist = true;
						a += 36;
						bullet_level_index[i + 1] += 1;
					}
					bullet_level[i][j].exist = false;
				}
				if (bullet_level[i][j].x >= SCREEN_WIDTH) {
					int a =36;
					for (int h = 1; h <= 4; h++) {
						bullet_level[i + 1][bullet_level_index[i + 1]].start_x = bullet_level[i + 1][bullet_level_index[i + 1]].x = bullet_level[i][j].x-10;
						bullet_level[i + 1][bullet_level_index[i + 1]].start_y = bullet_level[i + 1][bullet_level_index[i + 1]].y = bullet_level[i][j].y;
						bullet_level[i + 1][bullet_level_index[i + 1]].angle = a;
						bullet_level[i + 1][bullet_level_index[i + 1]].exist = true;
						a += 36;
						bullet_level_index[i + 1] += 1;
					}
					bullet_level[i][j].exist = false;
				}
				if (bullet_level[i][j].x <=0) {
					int a = 180 + 36;
					for (int h = 1; h <= 4; h++) {
						bullet_level[i + 1][bullet_level_index[i + 1]].start_x = bullet_level[i + 1][bullet_level_index[i + 1]].x = bullet_level[i][j].x+10;
						bullet_level[i + 1][bullet_level_index[i + 1]].start_y = bullet_level[i + 1][bullet_level_index[i + 1]].y = bullet_level[i][j].y;
						bullet_level[i + 1][bullet_level_index[i + 1]].angle = a;
						bullet_level[i + 1][bullet_level_index[i + 1]].exist = true;
						a += 36;
						bullet_level_index[i + 1] += 1;
					}
					bullet_level[i][j].exist = false;
				}
			}
		}
	}
	/*load_boom_time = (load_boom_time + 1) % 401;
		if (boom_index == 3) {
			for (int i = 0; i < boom_index; i++) {
				boom[i].explode_bool = true;
			}
			boom_index = 0;
			load_boom_time = 0;
		}
		if (boom_index < 3) {
			if (load_boom_time == 400) {
				cout << boom_index << endl;
				boom[boom_index].SetBoom();
				boom[boom_index].exist = true;
				boom_index++;
			}
	}*/
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
	int a = 0;
	if (bool_load_bullet_level[0] == true) {
		bullet_level[0][bullet_level_index[0]].start_x = bullet_level[0][bullet_level_index[0]].x = mini_boss_center_1.x + mini_boss_center_1.width/2 + R_mini_boss * cos((angle_first_mini_boss + a + 90) * PI / 180) - bullet_level_ratio[0] * bullet_level[0][bullet_level_index[0]].width / 2;
		bullet_level[0][bullet_level_index[0]].start_y = bullet_level[0][bullet_level_index[0]].y = mini_boss_center_1.y + mini_boss_center_1.height/ 2 + R_mini_boss * sin((angle_first_mini_boss + a + 90) * PI / 180) - bullet_level_ratio[0] * bullet_level[0][bullet_level_index[0]].height / 2;
		SDL_Rect b = { bullet_level[0][bullet_level_index[0]].x,  bullet_level[0][bullet_level_index[0]].y, bullet_level[0][bullet_level_index[0]].width * bullet_level_ratio[0], bullet_level[0][bullet_level_index[0]].height * bullet_level_ratio[0] };
		SDL_RenderCopy(gRenderer, bullet_level[0][bullet_level_index[0]].Texture, NULL, &b);
		bullet_level_ratio[0] += 0.001;
		if (bullet_level_ratio[0] >= 1.0) {
			bullet_level_ratio[0] = 1;
		}
	}
	a += 120;
	if (bool_load_bullet_level[1] == true) {
		bullet_level[0][bullet_level_index[0] + 1].start_x = bullet_level[0][bullet_level_index[0] + 1].x = mini_boss_center_1.x + mini_boss_center_1.width / 2 + R_mini_boss * cos((angle_first_mini_boss + a + 90) * PI / 180) - bullet_level_ratio[2] * bullet_level[0][bullet_level_index[0] + 1].width / 2;
		bullet_level[0][bullet_level_index[0] + 1].start_y = bullet_level[0][bullet_level_index[0] + 1].y = mini_boss_center_1.y + mini_boss_center_1.height / 2 + R_mini_boss * sin((angle_first_mini_boss + a + 90) * PI / 180) - bullet_level_ratio[2] * bullet_level[0][bullet_level_index[0] + 1].height / 2;
		SDL_Rect d = { bullet_level[0][bullet_level_index[0] + 1].x,  bullet_level[0][bullet_level_index[0] + 1].y, bullet_level[0][bullet_level_index[0] + 1].width * bullet_level_ratio[2], bullet_level[0][bullet_level_index[0] + 1].height * bullet_level_ratio[2] };
		SDL_RenderCopy(gRenderer, bullet_level[0][bullet_level_index[0] + 1].Texture, NULL, &d);
		bullet_level_ratio[1] += 0.001;
		if (bullet_level_ratio[1] >= 1) {
			bullet_level_ratio[1] = 1.0;
		}
	}
	a += 120;
	if (bool_load_bullet_level[2] == true) {
		bullet_level[0][bullet_level_index[0] + 2].start_x = bullet_level[0][bullet_level_index[0] + 2].x = mini_boss_center_1.x + mini_boss_center_1.width / 2  + R_mini_boss * cos((angle_first_mini_boss + a + 90) * PI / 180) - bullet_level_ratio[2] * bullet_level[0][bullet_level_index[0] + 2].width / 2;
		bullet_level[0][bullet_level_index[0] + 2].start_y = bullet_level[0][bullet_level_index[0] + 2].y = mini_boss_center_1.y + mini_boss_center_1.height / 2 + R_mini_boss * sin((angle_first_mini_boss + a + 90) * PI / 180) - bullet_level_ratio[2] * bullet_level[0][bullet_level_index[0] + 2].height / 2;
		SDL_Rect d = { bullet_level[0][bullet_level_index[0] + 2].x,  bullet_level[0][bullet_level_index[0] + 2].y, bullet_level[0][bullet_level_index[0] + 2].width * bullet_level_ratio[2], bullet_level[0][bullet_level_index[0] + 2].height * bullet_level_ratio[2] };
		SDL_RenderCopy(gRenderer, bullet_level[0][bullet_level_index[0] + 2].Texture, NULL, &d);
		bullet_level_ratio[2] += 0.001;
		if (bullet_level_ratio[2] >= 1) {
			bullet_level_ratio[2] = 1.0;
			start_dem_time = true;
		}
	}
	
	//a = 0;
	//miniboss_2_B.x = mini_boss_center_2.x + R_mini_boss * cos((angle_first_mini_boss + a + 90) * PI / 180) - miniboss_2_B.width / 2;
	//miniboss_2_B.y = mini_boss_center_2.y + R_mini_boss * sin((angle_first_mini_boss + a + 90) * PI / 180) - miniboss_2_B.height / 2;
	//miniboss_2_B.RenderMiniBoss();
	//a += 120;
	//miniboss_2_D.x = mini_boss_center_2.x + R_mini_boss * cos((angle_first_mini_boss + a + 90) * PI / 180) - miniboss_2_D.width / 2;
	//miniboss_2_D.y = mini_boss_center_2.y + R_mini_boss * sin((angle_first_mini_boss + a + 90) * PI / 180) - miniboss_2_D.height / 2;
	//miniboss_2_D.RenderMiniBoss();
	//a += 120;
	//miniboss_2_E.x = mini_boss_center_2.x + R_mini_boss * cos((angle_first_mini_boss + a + 90) * PI / 180) - miniboss_2_E.width / 2;
	//miniboss_2_E.y = mini_boss_center_2.y + R_mini_boss * sin((angle_first_mini_boss + a + 90) * PI / 180) - miniboss_2_E.height / 2;
	//miniboss_2_E.RenderMiniBoss();
	angle_first_mini_boss += 0.5;
}