#include "Bullet_Round.h"
#include "Declaration.h"
void Bullet_Round::RenderBullet_Round() {
	if (bullet_virtual.exist == true) {
		R_increase_time = (R_increase_time + 1) % 3;
		if (R <= 400 && R_increase_time == 2) {
			R += 3;
		}
		double a = 0;
		SDL_Point b = { bullet_around[0][0].width / 2, bullet_around[0][0].height / 2 };
		for (int j = 0; j < 3; j++) {
			bullet_around[j][0].x = bullet_virtual.x + R * cos((angle_first + a + 90) * PI / 180) - bullet_around[j][0].width / 2;
			bullet_around[j][0].y = bullet_virtual.y + R * sin((angle_first + a + 90) * PI / 180) - bullet_around[j][0].height / 2;
			bullet_around[j][0].angle = angle_first + a;
			bullet_around[j][0].render(bullet_around[j][0].x, bullet_around[j][0].y, NULL, bullet_around[j][0].angle, &b);
			a += 120;
		}
		for (int i = 0; i < 3; i++) {
			double delta_x = 1;
			double delta_y = 1;
			double slope = 0.0;
			int start_x = 0;
			int start_y = 0;
			if (i < 2) {
				delta_y = bullet_around[i + 1][0].y - bullet_around[i][0].y;
				delta_x = bullet_around[i + 1][0].x - bullet_around[i][0].x;
			}
			else if (i == 2) {
				delta_y = bullet_around[0][0].y - bullet_around[i][0].y;
				delta_x = bullet_around[0][0].x - bullet_around[i][0].x;
			}
			start_x = bullet_around[i][0].x;
			start_y = bullet_around[i][0].y;
			if (delta_y != 0);
			slope = 1.0 * delta_x / delta_y;
			double dis = 1.0 * R * sqrt(3) / 3;
			for (int k = 1; k < 3; k++) {

				bullet_around[i][k].x = bullet_around[i][0].x;
				bullet_around[i][k].y = bullet_around[i][0].y;

				if (delta_y == 0 && delta_x > 0) {
					bullet_around[i][k].x += dis;
				}
				else if (delta_y == 0 && delta_x < 0) {
					bullet_around[i][k].x -= dis;
				}
				else if (delta_y > 0 && delta_x == 0) {
					bullet_around[i][k].y += dis;
				}
				else if (delta_y < 0 && delta_x == 0) {
					bullet_around[i][k].y -= dis;
				}
				else {
					if (slope >= 1) {
						bullet_around[i][k].x += round((dis) / sqrt(1 + 1.00 / (slope * slope))) * 1.0 * delta_y / abs(delta_y);
						bullet_around[i][k].y = round((1.0 * bullet_around[i][k].x) / slope + start_y * 1.000 - 1.000 * start_x / slope);
					}
					else if ((slope <= 1) && (slope >= -1)) {
						bullet_around[i][k].y += round((dis) / sqrt(1 + 1.00 * slope * slope)) * 1.0 * delta_y / abs(delta_y);
						bullet_around[i][k].x = round((bullet_around[i][k].y + 1.000 * start_x / slope - start_y * 1.000) * slope);
					}
					else if ((slope <= -1)) {
						bullet_around[i][k].x -= round((dis) / sqrt(1 + 1.00 / (slope * slope))) * 1.0 * delta_y / abs(delta_y);
						bullet_around[i][k].y = round((1.0 * bullet_around[i][k].x) / slope + start_y * 1.000 - 1.000 * start_x / slope);
					}
				}
				bullet_around[i][k].render(bullet_around[i][k].x, bullet_around[i][k].y);
				dis += 1.0 * R * sqrt(3) / 3;
			}
		}
		angle_first = 0.5 + angle_first;
	}
}
void Bullet_Round::set() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			bullet_around[i][j].exist = true;
		}
	}
}