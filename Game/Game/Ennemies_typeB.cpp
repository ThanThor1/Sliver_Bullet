#include "Ennemies_typeB.h"
#include"Declaration.h"
// di chuyển 
bool Ennemies_typeB::checkExist() {
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
void Ennemies_typeB::moveEnnemies() {
	if (load_bullet_ennemies_B_time == 1000) {
		frameth = 2;
	}
	else if (load_bullet_ennemies_B_time >= 150) {
		frameth = 1;
		if (angle >= 15) { direction = -1; }
		if (angle <= -15) { direction = 1; }
		angle += 0.1 * direction;
	}
	render();
	if (center_y != center_finish_y) {
		center_y++;
	}
	else {
		loadShoot();
	}
}
//sạc đạn
void Ennemies_typeB::loadShoot() {
	load_bullet_ennemies_B_time = (load_bullet_ennemies_B_time + 1) % 1001;
	if (bullet_ennemies_B_index == NUMBER_BULLET) {
		bullet_ennemies_B_index = 0;
	}
	if (load_bullet_ennemies_B_time == 1000) {
		int a = -20;
		for (int i = 0; i < 3; i++) {
			bullet_ennemies_B[bullet_ennemies_B_index][i].center_start_x = bullet_ennemies_B[bullet_ennemies_B_index][i].center_x =center_x+ width / 2 + (height + 10) * sin(-angle * PI / 180) - bullet_ennemies_B[bullet_ennemies_B_index][i].width / 2;
			bullet_ennemies_B[bullet_ennemies_B_index][i].center_start_y = bullet_ennemies_B[bullet_ennemies_B_index][i].center_y =center_y+ (height + 10) * cos(-angle * PI / 180);
			bullet_ennemies_B[bullet_ennemies_B_index][i].angle = angle + a;
			bullet_ennemies_B[bullet_ennemies_B_index][i].exist = true;
			a += 20;
		}
		bullet_ennemies_B_index++;
	}
}

void Ennemies_typeB::free() {
	center_x = 0;
	center_y = 0;
	center_start_x = 0;
	center_start_y = 0;
	center_finish_x = 0;
	center_finish_y = 0;
	slope = 0;
	angle = 0;
	exist = false;
	health = 10;
	load_bullet_ennemies_B_time = Rand(0, 1000);
	speed = 1;
	direction = 1;
	photo = 0;
	death.free();
}

