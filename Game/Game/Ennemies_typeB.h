
#ifndef ENNEMIES_TYPEB_H
#define ENNEMIES_TYPEB_H

#include "Ennemies.h"
class Ennemies_typeB : public Ennemies
{
public:
	int load_reborn_time = 0;
	int load_bullet_ennemies_B_time = 0;
	double speed = 1;
	int direction = 1;
	int health = 10;
	bool checkExist();
	// di chuyển 
	void moveEnnemies();
	void free();
	//sạc đạn
	void loadShoot();
};

#endif