#pragma once
#pragma once
#ifndef DECLARATION
#define DECLARATION
#include "Ennemies.h"
#include "Bullet_Straight.h"
#include "SomeConst.h"
#include "Object.h"
#include "Ennemies_typeA.h"
#include "Ennemies_typeB.h"
#include "Ennemies_typeC.h"
#include "Ennemies_typeD.h"
#include "Ennemies_typeE.h"
#include "Player.h"
#include "Item.h"
#include "Library.h"
#include "Boss.h"
#include "Bullet_Round.h"
#include "Boom.h"

extern bool loadmap_bool;
extern bool sound_bool;
extern bool music_bool;
extern bool nhanchuot;
extern int screen_status;
extern bool prepare_to_press_pause;

extern int pause_x;
extern int pause_y;
extern int now_x;
extern int now_y;
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
extern Boss boss;
extern Object mini_boss_1[3];
extern Object mini_boss_2[3];
extern Object mini_boss_center_1;
extern Object staff_mini_boss_1;
extern Object mini_boss_center_2;
extern Object lazer[2];
extern Object head_lazer[2];
extern Object lazer_warning_red[2];
extern Object lazer_warning_green[2];
extern Bullet_Straight star[1000];
extern int star_index;
extern int star_coordinates[100][3];
extern Ennemies_typeB miniboss_1_B;
extern Ennemies_typeD miniboss_1_D;
extern Ennemies_typeE miniboss_1_E;
extern Ennemies_typeB miniboss_2_B;
extern Ennemies_typeD miniboss_2_D;
extern Ennemies_typeE miniboss_2_E;
extern Boom boom[NUMBER_BULLET];
extern Ennemies_typeA ennemies_A[NUMBER_ENNEMIES];
extern Ennemies_typeB ennemies_B[NUMBER_ENNEMIES];
extern Ennemies_typeC ennemies_C[NUMBER_ENNEMIES];
extern Ennemies_typeD ennemies_D[NUMBER_ENNEMIES];
extern Ennemies_typeE ennemies_E[NUMBER_ENNEMIES];
extern int number_ennemies_A;
extern int number_ennemies_B;
extern int number_ennemies_C;
extern int number_ennemies_D;
extern int number_ennemies_E;
extern Bullet_Straight  bullet_ennemies_A[NUMBER_BULLET];
extern Bullet_Straight  bullet_ennemies_B[NUMBER_BULLET][3];
extern Bullet_Straight  bullet_ennemies_C[NUMBER_BULLET][4];
extern Bullet_Straight  bullet_ennemies_D[NUMBER_BULLET];
extern Bullet_Straight  bullet_ennemies_E[NUMBER_BULLET];
extern Bullet_Round bullet_round[NUMBER_BULLET];
extern Bullet_Straight bullet_level[3][NUMBER_BULLET * 25];
extern int bullet_ennemies_A_index ;
extern int bullet_ennemies_B_index ;
extern int bullet_ennemies_C_index ;
extern int bullet_ennemies_D_index ;
extern int bullet_ennemies_E_index ;
extern int bullet_round_index ;
extern int bullet_level_index[3];
extern int boom_index;
extern Item item[100];
extern int item_index ;
extern Item item_example[20];

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
extern Mix_Chunk* chunk_item;

extern UINT32 currentime;
extern UINT32 distimewave;
extern UINT32 timewave;

extern Object support_1;
extern Object support_2;
#endif