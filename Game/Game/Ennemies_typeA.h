#ifndef ENNEMIES_TYPEA_H
#define ENNEMIES_TYPEA_H

#include "Ennemies.h"
class Ennemies_typeA : public Ennemies
{
public:
	int load_bullet_ennemies_A_time = 0;
	int score = 10;
	int direction = 1;
	int health = HEALTH_ENNEMIES_A;
	bool checkExist();
	// di chuyển 
	void moveEnnemies();
	void free();
	//sạc đạn
	void loadShoot();
	//
};

#endif