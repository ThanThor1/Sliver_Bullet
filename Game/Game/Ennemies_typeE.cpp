
#include "FindAngle.h"
#include "Declaration.h"
#include "Ennemies_typeE.h"
// di chuyển 
bool Ennemies_typeE::checkExist() {
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
void Ennemies_typeE::moveEnnemies() {
	SDL_Rect cut2; cut2 = { photo * width, 0, width , height };
	if (load_bullet_ennemies_E_time == 100) {
		photo = 1;
	}
	else if (load_bullet_ennemies_E_time >= 15) {
		photo = 1;
		angle = FindAngle(center_x ,center_y, player.center_x , player.center_y );
	}
	SDL_Rect  renderQuad1 = { center_x - width/2,center_y - height/2, width, height };
	SDL_Point center = { width / 2 , height / 2 };
	SDL_Rect cut1 = { 2 * width,0, width , height };
	SDL_RenderCopyEx(gRenderer, Texture, &cut1, &renderQuad1, 0, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(gRenderer, Texture, &cut2, &renderQuad1, angle, &center, SDL_FLIP_NONE);
	if (center_y != center_finish_y) {
		center_y++;
	}
	else {
		loadShoot();
	}
}
//sạc đạn
void Ennemies_typeE::loadShoot() {
	load_bullet_ennemies_E_time = (load_bullet_ennemies_E_time + 1) % 101;
	if (bullet_ennemies_E_index == NUMBER_BULLET) {
		bullet_ennemies_E_index = 0;
	}
	if (load_bullet_ennemies_E_time == 100) {
		bullet_ennemies_E[bullet_ennemies_E_index].center_start_x = bullet_ennemies_E[bullet_ennemies_E_index].center_x =center_x+ width / 2 + (height + 10) * sin(-angle * PI / 180) - bullet_ennemies_E[bullet_ennemies_E_index].width / 2;
		bullet_ennemies_E[bullet_ennemies_E_index].center_start_y = bullet_ennemies_E[bullet_ennemies_E_index].center_y =center_y+ (height + 10) * cos(-angle * PI / 180);
		bullet_ennemies_E[bullet_ennemies_E_index].angle = angle;
		bullet_ennemies_E[bullet_ennemies_E_index].exist = true;
		bullet_ennemies_E_index++;
	}
}

void Ennemies_typeE::free() {
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
	bullet_ennemies_E_index = 0;
	load_bullet_ennemies_E_time = Rand(0, 1000);
	speed = 1;
	direction = 1;
	photo = 0;
	death.free();
}