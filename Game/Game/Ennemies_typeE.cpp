
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
		photo = 0;
		angle = FindAngle(x + width / 2, y + height / 2, player.x + player.width / 2, player.y + player.height / 2);
	}
	SDL_Rect  renderQuad1 = { x, y , width, height };
	SDL_Point center = { width / 2 , height / 2 };
	SDL_Rect cut1 = { 2 * width,0, width , height };
	SDL_RenderCopyEx(gRenderer, Texture, &cut1, &renderQuad1, 0, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(gRenderer, Texture, &cut2, &renderQuad1, angle, &center, SDL_FLIP_NONE);

	if (y != finish_y) {
		y++;
	}
	else {
		loadShoot();
	}
}
void Ennemies_typeE::RenderMiniBoss() {
	checkHit(health);
	if (health <= 0) {
		exist = false;
	}
	else exist = true;
	if (exist == true) {
		SDL_Rect cut2; cut2 = { photo * width, 0, width , height };
		if (load_bullet_ennemies_E_time == 100) {
			photo = 1;
		}
		else if (load_bullet_ennemies_E_time >= 15) {
			photo = 0;
			angle = FindAngle(x + width / 2, y + height / 2, player.x + player.width / 2, player.y + player.height / 2);
		}
		SDL_Rect  renderQuad1 = { x, y , width, height };
		SDL_Point center = { width / 2 , height / 2 };
		SDL_Rect cut1 = { 2 * width,0, width , height };
		SDL_RenderCopyEx(gRenderer, Texture, &cut1, &renderQuad1, 0, NULL, SDL_FLIP_NONE);
		SDL_RenderCopyEx(gRenderer, Texture, &cut2, &renderQuad1, angle, &center, SDL_FLIP_NONE);
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
void Ennemies_typeE::loadShoot() {
	load_bullet_ennemies_E_time = (load_bullet_ennemies_E_time + 1) % 101;
	if (bullet_ennemies_E_index == NUMBER_BULLET) {
		bullet_ennemies_E_index = 0;
	}
	if (load_bullet_ennemies_E_time == 100) {
		bullet_ennemies_E[bullet_ennemies_E_index].start_x = bullet_ennemies_E[bullet_ennemies_E_index].x = x + width / 2 + (height + 10) * sin(-angle * PI / 180) - bullet_ennemies_E[bullet_ennemies_E_index].width / 2;
		bullet_ennemies_E[bullet_ennemies_E_index].start_y = bullet_ennemies_E[bullet_ennemies_E_index].y = y + (height + 10) * cos(-angle * PI / 180);
		bullet_ennemies_E[bullet_ennemies_E_index].angle = angle;
		bullet_ennemies_E[bullet_ennemies_E_index].exist = true;
		bullet_ennemies_E_index++;
	}
}

void Ennemies_typeE::free() {
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
	bullet_ennemies_E_index = 0;
	load_bullet_ennemies_E_time = Rand(0, 1000);
	speed = 1;
	direction = 1;
	photo = 0;
	death.free();
}
bool Ennemies_typeE::loadFromFile(string path) {
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
			load_bullet_ennemies_E_time = Rand(0, 1000);
			width = loadedSurface->w / 3;
			height = loadedSurface->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	Texture = newTexture;
	return Texture != NULL;
}