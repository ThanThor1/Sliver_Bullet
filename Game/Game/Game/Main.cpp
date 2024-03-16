#include"Library.h"
#include"SomeConst.h"
#include"IncludeAll.h"
#include"Declaration.h"
#include"LoadAll.h"
#include "Wave1.h"

int main(int argc, char* args[]) {
	gWindow = SDL_CreateWindow("taplamgame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL) {
		cout << "Window could not be created!" << SDL_GetError();
	}
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (gWindow == NULL) {
		cout << "Window could not be created!" << SDL_GetError();
	}
	int x = 0;
	int y = 0;
	loadall();
	bool quit = false;
	SDL_Event e;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initialize" << SDL_GetError();;
	}
	else {
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				checkEvent(e);
			}
			SDL_RenderClear(gRenderer);
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			BackGround.renderbackground();
			Wave1();
			SDL_GetMouseState(&x, &y);
			player.loadFrame(x, y);
			Wave1();
			SDL_RenderPresent(gRenderer);
		}
	}
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	SDL_Quit();
	return 0;
}