#include "Bullet_Round.h"
#include "Declaration.h"
void Bullet_Round::RenderBullet_Round() {
	if (bullet_virtual.exist == true) {
		R_increase_time = (R_increase_time + 1) % 3;
		if (R <= 400 && R_increase_time == 2) {
			R += 3;
		}
		double a = 0;
		for (int j = 0; j < 3; j++) {

			bullet_around[j][0].center_x = bullet_virtual.center_x + R * cos((angle_first + a + 90) * PI / 180) ;
			bullet_around[j][0].center_y = bullet_virtual.center_y + R * sin((angle_first + a + 90) * PI / 180) ;
			bullet_around[j][0].angle = angle_first + a;
			if (bullet_around[j][0].exist == true) {
				bullet_around[j][0].render();
			}
			a += 120;
		}
		for (int i = 0; i < 3; i++) {
			double center_delta_x = 1;
			double center_delta_y = 1;
			double slope = 0.0;
			int center_start_x = 0;
			int center_start_y = 0;
			if (i < 2) {
				center_delta_y = bullet_around[i + 1][0].center_y - bullet_around[i][0].center_y;
				center_delta_x = bullet_around[i + 1][0].center_x - bullet_around[i][0].center_x;
			}
			else if (i == 2) {
				center_delta_y = bullet_around[0][0].center_y - bullet_around[i][0].center_y;
				center_delta_x = bullet_around[0][0].center_x - bullet_around[i][0].center_x;
			}
			center_start_x = bullet_around[i][0].center_x;
			center_start_y = bullet_around[i][0].center_y;
			if (center_delta_y != 0);
			slope = 1.0 * center_delta_x / center_delta_y;
			double dis = 1.0 * R * sqrt(3) / 3;
			for (int k = 1; k < 3; k++) {
				bullet_around[i][k].center_x = bullet_around[i][0].center_x;
				bullet_around[i][k].center_y = bullet_around[i][0].center_y;
				if (center_delta_y == 0 && center_delta_x > 0) {
					bullet_around[i][k].center_x += dis;
				}
				else if (center_delta_y == 0 && center_delta_x < 0) {
					bullet_around[i][k].center_x -= dis;
				}
				else if (center_delta_y > 0 && center_delta_x == 0) {
					bullet_around[i][k].center_y += dis;
				}
				else if (center_delta_y < 0 && center_delta_x == 0) {
					bullet_around[i][k].center_y -= dis;
				}
				else {
					if (slope >= 1) {
						bullet_around[i][k].center_x += round((dis) / sqrt(1 + 1.00 / (slope * slope))) * 1.0 * center_delta_y / abs(center_delta_y);
						bullet_around[i][k].center_y = round((1.0 * bullet_around[i][k].center_x) / slope + center_start_y * 1.000 - 1.000 * center_start_x / slope);
					}
					else if ((slope <= 1) && (slope >= -1)) {
						bullet_around[i][k].center_y += round((dis) / sqrt(1 + 1.00 * slope * slope)) * 1.0 * center_delta_y / abs(center_delta_y);
						bullet_around[i][k].center_x = round((bullet_around[i][k].center_y + 1.000 * center_start_x / slope - center_start_y * 1.000) * slope);
					}
					else if ((slope <= -1)) {
						bullet_around[i][k].center_x -= round((dis) / sqrt(1 + 1.00 / (slope * slope))) * 1.0 * center_delta_y / abs(center_delta_y);
						bullet_around[i][k].center_y = round((1.0 * bullet_around[i][k].center_x) / slope + center_start_y * 1.000 - 1.000 * center_start_x / slope);
					}
				}
				if (bullet_around[i][k].exist == true) {
					bullet_around[i][k].render();
				}
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