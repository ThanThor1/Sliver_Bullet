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
	shoot();
	return exist;
}
void Ennemies_typeC::moveEnnemies() {
	SDL_Rect  renderQuad = { E_x, E_y , E_Width, E_Height };
	if (E_angle >= 360) { E_angle = 0; }
	E_angle += 0.1;
	SDL_RenderCopyEx(gRenderer, E_Texture, NULL, &renderQuad, E_angle, NULL, SDL_FLIP_NONE);
	if (E_x > 0 && E_x < (SCREEN_WIDTH - E_Width)) {
		if (E_y > 0 && E_y < (SCREEN_HEIGHT - E_Height)) {
			turning = true;
		}
	}
	if ((E_x <= 0 || E_x >= SCREEN_WIDTH - E_Width) && turning == true) {
		E_denta_x = -E_denta_x;
		E_start_x = E_x;
		E_start_y = E_y;
		turning = false;
	}
	if ((E_y <= 0 || E_y >= SCREEN_HEIGHT - E_Height) && turning == true) {
		E_denta_y = -E_denta_y;
		E_start_x = E_x;
		E_start_y = E_y;
		turning = false;
	}
	/*
	<< denta_x << " " << denta_y << " ";*/
	E_slope = 1.0 * (E_denta_y) / (E_denta_x);
	/*cout << E_x << " " << E_y<<" "<<E_slope << endl;*/

	if (E_denta_y == 0 && E_denta_x > 0) {
		E_x += SPEED_RIVAL;
	}
	else if (E_denta_y == 0 && E_denta_x < 0) {
		E_x -= SPEED_RIVAL;
	}
	else if (E_denta_y > 0 && E_denta_x == 0) {
		E_y += SPEED_RIVAL;
	}
	else if (E_denta_y < 0 && E_denta_x == 0) {
		E_y -= SPEED_RIVAL;
	}
	else {
		if (E_slope >= 1) {
			E_y += round((SPEED_RIVAL) / sqrt(1 + 1.00 / (E_slope * E_slope))) * E_denta_x / abs(E_denta_x);
			E_x = round((E_y + 1.000 * E_start_x * E_slope - E_start_y * 1.000) / E_slope);
		}
		else if ((E_slope <= 1) && (E_slope >= -1)) {
			E_x += round((SPEED_RIVAL) / sqrt(1 + 1.00 * E_slope * E_slope)) * E_denta_x / abs(E_denta_x);
			E_y = round((E_x)*E_slope + E_start_y * 1.000 - 1.000 * E_start_x * E_slope);
		}
		else if ((E_slope <= -1)) {
			E_y -= round((SPEED_RIVAL) / sqrt(1 + 1.00 / (E_slope * E_slope))) * E_denta_x / abs(E_denta_x);
			E_x = round((E_y + 1.000 * E_start_x * E_slope - E_start_y * 1.000) / E_slope);
		}
	}
	loadShoot();
}
//sạc đạn
void Ennemies_typeC::loadShoot() {
	load_bullet_x4_time = (load_bullet_x4_time + 1) % 1001;
	if (thbullet_x4 == NUMBER_BULLET) {
		thbullet_x4 = 0;
	}
	if (load_bullet_x4_time == 1000) {
		int a = Rand(0, 90);
		for (int i = 0; i < 4; i++) {
			bullet_x4[thbullet_x4][i].B_start_x = bullet_x4[thbullet_x4][i].B_x = E_x + E_Width/2 - bullet_x4[thbullet_x4][i].B_Width/2;
			bullet_x4[thbullet_x4][i].B_start_y = bullet_x4[thbullet_x4][i].B_y = E_y + E_Height/2 - bullet_x4[thbullet_x4][i].B_Height/2;
			bullet_x4[thbullet_x4][i].B_angle = a;
			bullet_x4[thbullet_x4][i].B_exist = true;
			a += 90;
		}
		thbullet_x4++;
	}
}
//bắn
void Ennemies_typeC::shoot() {
	for (int i = 0; i < NUMBER_BULLET; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			bullet_x4[i][j].RenderBulletAngle();
		}
	}
}
void Ennemies_typeC::free() {
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
	thbullet_x4 = 0;
	load_bullet_x4_time = Rand(0, 1000);
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
			E_Width = loadedSurface->w;
			E_Height = loadedSurface->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	E_Texture = newTexture;
	return E_Texture != NULL;
}