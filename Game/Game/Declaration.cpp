﻿#include "Declaration.h"

bool loadmap_bool = false;
bool sound_bool = true;
bool music_bool = true;
int screen_status = HOME;
bool prepare_to_press_pause = false;
bool nhanchuot = false;
/// <summary>
/// 
/// </summary>

int x = 0;
int y = 0;
int pre_x = 0;
int pre_y = 0;
int pause_x = 0;
int pause_y = 0;
int home_x = 0;
int home_y = 0;
/// <summary>
/// 
/// </summary>
/// extern Object continue_pause;
Object home;
Object press_start;
Object continue_pause;
Object home_pause;
Object sensitivity_down_pause;
Object sensitivity_up_pause;
Object sensitivity[3];
Object sound_pause;
Object unsound_pause;
Object unmusic_pause;
Object music_pause;
Object pause_menu;
Object pause_button;
Object Heart[3];
Object BackGround;
/// <summary>
/// 
/// </summary>

/// <summary>
/// 
/// </summary>
Player player;
Ennemies boss1;
Ennemies_typeA ennemies_A[NUMBER_ENNEMIES];
Ennemies_typeB ennemies_B[NUMBER_ENNEMIES];
Ennemies_typeC ennemies_C[NUMBER_ENNEMIES];
int number_ennemies_A = 0;
int number_ennemies_B = 0;
int number_ennemies_C = 0;
Ennemies ennemies_1[NUMBER_ENNEMIES];
Ennemies ennemies_2[NUMBER_ENNEMIES];
Ennemies ennemies_3[NUMBER_ENNEMIES];
Ennemies ennemies_4[NUMBER_ENNEMIES];
/// <summary>
/// 
/// </summary>
int MAP = 0;
string map[NUMBER_MAX_HEIGHT][ NUMBER_MAX_WIDTH] = {};

SDL_Window* gWindow;
SDL_Renderer* gRenderer;
SDL_Surface* surface;
SDL_Texture* texture;

Mix_Music* music_menu;
Mix_Music* music_fight;