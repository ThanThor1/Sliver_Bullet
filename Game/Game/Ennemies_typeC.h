
#ifndef ENNEMIES_TYPEC_H
#define ENNEMIES_TYPEC_H

#include "Ennemies.h"
class Ennemies_typeC : public Ennemies
{
public:
	Bullet bullet_x4[NUMBER_BULLET][4];
	int thbullet_x4 = 0;
	int load_bullet_x4_time = 0;
	double speed = 1;
	bool turning = false;
	void checkExist();
	// di chuyển 
	void moveEnnemies();
	void free();
	//sạc đạn
	void loadShoot();
	//bắn
	void shoot();
};

#endif