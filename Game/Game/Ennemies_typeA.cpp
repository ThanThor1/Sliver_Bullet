#include "Ennemies_typeA.h"
#include"Declaration.h"
// di chuyển 
bool Ennemies_typeA::checkExist() {
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
void Ennemies_typeA::moveEnnemies() {
	if (load_bullet_ennemies_A_time == DELAY_BULLET_ENNEMIES_B) {
		frameth = 2;
	}
	else if (load_bullet_ennemies_A_time >= 150) {
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
void Ennemies_typeA::loadShoot() {
	load_bullet_ennemies_A_time = (load_bullet_ennemies_A_time + 1) % (DELAY_BULLET_ENNEMIES_A+1);
	if (bullet_ennemies_A_index == NUMBER_BULLET) {
		bullet_ennemies_A_index = 0;
	}
	if (load_bullet_ennemies_A_time == (DELAY_BULLET_ENNEMIES_A)) {
		bullet_ennemies_A[bullet_ennemies_A_index].center_start_x = bullet_ennemies_A[bullet_ennemies_A_index].center_x =center_x+ width / 2 + (height + 10) * sin(-angle * PI / 180) - bullet_ennemies_A[bullet_ennemies_A_index].width / 2;
		bullet_ennemies_A[bullet_ennemies_A_index].center_start_y = bullet_ennemies_A[bullet_ennemies_A_index].center_y =center_y+ (height + 10) * cos(-angle * PI / 180);
		bullet_ennemies_A[bullet_ennemies_A_index].angle = angle;
		bullet_ennemies_A[bullet_ennemies_A_index].exist = true;
		bullet_ennemies_A_index++;
	}
}

void Ennemies_typeA::free() {
	center_x = 0;
	center_y = 0;
	center_start_x = 0;
	center_start_y = 0;
	center_finish_x = 0;
	center_finish_y = 0;
	slope = 0;
	angle = 0;
	exist = false;
	health = HEALTH_ENNEMIES_A;
	load_bullet_ennemies_A_time = Rand(0, DELAY_BULLET_ENNEMIES_A);
	direction = 1;
	photo = 0;
	death.free();
}
