#include"Library.h"
#include"SomeConst.h"
#include"Declaration.h"
#include "Event.h"
#include"LoadAll.h"
#include"RenderScreen.h"
bool init() {
	gWindow = SDL_CreateWindow("Arcadium", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL) {
		
		cout<< "Window could not be created!" << SDL_GetError();
	}
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Renderer* pauseRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gWindow == NULL) {
		cout << "Window could not be created!" << SDL_GetError();
	}
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init()<0) {
		success = false;
	}
	else if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		success = false;
	}
	else if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 3, 2048) < 0) {
		success = false;
	}
	else if (TTF_Init() < 0) {
		success = false;
	}
	return success;
}
int main(int argc, char* args[]) {
	bool quit = false;
	SDL_Event e;
	if (!init()) {
		cout << "cannot init";
	}
	else {
		loadAll();
		Mix_PlayMusic(home_screen_music, -1);
		while (!quit)
		{
			int start = SDL_GetTicks();
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				checkEvent(e);
			}
			if (screen_status == PAUSE) {
				loadPauseScreen();
			}
			else if (screen_status == FIGHT) {
				loadFightScreen();
			}
			else if (screen_status == HOME) {
				loadHomeScreen();
			}
			else if (screen_status == GAMEOVER) {
				loadGameoverScreen();
			}
			else if (screen_status == WARNING) {
				loadWarningScreen();
			}
			else if (screen_status == OPTION) {
				loadOptionScreen();
			}
			else if (screen_status == CREDIT) {
				loadCreditGame();
			}
		    int end = SDL_GetTicks();
			if (quit != true && (1000 / 120 - end + start)>0) {
				SDL_Delay(1000 / 120 - end + start);
			}
		}
		
	}
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	SDL_Quit();
	return 0;
}
