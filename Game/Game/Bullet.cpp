
#pragma once
#include "Bullet.h"
#include "Declaration.h"
void Bullet::free()
{
	B_denta_x = 0;
	B_denta_y = 0;
	B_exist = false;
	B_start_x = 0;
	B_start_y = 0;
	B_x = 0;
	B_y = 0;
}
Bullet::Bullet()
{
	B_exist = false;
	B_Texture = NULL;
	B_Width = 0;
	B_Height = 0;
}
Bullet::~Bullet()
{
	free();
}
void Bullet::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(B_Texture, red, green, blue);
}
void Bullet::setBlendMode(SDL_BlendMode blending)
{

	SDL_SetTextureBlendMode(B_Texture, blending);
}
void Bullet::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(B_Texture, alpha);
}
bool Bullet::loadFromFile(string path) {
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
			B_Width = loadedSurface->w;
			B_Height = loadedSurface->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	B_Texture = newTexture;
	return B_Texture != NULL;
}
void Bullet::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Point center1 = { B_Width / 2,B_Height / 2 };
	if (clip != NULL)
	{
		center1.x = clip->x;
		center1.y = clip->y;
	}
	SDL_Rect renderQuad = { x, y , B_Width, B_Height };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(gRenderer, B_Texture, clip, &renderQuad, angle, &center1, flip);
}
void Bullet::RenderBulletSlope() {
	if (B_exist == true)
	{
		if (B_denta_x > 0 && B_denta_y > 0) {
			B_angle = 360 - atan(B_slope) / PI * 180;
		}
		else if (B_denta_x < 0 && B_denta_y > 0) {
			B_angle = -atan(B_slope) / PI * 180;
		}
		else if (B_denta_x < 0 && B_denta_y < 0) {
			B_angle = 180 - atan(B_slope) / PI * 180;
		}
		else if (B_denta_x > 0 && B_denta_y < 0) {
			B_angle = 180 - atan(B_slope) / PI * 180;
		}
		if (B_denta_x == 0 && B_denta_y > 0) {
			B_angle = 0;
		}
		if (B_denta_x == 0 && B_denta_y < 0) {
			B_angle = 180;
		}
		if (B_denta_y == 0 && B_denta_x < 0) {
			B_angle = 90;
		}
		if (B_denta_y == 0 && B_denta_x > 0) {
			B_angle = 270;
		}
		RenderBulletStraight();
	}
}
void Bullet::RenderBulletAngle() {
	if (B_exist == true)
	{
		// set lai goc neu bi lech
		if (B_angle >= 360) {
			B_angle = B_angle - 360;
		}
		else if (B_angle < 0) {
			B_angle = 360 + B_angle;
		}
		// set denta_x,denta_y
		if (B_angle > 0 && B_angle < 90) {
			B_denta_x = -1;
			B_denta_y = 1;
		}
		else if (B_angle > 90 && B_angle < 180) {
			B_denta_x = -1;
			B_denta_y = -1;
		}
		else if (B_angle > 180 && B_angle < 270) {
			B_denta_x = 1;
			B_denta_y = -1;
		}
		else if (B_angle > 270 && B_angle < 360) {
			B_denta_x = 1;
			B_denta_y = 1;
		}
		if (B_angle == 0) {
			B_denta_x = 0;
			B_denta_y = 1;
		}
		else if (B_angle == 90) {
			B_denta_y = 0;
			B_denta_x = -1;
		}
		else if (B_angle == 180) {
			B_denta_x = 0;
			B_denta_y = -1;
		}
		else if (B_angle == 270) {
			B_denta_y = 0;
			B_denta_x = 1;
		}
		//
		if (B_angle >= 0 && B_angle <= 90) {
			B_slope = tan(-B_angle * 1.0 * PI / 180);
		}
		else if (B_angle >= 90 && B_angle <= 270) {
			B_slope = tan((180 - B_angle) * 1.0 * PI / 180);
		}
		else {
			B_slope = tan((360 - B_angle) * 1.0 * PI / 180);
		}
		RenderBulletStraight();
	}
}
void Bullet::RenderBulletStraight() {
	render(B_x, B_y, NULL, B_angle);
	if (B_denta_y == 0 && B_denta_x > 0) {
		B_x += BULLET_SPEED_RIVAL + B_speedPlus;
	}
	else if (B_denta_y == 0 && B_denta_x < 0) {
		B_x -= BULLET_SPEED_RIVAL + B_speedPlus;
	}
	else if (B_denta_y > 0 && B_denta_x == 0) {
		B_y += BULLET_SPEED_RIVAL + B_speedPlus;
	}
	else if (B_denta_y < 0 && B_denta_x == 0) {
		B_y -= BULLET_SPEED_RIVAL + B_speedPlus;
	}
	else {
		if (B_slope >= 1) {
			B_x += round((BULLET_SPEED_RIVAL + B_speedPlus) / sqrt(1 + 1.00 /( B_slope * B_slope))) * 1.0 * B_denta_y/abs(B_denta_y);
			B_y = round((B_x)/B_slope + B_start_y * 1.000 - 1.000 * B_start_x / B_slope);
		}
		else if ((B_slope <= 1) && (B_slope >= -1)) {
			B_y += round((BULLET_SPEED_RIVAL + B_speedPlus) / sqrt(1 + 1.00 * B_slope * B_slope))   * 1.0* B_denta_y/ abs(B_denta_y);
			B_x = round((B_y + 1.000 * B_start_x / B_slope - B_start_y * 1.000) * B_slope);
		}
		else if ((B_slope <= -1)) {
			B_x -= round((BULLET_SPEED_RIVAL + B_speedPlus) / sqrt(1 + 1.00 / (B_slope * B_slope))) * 1.0*  B_denta_y/ abs(B_denta_y);
			B_y = round((B_x)/B_slope + B_start_y * 1.000 - 1.000 * B_start_x / B_slope);
		}
	}
}