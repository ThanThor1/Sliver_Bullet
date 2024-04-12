#pragma once
#pragma once
#ifndef DECLARATION
#define DECLARATION
#include "Ennemies.h"
#include "Bullet.h"
#include "SomeConst.h"
#include "Object.h"
#include "Ennemies_typeA.h"
#include "Ennemies_typeB.h"
#include "Ennemies_typeC.h"
#include "Ennemies_typeD.h"
#include "Player.h"
#include "Item_shield.h"
#include "Item_support.h"
#include "Item_x5.h"
#include "Item_x7.h"
#include "Library.h"

extern bool loadmap_bool;
extern bool sound_bool;
extern bool music_bool;
extern bool nhanchuot;
extern int screen_status;
extern bool prepare_to_press_pause;

extern int pause_x;
extern int pause_y;
extern int x;
extern int y;
extern int pre_x;
extern int pre_y;
extern int home_x;
extern int home_y;

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

extern Object gameover;
extern Object start;
extern Object Heart[3];
extern Object BackGround;

extern Player player;
extern Ennemies boss1;
extern Ennemies_typeA ennemies_A[NUMBER_ENNEMIES];
extern Ennemies_typeB ennemies_B[NUMBER_ENNEMIES];
extern Ennemies_typeC ennemies_C[NUMBER_ENNEMIES];
extern Ennemies_typeD ennemies_D[NUMBER_ENNEMIES];
extern int number_ennemies_A;
extern int number_ennemies_B;
extern int number_ennemies_C;
extern int number_ennemies_D;
extern Object item[20];

extern int MAP;
extern string map[NUMBER_MAX_HEIGHT][NUMBER_MAX_WIDTH];

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern SDL_Surface* surface;
extern SDL_Texture* texture;

extern Mix_Music* music_menu;
extern Mix_Music* music_fight;
extern Mix_Chunk* chunk_mouse;
extern Mix_Chunk* chunk_shoot;
extern Mix_Chunk* chunk_explode1;
extern Mix_Chunk* chunk_explode2;

extern UINT32 currentime;
extern UINT32 distimewave;
extern UINT32 timewave;
#endif