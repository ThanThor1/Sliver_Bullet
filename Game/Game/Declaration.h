#pragma once
#pragma once
#ifndef DECLARATION
#define DECLARATION
#include "IncludeAll.h"
extern bool sound_bool;
extern bool music_bool;
extern bool nhanchuot;
extern int screen_status;
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
extern int home_x;
extern int home_y;
/// <summary>
/// 
/// </summary>
extern Object sensitivity[3];
extern Object home;
extern Object press_start;
extern Object continue_pause;
extern Object home_pause;
extern Object sensitivity_down_pause;
extern Object sensitivity_up_pause;
extern Object sound_pause;
extern Object unsound_pause;
extern Object unmusic_pause;
extern Object music_pause;
extern Object pause_menu;
extern Object pause_button;
/// <summary>
/// 
/// </summary>
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
extern Ennemies ennemies_1[NUMBER_ENNEMIES];
extern Ennemies ennemies_2[NUMBER_ENNEMIES];
extern Ennemies ennemies_3[NUMBER_ENNEMIES];
extern Ennemies ennemies_4[NUMBER_ENNEMIES];
/// <summary>
/// 
/// </summary>
extern bool wave_1;
extern bool wave_2;
///
//
///

#endif