#include "Boom.h"
#include "Declaration.h"
void Boom :: RenderWarning() {
		warning.render();
		SDL_Rect a;
		warning_around_dem = (warning_around_dem+1) % 51;
		if (warning_around_dem % 50 == 0) {
			warning_around[thwarning_around].exist = true;
			warning_around[thwarning_around].ratio = 0.4;
			warning_around[thwarning_around].alpha = 255;
			thwarning_around++;
			if (thwarning_around == 5) {
				thwarning_around = 0;
			}
		}
		for (int i = 0; i < 5; i++) {
			if (warning_around[i].exist == true) {
				warning_around[i].renderRatio();
				if (warning_around[i].ratio < 1) {
					warning_around[i].ratio += 3*0.6 / 254;
					warning_around[i].alpha-=3;
				}
				else {
					warning_around[i].exist = false;
				}
			}
		}
}
void Boom::RenderExplode() {
	    explode.renderRatio();
		explode.ratio += 0.02;
		if (explode.ratio >= 1) {
			exist = false;
			explode_bool = false;
			explode.ratio = 0.0;
		}
}
void Boom::SetBoom() {
	warning.center_x = player.center_x ;
	warning.center_y = player.center_y ;
	explode.center_x = player.center_x ;
	explode.center_y = player.center_y ;
	for (int i = 0; i < 5; i++) {
		warning_around[i].center_x = player.center_x ;
		warning_around[i].center_y = player.center_y ;
	}
}
