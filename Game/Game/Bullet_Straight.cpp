
#pragma once
#include "Bullet_Straight.h"
#include "Declaration.h"
void Bullet_Straight::free()
{
	delta_x = 0;
	delta_y = 0;
	start_x = 0;
	start_y = 0;
	x = 0;
	y = 0;
	exist = false;
	good = false;
	hit_bool = false;
	damage = 3;
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
void Bullet_Straight::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(Texture, red, green, blue);
}
void Bullet_Straight::setBlendMode(SDL_BlendMode blending)
{

	SDL_SetTextureBlendMode(Texture, blending);
}
void Bullet_Straight::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(Texture, alpha);
}
bool Bullet_Straight::loadFromFile(string path) {
	//Get rid of preexisting texture
	free();

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
void Bullet_Straight::RenderBullet_StraightSlope() {
	if (exist == true)
	{
		if (delta_x > 0 && delta_y > 0) {
			angle = 360 - atan(slope) / PI * 180;
		}
		else if (delta_x < 0 && delta_y > 0) {
			angle = -atan(slope) / PI * 180;
		}
		else if (delta_x < 0 && delta_y < 0) {
			angle = 180 - atan(slope) / PI * 180;
		}
		else if (delta_x > 0 && delta_y < 0) {
			angle = 180 - atan(slope) / PI * 180;
		}
		if (delta_x == 0 && delta_y > 0) {
			angle = 0;
		}
		if (delta_x == 0 && delta_y < 0) {
			angle = 180;
		}
		if (delta_y == 0 && delta_x < 0) {
			angle = 90;
		}
		if (delta_y == 0 && delta_x > 0) {
			angle = 270;
		}
		RenderBullet_Straight();
	}
}

void Bullet_Straight::RenderBullet_StraightAngle() {
	checkOutScreen();
	if (exist == true)
	{
		// set lai goc neu bi lech
		if (angle >= 360) {
			angle = angle - 360;
		}
		else if (angle < 0) {
			angle = 360 + angle;
		}
		// set delta_x,delta_y
		if (angle > 0 && angle < 90) {
			delta_x = -1;
			delta_y = 1;
		}
		else if (angle > 90 && angle < 180) {
			delta_x = -1;
			delta_y = -1;
		}
		else if (angle > 180 && angle < 270) {
			delta_x = 1;
			delta_y = -1;
		}
		else if (angle > 270 && angle < 360) {
			delta_x = 1;
			delta_y = 1;
		}
		if (angle == 0) {
			delta_x = 0;
			delta_y = 1;
		}
		else if (angle == 90) {
			delta_y = 0;
			delta_x = -1;
		}
		else if (angle == 180) {
			delta_x = 0;
			delta_y = -1;
		}
		else if (angle == 270) {
			delta_y = 0;
			delta_x = 1;
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
}
void Bullet_Straight::RenderBullet_Straight() {
	render(x, y, NULL, angle);
	if (delta_y == 0 && delta_x > 0) {
		x += speed + speedPlus;
	}
	else if (delta_y == 0 && delta_x < 0) {
		x -= speed + speedPlus;
	}
	else if (delta_y > 0 && delta_x == 0) {
		y += speed + speedPlus;
	}
	else if (delta_y < 0 && delta_x == 0) {
		y -= speed + speedPlus;
	}
	else {
		if (slope >= 1) {
			x += round((speed + speedPlus) / sqrt(1 + 1.00 / (slope * slope))) * 1.0 * delta_y / abs(delta_y);
			y = round((x) / slope + start_y * 1.000 - 1.000 * start_x / slope);
		}
		else if ((slope <= 1) && (slope >= -1)) {
			y += round((speed + speedPlus) / sqrt(1 + 1.00 * slope * slope)) * 1.0 * delta_y / abs(delta_y);
			x = round((y + 1.000 * start_x / slope - start_y * 1.000) * slope);
		}
		else if ((slope <= -1)) {
			x -= round((speed + speedPlus) / sqrt(1 + 1.00 / (slope * slope))) * 1.0 * delta_y / abs(delta_y);
			y = round((x) / slope + start_y * 1.000 - 1.000 * start_x / slope);
		}
	}
}
void Bullet_Straight::RenderBullet_FollowSlope() {
	if (good == false) {
		if (SolveDistance() <= 40000) {
			speedPlus = 3;
			follow = false;
		}
		if (follow) {
			start_x = x;
			start_y = y;
			delta_x = 1.0 * (player.x + player.width / 2 - (x + width / 2));
			delta_y = 1.0 * (player.y + player.height / 2 - (y + height / 2));
			slope = 1.0 * delta_x / delta_y;
		}
		RenderBullet_StraightSlope();
	}
	else {
		RenderBullet_StraightAngle();
	}
}
int Bullet_Straight::SolveDistance() {
	int dis = ((x + width / 2) - (player.x + player.width / 2))
		* ((x + width / 2) - (player.x + player.width / 2)) +
		((y + height / 2) - (player.y + player.height / 2))
		* ((y + height / 2) - (player.y + player.height / 2))
		;
	return dis;
}
void Bullet_Straight::checkOutScreen() {
	if (x > (SCREEN_WIDTH + 200) || x< -200 || y>(SCREEN_HEIGHT + 200) || y < -200) {
		free();
	}
}