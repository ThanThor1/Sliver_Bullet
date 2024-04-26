#include "Boss.h"
#include "SomeFunction.h"
#include "Declaration.h"
// di chuyển 
bool Boss::checkExist() {
	checkHit(health,score);
	if (health <= 0) {
		exist = false;
		dem_death++;
			if (dem_death < 200) {
				for (int i = 0; i < 4; i++) {
					if (death[i].exist == true) {
						death[i].frameth = death[i].photo / 10 + 1;
						death[i].alpha = 255 - death[i].photo * 3;
						death[i].center_x = center_x + death[i].center_delta_x;
						death[i].center_y = center_y + death[i].center_delta_y;
						death[i].render();
						death[i].photo = (death[i].photo + 1) % 72;
						if (death[i].photo > 70) {
								death[i].alpha = 255;
								death[i].exist = false;
						}
					}
				}
				for (int i = 4; i < 8; i++) {
					if (death[i].exist == true) {
						death[i].frameth = death[i].photo / 10 + 1;
						death[i].alpha = 255 - death[i].photo * 3;
						death[i].center_x = mini_boss_center_1.center_x + death[i].center_delta_x;
						death[i].center_y = mini_boss_center_1.center_y + death[i].center_delta_y;
						death[i].render();
						death[i].photo = (death[i].photo + 1) % 72;
						if (death[i].photo > 70) {
							death[i].alpha = 255;
							death[i].exist = false;
						}
					}
				}
				for (int i = 8; i < 12; i++) {
					if (death[i].exist == true) {
						death[i].frameth = death[i].photo / 10 + 1;
						death[i].alpha = 255 - death[i].photo * 3;
						death[i].center_x = mini_boss_center_2.center_x + death[i].center_delta_x;
						death[i].center_y = mini_boss_center_2.center_y + death[i].center_delta_y;
						death[i].render();
						death[i].photo = (death[i].photo + 1) % 72;
						if (death[i].photo > 70) {
							death[i].alpha = 255;
							death[i].exist = false;
						}
					}
				}
			}
	}
	else exist = true;
	if (exist == true) {
		moveEnnemies();
	}
	return exist;
}
void Boss::moveEnnemies() {
	render();
	mini_boss_center_1.center_x =center_x + 250;
	mini_boss_center_2.center_x =center_x - 250;
	mini_boss_center_1.center_y =center_y - 100;
	mini_boss_center_2.center_y =center_y - 100;
	if (center_y != center_finish_y) {
		death[0].photo = 0;
		death[1].photo = 0;
		death[2].photo = 0;
		death[3].photo = 0;
		death[4].photo = 0;
		death[5].photo = 0;
		death[6].photo = 0;
		death[7].photo = 0;
		death[8].photo = 0;
		death[9].photo = 0;
		death[10].photo = 0;
		death[11].photo = 0;
		death[0].exist = true;
		death[1].exist = true;
		death[2].exist = true;
		death[3].exist = true;
		death[4].exist = true;
		death[5].exist = true;
		death[6].exist = true;
		death[7].exist = true;
		death[8].exist = true;
		death[9].exist = true;
		death[10].exist = true;
		death[11].exist = true;
		death[0].center_delta_x = 40;
		death[1].center_delta_x = -40;
		death[2].center_delta_y = 30;
		death[3].center_delta_y = -25;
		death[4].center_delta_x = 40;
		death[5].center_delta_x = -40;
		death[6].center_delta_y = 30;
		death[7].center_delta_y = -25;
		death[8].center_delta_x = 40;
		death[9].center_delta_x = -40;
		death[10].center_delta_y = 30;
		death[11].center_delta_y = -25;
		bool_load_bullet_level[0] = true;
		bool_load_bullet_level[1] = true;
		bool_load_bullet_level[2] = true;
		center_y++;
	}
	load_turn_fight = (load_turn_fight + 1) % 1000000000;
	/*cout << load_turn_fight << endl;*/
	if (load_turn_fight != 0) {
		if (load_turn_fight % 3000 == 0) {
			TurnBulletLevel = true;
		}
		if (load_turn_fight % 1000 == 0) {
			TurnBulletTriangle = true;
		}
		if (load_turn_fight % 1500 == 0) {
			TurnLazer = true;
		}
		if (load_turn_fight % 1800 == 0) {
			TurnBoom = true;
		}
		if (load_turn_fight % 2500 == 0) {
			TurnStar = true;
		}
		if (load_turn_fight % 900 == 0) {
			if (item_index == NUMBER_ITEM) {
				item_index = 0;
			}
			item[item_index] = item_example[Rand(1,5)];
			item[item_index].center_x = Rand(50, 750);
			item[item_index].center_y = -50;
			item[item_index].exist = true;
		}
	}
	int a = 0;
	if (bool_load_bullet_level[0] == true) {
		bullet_level[0][bullet_level_index[0]].center_start_x = bullet_level[0][bullet_level_index[0]].center_x = mini_boss_center_1.center_x + R_mini_boss * cos((angle_first_mini_boss + a + 90) * PI / 180);
		bullet_level[0][bullet_level_index[0]].center_start_y = bullet_level[0][bullet_level_index[0]].center_y = mini_boss_center_1.center_y + R_mini_boss * sin((angle_first_mini_boss + a + 90) * PI / 180);
		bullet_level[0][bullet_level_index[0]].renderRatio();
		bullet_level[0][bullet_level_index[0]].ratio = bullet_level_ratio[0];
		bullet_level_ratio[0] += 0.001;
		if (bullet_level_ratio[0] >= 1.0) {
			bullet_level_ratio[0] = 1;
		}
	}
	a += 120;
	if (bool_load_bullet_level[1] == true) {
		bullet_level[0][bullet_level_index[0] + 1].center_start_x = bullet_level[0][bullet_level_index[0] + 1].center_x = mini_boss_center_1.center_x + R_mini_boss * cos((angle_first_mini_boss + a + 90) * PI / 180);
		bullet_level[0][bullet_level_index[0] + 1].center_start_y = bullet_level[0][bullet_level_index[0] + 1].center_y = mini_boss_center_1.center_y + R_mini_boss * sin((angle_first_mini_boss + a + 90) * PI / 180);
		bullet_level[0][bullet_level_index[0] + 1].renderRatio();
		bullet_level[0][bullet_level_index[0] + 1].ratio = bullet_level_ratio[1];
		bullet_level_ratio[1] += 0.001;
		if (bullet_level_ratio[1] >= 1) {
			bullet_level_ratio[1] = 1.0;
		}
	}
	a += 120;
	if (bool_load_bullet_level[2] == true) {
		bullet_level[0][bullet_level_index[0] + 2].center_start_x = bullet_level[0][bullet_level_index[0] + 2].center_x = mini_boss_center_1.center_x + R_mini_boss * cos((angle_first_mini_boss + a + 90) * PI / 180);
		bullet_level[0][bullet_level_index[0] + 2].center_start_y = bullet_level[0][bullet_level_index[0] + 2].center_y = mini_boss_center_1.center_y + R_mini_boss * sin((angle_first_mini_boss + a + 90) * PI / 180);
		bullet_level[0][bullet_level_index[0] + 2].renderRatio();
		bullet_level[0][bullet_level_index[0] + 2].ratio = bullet_level_ratio[2];
		bullet_level_ratio[2] += 0.001;
		if (bullet_level_ratio[2] >= 1) {
			bullet_level_ratio[2] = 1.0;
			start_load_shoot_bullet_level_time = true;
		}
	}
	angle_first_mini_boss += 0.5;
	mini_boss_center_2.frameth = 1;
	mini_boss_center_1.frameth = 1;
	if (TurnBulletLevel == true) {
		loadTurnBulletLevel();
	}
	if (TurnBulletTriangle == true) {
		loadTurnBulletTriangle();
	}
	if (TurnLazer == true) {
		loadTurnLazer();
	}
	if (TurnBoom == true) {
		loadTurnBoom();
	}
	if (TurnStar == true) {
		loadTurnStar();
	}
	//
	staff_mini_boss_1.center_x = mini_boss_center_1.center_x + mini_boss_center_1.width / 2;
	staff_mini_boss_1.center_y = mini_boss_center_1.center_y + 10;
	health_boss_background.center_x = center_x;
	health_boss_background.center_y = center_y - 100;
	SDL_Rect b = { health_boss_background.center_x - health_boss_background.width/2 +(health_boss_background.width- health_boss.width)/2 ,  health_boss_background.center_y - health_boss_background.height / 2 + +(health_boss_background.height - health_boss.height) / 2 , health_boss.width * health / 2000,  health_boss.height};
	health_boss_background.render();
	health_boss.renderFlexible(NULL, &b);
	mini_boss_center_1.render();
	staff_mini_boss_1.render();
	if (mini_boss_center_2.angle >= 15) { mini_boss_center_2.direction = -1; }
	if (mini_boss_center_2.angle <= -15) { mini_boss_center_2.direction = 1; }
	mini_boss_center_2.angle += 0.1 * mini_boss_center_2.direction;
	mini_boss_center_2.render();
}
void Boss::loadTurnBulletLevel() {
	if (load_bullet_level_time > 400 && load_bullet_level_time < 500) {
		staff_mini_boss_1.angle -= 0.5;
		mini_boss_center_1.frameth = 2;
	}
	else if (load_bullet_level_time > 500 && load_bullet_level_time < 600) {
		staff_mini_boss_1.angle += 0.5;
		mini_boss_center_1.frameth = 2;
	}
	else if (load_bullet_level_time > 900 && load_bullet_level_time < 1000) {
		staff_mini_boss_1.angle -= 0.5;
		mini_boss_center_1.frameth = 2;
	}
	else if (load_bullet_level_time > 1000 && load_bullet_level_time < 1100) {
		staff_mini_boss_1.angle += 0.5;
		mini_boss_center_1.frameth = 2;
	}
	else if (load_bullet_level_time > 1400 && load_bullet_level_time < 1500) {
		staff_mini_boss_1.angle -= 0.5;
		mini_boss_center_1.frameth = 2;
	}
	else if (load_bullet_level_time > 1500 && load_bullet_level_time < 1600) {
		staff_mini_boss_1.angle += 0.5;
		mini_boss_center_1.frameth = 2;
	}
	if (load_bullet_level_time == 500) {
		bullet_level[0][bullet_level_index[0]].angle = 1.0 * Rand(0, 70);
		bullet_level[0][bullet_level_index[0]].exist = true;
		bool_load_bullet_level[0] = false;
	}
	else if (load_bullet_level_time == 1000) {
		staff_mini_boss_1.angle -= 0.1;
		bullet_level[0][bullet_level_index[0] + 1].angle = 1.0 * Rand(0, 70);
		bullet_level[0][bullet_level_index[0] + 1].exist = true;
		bool_load_bullet_level[1] = false;
	}
	else if (load_bullet_level_time == 1500) {
		bullet_level[0][bullet_level_index[0] + 2].angle = 1.0 * Rand(0, 70);
		bullet_level[0][bullet_level_index[0] + 2].exist = true;
		bool_load_bullet_level[2] = false;
	}
	else if (load_bullet_level_time == 1800) {
		bullet_level_index[0] += 3;
		bullet_level_ratio[0] = 0.0;
		bullet_level_ratio[1] = 0.0;
		bullet_level_ratio[2] = 0.0;
		bool_load_bullet_level[0] = bool_load_bullet_level[1] = bool_load_bullet_level[2] = true;
		load_bullet_level_time = 0;
		start_load_shoot_bullet_level_time = false;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < NUMBER_BULLET * 25; j++) {
			if (bullet_level[i][j].exist == true) {
				if (bullet_level[i][j].center_y >= SCREEN_HEIGHT) {
					int a = 90 + Rand(0, 72);
					for (int h = 1; h <= 4; h++) {
						bullet_level[i + 1][bullet_level_index[i + 1]].center_start_x = bullet_level[i + 1][bullet_level_index[i + 1]].center_x = bullet_level[i][j].center_x;
						bullet_level[i + 1][bullet_level_index[i + 1]].center_start_y = bullet_level[i + 1][bullet_level_index[i + 1]].center_y = bullet_level[i][j].center_y - 10;
						bullet_level[i + 1][bullet_level_index[i + 1]].angle = a;
						bullet_level[i + 1][bullet_level_index[i + 1]].exist = true;
						a += 36;
						bullet_level_index[i + 1] += 1;
					}
					bullet_level[i][j].exist = false;
				}
				else if (bullet_level[i][j].center_y <= 0) {
					int a = 270 + Rand(0, 72);
					for (int h = 1; h <= 4; h++) {
						bullet_level[i + 1][bullet_level_index[i + 1]].center_start_x = bullet_level[i + 1][bullet_level_index[i + 1]].center_x = bullet_level[i][j].center_x;
						bullet_level[i + 1][bullet_level_index[i + 1]].center_start_y = bullet_level[i + 1][bullet_level_index[i + 1]].center_y = bullet_level[i][j].center_y + 10;
						bullet_level[i + 1][bullet_level_index[i + 1]].angle = a;
						bullet_level[i + 1][bullet_level_index[i + 1]].exist = true;
						a += 36;
						bullet_level_index[i + 1] += 1;
					}
					bullet_level[i][j].exist = false;
				}
				else if (bullet_level[i][j].center_x >= SCREEN_WIDTH) {
					int a = Rand(0, 72);
					for (int h = 1; h <= 4; h++) {
						bullet_level[i + 1][bullet_level_index[i + 1]].center_start_x = bullet_level[i + 1][bullet_level_index[i + 1]].center_x = bullet_level[i][j].center_x - 10;
						bullet_level[i + 1][bullet_level_index[i + 1]].center_start_y = bullet_level[i + 1][bullet_level_index[i + 1]].center_y = bullet_level[i][j].center_y;
						bullet_level[i + 1][bullet_level_index[i + 1]].angle = a;
						bullet_level[i + 1][bullet_level_index[i + 1]].exist = true;
						a += 36;
						bullet_level_index[i + 1] += 1;
					}
					bullet_level[i][j].exist = false;
				}
				else if (bullet_level[i][j].center_x <= 0) {
					int a = 180 + Rand(0, 72);
					for (int h = 1; h <= 4; h++) {
						bullet_level[i + 1][bullet_level_index[i + 1]].center_start_x = bullet_level[i + 1][bullet_level_index[i + 1]].center_x = bullet_level[i][j].center_x + 10;
						bullet_level[i + 1][bullet_level_index[i + 1]].center_start_y = bullet_level[i + 1][bullet_level_index[i + 1]].center_y = bullet_level[i][j].center_y;
						bullet_level[i + 1][bullet_level_index[i + 1]].angle = a;
						bullet_level[i + 1][bullet_level_index[i + 1]].exist = true;
						a += 36;
						bullet_level_index[i + 1] += 1;
					}
					bullet_level[i][j].exist = false;
				}
				else if (((bullet_level[i][j].center_x - mini_boss_center_1.center_x) * (bullet_level[i][j].center_x - mini_boss_center_1.center_x)
					+ (bullet_level[i][j].center_y - mini_boss_center_1.center_y) * (bullet_level[i][j].center_y - mini_boss_center_1.center_y)
					>= 160000) && i == 0) {
					int a = Rand(0, 36);
					for (int h = 1; h <= 5; h++) {
						bullet_level[i + 1][bullet_level_index[i + 1]].center_start_x = bullet_level[i + 1][bullet_level_index[i + 1]].center_x = bullet_level[i][j].center_x + 10;
						bullet_level[i + 1][bullet_level_index[i + 1]].center_start_y = bullet_level[i + 1][bullet_level_index[i + 1]].center_y = bullet_level[i][j].center_y;
						bullet_level[i + 1][bullet_level_index[i + 1]].angle = a;
						bullet_level[i + 1][bullet_level_index[i + 1]].exist = true;
						a += 72;
						bullet_level_index[i + 1] += 1;
					}
					bullet_level[i][j].exist = false;
				}
			}
		}
	}
	if (start_load_shoot_bullet_level_time == true) {
		load_bullet_level_time = (load_bullet_level_time + 1) % 2001;
	}
	if (load_bullet_level_time == 1900) {
		TurnBulletLevel = false;
		load_bullet_level_time = 0;
	}
}
void Boss::loadTurnLazer() {
	SDL_Point a1 = { lazer_warning_green[0].width / 2, 0 };
	lazer_warning_red[0].center_x = lazer_warning_green[0].center_x = lazer[0].center_x = head_lazer[0].center_x = lazer_warning_green[0].center_x = boss.center_x - 25;
	lazer_warning_red[0].center_y = lazer_warning_green[0].center_y = lazer[0].center_y = head_lazer[0].center_y = lazer_warning_green[0].center_y = boss.center_y;
	if (load_lazer_time < 400) {
		lazer[0].angle = head_lazer[0].angle = lazer_warning_red[0].angle = lazer_warning_green[0].angle = FindAngle(lazer_warning_green[0].center_x, lazer_warning_green[0].center_y, player.center_x - 25, player.center_y);
		lazer_warning_green[0].render(&a1);
	}
	else if (load_lazer_time < 450) {
		lazer_warning_red[0].render(&a1);
	}
	else if (load_lazer_time < 550) {
		head_lazer[0].renderRatio();
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
		SDL_Point a2 = { lazer[0].width / 2, (head_lazer[0].height / 2) };
		lazer[0].render(&a2);
	}
	else if (load_lazer_time < 750) {
		SDL_Point a2 = { lazer[0].width / 2,(head_lazer[0].height / 2) };
		lazer[0].render(&a2);
	}
	else if (load_lazer_time >= 750) {
		lazer[0].exist = false;
	}
	///
	load_lazer_time = (load_lazer_time + 1) % 1001;
	lazer_warning_red[1].center_x = lazer_warning_green[1].center_x = lazer[1].center_x = head_lazer[1].center_x = lazer_warning_green[1].center_x = boss.center_x + 25;
	lazer_warning_red[1].center_y = lazer_warning_green[1].center_y = lazer[1].center_y = head_lazer[1].center_y = lazer_warning_green[1].center_y = boss.center_y;
	if (load_lazer_time < 400) {
		lazer[1].angle = head_lazer[1].angle = lazer_warning_red[1].angle = lazer_warning_green[1].angle = FindAngle(lazer_warning_green[1].center_x, lazer_warning_green[1].center_y, player.center_x + 25, player.center_y);
		lazer_warning_green[1].render(&a1);
	}
	else if (load_lazer_time < 450) {
		lazer_warning_red[1].render(&a1);
	}
	else if (load_lazer_time < 550) {
		head_lazer[1].renderRatio();
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
		SDL_Point a2 = { lazer[1].width / 2, (head_lazer[1].height / 2) };
		lazer[1].render(&a2);
	}
	else if (load_lazer_time < 750) {
		SDL_Point a2 = { lazer[1].width / 2,(head_lazer[1].height / 2) };
		lazer[1].render(&a2);
	}
	else if (load_lazer_time >= 750) {
		lazer[1].exist = false;
	}
	//
	load_lazer_time = (load_lazer_time + 1) % 1001;
	if (load_lazer_time > 900) {
		TurnLazer = false;
		load_lazer_time = 0;
	}
}
void Boss::loadTurnBoom() {
	
	if (load_boom_time == 2000) {
		for (int i = 0; i < boom_index; i++) {
			boom[i].explode_bool = true;
		}
		boom_index = 0;
		load_boom_time = 0;
	}
	if (boom_index < 6) {
		if (load_boom_time % 200 == 0 && load_boom_time <= 1600 && load_boom_time >= 400) {
			boom[boom_index].SetBoom();
			boom[boom_index].warning_bool = true;
			boom_index++;
		}
	}
	else if (load_boom_time >= 1800) {
		for (int i = 0; i < boom_index; i++) {
			boom[i].warning_bool = false;
		}
	}
	load_boom_time = (load_boom_time + 1) % 5002;
	if (load_boom_time == 2200) {
		TurnBoom = false;
		load_boom_time = 0;
	}
}
void Boss::loadTurnBulletTriangle() {
	if (load_bullet_triangle_time % 300 == 0) {
		bullet_triangle[bullet_triangle_index].bullet_virtual.center_start_x = bullet_triangle[bullet_triangle_index].bullet_virtual.center_x = center_x;
		bullet_triangle[bullet_triangle_index].bullet_virtual.center_start_y = bullet_triangle[bullet_triangle_index].bullet_virtual.center_y = center_y;
		bullet_triangle[bullet_triangle_index].bullet_virtual.angle = FindAngle(center_x, center_y, player.center_x, player.center_y);
		bullet_triangle[bullet_triangle_index].exist = true;
		bullet_triangle[bullet_triangle_index].bullet_virtual.exist = true;
		bullet_triangle[bullet_triangle_index].set();
		bullet_triangle_index++;
	}
	load_bullet_triangle_time = (load_bullet_triangle_time + 1) % 3001;
	if (load_bullet_triangle_time == 3000){
		TurnBulletTriangle = false;
		load_bullet_triangle_time = 0;
	}
	if (bullet_triangle_index == NUMBER_BULLET) {
		bullet_triangle_index = 0;
	}
}
void Boss::loadTurnStar() {
	if (star_dem_time <= 2500) {
		mini_boss_center_2.frameth = 2;
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
						star[star_index].center_start_x = star[star_index].center_x = star_coordinates[a10][0];
						star[star_index].center_start_y = star[star_index].center_y = star_coordinates[a10][1];
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
		star_dem_time = 0;
		TurnStar = false;
	}
	star_dem_time = (star_dem_time + 1) % 2502;
	if (star_dem_time == 2600) {
		star_dem_time = 0;
		TurnStar = false;
	}
}
void Boss::free() {
	dem_death = 0;
	score = 1000000;
	load_turn_fight = 0;
	// star
	star_bool = false;
	star_dem_time = 0;
	//bullet_level
	start_load_shoot_bullet_level_time = false;
	bullet_level_ratio[0] = 0;
	bullet_level_ratio[1] = 0;
	bullet_level_ratio[2] = 0;
	bool_load_bullet_level[0] = true;
	bool_load_bullet_level[1] = true;
	bool_load_bullet_level[2] = true;
	load_bullet_level_time = 0;
	angle_first_mini_boss = 0.0;
	R_mini_boss = 100;
	// lazer
	lazer_shoot_bool = false;
	load_lazer_time;
	direction_rotation_lazer = 1;
	// bullet_triangle
    load_bullet_triangle_time = 0;
	// boom
	load_boom_time = 0;
	health = 2000;
	TurnBulletLevel = false;
	TurnLazer = false;
	TurnBoom = false;
	TurnBulletTriangle = false;
	TurnStar = false;
	for (int i = 0; i < NUMBER_BULLET; i++) {
		boom[i].free();
	}
	for (int i = 0; i < 1000; i++) {
		star[i].free();
	}
	for (int i = 0; i < NUMBER_BULLET; i++) {
		bullet_triangle[i].free1();
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < NUMBER_BULLET * 25; j++) {
			bullet_level[i][j].free();
		}
	}
	health_boss.free();
	health_boss_background.free();
	mini_boss_center_1.free();
	staff_mini_boss_1.free();
	mini_boss_center_2.free();
	lazer[0].free();
	lazer[1].free();
	head_lazer[0].free();
	head_lazer[1].free();
	lazer_warning_red[0].free();
	lazer_warning_red[1].free();
	lazer_warning_green[0].free();
	lazer_warning_green[1].free();
	bullet_around_boss_index = 0;
	boom_index = 0;
	star_index = 0;
	bullet_triangle_index = 0;
	bullet_level_index[0] =0;
	bullet_level_index[1] = 0;
    bullet_level_index[2] = 0;
}
