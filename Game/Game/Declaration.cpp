#include "Declaration.h"

bool loadmap_bool = false;
bool sound_bool = true;
bool music_bool = true;
int screen_status = HOME;
bool prepare_to_press_pause = false;
bool nhanchuot = false;
/// <summary>
/// 
/// </summary>

int now_x = 0;
int now_y = 0;
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
Object gameover;
Object start;
/// <summary>
/// 
/// </summary>
Player player;
Ennemies boss1;
Ennemies_typeA ennemies_A[NUMBER_ENNEMIES];
Ennemies_typeB ennemies_B[NUMBER_ENNEMIES];
Ennemies_typeC ennemies_C[NUMBER_ENNEMIES];
Ennemies_typeD ennemies_D[NUMBER_ENNEMIES];
Ennemies_typeE ennemies_E[NUMBER_ENNEMIES];
int number_ennemies_A = 0;
int number_ennemies_B = 0;
int number_ennemies_C = 0;
int number_ennemies_D = 0; 
int number_ennemies_E = 0;
Bullet_Straight  bullet_ennemies_A[NUMBER_BULLET];
Bullet_Straight  bullet_ennemies_B[NUMBER_BULLET][3];
Bullet_Straight  bullet_ennemies_C[NUMBER_BULLET][4];
Bullet_Straight  bullet_ennemies_D[NUMBER_BULLET];
Bullet_Straight  bullet_ennemies_E[NUMBER_BULLET];
int bullet_ennemies_A_index = 0;
int bullet_ennemies_B_index = 0;
int bullet_ennemies_C_index = 0;
int bullet_ennemies_D_index = 0;
int bullet_ennemies_E_index = 0;
Item item[100];
int item_index = 0;
Item item_example[20];
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
Mix_Chunk* chunk_mouse;
Mix_Chunk* chunk_shoot;
Mix_Chunk* chunk_explode1;
Mix_Chunk* chunk_explode2;

UINT32 currentime = 0;
UINT32 distimewave = 3000;
UINT32 timewave =0;

Object support_1;
Object support_2;