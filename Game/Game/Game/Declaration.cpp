#include "Declaration.h"

bool sound_bool = true;
bool music_bool = true;
int screen_status = FIGHT;
bool prepare_to_press_pause = false;
bool nhanchuot = false;
/// <summary>
/// 
/// </summary>
int x = 0;
int y = 0;
int pre_x=0;
int pre_y=0;
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
SDL_Window* gWindow;
SDL_Renderer* gRenderer;
SDL_Surface* surface;
SDL_Texture* texture;
/// <summary>
/// 
/// </summary>
Player player;
Ennemies boss1;
Ennemies ennemies_1[1000];
Ennemies ennemies_2[1000];
Ennemies ennemies_3[1000];
Ennemies ennemies_4[1000];
/// <summary>
/// 
/// </summary>
bool wave_1 = true;
bool wave_2 = true;
///
//
///