
#include "Wave1.h"
#include "Declaration.h"
#include "LoadAll.h"
void Wave1() {
	if (loadmap_bool == false) {
		MAP = WAVE_1;
		loadAllMap();
		loadmap_bool = true;
	}
	/*cout << number_ennemies_A << "    " << number_ennemies_B << "   " << number_ennemies_C<<endl;*/
	for (int i = 1; i <= number_ennemies_A; i++) {
		ennemies_A[i].checkExist();
	}
	for (int i = 1; i <= number_ennemies_B; i++) {
		ennemies_B[i].checkExist();
	}
	for (int i = 1; i <= number_ennemies_C; i++) {
		ennemies_C[i].checkExist();
	}
}