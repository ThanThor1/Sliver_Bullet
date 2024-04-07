#include "Ennemies_typeD.h"
#include"Declaration.h"
// di chuyển 
bool Ennemies_typeD::checkExist() {
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
void Ennemies_typeD::moveEnnemies() {
	SDL_Rect  renderQuad = { E_x, E_y , E_Width, E_Height };
	SDL_RenderCopy(gRenderer, E_Texture, NULL, &renderQuad);
	if (E_x >= SCREEN_WIDTH - E_Width)
	    direction = -1;
	if (E_x <=0 ) {
		direction = 1;
	}
	E_x += direction;
	loadShoot();
}
//sạc đạn
void Ennemies_typeD::loadShoot() {
	load_bullet_follow_time = (load_bullet_follow_time + 1) % 1001;
	if (thbullet_follow == NUMBER_BULLET) {
		thbullet_follow = 0;
	}
	if (load_bullet_follow_time == 1000) {
		bullet_follow[thbullet_follow].B_x = bullet_follow[thbullet_follow].B_start_x = E_x + E_Width / 2;
		bullet_follow[thbullet_follow].B_y = bullet_follow[thbullet_follow].B_start_y = E_y + E_Height;
		bullet_follow[thbullet_follow].B_denta_y = 1.00000 * (player.P_x + player.P_Width / 2 - (bullet_follow[thbullet_follow].B_start_x + bullet_follow[thbullet_follow].B_Width / 2));
		bullet_follow[thbullet_follow].B_denta_x = 1.00000 * (player.P_y + player.P_Height / 2 - (bullet_follow[thbullet_follow].B_start_y + bullet_follow[thbullet_follow].B_Height / 2));
		bullet_follow[thbullet_follow].B_slope = 1.00000 * bullet_follow[thbullet_follow].B_denta_y / bullet_follow[thbullet_follow].B_denta_x;
		if (bullet_follow[thbullet_follow].B_denta_y >= 0)
			bullet_follow[thbullet_follow].B_angle = -1.000000 * atan(1.00000 / bullet_follow[thbullet_follow].B_slope) * 180 / PI;
		else bullet_follow[thbullet_follow].B_angle = -(180.0000 + (1.0000 * atan(1.0000 / bullet_follow[thbullet_follow].B_slope) * 180 / PI));
		bullet_follow[thbullet_follow].B_exist = true;
		thbullet_follow++;
	}
}
//bắn
void Ennemies_typeD::shoot() {
	SDL_Point pointBullet = { E_Width / 2, E_Height / 2 };
	for (int i = 0; i < 10; i++)
	{
		if (bullet_follow[i].B_exist == true) {
			if ((checkDistance(bullet_follow[i])) <= 40000) {
				bullet_follow[i].B_speedPlus = 3;
				bullet_follow[i].B_follow = false;
			}
			if (bullet_follow[i].B_follow) {
				bullet_follow[i].B_start_x = bullet_follow[i].B_x ;
				bullet_follow[i].B_start_y = bullet_follow[i].B_y ;
				bullet_follow[i].B_denta_x = 1.0 * (player.P_x + player.P_Width / 2 - (bullet_follow[i].B_x + bullet_follow[i].B_Width / 2));
				bullet_follow[i].B_denta_y = 1.0 * (player.P_y + player.P_Height / 2 - (bullet_follow[i].B_y + bullet_follow[i].B_Height / 2));
				bullet_follow[i].B_slope = 1.0 * bullet_follow[i].B_denta_y / bullet_follow[i].B_denta_x;
				if (bullet_follow[i].B_denta_y >= 0)
					bullet_follow[i].B_angle = -1.0 * atan(1.0 / bullet_follow[i].B_slope) * 180 / PI;
				else bullet_follow[i].B_angle = -(180.0 + (1.0 * atan(1.0 / bullet_follow[i].B_slope) * 180 / PI));
			}
			bullet_follow[i].render(bullet_follow[i].B_x, bullet_follow[i].B_y, NULL, bullet_follow[i].B_angle, &pointBullet);
			if (bullet_follow[i].B_denta_y == 0 && bullet_follow[i].B_denta_x > 0) {
				bullet_follow[i].B_x += BULLET_SPEED_RIVAL + bullet_follow[i].B_speedPlus;
			}
			else if (bullet_follow[i].B_denta_y == 0 && bullet_follow[i].B_denta_x < 0) {
				bullet_follow[i].B_x -= BULLET_SPEED_RIVAL + bullet_follow[i].B_speedPlus;
			}
			else if (bullet_follow[i].B_denta_y > 0 && bullet_follow[i].B_denta_x == 0) {
				bullet_follow[i].B_y += BULLET_SPEED_RIVAL + bullet_follow[i].B_speedPlus;
			}
			else if (bullet_follow[i].B_denta_y < 0 && bullet_follow[i].B_denta_x == 0) {
				bullet_follow[i].B_y -= BULLET_SPEED_RIVAL + bullet_follow[i].B_speedPlus;
			}
			else {
				if (bullet_follow[i].B_slope >= 1) {
					bullet_follow[i].B_y += round((BULLET_SPEED_RIVAL + bullet_follow[i].B_speedPlus) /
						sqrt(1 + 1.00 / (bullet_follow[i].B_slope * bullet_follow[i].B_slope))) * bullet_follow[i].B_denta_x / abs(bullet_follow[i].B_denta_x);
					bullet_follow[i].B_x = round((bullet_follow[i].B_y + 1.000 * bullet_follow[i].B_start_x * bullet_follow[i].B_slope - bullet_follow[i].B_start_y * 1.000) / bullet_follow[i].B_slope);
				}
				else if ((bullet_follow[i].B_slope <= 1) && (bullet_follow[i].B_slope >= -1)) {
					bullet_follow[i].B_x += round((BULLET_SPEED_RIVAL + bullet_follow[i].B_speedPlus) /
						sqrt(1 + 1.00 * bullet_follow[i].B_slope * bullet_follow[i].B_slope)) * bullet_follow[i].B_denta_x / abs(bullet_follow[i].B_denta_x);
					bullet_follow[i].B_y = round((bullet_follow[i].B_x) * bullet_follow[i].B_slope + bullet_follow[i].B_start_y * 1.000 - 1.000 * bullet_follow[i].B_start_x * bullet_follow[i].B_slope);
				}
				else if ((bullet_follow[i].B_slope <= -1)) {
					bullet_follow[i].B_y -= round((BULLET_SPEED_RIVAL + bullet_follow[i].B_speedPlus) /
						sqrt(1 + 1.00 / (bullet_follow[i].B_slope * bullet_follow[i].B_slope))) * bullet_follow[i].B_denta_x / abs(bullet_follow[i].B_denta_x);
					bullet_follow[i].B_x = round((bullet_follow[i].B_y + 1.000 * bullet_follow[i].B_start_x * bullet_follow[i].B_slope - bullet_follow[i].B_start_y * 1.000) / bullet_follow[i].B_slope);
				}
			}
		}
	}
}
int Ennemies_typeD::checkDistance(Bullet& a){
	int dis = ((a.B_x + a.B_Width / 2) - (player.P_x + player.P_Width / 2))
		* ((a.B_x + a.B_Width / 2) - (player.P_x + player.P_Width / 2)) + 
		((a.B_y + a.B_Height / 2) - (player.P_y + player.P_Height / 2))
		* ((a.B_y + a.B_Height / 2) - (player.P_y + player.P_Height / 2))
		;
	return dis;
}


void Ennemies_typeD::free() {
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
	thbullet_follow = 0;
	load_bullet_follow_time = Rand(0, 1000);
	speed = 1;
	direction = 1;
}