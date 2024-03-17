#include "Event.h"
#include "Declaration.h"
void checkEvent(SDL_Event e) {
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
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		nhanchuot = true;
	}
	if (e.type == SDL_MOUSEBUTTONUP) {
		nhanchuot = false;
	}
}