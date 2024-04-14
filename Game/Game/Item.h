#pragma once
#include "Object.h"
class Item : public Object
{
public:
	int buff_type = 0;
	void loadCoordinates(int x1, int y1, int width1, int height1 );
	void Render_Item();
};

