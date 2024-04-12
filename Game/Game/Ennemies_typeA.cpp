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
	    SDL_Rect cut;
	    cut = { photo* E_Width, 0, E_Width , E_Height };
		if (load_bullet_simple_time == 1000) {
			photo = 1;
		}
		else if (load_bullet_simple_time >= 150) {
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
void Ennemies_typeA::loadShoot() {
	load_bullet_simple_time = (load_bullet_simple_time + 1) % 1001;
	if (thbullet_simple == NUMBER_BULLET) {
		thbullet_simple = 0;
	}
	if (load_bullet_simple_time == 1000) {
		bullet_simple[thbullet_simple].B_start_x = bullet_simple[thbullet_simple].B_x = E_x + E_Width / 2 + (E_Height + 10) * sin(-E_angle * PI / 180) - bullet_simple[thbullet_simple].B_Width / 2;
		bullet_simple[thbullet_simple].B_start_y = bullet_simple[thbullet_simple].B_y = E_y + (E_Height + 10) * cos(-E_angle * PI / 180);
		bullet_simple[thbullet_simple].B_angle = E_angle;
		bullet_simple[thbullet_simple].B_exist = true;
		thbullet_simple++;
	}
}
//bắn
void Ennemies_typeA::shoot() {
	for (int i = 0; i < NUMBER_BULLET; i++) {
		bullet_simple[i].RenderBulletAngle();
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
	photo = 0;
}
bool Ennemies_typeA::loadFromFile(string path) {
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