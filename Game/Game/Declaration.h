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
#include "bullet_triangle.h"
#include "Boom.h"
#include "Text.h"

extern Bullet_Straight bullet_x7[NUMBER_BULLET][7];

/// <summary>
/// some_bool
/// </summary>
extern bool loadmap_bool;
extern bool sound_bool;
extern bool music_bool;
extern bool prepare_to_press_pause;
extern bool nhanchuot;
extern int screen_status;
extern string wave_path;
/// <summary>
/// location of mouse
/// </summary>
extern int now_x;
extern int now_y;
extern int pre_x;
extern int pre_y;
extern int pause_x;
extern int pause_y;
extern int home_x;
extern int home_y;
extern int gameover_x;
extern int gameover_y;
extern int warning_x;
extern int warning_y;
extern int option_x;
extern int option_y;
extern int credit_x;
extern int credit_y;
/// <summary>
/// icon
/// </summary>
/// icon in home
extern Object home_background;
extern Object home_screen_press_start;
extern Object home_screen_option;
extern Object home_screen_credit;
// icon in pause
extern Object pause_screen_continue;
extern Object pause_screen_home;
extern Object pause_screen_sensitivity_down;
extern Object pause_screen_sensitivity_up;
extern Object pause_screen_sensitivity[3];
extern Object pause_screen_sound_pause;
extern Object pause_screen_unsound_pause;
extern Object pause_screen_unmusic_pause;
extern Object pause_screen_music_pause;
extern Object pause_background;
extern Object pause_button;
// icon in option
extern Object option_screen_continue;
extern Object option_screen_sensitivity_down;
extern Object option_screen_sensitivity_up;
extern Object option_screen_sensitivity[3];
extern Object option_screen_sound_pause;
extern Object option_screen_unsound_pause;
extern Object option_screen_unmusic_pause;
extern Object option_screen_music_pause;
extern Object option_background;
extern Object option_button;
// icon in fight
extern Object fight_screen_background;
extern Object fight_screen_gameover;
extern Object fight_screen_start;
extern Object fight_screen_score;
extern Text score_fight_screen_text;
extern Text you_win;
extern Object Heart[3];
extern int wave_number;
extern int score_number;
extern int aliens_defeated_number;
// icon in game over
extern Object gameover_screen_background;
extern Object gameover_screen_home;
extern Object gameover_screen_win;
extern Text wave_number_gameover_screen_text;
extern Text score_gameover_menu_screen_text;
extern Text aliens_defeated_gameover_screen_text;
// icon in warning
extern Object warning_screen_background;
extern Object warning_screen_yes;
extern Object warning_screen_no;
// icon in warning
extern Object credit_win_screen;
/// <summary>
/// Player
/// </summary>
extern Player player;
extern Object support_1;
extern Object support_2;
/// <summary>
/// boss
/// </summary>
extern Boss boss;
extern Object health_boss;
extern Object health_boss_background;
extern Object mini_boss_center_1;
extern Object staff_mini_boss_1;
extern Object mini_boss_center_2;
extern Object lazer[2];
extern Object head_lazer[2];
extern Object lazer_warning_red[2];
extern Object lazer_warning_green[2];
extern Bullet_Straight bullet_around_boss[NUMBER_BULLET];
extern int bullet_around_boss_index;
extern Boom boom[NUMBER_BULLET];
extern int boom_index;
extern Bullet_Straight star[1000];
extern int star_coordinates[100][3];
extern int star_index;
extern Bullet_Triangle bullet_triangle[NUMBER_BULLET];
extern int bullet_triangle_index;
extern Bullet_Straight bullet_level[3][NUMBER_BULLET * 25];
extern int bullet_level_index[3];
/// <summary>
/// Ennemies
/// </summary>
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
/// <summary>
/// Bullet Ennemies
/// </summary>
extern Bullet_Straight  bullet_ennemies_A[NUMBER_BULLET];
extern Bullet_Straight  bullet_ennemies_B[NUMBER_BULLET][3];
extern Bullet_Straight  bullet_ennemies_C[NUMBER_BULLET][4];
extern Bullet_Straight  bullet_ennemies_D[NUMBER_BULLET];
extern Bullet_Straight  bullet_ennemies_E[NUMBER_BULLET];
extern int bullet_ennemies_A_index;
extern int bullet_ennemies_B_index;
extern int bullet_ennemies_C_index;
extern int bullet_ennemies_D_index;
extern int bullet_ennemies_E_index;
/// <summary>
/// Bullet Ennemies
/// </summary>
extern Item item[NUMBER_ITEM];
extern int item_index;
extern Item item_example[20];
/// <summary>
/// map
/// </summary>
extern int MAP;
extern string map[NUMBER_MAX_HEIGHT][NUMBER_MAX_WIDTH];
extern Uint32 currentime;
extern Uint32 distimewave;
extern Uint32 timewave;

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern SDL_Surface* surface;
extern SDL_Texture* texture;
/// <summary>
/// music
/// </summary>
extern Mix_Music* home_screen_music;
extern Mix_Music* fight_screen_music;
extern Mix_Chunk* chunk_mouse;
extern Mix_Chunk* chunk_shoot;
extern Mix_Chunk* chunk_explode1;
extern Mix_Chunk* chunk_explode2;
extern Mix_Chunk* chunk_item;
extern Mix_Chunk* chunk_gameover;
#endif