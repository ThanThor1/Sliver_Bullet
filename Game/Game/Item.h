#pragma once
#include "Object.h"
class Item : public Object
{
public:
	int buff_type = 0;
	void Render_Item();
};

