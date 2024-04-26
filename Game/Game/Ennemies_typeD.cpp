#include "Ennemies_typeD.h"
#include"Declaration.h"
// di chuyển 
bool Ennemies_typeD::checkExist() {
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
void Ennemies_typeD::moveEnnemies() {
	frameth = photo/10+1;
	photo = (photo + 1) % 41;
	render();
	if (center_x >= SCREEN_WIDTH - width) {
		direction = -1;
	}
	if (center_x <= 0) {
		direction = 1;
	}
	center_x += ENNEMIES_D_SPEED* direction;
	loadShoot();
}
//sạc đạn
void Ennemies_typeD::loadShoot() {
	load_bullet_ennemies_D_time = (load_bullet_ennemies_D_time + 1) % (DELAY_BULLET_ENNEMIES_D+1);
	if (bullet_ennemies_D_index == NUMBER_BULLET) {
		bullet_ennemies_D_index = 0;
	}
	if (load_bullet_ennemies_D_time == DELAY_BULLET_ENNEMIES_D) {
		bullet_ennemies_D[bullet_ennemies_D_index].center_x = bullet_ennemies_D[bullet_ennemies_D_index].center_start_x =center_x;
		bullet_ennemies_D[bullet_ennemies_D_index].center_y = bullet_ennemies_D[bullet_ennemies_D_index].center_start_y =center_y;
		bullet_ennemies_D[bullet_ennemies_D_index].center_delta_y = 1.00000 * (player.center_x - bullet_ennemies_D[bullet_ennemies_D_index].center_start_x );
		bullet_ennemies_D[bullet_ennemies_D_index].center_delta_x = 1.00000 * (player.center_y - bullet_ennemies_D[bullet_ennemies_D_index].center_start_y );
		bullet_ennemies_D[bullet_ennemies_D_index].slope = 1.00000 * bullet_ennemies_D[bullet_ennemies_D_index].center_delta_x / bullet_ennemies_D[bullet_ennemies_D_index].center_delta_y;
		bullet_ennemies_D[bullet_ennemies_D_index].exist = true;
		bullet_ennemies_D_index++;
	}
}
//bắn
void Ennemies_typeD::free() {
	center_x = 0;
	center_y = 0;
	center_start_x = 0;
	center_start_y = 0;
	center_finish_x = 0;
	center_finish_y = 0;
	slope = 0;
	angle = 0;
	exist = false;
	health = HEALTH_ENNEMIES_D;
	bullet_ennemies_D_index = 0;
	load_bullet_ennemies_D_time = Rand(0, DELAY_BULLET_ENNEMIES_D);
	direction = 1;
	photo = 0;
	death.free();
}