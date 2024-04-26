#pragma once
#ifndef ENNEMIES_TYPEE_H
#define ENNEMIES_TYPEE_H

#include "Ennemies.h"
class Ennemies_typeE : public Ennemies
{
public:
	int score = 15;
	int load_reborn_time = 0;
	int  load_bullet_ennemies_E_time = 0;
	int direction = 1;
	int health = HEALTH_ENNEMIES_E;
	bool checkExist();
	// di chuyển 
	void moveEnnemies();
	void free();
	//sạc đạn
	void loadShoot();

};
#endif
