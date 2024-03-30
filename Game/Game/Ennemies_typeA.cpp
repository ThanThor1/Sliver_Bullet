#include "Ennemies_typeA.h"
#include"Declaration.h"
// di chuyển 
void Ennemies_typeA::checkExist() {
	if (health == -1) {
		health = 10;
		E_denta_x = E_finish_x - E_start_x;
		E_denta_y = E_finish_y - E_start_y;
	}
	checkHit();
	if (health <= 0) {
		exist = false;
	}
	else exist = true;
	if (exist == true) {
		moveEnnemies();
	}
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
			shoot();
		}
}
//sạc đạn
void Ennemies_typeA::loadShoot() {
	load_bullet_simple_time = (load_bullet_simple_time + 1) % 1001;
	if (thbullet_simple == NUMBER_BULLET) {
		thbullet_simple = 0;
	}
	if (load_bullet_simple_time == 1000) {
		bullet_simple[thbullet_simple].start_x = bullet_simple[thbullet_simple].B_x = E_x + E_Width / 2 + (E_Height + 10) * sin(-E_angle * PI / 180) - bullet_simple[thbullet_simple].B_Width / 2;
		bullet_simple[thbullet_simple].start_y = bullet_simple[thbullet_simple].B_y = E_y + (E_Height + 10) * cos(-E_angle * PI / 180);
		bullet_simple[thbullet_simple].angle = E_angle;
		bullet_simple[thbullet_simple].slope = tan((bullet_simple[thbullet_simple].angle) * PI / 180);
		bullet_simple[thbullet_simple].exist = true;
		thbullet_simple++;
	}
}
//bắn
void Ennemies_typeA::shoot() {
	SDL_Point PointBullet1;
	for (int i = 0; i < NUMBER_BULLET; i++) {
		if (bullet_simple[i].exist == true)
		{
			PointBullet1 = { bullet_simple[i].B_Width / 2, 0 };
			bullet_simple[i].render(bullet_simple[i].B_x, bullet_simple[i].B_y, NULL, bullet_simple[i].angle, &PointBullet1);
		}
	}
	if (load_bullet_simple_time % 2 == 0) {
		for (int i = 0; i < NUMBER_BULLET; i++) {
			if (bullet_simple[i].exist == true)
			{
				bullet_simple[i].B_y += round((1) / sqrt(1 + 1.00 * (bullet_simple[i].slope * bullet_simple[i].slope)));
				bullet_simple[i].B_x = round(bullet_simple[i].start_x + (1.000 * bullet_simple[i].start_y * bullet_simple[i].slope - bullet_simple[i].B_y * 1.000 * bullet_simple[i].slope));
			}
		}
	}
}
void Ennemies_typeA::free() {
	E_x = 0;
	E_y = 0;
	E_Width = 0;
	E_Height = 0;
	E_start_x = 0;
	E_start_y = 0;
	E_finish_x = 0;
	E_finish_y = 0;
	E_slope = 0;
	E_angle = 0;
	exist = false;
	health = -1;
}