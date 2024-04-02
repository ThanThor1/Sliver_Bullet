#ifndef ENNEMIES_TYPED_H
#define ENNEMIES_TYPED_H

#include "Ennemies.h"
class Ennemies_typeD : public Ennemies
{
public:
	Bullet bullet_follow[NUMBER_BULLET];
	int thbullet_follow = 0;
	int load_bullet_follow_time = 0;
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
	//
	int checkDistance(Bullet &a);
};

#endif