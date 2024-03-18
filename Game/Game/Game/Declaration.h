#pragma once
#pragma once
#ifndef DECLARATION
#define DECLARATION
#include "IncludeAll.h"

extern bool sound_bool;
extern bool music_bool;
extern bool nhanchuot;
extern bool pause;
extern bool prepare_to_press_pause;
/// <summary>
/// 
/// </summary>
/// 
extern int pause_x;
extern int pause_y;
extern 	int x;
extern  int y;
extern 	int pre_x;
extern  int pre_y;
/// <summary>
/// 
/// </summary>
extern Object sensitivity[3];
extern Object SOUND;
extern Object MUSIC;
extern Object sound;
extern Object unsound;
extern Object unmusic;
extern Object music;
extern Object pause_menu;
extern Object pause_button;
extern Object Heart[3];
extern Object BackGround;
/// <summary>
/// 
/// </summary>
extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern SDL_Surface* surface;
extern SDL_Texture* texture;
/// <summary>
/// 
/// </summary>
extern Player player;
extern Ennemies boss1;
extern Ennemies ennemies_1[1000];
extern Ennemies ennemies_2[1000];
extern Ennemies ennemies_3[1000];
extern Ennemies ennemies_4[1000];
/// <summary>
/// 
/// </summary>
extern bool wave_1;
extern bool wave_2;
#endif