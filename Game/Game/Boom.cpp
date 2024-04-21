#include "Boom.h"
#include "Declaration.h"
void Boom :: RenderWarning() {
		warning.render(warning.center_x - warning.width / 2, warning.center_y - warning.height / 2);
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
				warning_around[i].setAlpha(warning_around[i].alpha);
				a = { int(warning_around[i].center_x - warning_around[i].width * warning_around[i].ratio * 1 / 2),  int(warning_around[i].center_y - warning_around[i].height * warning_around[i].ratio * 1 / 2), int(warning_around[i].width * warning_around[i].ratio),  int(warning_around[i].height * warning_around[i].ratio) };
				SDL_RenderCopy(gRenderer, warning_around[i].Texture, NULL, &a);
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
		SDL_Rect a = { int(explode.center_x - explode.width * explode.ratio * 1 / 2),  int(explode.center_y - explode.height * explode.ratio * 1 / 2), int(explode.width * explode.ratio),  int(explode.height * explode.ratio) };
		SDL_RenderCopy(gRenderer, explode.Texture, NULL, &a);
		explode.ratio += 0.02;
		if (explode.ratio >= 1) {
			exist = false;
			explode_bool = false;
		}
}
void Boom::SetBoom() {
	warning.center_x = player.x + player.width/2 ;
	warning.center_y = player.y + player.height / 2 ;
	explode.center_x = player.x + player.width / 2;
	explode.center_y = player.y + player.height / 2;
	for (int i = 0; i < 5; i++) {
		warning_around[i].center_x = player.x + player.width / 2;
		warning_around[i].center_y = player.y + player.height / 2;
	}
}
