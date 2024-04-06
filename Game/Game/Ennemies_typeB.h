
#ifndef ENNEMIES_TYPEB_H
#define ENNEMIES_TYPEB_H

#include "Ennemies.h"
class Ennemies_typeB : public Ennemies
{
public:
	Bullet bullet_x3[NUMBER_BULLET][3];
	int thbullet_x3 = 0;
	int load_bullet_x3_time = 0;
	double speed = 1;
	int direction = 1;
	int health = 10;
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