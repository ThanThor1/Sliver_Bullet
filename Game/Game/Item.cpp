#include "Item.h"
void Item::loadCoordinates(int x1, int y1, int width1, int height1) {
	x = x1+ width1/2- width/2;
	y = y1 + height1 / 2 - height / 2;
}
void Item::Render_Item() {
	if (exist == true) {
		y++; 
		if (y >1200) {
			exist = false;
		}
		render(x,y);
	}
}