#include "Ennemies_typeB.h"
#include"Declaration.h"
// di chuyển 
bool Ennemies_typeB::checkExist() {
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
void Ennemies_typeB::moveEnnemies() {
	SDL_Rect cut;
	cut = { photo * E_Width, 0, E_Width , E_Height };
	if (load_bullet_x3_time == 1000) {
		photo = 1;
	}
	else if (load_bullet_x3_time >= 150) {
		photo = 0;
		if (E_angle >= 15) { direction = -1; }
		if (E_angle <= -15) { direction = 1; }
		E_angle += 0.1 * direction;
	}
		SDL_Rect  renderQuad = { E_x, E_y , E_Width, E_Height };
		SDL_Point center = { E_Width / 2 ,0 };
		SDL_RenderCopyEx(gRenderer, E_Texture, &cut, &renderQuad, E_angle, &center, SDL_FLIP_NONE);
		if (E_y != E_finish_y) {
			E_y++;
		}
		else {
			loadShoot();
		}
}
//sạc đạn
void Ennemies_typeB::loadShoot() {
	load_bullet_x3_time = (load_bullet_x3_time + 1) % 1001;
	if (thbullet_x3 == NUMBER_BULLET) {
		thbullet_x3 = 0;
	}
	if (load_bullet_x3_time == 1000) {
		int a = -20;
		for (int i = 0; i < 3; i++) {
			bullet_x3[thbullet_x3][i].B_start_x = bullet_x3[thbullet_x3][i].B_x = E_x + E_Width / 2 + (E_Height + 10) * sin(-E_angle * PI / 180) - bullet_x3[thbullet_x3][i].B_Width / 2;
			bullet_x3[thbullet_x3][i].B_start_y = bullet_x3[thbullet_x3][i].B_y = E_y + (E_Height + 10) * cos(-E_angle * PI / 180);
			bullet_x3[thbullet_x3][i].B_angle = E_angle + a;
			bullet_x3[thbullet_x3][i].B_exist = true;
			a += 20;
		}
		thbullet_x3++;
	}
}
//bắn
void Ennemies_typeB::shoot() {
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j <= 2; j++) {
			if (bullet_x3[i][j].B_exist == true)
			{
				/*bullet_x3[i][j].render(bullet_x3[i][j].B_x, bullet_x3[i][j].B_y, NULL, bullet_x3[i][j].B_angle);*/
				bullet_x3[i][j].RenderBulletAngle();
			}
		}
	}
	
}
void Ennemies_typeB::free() {
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
	thbullet_x3 = 0;
	load_bullet_x3_time = Rand(0, 1000);
	speed = 1;
	direction = 1;
	photo = 0;
}
bool Ennemies_typeB::loadFromFile(string path) {
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
			E_Width = loadedSurface->w/2;
			E_Height = loadedSurface->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	E_Texture = newTexture;
	return E_Texture != NULL;
}