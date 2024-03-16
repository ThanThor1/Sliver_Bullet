#include "Declaration.h"



Object Heart[3];
Object BackGround;
SDL_Window* gWindow;
SDL_Renderer* gRenderer;
Player player;
Ennemies boss1;
// quái thi thoảng bắn lung tung;
Ennemies ennemies_1[1000];
Ennemies ennemies_2[1000];
Ennemies ennemies_3[1000];
Ennemies ennemies_4[1000];

bool wave_1 = true;
bool wave_2 = true;