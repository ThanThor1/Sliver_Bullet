#include "Declaration.h"
Bullet_Straight bullet_x7[NUMBER_BULLET][7];
/// <summary>
/// some_bool
/// </summary>
bool loadmap_bool = false;
bool sound_bool = true;
bool music_bool = true;
bool prepare_to_press_pause = false;
bool nhanchuot = false;
int screen_status = HOME;
string wave_path= "wave//wave";
/// <summary>
/// location of mouse
/// </summary>
int now_x = 0;
int now_y = 0;
int pre_x = 0;
int pre_y = 0;
int pause_x = 0;
int pause_y = 0;
int home_x = 0;
int home_y = 0;
int gameover_x = 0;
int gameover_y = 0;
int warning_x = 0;
int warning_y = 0;
int option_x=0;
int option_y=0;
int credit_x=0;
int credit_y=0;
/// <summary>
/// icon
/// </summary>
/// icon in home
Object home_background;
Object home_screen_press_start;
Object home_screen_option;
Object home_screen_credit;
// icon in pause
Object pause_screen_continue;
Object pause_screen_home;
Object pause_screen_sensitivity_down;
Object pause_screen_sensitivity_up;
Object pause_screen_sensitivity[3];
Object pause_screen_sound_pause;
Object pause_screen_unsound_pause;
Object pause_screen_unmusic_pause;
Object pause_screen_music_pause;
Object pause_background;
Object pause_button;
// icon in option
Object option_screen_continue;
Object option_screen_sensitivity_down;
Object option_screen_sensitivity_up;
Object option_screen_sensitivity[3];
Object option_screen_sound_pause;
Object option_screen_unsound_pause;
Object option_screen_unmusic_pause;
Object option_screen_music_pause;
Object option_background;
Object option_button;
// icon in fight
Text you_win;
Object fight_screen_background;
Object fight_screen_gameover;
Object fight_screen_start;
Object fight_screen_score;
Text score_fight_screen_text;
Object Heart[3];
int wave_number = 0;
int score_number = 0;
int aliens_defeated_number= 0;
// icon in game over
Object gameover_screen_background;
Object gameover_screen_home;
Object gameover_screen_win;
Text wave_number_gameover_screen_text;
Text score_gameover_menu_screen_text;
Text aliens_defeated_gameover_screen_text;
// icon in warning
Object warning_screen_background;
Object warning_screen_yes;
Object warning_screen_no;
// icon in credit
Object credit_win_screen;
/// <summary>
/// Player
/// </summary>
Player player;
Object support_1;
Object support_2;
/// <summary>
/// boss
/// </summary>
Boss boss;
Object health_boss;
Object health_boss_background;
Object mini_boss_center_1;
Object staff_mini_boss_1;
Object mini_boss_center_2;
Object lazer[2];
Object head_lazer[2];
Object lazer_warning_red[2];
Object lazer_warning_green[2];

int bullet_around_boss_index =0;
Bullet_Straight bullet_around_boss[NUMBER_BULLET];
Boom boom[NUMBER_BULLET];
int boom_index = 0;
int star_coordinates[100][3];
Bullet_Straight star[1000];
int star_index = 0;
Bullet_Triangle bullet_triangle[NUMBER_BULLET];
int bullet_triangle_index = 0;
Bullet_Straight bullet_level[3][NUMBER_BULLET * 25];
int bullet_level_index[3];
/// <summary>
/// Ennemies
/// </summary>
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
/// <summary>
/// Bullet Ennemies
/// </summary>
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
/// <summary>
/// Bullet Ennemies
/// </summary>
Item item[NUMBER_ITEM];
int item_index = 0;
Item item_example[20];
/// <summary>
/// map
/// </summary>
int MAP = 1;
string map[NUMBER_MAX_HEIGHT][ NUMBER_MAX_WIDTH] = {};
UINT32 currentime = 0;
UINT32 distimewave = 3000;
UINT32 timewave = 0;

SDL_Window* gWindow;
SDL_Renderer* gRenderer;
SDL_Surface* surface;
SDL_Texture* texture;
/// <summary>
/// music
/// </summary>
Mix_Music* home_screen_music;
Mix_Music* fight_screen_music;
Mix_Chunk* chunk_mouse;
Mix_Chunk* chunk_shoot;
Mix_Chunk* chunk_explode1;
Mix_Chunk* chunk_explode2;
Mix_Chunk* chunk_item;
Mix_Chunk* chunk_gameover;







