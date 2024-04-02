#include "Ennemies_typeC.h"
#include "Declaration.h"
// di chuyển 
bool Ennemies_typeC::checkExist() {
	if (health == -100) {
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
	return exist;
}
void Ennemies_typeC::moveEnnemies() {
	SDL_Rect  renderQuad = { E_x, E_y , E_Width, E_Height };
	if (E_angle >= 360) { E_angle = 0; }
	E_angle += 0.1;
	SDL_RenderCopyEx(gRenderer, E_Texture, NULL, &renderQuad, E_angle, NULL, SDL_FLIP_NONE);
	loadShoot();
	if (E_x > 0 && E_x < (SCREEN_WIDTH - E_Width)) {
		if (E_y > 0 && E_y < (SCREEN_HEIGHT - E_Height)) {
			turning = true;
		}
	}
	if ((E_x <= 0 || E_x >= SCREEN_WIDTH - E_Width) && turning == true) {
		E_denta_x = -E_denta_x;
		E_start_x = E_x;
		E_start_y = E_y;
		turning = false;
	}
	if ((E_y <= 0 || E_y >= SCREEN_HEIGHT - E_Height) && turning == true) {
		E_denta_y = -E_denta_y;
		E_start_x = E_x;
		E_start_y = E_y;
		turning = false;
	}
	/*cout << denta_x << " " << denta_y << " ";*/
	E_slope = 1.0 * (E_denta_y) / (E_denta_x);
	/*cout << E_x << " " << E_y<<" "<<E_slope << endl;*/
	if (E_denta_y == 0 && E_denta_x > 0) {
		E_x += SPEED_RIVAL;
	}
	else if (E_denta_y == 0 && E_denta_x < 0) {
		E_x -= SPEED_RIVAL;
	}
	else if (E_denta_y > 0 && E_denta_x == 0) {
		E_y += SPEED_RIVAL;
	}
	else if (E_denta_y < 0 && E_denta_x == 0) {
		E_y -= SPEED_RIVAL;
	}
	else {
		if (E_slope >= 1) {
			E_y += round((SPEED_RIVAL) / sqrt(1 + 1.00 / (E_slope * E_slope))) * E_denta_x / abs(E_denta_x);
			E_x = round((E_y + 1.000 * E_start_x * E_slope - E_start_y * 1.000) / E_slope);
		}
		else if ((E_slope <= 1) && (E_slope >= -1)) {
			E_x += round((SPEED_RIVAL) / sqrt(1 + 1.00 * E_slope * E_slope)) * E_denta_x / abs(E_denta_x);
			E_y = round((E_x)*E_slope + E_start_y * 1.000 - 1.000 * E_start_x * E_slope);
		}
		else if ((E_slope <= -1)) {
			E_y -= round((SPEED_RIVAL) / sqrt(1 + 1.00 / (E_slope * E_slope))) * E_denta_x / abs(E_denta_x);
			E_x = round((E_y + 1.000 * E_start_x * E_slope - E_start_y * 1.000) / E_slope);
		}
	}
	loadShoot();
	shoot();
}
//sạc đạn
void Ennemies_typeC::loadShoot() {
	load_bullet_x4_time = (load_bullet_x4_time + 1) % 1001;
	if (thbullet_x4 == NUMBER_BULLET) {
		thbullet_x4 = 0;
	}
	if (load_bullet_x4_time == 1000) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 90);
		int a = dis(gen);
		for (int i = 0; i < 4; i++) {
			bullet_x4[thbullet_x4][i].B_start_x = bullet_x4[thbullet_x4][i].B_x = E_x - 10;
			bullet_x4[thbullet_x4][i].B_start_y = bullet_x4[thbullet_x4][i].B_y = E_y - 90;
			bullet_x4[thbullet_x4][i].B_angle = a;
			if (a >= 0 && a <= 90) {
				bullet_x4[thbullet_x4][i].B_slope = 1.0 / tan(-a * 1.0 * PI / 180);
			}
			else if (a >= 90 && a <= 270) {
				bullet_x4[thbullet_x4][i].B_slope = 1.0 / tan((180 - a) * 1.0 * PI / 180);
			}
			else {
				bullet_x4[thbullet_x4][i].B_slope = 1.0 / tan((360 - a) * 1.0 * PI / 180);
			}
			//
			if (a == 0) {
				bullet_x4[thbullet_x4][i].B_denta_x = 0;
				bullet_x4[thbullet_x4][i].B_denta_y = 1;
			}
			else if (a == 90) {
				bullet_x4[thbullet_x4][i].B_denta_y = 0;
				bullet_x4[thbullet_x4][i].B_denta_x = -1;
			}
			else if (a == 180) {
				bullet_x4[thbullet_x4][i].B_denta_x = 0;
				bullet_x4[thbullet_x4][i].B_denta_y = -1;
			}
			else if (a == 270) {
				bullet_x4[thbullet_x4][i].B_denta_y = 0;
				bullet_x4[thbullet_x4][i].B_denta_x = 1;
			}
			//
			if (a > 0 && a < 180) {
				bullet_x4[thbullet_x4][i].B_denta_x = -1;
				bullet_x4[thbullet_x4][i].B_denta_y = 1;
			}
			else if (a > 180 && a < 360) {
				bullet_x4[thbullet_x4][i].B_denta_x = 1;
				bullet_x4[thbullet_x4][i].B_denta_y = 1;
			}
			a += 90;
			if (a >= 360) {
				a = a - 360;
			}
			bullet_x4[thbullet_x4][i].B_exist = true;
		}
		thbullet_x4++;
	}
}
//bắn
void Ennemies_typeC::shoot() {
	for (int i = 0; i < NUMBER_BULLET; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (bullet_x4[i][j].B_exist == true)
			{
				bullet_x4[i][j].render(bullet_x4[i][j].B_x, bullet_x4[i][j].B_y, NULL, bullet_x4[i][j].B_angle);
				if (bullet_x4[i][j].B_denta_y == 0 && bullet_x4[i][j].B_denta_x > 0) {
					bullet_x4[i][j].B_x += BULLET_SPEED_RIVAL;
				}
				else if (bullet_x4[i][j].B_denta_y == 0 && bullet_x4[i][j].B_denta_x < 0) {
					bullet_x4[i][j].B_x -= BULLET_SPEED_RIVAL;
				}
				else if (bullet_x4[i][j].B_denta_y > 0 && bullet_x4[i][j].B_denta_x == 0) {
					bullet_x4[i][j].B_y += BULLET_SPEED_RIVAL;
				}
				else if (bullet_x4[i][j].B_denta_y < 0 && bullet_x4[i][j].B_denta_x == 0) {
					bullet_x4[i][j].B_y -= BULLET_SPEED_RIVAL;
				}
				else {
					if (bullet_x4[i][j].B_slope >= 1) {
						bullet_x4[i][j].B_y += round((BULLET_SPEED_RIVAL) /
							sqrt(1 + 1.00 / (bullet_x4[i][j].B_slope * bullet_x4[i][j].B_slope))) * bullet_x4[i][j].B_denta_x;
						bullet_x4[i][j].B_x = round((bullet_x4[i][j].B_y + 1.000 * bullet_x4[i][j].B_start_x * bullet_x4[i][j].B_slope - bullet_x4[i][j].B_start_y * 1.000) / bullet_x4[i][j].B_slope);
					}
					else if ((bullet_x4[i][j].B_slope <= 1) && (bullet_x4[i][j].B_slope >= -1)) {
						bullet_x4[i][j].B_x += round((BULLET_SPEED_RIVAL) /
							sqrt(1 + 1.00 * bullet_x4[i][j].B_slope * bullet_x4[i][j].B_slope)) * bullet_x4[i][j].B_denta_x;
						bullet_x4[i][j].B_y = round((bullet_x4[i][j].B_x) * bullet_x4[i][j].B_slope + bullet_x4[i][j].B_start_y * 1.000 - 1.000 * bullet_x4[i][j].B_start_x * bullet_x4[i][j].B_slope);
					}
					else if ((bullet_x4[i][j].B_slope <= -1)) {
						bullet_x4[i][j].B_y -= round((BULLET_SPEED_RIVAL) /
							sqrt(1 + 1.00 / (bullet_x4[i][j].B_slope * bullet_x4[i][j].B_slope))) * bullet_x4[i][j].B_denta_x;
						bullet_x4[i][j].B_x = round((bullet_x4[i][j].B_y + 1.000 * bullet_x4[i][j].B_start_x * bullet_x4[i][j].B_slope - bullet_x4[i][j].B_start_y * 1.000) / bullet_x4[i][j].B_slope);
					}
				}
			}
		}
	}
}
void Ennemies_typeC::free() {
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