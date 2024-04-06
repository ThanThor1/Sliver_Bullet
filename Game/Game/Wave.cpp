
#include "Wave.h"
#include "Declaration.h"
#include "LoadAll.h"
void Wave() {
	currentime = SDL_GetTicks();
	if (loadmap_bool == false) {
		loadAllMap();
		loadmap_bool = true;
	}
	bool win = false;
	switch (MAP) {
	   case WAVE_1:
		   win=Wave1();
		break;
	   case WAVE_2:
		   win=Wave2();
		break;
	}
	if (win == true ) {
		if (currentime >= timewave) {
			MAP++;
			loadmap_bool = false;
			renewAllEnnemies();
			number_ennemies_A = number_ennemies_B = number_ennemies_C = number_ennemies_D = 0;
		}
	}
	else timewave = currentime + distimewave;
}
bool Wave1() {
	bool win = true;
	for (int i = 1; i <= number_ennemies_A; i++) {
		win = win *!ennemies_A[i].checkExist();
	}
	for (int i = 1; i <= number_ennemies_B; i++) {
		win = win*!ennemies_B[i].checkExist();
	}
	for (int i = 1; i <= number_ennemies_C; i++) {
		win = win*!ennemies_C[i].checkExist();
	}
	for (int i = 1; i <= number_ennemies_D; i++) {
		win = win*!ennemies_D[i].checkExist();
	}
	return win;
}
bool Wave2() {
	bool win = true;
	for (int i = 1; i <= number_ennemies_A; i++) {
		win = win * !ennemies_A[i].checkExist();
	}
	for (int i = 1; i <= number_ennemies_B; i++) {
		win = win * !ennemies_B[i].checkExist();
	}
	for (int i = 1; i <= number_ennemies_C; i++) {
		win = win * !ennemies_C[i].checkExist();
	}
	for (int i = 1; i <= number_ennemies_D; i++) {
		win = win * !ennemies_D[i].checkExist();
	}
	return win;
}
