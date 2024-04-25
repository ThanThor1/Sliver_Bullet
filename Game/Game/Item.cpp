#include "Item.h"
void Item::Render_Item() {
	if (exist == true) {
		center_y++;
		if (center_y > 1200){
			exist = false;
		}
		render();
	}
}