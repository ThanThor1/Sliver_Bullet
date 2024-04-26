#ifndef ENNEMIES_TYPED_H
#define ENNEMIES_TYPED_H

#include "Ennemies.h"
class Ennemies_typeD : public Ennemies
{
public:
	int score = 15;
	int load_reborn_time = 0;
	int load_bullet_ennemies_D_time = 0;
	int direction = 1;
	int health = HEALTH_ENNEMIES_D;
	bool checkExist();
	// di chuyển 
	void moveEnnemies();
	void free();
	//sạc đạn
	void loadShoot();
	//bắn
};

#endif