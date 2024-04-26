#include "Event.h"
#include "Declaration.h"
#include "LoadAll.h"
#include "RenewAll.h"
#include "Player.h"
void checkEvent(SDL_Event e) {
	if (screen_status == FIGHT) {
		if (checkClickObject(e, pause_button, pre_x, pre_y)) {
			screen_status = PAUSE;
			surface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0, 0, 0, 0);
			SDL_RenderReadPixels(gRenderer, NULL, SDL_PIXELFORMAT_RGB888, surface->pixels, surface->pitch);
			texture = SDL_CreateTextureFromSurface(gRenderer, surface);
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {
			nhanchuot = true;
		}
		else if (e.type == SDL_MOUSEBUTTONUP) {
			nhanchuot = false;
		}
	}
	else if (screen_status == PAUSE) {
		SDL_GetMouseState(&pause_x, &pause_y);
		if (checkClickObject(e, pause_screen_sound_pause, pause_x, pause_y)) {
			if (sound_bool)
				sound_bool = false;
			else sound_bool = true;
		}
		if (checkClickObject(e, pause_screen_music_pause, pause_x, pause_y)) {
			if (music_bool) {
				music_bool = false;
			}
			else {
				music_bool = true;
			}
		}
		if (checkClickObject(e, pause_screen_continue, pause_x, pause_y)) {
			screen_status = FIGHT;
		}
		if (checkClickObject(e, pause_screen_home, pause_x, pause_y)) {
			surface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0, 0, 0, 0);
			SDL_RenderReadPixels(gRenderer, NULL, SDL_PIXELFORMAT_RGB888, surface->pixels, surface->pitch);
			texture = SDL_CreateTextureFromSurface(gRenderer, surface);
			screen_status = WARNING;
		}
		if (checkClickObject(e, pause_screen_sensitivity_down, pause_x, pause_y)) {
			if (player.sensitivity_index >= 1) {
				player.sensitivity_index--;
			}
		}
		if (checkClickObject(e, pause_screen_sensitivity_up, pause_x, pause_y)) {
			if (player.sensitivity_index <= 1) {
				player.sensitivity_index++;
			}
		}
		
	}
	else if (screen_status == OPTION) {
		SDL_GetMouseState(&option_x, &option_y);
		if (checkClickObject(e, option_screen_sound_pause, option_x, option_y)) {
			if (sound_bool)
				sound_bool = false;
			else sound_bool = true;
		}
		if (checkClickObject(e, option_screen_music_pause, option_x, option_y)) {
			if (music_bool) {
				music_bool = false;
			}
			else {
				music_bool = true;
			}
		}
		if (checkClickObject(e, option_screen_continue, option_x, option_y)) {
			screen_status = HOME;
			Mix_PlayMusic(home_screen_music, -1);
		}
		if (checkClickObject(e, option_screen_sensitivity_down, option_x, option_y)) {
			if (player.sensitivity_index >= 1) {
				player.sensitivity_index--;
			}
		}
		if (checkClickObject(e, option_screen_sensitivity_up, option_x, option_y)) {
			if (player.sensitivity_index <= 1) {
				player.sensitivity_index++;
			}
		}
	}
	else if (screen_status == HOME) {
		SDL_GetMouseState(&home_x, &home_y);
		if (checkClickObject(e, home_screen_option, home_x, home_y)) {
			screen_status = OPTION;
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {
			screen_status = FIGHT;
			renewAll();
			if (sound_bool == true) {
				Mix_PlayMusic(fight_screen_music, -1);
			}
		}
	}
	else if (screen_status == GAMEOVER) {
		SDL_GetMouseState(&gameover_x,&gameover_y);
		if (boss.health > 0) {
			if (checkClickObject(e, gameover_screen_home, gameover_x, gameover_y)) {
				screen_status = HOME;
				Mix_PlayMusic(home_screen_music, -1);
			}
		}
		else {
			if (checkClickObject(e, gameover_screen_home, gameover_x, gameover_y)) {
				screen_status = CREDIT;
				Mix_PlayMusic(home_screen_music, -1);
			}
		}
	}
	else if (screen_status == WARNING) {
		SDL_GetMouseState(&warning_x, &warning_y);
		if (checkClickObject(e, warning_screen_yes, warning_x, warning_y)) {
			screen_status = HOME;
			Mix_PlayMusic(home_screen_music, -1);
		}
		if (checkClickObject(e, warning_screen_no, warning_x, warning_y)) {
			screen_status = PAUSE;
		}
	}
	if (music_bool == false) {
		Mix_PauseMusic();
	}
	else Mix_ResumeMusic();
}
bool checkClickObject(SDL_Event& e, Object& a, int x, int y) {
	if (e.type == SDL_MOUSEBUTTONDOWN && x >= (a.center_x - a.width / 2) && y>= (a.center_y - a.height / 2) && x<= (a.center_x + a.width/2) && y<= (a.center_y + a.height/2)) {
		if(sound_bool==true)
		Mix_PlayChannel(-1, chunk_mouse, 0);
		return true;
	}
	return false;
}