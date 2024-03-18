#pragma once
#ifndef EVENT
#define EVENT
#include "Library.h"
#include "Declaration.h"
void checkEvent(SDL_Event e);
bool checkClickObject(SDL_Event& e, Object &a, int x, int y);
#endif
