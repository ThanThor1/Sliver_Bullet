#pragma once
#include "Ennemies.h"
class Boss : public Ennemies
{
public:
	int score= 1000000;
	int load_turn_fight = 0;
	// star
	bool star_bool = false;
	int star_dem_time = 0;
	//bullet_level
	bool start_load_shoot_bullet_level_time = false;
	double bullet_level_ratio[3];
	bool  bool_load_bullet_level[3];
	int load_bullet_level_time = 0;
	double angle_first_mini_boss = 0;
	int R_mini_boss = 100;
	// lazer
	bool lazer_shoot_bool = false;
	int load_lazer_time;
	int direction_rotation_lazer = 1;
	// bullet_triangle
	int load_bullet_triangle_time = 0;
	// boom
	int load_boom_time = 0;
	int health = 1000;

	bool checkExist();
	// di chuyển 
	void moveEnnemies();
	void free();
	//sạc đạn
	void loadShoot();
	void RenderMiniBoss();
};


