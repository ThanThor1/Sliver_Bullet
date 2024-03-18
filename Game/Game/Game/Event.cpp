#include "Event.h"
#include "Declaration.h"
void checkEvent(SDL_Event e) {
	if (pause == false) {
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym) {
			case SDLK_1:
				player.bullet_type = BULLET_SIMPLE;
				break;
			case SDLK_2:
				player.bullet_type = BULLET_X5;
				break;
			case SDLK_3:
				player.bullet_type = BULLET_X7;
				break;
			case SDLK_9:
				player.bullet_type = 10;
				break;
			case SDLK_4:
				player.lazer_bool = true;
				break;
			case SDLK_5:
				player.support_bool = true;
				break;
			}
		}
		if (e.type == SDL_MOUSEBUTTONDOWN && pre_x >= pause_button.O_x && pre_y >= pause_button.O_y && pre_x <= (pause_button.O_x + pause_button.O_Width) && pre_y <= (pause_button.O_y + pause_button.O_Height)) {
			pause = true;
			surface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0, 0, 0, 0);
			SDL_RenderReadPixels(gRenderer, NULL, SDL_PIXELFORMAT_RGB888, surface->pixels, surface->pitch);
			texture = SDL_CreateTextureFromSurface(gRenderer, surface);
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {
			nhanchuot = true;
		}
		if (e.type == SDL_MOUSEBUTTONUP) {
			nhanchuot = false;
		}
	}
	else{
		SDL_GetMouseState(&pause_x, &pause_y);
		if (e.type == SDL_MOUSEBUTTONDOWN && pause_x >= sound.O_x && pause_y >= sound.O_y && pause_x <= (sound.O_x + sound.O_Width) && pause_y <= (sound.O_y + sound.O_Height)) {
			if (sound_bool)
				sound_bool = false;
			else sound_bool = true;
		}
		if (e.type == SDL_MOUSEBUTTONDOWN && pause_x >= music.O_x && pause_y >= music.O_y && pause_x <= (music.O_x + music.O_Width) && pause_y <= (music.O_y + music.O_Height)) {
			if (music_bool)
				music_bool = false;
			else music_bool = true;
		}
		if (e.type == SDL_MOUSEBUTTONDOWN && pause_x >= (490+pause_menu.O_x) && pause_y >=(662+pause_menu.O_y)  && pause_x <= (490 + 128+pause_menu.O_x) && pause_y <= (662 + 148 + pause_menu.O_y)) {
			pause = false;
		}
		if (e.type == SDL_MOUSEBUTTONDOWN && pause_x >= (210-18-45+ pause_menu.O_x) && pause_y >= (445+ pause_menu.O_y) && pause_x <= (210-18+ pause_menu.O_x) && pause_y <= (445 +45 + pause_menu.O_y)) {
			if (player.sensitivity_index >= 1) {
				player.sensitivity_index--;
			}
		}
		if (e.type == SDL_MOUSEBUTTONDOWN && pause_x >= (210 + pause_menu.O_x + 252 +18 ) && pause_y >= (445 + pause_menu.O_y) && pause_x <= (210 + 18 + pause_menu.O_x + 252+ 45) && pause_y <= (445 + 45 + pause_menu.O_y)) {
			if (player.sensitivity_index <= 1) {
				player.sensitivity_index++;
			}
		}
	}
	
}