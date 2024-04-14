
#ifndef ENNEMIES_TYPEC_H
#define ENNEMIES_TYPEC_H

#include "Ennemies.h"
class Ennemies_typeC : public Ennemies
{
public:
	int load_bullet_ennemies_C_time = 0;
	double speed = 1;
	bool turning = false;
	int health = 10;
	bool checkExist();
	// di chuyển 
	void moveEnnemies();
	void free();
	//sạc đạn
	void loadShoot();
	//bắn
	bool loadFromFile(string path);
};

#endif