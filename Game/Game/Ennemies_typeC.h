
#ifndef ENNEMIES_TYPEC_H
#define ENNEMIES_TYPEC_H

#include "Ennemies.h"
class Ennemies_typeC : public Ennemies
{
public:
	int score = 20;
	int load_bullet_ennemies_C_time = 0;
	bool turning = false;
	int health = HEALTH_ENNEMIES_C;
	bool inscreen = false;
	bool checkExist();
	// di chuyển 
	void moveEnnemies();
	void free();
	//sạc đạn
	void loadShoot();
};

#endif