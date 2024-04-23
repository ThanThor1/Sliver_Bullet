#pragma once
#include "Object.h"
class Boom : public Object
{
public:
	bool explode_bool = 0;
	bool warning_bool = 0;
	Object warning;
	Object explode;
	Object warning_around[5];
	int thwarning_around = 0;
	int warning_around_dem = 0;
	void RenderExplode();
	void RenderWarning();
	void SetBoom();
};

