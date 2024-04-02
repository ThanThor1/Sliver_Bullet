#ifndef ENNEMIES_TYPEA_H
#define ENNEMIES_TYPEA_H

#include "Ennemies.h"
class Ennemies_typeA : public Ennemies
{
public:
	Bullet bullet_simple[NUMBER_BULLET];
	int thbullet_simple = 0;
	int load_bullet_simple_time = 0;
	double speed = 1;
	int direction = 1;
	bool checkExist();
	// di chuyển 
	void moveEnnemies();
	void free();
	//sạc đạn
	void loadShoot();
	//bắn
	void shoot();
};

#endif