#include "Text.h"
#include "Declaration.h"
void Text::loadText(string text, int x, int y) {
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), TextColor);
	textTexture = SDL_CreateTextureFromSurface(gRenderer,textSurface);
	if (textSurface == NULL) {
		cout << "loi textSuface" << endl;
	}
	else {
		width = textSurface->w;
		height = textSurface->h;
	}
    SDL_Rect a = { x, y - height /2 , width, height };
	SDL_RenderCopy(gRenderer, textTexture, NULL, &a);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
}
void Text::loadFont(string location, int size) {
	font = TTF_OpenFont(location.c_str(), size);
	if (font == NULL) {
		cout << "loi font" << endl;
	}
}