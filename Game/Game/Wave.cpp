
#include "Wave.h"
#include "Declaration.h"
#include "RenewAll.h"
#include "LoadAll.h"
void Wave() {
	currentime = SDL_GetTicks();
	if (loadmap_bool == false) {
		loadAllMap();
		loadmap_bool = true;
	}
	bool win = false;
	cout << MAP << endl;
	win = checkWin();
	if (MAP < 7) {
		if (win == true) {
			if (currentime >= timewave) {
				
				wave_number++;
				MAP++;
				loadmap_bool = false;
				renewAllEnnemies();
				number_ennemies_A = number_ennemies_B = number_ennemies_C = number_ennemies_D = number_ennemies_E = 0;
			}
		}
	}
	else timewave = currentime + distimewave;
	RenderBullet();
	RenderItem();
}
bool checkWin() {
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
	for (int i = 1; i <= number_ennemies_E; i++) {
		win = win * !ennemies_E[i].checkExist();
	}
	if (MAP == 7) {
		win = win * !boss.checkExist();
	}
	return win;
}
void RenderBullet() {
	for (int j = 0; j < NUMBER_BULLET; j++) {
		if (bullet_ennemies_A[j].exist == true) {
			bullet_ennemies_A[j].RenderBullet_StraightAngle();
		}
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		for (int k = 0; k < 3; k++) {
			if (bullet_ennemies_B[j][k].exist == true) {
				bullet_ennemies_B[j][k].RenderBullet_StraightAngle();
			}
		}
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		for (int k = 0; k < 4; k++) {
			if (bullet_ennemies_C[j][k].exist == true) {
				bullet_ennemies_C[j][k].RenderBullet_StraightAngle();
			}
		}
	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		if (bullet_ennemies_D[j].exist == true) {
			bullet_ennemies_D[j].RenderBullet_FollowSlope();
		}

	}
	for (int j = 0; j < NUMBER_BULLET; j++) {
		if (bullet_ennemies_E[j].exist == true) {
			bullet_ennemies_E[j].RenderBullet_StraightAngle();
		}
	}
	for (int k = 0; k < NUMBER_BULLET; k++) {
		if (bullet_triangle[k].exist == true) {
			if (bullet_triangle[k].bullet_virtual.exist == true) {
				bullet_triangle[k].bullet_virtual.RenderBullet_StraightAngle();
			}
			bullet_triangle[k].RenderBullet_Triangle();
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < NUMBER_BULLET * 25; j++) {
			if (bullet_level[i][j].exist == true) {
				bullet_level[i][j].RenderBullet_StraightAngle();
			}
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++) {
			if (boom[i].explode_bool == true) {
				boom[i].RenderExplode();
			}
			if (boom[i].warning_bool == true) {
				boom[i].RenderWarning(); 
			}
	}
	for (int i = 0; i < 1000; i++) {
		if (star[i].exist == true) {
			star[i].RenderBullet_StraightAngle();
		}
	}
	for (int i = 0; i < NUMBER_BULLET; i++) {
		for (int j = 0; j <= 6; j++) {
			if (bullet_x7[i][j].exist == true) {
				bullet_x7[i][j].RenderBullet_StraightAngle();
			}
		}
	}
}
void RenderItem() {
	for (int i = 0; i < NUMBER_ITEM; i++) {
		item[i].Render_Item();
	}
}
