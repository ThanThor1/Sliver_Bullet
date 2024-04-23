#pragma once
#include "Ennemies.h"
class Boss : public Ennemies
{
public:
	bool star_bool = false;
	int star_dem_time = 0;
	int direction_rotation_lazer = 1;
	bool start_dem_time = false;
	double bullet_level_ratio[3];
	bool  bool_load_bullet_level[3];
	double angle_first_mini_boss = 0 ;
	bool lazer_shoot_bool = false;
	int R_mini_boss = 100;
	int load_lazer_time;
	int load_turn_fight = 0;
	int load_bullet_round_time = 0;
	int load_bullet_level_time=0;
	int load_boom_time = 0;
	int direction = 1;
	int health = 1000;
	bool checkExist();
	// di chuyển 
	void moveEnnemies();
	void free();
	//sạc đạn
	void loadShoot();
	//
	bool loadFromFile(string path);
	//
	void RenderMiniBoss();
};


