#include "Ennemies_typeC.h"
#include "Declaration.h"
// di chuyển 
bool Ennemies_typeC::checkExist() {
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
void Ennemies_typeC::moveEnnemies() {
	SDL_Rect  renderQuad = { x, y , width, height };
	if (angle >= 360) { angle = 0; }
	angle += 0.1;
	SDL_RenderCopyEx(gRenderer, Texture, NULL, &renderQuad, angle, NULL, SDL_FLIP_NONE);
	if (x > 0 && x < (SCREEN_WIDTH - width)) {
		if (y > 0 && y < (SCREEN_HEIGHT - height)) {
			turning = true;
		}
	}
	if ((x <= 0 || x >= SCREEN_WIDTH - width) && turning == true) {
		delta_x = -delta_x;
		start_x = x;
		start_y = y;
		turning = false;
	}
	if ((y <= 0 || y >= SCREEN_HEIGHT - height) && turning == true) {
		delta_y = -delta_y;
		start_x = x;
		start_y = y;
		turning = false;
	}
	/*
	<< delta_x << " " << delta_y << " ";*/
	slope = 1.0 * (delta_y) / (delta_x);
	/*cout << x << " " << y<<" "<<slope << endl;*/

	if (delta_y == 0 && delta_x > 0) {
		x += SPEED_RIVAL;
	}
	else if (delta_y == 0 && delta_x < 0) {
		x -= SPEED_RIVAL;
	}
	else if (delta_y > 0 && delta_x == 0) {
		y += SPEED_RIVAL;
	}
	else if (delta_y < 0 && delta_x == 0) {
		y -= SPEED_RIVAL;
	}
	else {
		if (slope >= 1) {
			y += round((SPEED_RIVAL) / sqrt(1 + 1.00 / (slope * slope))) * delta_x / abs(delta_x);
			x = round((y + 1.000 * start_x * slope - start_y * 1.000) / slope);
		}
		else if ((slope <= 1) && (slope >= -1)) {
			x += round((SPEED_RIVAL) / sqrt(1 + 1.00 * slope * slope)) * delta_x / abs(delta_x);
			y = round((x)*slope + start_y * 1.000 - 1.000 * start_x * slope);
		}
		else if ((slope <= -1)) {
			y -= round((SPEED_RIVAL) / sqrt(1 + 1.00 / (slope * slope))) * delta_x / abs(delta_x);
			x = round((y + 1.000 * start_x * slope - start_y * 1.000) / slope);
		}
	}
	loadShoot();
}
//sạc đạn
void Ennemies_typeC::loadShoot() {
	load_bullet_ennemies_C_time = (load_bullet_ennemies_C_time + 1) % 1001;
	if (bullet_ennemies_C_index == NUMBER_BULLET) {
		bullet_ennemies_C_index = 0;
	}
	if (load_bullet_ennemies_C_time == 1000) {
		int a = Rand(0, 90);
		for (int i = 0; i < 4; i++) {
			bullet_ennemies_C[bullet_ennemies_C_index][i].start_x = bullet_ennemies_C[bullet_ennemies_C_index][i].x = x + width / 2 - bullet_ennemies_C[bullet_ennemies_C_index][i].width / 2;
			bullet_ennemies_C[bullet_ennemies_C_index][i].start_y = bullet_ennemies_C[bullet_ennemies_C_index][i].y = y + height / 2 - bullet_ennemies_C[bullet_ennemies_C_index][i].height / 2;
			bullet_ennemies_C[bullet_ennemies_C_index][i].angle = a;
			bullet_ennemies_C[bullet_ennemies_C_index][i].exist = true;
			a += 90;
		}
		bullet_ennemies_C_index++;
	}
}
//bắn

void Ennemies_typeC::free() {
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
	bullet_ennemies_C_index = 0;
	load_bullet_ennemies_C_time = Rand(0, 1000);
	speed = 1;
	photo = 0;
	turning = false;
}
bool Ennemies_typeC::loadFromFile(string path) {
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
			width = loadedSurface->w;
			height = loadedSurface->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	Texture = newTexture;
	return Texture != NULL;
}