
#pragma once
#include "Bullet_Straight.h"
#include "Declaration.h"
void Bullet_Straight::free()
{
	hit.free();
	center_delta_x = 0;
	center_delta_y = 0;
	center_start_x = 0;
	center_start_y = 0;
	center_x = 0;
	center_y = 0;
	exist = false;
	good = false;
	hit_bool = false;
	damage = 10;
	speed = 3;
	speedPlus = 1;
	follow = true;
}
Bullet_Straight::Bullet_Straight()
{
	exist = false;
	Texture = NULL;
	width = 0;
	height = 0;
}
Bullet_Straight::~Bullet_Straight()
{
	free();
}
void Bullet_Straight::RenderBullet_StraightSlope() {
	checkOutScreen();
		if (center_delta_x > 0 && center_delta_y > 0) {
			angle = 360 - atan(slope) / PI * 180;
		}
		else if (center_delta_x < 0 && center_delta_y > 0) {
			angle = -atan(slope) / PI * 180;
		}
		else if (center_delta_x < 0 && center_delta_y < 0) {
			angle = 180 - atan(slope) / PI * 180;
		}
		else if (center_delta_x > 0 && center_delta_y < 0) {
			angle = 180 - atan(slope) / PI * 180;
		}
		if (center_delta_x == 0 && center_delta_y > 0) {
			angle = 0;
		}
		if (center_delta_x == 0 && center_delta_y < 0) {
			angle = 180;
		}
		if (center_delta_y == 0 && center_delta_x < 0) {
			angle = 90;
		}
		if (center_delta_y == 0 && center_delta_x > 0) {
			angle = 270;
		}
		RenderBullet_Straight();
}
void Bullet_Straight::RenderBullet_StraightAngle() {
	checkOutScreen();
		// set lai goc neu bi lech
		if (angle >= 360) {
			angle = angle - 360;
		}
		else if (angle < 0) {
			angle = 360 + angle;
		}
		// set center_delta_x,center_delta_y
		if (angle > 0 && angle < 90) {
			center_delta_x = -1;
			center_delta_y = 1;
		}
		else if (angle > 90 && angle < 180) {
			center_delta_x = -1;
			center_delta_y = -1;
		}
		else if (angle > 180 && angle < 270) {
			center_delta_x = 1;
			center_delta_y = -1;
		}
		else if (angle > 270 && angle < 360) {
			center_delta_x = 1;
			center_delta_y = 1;
		}
		if (angle == 0) {
			center_delta_x = 0;
			center_delta_y = 1;
		}
		else if (angle == 90) {
			center_delta_y = 0;
			center_delta_x = -1;
		}
		else if (angle == 180) {
			center_delta_x = 0;
			center_delta_y = -1;
		}
		else if (angle == 270) {
			center_delta_y = 0;
			center_delta_x = 1;
		}
		//
		if (angle >= 0 && angle <= 90) {
			slope = tan(-angle * 1.0 * PI / 180);
		}
		else if (angle >= 90 && angle <= 270) {
			slope = tan((180 - angle) * 1.0 * PI / 180);
		}
		else {
			slope = tan((360 - angle) * 1.0 * PI / 180);
		}
		RenderBullet_Straight();
}
void Bullet_Straight::RenderBullet_Straight() {
	if (exist == true) {
			if (center_delta_y == 0 && center_delta_x > 0) {
				center_x += speed + speedPlus;
			}
			else if (center_delta_y == 0 && center_delta_x < 0) {
				center_x -= speed + speedPlus;
			}
			else if (center_delta_y > 0 && center_delta_x == 0) {
				center_y += speed + speedPlus;
			}
			else if (center_delta_y < 0 && center_delta_x == 0) {
				center_y -= speed + speedPlus;
			}
			else {
				if (slope >= 1) {
					center_x += round((speed + speedPlus) / sqrt(1 + 1.00 / (slope * slope))) * 1.0 * center_delta_y / abs(center_delta_y);
					center_y = round((center_x) / slope + center_start_y * 1.000 - 1.000 * center_start_x / slope);
				}
				else if ((slope <= 1) && (slope >= -1)) {
					center_y += round((speed + speedPlus) / sqrt(1 + 1.00 * slope * slope)) * 1.0 * center_delta_y / abs(center_delta_y);
					center_x = round((center_y + 1.000 * center_start_x / slope - center_start_y * 1.000) * slope);
				}
				else if ((slope <= -1)) {
					center_x -= round((speed + speedPlus) / sqrt(1 + 1.00 / (slope * slope))) * 1.0 * center_delta_y / abs(center_delta_y);
					center_y = round((center_x) / slope + center_start_y * 1.000 - 1.000 * center_start_x / slope);
				}
			}
			put = { center_x - center.x, center_y - center.y,width,height };
			SDL_RenderCopyEx(gRenderer, Texture, &cut[frameth], &put, angle, &center, flip);
	}
}
void Bullet_Straight::RenderBullet_FollowSlope() {
	checkOutScreen();
	if (good == false) {
		if (SolveDistance() <= 40000) {
			speedPlus = 3;
			follow = false;
		}
		if (follow) {
			center_start_x = center_x;
			center_start_y = center_y;
			center_delta_x = 1.0 * (player.center_x - center_x);
			center_delta_y = 1.0 * (player.center_y - center_y);
			slope = 1.0 * center_delta_x / center_delta_y;
		}
		RenderBullet_StraightSlope();
	}
	else {
		RenderBullet_StraightAngle();
	}
}
int Bullet_Straight::SolveDistance() {
	int dis = (center_x -player.center_x)
		* (center_x - player.center_x) +
		(center_y  - player.center_y )
		* (center_y - player.center_y)
		;
	return dis;
}
void Bullet_Straight::checkOutScreen() {
	if (center_x > (SCREEN_WIDTH + 200) || center_x< -200 || center_y>(SCREEN_HEIGHT + 200) || center_y< -200) {
		free();
	}
}