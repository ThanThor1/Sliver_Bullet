
#ifndef ENNEMIES_TYPEB_H
#define ENNEMIES_TYPEB_H

#include "Ennemies.h"
class Ennemies_typeB : public Ennemies
{
public:
	int score = 15;
	int load_reborn_time = 0;
	int load_bullet_ennemies_B_time = 0;
	int direction = 1;
	int health = HEALTH_ENNEMIES_B;
	bool checkExist();
	// di chuyển 
	void moveEnnemies();
	void free();
	//sạc đạn
	void loadShoot();
};

#endif