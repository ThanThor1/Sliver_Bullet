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
	SDL_Rect cut;
	cut= {photo/10 * E_Width, 0, E_Width , E_Height};
	photo = (photo + 1) % 41;
	SDL_RenderCopy(gRenderer, E_Texture,&cut, &renderQuad);
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
		bullet_follow[thbullet_follow].B_slope = 1.00000 * bullet_follow[thbullet_follow].B_denta_x / bullet_follow[thbullet_follow].B_denta_y;
		bullet_follow[thbullet_follow].B_exist = true;
		thbullet_follow++;
	}
}
//bắn
void Ennemies_typeD::shoot() {
	for (int i = 0; i < 10; i++)
	{
		if (bullet_follow[i].B_exist == true) {
			if (bullet_follow[i].phandan == false) {
				if ((checkDistance(bullet_follow[i])) <= 40000) {
					bullet_follow[i].B_speedPlus = 3;
					bullet_follow[i].B_follow = false;
				}
				if (bullet_follow[i].B_follow) {
					bullet_follow[i].B_start_x = bullet_follow[i].B_x;
					bullet_follow[i].B_start_y = bullet_follow[i].B_y;
					bullet_follow[i].B_denta_x = 1.0 * (player.P_x + player.P_Width / 2 - (bullet_follow[i].B_x + bullet_follow[i].B_Width / 2));
					bullet_follow[i].B_denta_y = 1.0 * (player.P_y + player.P_Height / 2 - (bullet_follow[i].B_y + bullet_follow[i].B_Height / 2));
					bullet_follow[i].B_slope = 1.0 * bullet_follow[i].B_denta_x / bullet_follow[i].B_denta_y;
				}
				bullet_follow[i].RenderBulletSlope();
			}
			else {
				bullet_follow[i].RenderBulletAngle();
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
	photo = 0;
}
bool Ennemies_typeD::loadFromFile(string path) {
	//Get rid of preexisting texture
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 180, 180, 180));
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			E_Width = loadedSurface->w/4;
			E_Height = loadedSurface->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	E_Texture = newTexture;
	return E_Texture != NULL;
}