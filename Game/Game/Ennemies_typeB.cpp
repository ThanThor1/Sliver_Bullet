#include "Ennemies_typeB.h"
#include"Declaration.h"
// di chuyển 
bool Ennemies_typeB::checkExist() {
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
void Ennemies_typeB::moveEnnemies() {
	
		SDL_Rect  renderQuad = { E_x, E_y , E_Width, E_Height };
		SDL_Point center = { E_Width / 2 ,0 };
		if (E_angle >= 15) { direction = -1; }
		if (E_angle <= -15) { direction = 1; }
		E_angle += 0.1 * direction;
		exist = true;
		SDL_RenderCopyEx(gRenderer, E_Texture, NULL, &renderQuad, E_angle, &center, SDL_FLIP_NONE);
		if (E_y != E_finish_y) {
			E_y++;
		}
		else {
			loadShoot();
			shoot();
		}
}
//sạc đạn
void Ennemies_typeB::loadShoot() {
	load_bullet_x3_time = (load_bullet_x3_time + 1) % 1001;
	if (thbullet_x3 == NUMBER_BULLET) {
		thbullet_x3 = 0;
	}
	if (load_bullet_x3_time == 1000) {
		int a = -20;
		for (int i = 0; i < 3; i++) {
			bullet_x3[thbullet_x3][i].B_start_x = bullet_x3[thbullet_x3][i].B_x = E_x + E_Width / 2 + (E_Height + 10) * sin(-E_angle * PI / 180) - bullet_x3[thbullet_x3][i].B_Width / 2;
			bullet_x3[thbullet_x3][i].B_start_y = bullet_x3[thbullet_x3][i].B_y = E_y + (E_Height + 10) * cos(-E_angle * PI / 180);
			bullet_x3[thbullet_x3][i].B_angle = E_angle + a;
			bullet_x3[thbullet_x3][i].B_slope = tan((bullet_x3[thbullet_x3][i].B_angle) * PI / 180);
			bullet_x3[thbullet_x3][i].B_exist = true;
			a += 20;
		}
		thbullet_x3++;
	}
}
//bắn
void Ennemies_typeB::shoot() {
	SDL_Point PointBullet2;
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j <= 2; j++) {
			if (bullet_x3[i][j].B_exist == true)
			{
				PointBullet2 = { bullet_x3[i][j].B_Width / 2, 0 };
				bullet_x3[i][j].render(bullet_x3[i][j].B_x, bullet_x3[i][j].B_y, NULL, bullet_x3[i][j].B_angle, &PointBullet2);
			}
		}
	}
	if (load_bullet_x3_time % 2 == 0) {
		for (int i = 0; i < NUMBER_BULLET; i++) {
			for (int j = 0; j <= 2; j++) {
				if (bullet_x3[i][j].B_exist == true)
				{
					bullet_x3[i][j].B_y += 2;
					bullet_x3[i][j].B_x = round(bullet_x3[i][j].B_start_x + (1.000 * bullet_x3[i][j].B_start_y * bullet_x3[i][j].B_slope - bullet_x3[i][j].B_y * 1.000 * bullet_x3[i][j].B_slope));
				}
			}
		}
	}
}
void Ennemies_typeB::free() {
	E_x = 0;
	E_y = 0;
	E_start_x = 0;
	E_start_y = 0;
	E_finish_x = 0;
	E_finish_y = 0;
	E_slope = 0;
	E_angle = 0;
	exist = false;
	health = 10;
	thbullet_x3 = 0;
	load_bullet_x3_time = 0;
	speed = 1;
	direction = 1;
}