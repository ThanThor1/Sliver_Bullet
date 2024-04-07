#include "Ennemies_typeA.h"
#include"Declaration.h"
// di chuyển 
bool Ennemies_typeA::checkExist() {
	checkHit(health);
	if (health <= 0) {
		exist = false;
	}
	else exist = true;
	if (exist == true) {
		moveEnnemies();
	}
	shoot();
	return exist;
}
void Ennemies_typeA::moveEnnemies() {
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
		}
}
//sạc đạn
void Ennemies_typeA::loadShoot() {
	load_bullet_simple_time = (load_bullet_simple_time + 1) % 1001;
	if (thbullet_simple == NUMBER_BULLET) {
		thbullet_simple = 0;
	}
	if (load_bullet_simple_time == 1000) {
		bullet_simple[thbullet_simple].B_start_x = bullet_simple[thbullet_simple].B_x = E_x + E_Width / 2 + (E_Height + 10) * sin(-E_angle * PI / 180) - bullet_simple[thbullet_simple].B_Width / 2;
		bullet_simple[thbullet_simple].B_start_y = bullet_simple[thbullet_simple].B_y = E_y + (E_Height + 10) * cos(-E_angle * PI / 180);
		bullet_simple[thbullet_simple].B_angle = E_angle;
		bullet_simple[thbullet_simple].B_slope = tan((bullet_simple[thbullet_simple].B_angle) * PI / 180);
		bullet_simple[thbullet_simple].B_exist = true;
		thbullet_simple++;
	}
}
//bắn
void Ennemies_typeA::shoot() {
	SDL_Point PointBullet1;
	for (int i = 0; i < NUMBER_BULLET; i++) {
		if (bullet_simple[i].B_exist == true)
		{
			PointBullet1 = { bullet_simple[i].B_Width / 2, 0 };
			bullet_simple[i].render(bullet_simple[i].B_x, bullet_simple[i].B_y, NULL, bullet_simple[i].B_angle, &PointBullet1);
			bullet_simple[i].B_y += round((1) / sqrt(1 + 1.00 * (bullet_simple[i].B_slope * bullet_simple[i].B_slope)));
			bullet_simple[i].B_x = round(bullet_simple[i].B_start_x + (1.000 * bullet_simple[i].B_start_y * bullet_simple[i].B_slope - bullet_simple[i].B_y * 1.000 * bullet_simple[i].B_slope));
		}
	}
}
void Ennemies_typeA::free() {
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
	thbullet_simple = 0;
	load_bullet_simple_time = Rand(0,1000);
	speed = 1;
	direction = 1;
}