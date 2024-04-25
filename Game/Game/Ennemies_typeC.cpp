#include "Ennemies_typeC.h"
#include "Declaration.h"
// di chuyển 
bool Ennemies_typeC::checkExist() {
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
void Ennemies_typeC::moveEnnemies() {

	if (angle >= 360) { angle = 0; }
	angle += 0.1;
	render();
	if (inscreen == false &&center_y> center_finish_y) {
		inscreen = true;
	}
	if (inscreen == true) {
		if (center_x > 0 && center_x< (SCREEN_WIDTH - width)) {
			if (center_y > 0 && center_y< (SCREEN_HEIGHT - height)) {
				turning = true;
			}
		}
		if ((center_x <= 0 || center_x>= SCREEN_WIDTH - width) && turning == true) {
			center_delta_x = -center_delta_x;
			center_start_x = center_x;
			center_start_y = center_y;
			turning = false;
		}
		if ((center_y <= 0 || center_y>= SCREEN_HEIGHT - height) && turning == true) {
			center_delta_y = -center_delta_y;
			center_start_x = center_x;
			center_start_y = center_y;
			turning = false;
		}
	}
	slope = 1.0 * (center_delta_y) / (center_delta_x);
	if (center_delta_y == 0 && center_delta_x > 0) {
		center_x += SPEED_RIVAL;
	}
	else if (center_delta_y == 0 && center_delta_x < 0) {
		center_x -= SPEED_RIVAL;
	}
	else if (center_delta_y > 0 && center_delta_x == 0) {
		center_y += SPEED_RIVAL;
	}
	else if (center_delta_y < 0 && center_delta_x == 0) {
		center_y -= SPEED_RIVAL;
	}
	else {
		if (slope >= 1) {
			center_y += round((SPEED_RIVAL) / sqrt(1 + 1.00 / (slope * slope))) * center_delta_x / abs(center_delta_x);
			center_x = round((center_y + 1.000 * center_start_x * slope - center_start_y * 1.000) / slope);
		}
		else if ((slope <= 1) && (slope >= -1)) {
			center_x += round((SPEED_RIVAL) / sqrt(1 + 1.00 * slope * slope)) * center_delta_x / abs(center_delta_x);
			center_y = round((center_x)*slope + center_start_y * 1.000 - 1.000 * center_start_x * slope);
		}
		else if ((slope <= -1)) {
			center_y -= round((SPEED_RIVAL) / sqrt(1 + 1.00 / (slope * slope))) * center_delta_x / abs(center_delta_x);
			center_x = round((center_y + 1.000 * center_start_x * slope - center_start_y * 1.000) / slope);
		}
	}
	loadShoot();
}
//sạc đạn
void Ennemies_typeC::loadShoot() {
	load_bullet_ennemies_C_time = (load_bullet_ennemies_C_time + 1) % 1001;
	if (bullet_ennemies_C_index == NUMBER_BULLET) {
		bullet_ennemies_C_index = 0;
	}
	if (load_bullet_ennemies_C_time == 1000) {
		int a = Rand(0, 90);
		for (int i = 0; i < 4; i++) {
			bullet_ennemies_C[bullet_ennemies_C_index][i].center_start_x = bullet_ennemies_C[bullet_ennemies_C_index][i].center_x =center_x;
			bullet_ennemies_C[bullet_ennemies_C_index][i].center_start_y = bullet_ennemies_C[bullet_ennemies_C_index][i].center_y =center_y;
			bullet_ennemies_C[bullet_ennemies_C_index][i].angle = a;
			bullet_ennemies_C[bullet_ennemies_C_index][i].exist = true;
			a += 90;
		}
		bullet_ennemies_C_index++;
	}
}
//bắn

void Ennemies_typeC::free() {
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
	bullet_ennemies_C_index = 0;
	load_bullet_ennemies_C_time = Rand(0, 1000);
	speed = 1;
	photo = 0;
	turning = false;
	death.free();
}
