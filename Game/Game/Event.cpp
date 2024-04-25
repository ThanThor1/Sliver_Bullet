#include "Event.h"
#include "Declaration.h"
#include "LoadAll.h"
#include "Player.h"
void checkEvent(SDL_Event e) {
	if (screen_status == FIGHT) {
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym) {
			case SDLK_1:
				player.bullet_type = NONE;
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
				player.buff_lazer = true;
				break;
			case SDLK_5:
				player.buff_support = true;
				break;
			case SDLK_6:
				player.buff_shield = true;
				break;
			case SDLK_7:
				player.buff_speed_bullet = true;
				break;	
		    }
		}
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
				Mix_PauseMusic();
			}
			else {
				music_bool = true;
				Mix_ResumeMusic();
			}
		}
		if (checkClickObject(e, pause_screen_continue, pause_x, pause_y)) {
			screen_status = FIGHT;
		}
		if (checkClickObject(e, pause_screen_home, pause_x, pause_y)) {
			screen_status = HOME;
			if (sound_bool == true) { Mix_PlayMusic(music_menu, -1); }
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
	else if (screen_status == HOME) {
		SDL_GetMouseState(&home_x, &home_y);
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			screen_status = FIGHT;
			renewAll();
			if (sound_bool == true) {
				Mix_PlayMusic(music_fight, -1);
			}
		}
	}
	else if (screen_status == GAMEOVER) {
		SDL_GetMouseState(&gameover_x,&gameover_y);
		if (checkClickObject(e, gameover_screen_home , gameover_x, gameover_y)) {
			screen_status = HOME;
		}
	}
}
bool checkClickObject(SDL_Event& e, Object& a, int x, int y) {
	if (e.type == SDL_MOUSEBUTTONDOWN && x >= (a.center_x - a.width / 2) && y>= (a.center_y - a.height / 2) && x<= (a.center_x + a.width/2) && y<= (a.center_y + a.height/2)) {
		if(sound_bool==true)
		Mix_PlayChannel(-1, chunk_mouse, 0);
		return true;
	}
	return false;
}