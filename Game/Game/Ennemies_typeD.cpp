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
	return exist;
}
void Ennemies_typeD::moveEnnemies() {
	SDL_Rect  renderQuad = { x, y , width, height };
	SDL_Rect cut;
	cut = { photo / 10 * width, 0, width , height };
	photo = (photo + 1) % 41;
	SDL_RenderCopy(gRenderer, Texture, &cut, &renderQuad);
	if (x >= SCREEN_WIDTH - width)
		direction = -1;
	if (x <= 0) {
		direction = 1;
	}
	x += direction;
	loadShoot();
}
void Ennemies_typeD::RenderMiniBoss() {
	checkHit(health);
	if (health <= 0) {
		exist = false;
	}
	else exist = true;
	if (exist == true) {
		SDL_Rect  renderQuad = { x, y , width, height };
		SDL_Rect cut;
		cut = { photo / 10 * width, 0, width , height };
		photo = (photo + 1) % 41;
		SDL_RenderCopy(gRenderer, Texture, &cut, &renderQuad);
		loadShoot();
	}
	else {
		load_reborn_time++;
		if (load_reborn_time == 1000) {
			free();
			load_reborn_time = 0;
		}
	}
}
//sạc đạn
void Ennemies_typeD::loadShoot() {
	load_bullet_ennemies_D_time = (load_bullet_ennemies_D_time + 1) % 1001;
	if (bullet_ennemies_D_index == NUMBER_BULLET) {
		bullet_ennemies_D_index = 0;
	}
	if (load_bullet_ennemies_D_time == 1000) {
		bullet_ennemies_D[bullet_ennemies_D_index].x = bullet_ennemies_D[bullet_ennemies_D_index].start_x = x + width / 2;
		bullet_ennemies_D[bullet_ennemies_D_index].y = bullet_ennemies_D[bullet_ennemies_D_index].start_y = y + height;
		bullet_ennemies_D[bullet_ennemies_D_index].delta_y = 1.00000 * (player.x + player.width / 2 - (bullet_ennemies_D[bullet_ennemies_D_index].start_x + bullet_ennemies_D[bullet_ennemies_D_index].width / 2));
		bullet_ennemies_D[bullet_ennemies_D_index].delta_x = 1.00000 * (player.y + player.height / 2 - (bullet_ennemies_D[bullet_ennemies_D_index].start_y + bullet_ennemies_D[bullet_ennemies_D_index].height / 2));
		bullet_ennemies_D[bullet_ennemies_D_index].slope = 1.00000 * bullet_ennemies_D[bullet_ennemies_D_index].delta_x / bullet_ennemies_D[bullet_ennemies_D_index].delta_y;
		bullet_ennemies_D[bullet_ennemies_D_index].exist = true;
		bullet_ennemies_D_index++;
	}
}
//bắn
void Ennemies_typeD::free() {
	x = 0;
	y = 0;
	start_x = 0;
	start_y = 0;
	finish_x = 0;
	finish_y = 0;
	slope = 0;
	angle = 0;
	exist = false;
	health = 10;
	bullet_ennemies_D_index = 0;
	load_bullet_ennemies_D_time = Rand(0, 1000);
	speed = 1;
	direction = 1;
	photo = 0;
	death.free();
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
			load_bullet_ennemies_D_time = Rand(0, 1000);
			//Get image dimensions
			width = loadedSurface->w / 4;
			height = loadedSurface->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	Texture = newTexture;
	return Texture != NULL;
}