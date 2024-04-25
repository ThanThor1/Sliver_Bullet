#include "Boss.h"
#include "SomeFunction.h"
#include "Declaration.h"
// di chuyển 
bool Boss::checkExist() {
	checkHit(health,score);
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
	render();
	mini_boss_center_1.center_x =center_x+ 200;
	mini_boss_center_2.center_x =center_x- 200;
	mini_boss_center_1.center_y =center_y- 100;
	mini_boss_center_2.center_y =center_y- 100;
	RenderMiniBoss();
	if (center_y != center_finish_y) {
		center_y++;
		bool_load_bullet_level[0] = true;
		bool_load_bullet_level[1] = true;
		bool_load_bullet_level[2] = true;
	}
	else {
		loadShoot();
	}
}
//sạc đạn
void Boss::loadShoot() {
	/*SDL_Point a1 = { lazer_warning_green[0].width / 2, 0 };
	load_lazer_time = (load_lazer_time + 1) % 1001;
	lazer_warning_green[0].center_x = lazer[0].center_x = head_lazer[0].center_x = lazer_warning_green[0].center_x = boss.center_x - 30;
	lazer_warning_green[0].center_y = lazer[0].center_y = head_lazer[0].center_y = lazer_warning_green[0].center_y = boss.center_y;
	if (load_lazer_time < 400) {
		lazer[0].angle = head_lazer[0].angle = lazer_warning_green[0].angle = FindAngle(lazer_warning_green[0].center_x, lazer_warning_green[0].center_y, player.center_x -30, player.center_y );
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
	}*/
	///
	/*load_lazer_time = (load_lazer_time + 1) % 1001;
	lazer_warning_green[1].center_x = lazer[1].center_x = head_lazer[1].center_x = lazer_warning_green[1].center_x = boss.center_x  + 30;
	lazer_warning_green[1].center_y = lazer[1].center_y = head_lazer[1].center_y = lazer_warning_green[1].center_y = boss.center_y ;
	if (load_lazer_time < 400) {
		lazer[1].angle = head_lazer[1].angle = lazer_warning_green[1].angle = FindAngle(lazer_warning_green[1].center_x, lazer_warning_green[1].center_y, player.center_x+ 30, player.center_y);
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
	}*/
	//
	//
	//
	//
	//
	//

	/*load_bullet_triangle_time = (load_bullet_triangle_time + 1) % 501;
	if (bullet_triangle_index == NUMBER_BULLET) {
		bullet_triangle_index = 0;
	}
	if (load_bullet_triangle_time == 500) {
		bullet_triangle[bullet_triangle_index].bullet_virtual.center_start_x = bullet_triangle[bullet_triangle_index].bullet_virtual.center_x = center_x;
		bullet_triangle[bullet_triangle_index].bullet_virtual.center_start_y = bullet_triangle[bullet_triangle_index].bullet_virtual.center_y = center_y;
		bullet_triangle[bullet_triangle_index].bullet_virtual.angle = FindAngle(center_x, center_y , player.center_x , player.center_y );
		bullet_triangle[bullet_triangle_index].exist = true;
		bullet_triangle[bullet_triangle_index].bullet_virtual.exist = true;
		bullet_triangle[bullet_triangle_index].set();
		bullet_triangle_index++;
	}*/

	/*load_boom_time = (load_boom_time + 1) % 7002;
	if (load_boom_time == 2200) {
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
	else if (load_boom_time >= 2000) {
		for (int i = 0; i < boom_index; i++) {
			boom[i].warning_bool = false;
		}
	}*/
}
void Boss::free() {

}
void Boss::RenderMiniBoss() {
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
	SDL_Rect b4 = { mini_boss_center_1.width / 2  , 0 ,  mini_boss_center_1.width / 2, mini_boss_center_1.height };
	mini_boss_center_1.frameth = 2;
	staff_mini_boss_1.center_x = mini_boss_center_1.center_x + mini_boss_center_1.width / 2;
	staff_mini_boss_1.center_y = mini_boss_center_1.center_y + 10;
	if (load_bullet_level_time > 400 && load_bullet_level_time < 500) {
		staff_mini_boss_1.angle -= 0.5;
	}
	else if (load_bullet_level_time > 500 && load_bullet_level_time < 600) {
		staff_mini_boss_1.angle += 0.5;
	}
	else if (load_bullet_level_time > 900 && load_bullet_level_time < 1000) {
		staff_mini_boss_1.angle -= 0.5;
	}
	else if (load_bullet_level_time > 1000 && load_bullet_level_time < 1100) {
		staff_mini_boss_1.angle += 0.5;
	}
	else if (load_bullet_level_time > 1400 && load_bullet_level_time < 1500) {
		staff_mini_boss_1.angle -= 0.5;
	}
	else if (load_bullet_level_time > 1500 && load_bullet_level_time < 1600) {
		staff_mini_boss_1.angle += 0.5;
	}
	else {
		mini_boss_center_1.frameth = 1;
	}
	mini_boss_center_1.render();
	staff_mini_boss_1.render();
	if (start_load_shoot_bullet_level_time == true) {
		load_bullet_level_time = (load_bullet_level_time + 1) % 1801;
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
	/*mini_boss_center_2.frameth = 2;
    star_dem_time= (star_dem_time+1)%5000;
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
		mini_boss_center_2.frameth = 1;
	}
	mini_boss_center_2.render();*/
	angle_first_mini_boss += 0.5;
}
