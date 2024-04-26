#include "RenderScreen.h"
#include "Declaration.h"
void loadFightBackGround() {
	fight_screen_background.renderbackground();
	if (pre_x >= pause_button.center_x && pre_y >= pause_button.center_y && pre_x <= (pause_button.center_x + pause_button.width) && pre_y <= (pause_button.center_y + pause_button.height)) {
		pause_button.width = 48;
		pause_button.height = 63;
		prepare_to_press_pause = true;
	}
	else {
		pause_button.width = 31;
		pause_button.height = 51;
		prepare_to_press_pause = false;
	}
	pause_button.render();
	for (int i = 0; i <= 2; i++) {
		if (i >= player.number_of_hearts) {
			Heart[i].alpha = 100;
		}
		else Heart[i].alpha = 255;
		Heart[i].render();
	}
	fight_screen_score.center_x = 400;
	fight_screen_score.center_y = 70;
	fight_screen_score.render();
	score_fight_screen_text.loadText((": " + to_string(score_number)).c_str(), 490, 65);
}

void loadPauseScreen() {
	SDL_RenderClear(gRenderer);
	SDL_Rect rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	SDL_RenderCopy(gRenderer, texture, NULL, &rect);
	pause_background.render();
	pause_screen_continue.render();
	pause_screen_home.render();
	pause_screen_sensitivity_down.render();
	pause_screen_sensitivity_up.render();
	if (music_bool == true) {
		pause_screen_music_pause.render();
	}
	else {
		pause_screen_unmusic_pause.render();
	}
	if (sound_bool == true) {
		pause_screen_sound_pause.render();
	}
	else { pause_screen_unsound_pause.render(); }

	pause_screen_sensitivity[player.sensitivity_index].render();
	SDL_RenderPresent(gRenderer);
}
void loadFightScreen() {
	SDL_RenderClear(gRenderer);
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	loadFightBackGround();
	if (fight_screen_start.exist == false) {
		fight_screen_start.center_x = SCREEN_WIDTH / 2;
		fight_screen_start.center_y = SCREEN_HEIGHT / 2;
		if (fight_screen_start.ratio <= 1) {
			fight_screen_start.renderRatio();
		}
		else {
			fight_screen_start.render();
		}
		fight_screen_start.ratio += 0.0025;
		if (fight_screen_start.ratio >= 2) {
			fight_screen_start.exist = true;
		}
	}
	else {
		Wave();
	}
	if (boss.health <= 0) {
		you_win.loadText("YOU WIN !!!!", 100, 400);
		you_win.photo++;
		if (you_win.photo == 300) {
			screen_status = GAMEOVER;
		}
	}
	player.loadFrame();
	SDL_RenderPresent(gRenderer);
}
void loadHomeScreen() {
	SDL_RenderClear(gRenderer);
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	fight_screen_background.renderbackground();
	home_background.render();
	home_screen_option.render();
	home_screen_credit.render();
	home_screen_press_start.dem1 = (home_screen_press_start.dem1 + 1) % 5;
	home_screen_press_start.dem2 = (home_screen_press_start.dem2 + home_screen_press_start.dem1 / 4) % 30;
	if (home_screen_press_start.dem2 <= 29 && home_screen_press_start.dem2 >= 10) {
		home_screen_press_start.render();
	}
	SDL_RenderPresent(gRenderer);
}
void loadGameoverScreen() {
	SDL_RenderClear(gRenderer);
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	Mix_PauseMusic();
	gameover_screen_background.render();
    if (score_gameover_menu_screen_text.start_count < score_number) {
		score_gameover_menu_screen_text.photo = (score_gameover_menu_screen_text.photo + 1) ;
		if (score_gameover_menu_screen_text.photo % 21 == 0 && score_gameover_menu_screen_text.photo > 120) {
			if (score_number - score_gameover_menu_screen_text.start_count > score_number / 20  && score_number / 20 !=0) {
				score_gameover_menu_screen_text.start_count += score_number / 20;
			}
			else {
				score_gameover_menu_screen_text.start_count += score_number - score_gameover_menu_screen_text.start_count;
			}
			Mix_PlayChannel(-1, chunk_gameover, 0);
		}
	}
	else if (wave_number_gameover_screen_text.start_count < wave_number) {
		wave_number_gameover_screen_text.photo = (wave_number_gameover_screen_text.photo + 1) ;
		if (wave_number_gameover_screen_text.photo % 21 == 0  && wave_number_gameover_screen_text.photo > 120) {
			if (wave_number - wave_number_gameover_screen_text.start_count > wave_number / 2 && wave_number / 2 !=0) {
				wave_number_gameover_screen_text.start_count += wave_number / 2;
			}
			else {
				wave_number_gameover_screen_text.start_count += wave_number - wave_number_gameover_screen_text.start_count;
			}
			Mix_PlayChannel(-1, chunk_gameover, 0);
		}
	}
	else if (aliens_defeated_gameover_screen_text.start_count < aliens_defeated_number) {
		aliens_defeated_gameover_screen_text.photo = (aliens_defeated_gameover_screen_text.photo + 1) ;
		if (aliens_defeated_gameover_screen_text.photo % 21 == 0 && aliens_defeated_gameover_screen_text.photo > 120) {
			if (aliens_defeated_number - aliens_defeated_gameover_screen_text.start_count > aliens_defeated_number / 5 && aliens_defeated_number / 5 !=0) {
				aliens_defeated_gameover_screen_text.start_count += aliens_defeated_number / 5;
			}
			else {
				aliens_defeated_gameover_screen_text.start_count += aliens_defeated_number - aliens_defeated_gameover_screen_text.start_count;
			}
			Mix_PlayChannel(-1, chunk_gameover, 0);
		}
	}
	aliens_defeated_gameover_screen_text.loadText((to_string(aliens_defeated_gameover_screen_text.start_count)).c_str(), 530, 590);
	wave_number_gameover_screen_text.loadText((to_string(wave_number_gameover_screen_text.start_count)).c_str(), 530, 460);
	score_gameover_menu_screen_text.loadText((to_string(score_gameover_menu_screen_text.start_count)).c_str(), 530, 330);
	if (boss.health>0) {
		gameover_screen_home.render();
	}
	else {
		gameover_screen_win.render();
	}
	SDL_RenderPresent(gRenderer);
}
void loadWarningScreen() {
	SDL_RenderClear(gRenderer);
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_Rect rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	SDL_RenderCopy(gRenderer, texture, NULL, &rect);
	warning_screen_background.render();
	warning_screen_yes.render();
	warning_screen_no.render();
	SDL_RenderPresent(gRenderer);
}
void loadCreditScreen() {
	
}
void loadOptionScreen() {
	SDL_RenderClear(gRenderer);
	fight_screen_background.renderbackground();
	option_background.render();
	option_screen_continue.render();
	option_screen_sensitivity_down.render();
	option_screen_sensitivity_up.render();
	if (music_bool == true) {
		option_screen_music_pause.render();
	}
	else {
		option_screen_unmusic_pause.render();
	}
	if (sound_bool == true) {
		option_screen_sound_pause.render();
	}
	else { option_screen_unsound_pause.render(); }
	option_screen_sensitivity[player.sensitivity_index].render();
	SDL_RenderPresent(gRenderer);
}
void loadCreditGame() {
	SDL_RenderClear(gRenderer);
	SDL_Rect a = {0, 0, SCREEN_WIDTH,  SCREEN_HEIGHT };
	SDL_Rect b = { 0, credit_win_screen.height - SCREEN_HEIGHT, SCREEN_WIDTH,  SCREEN_HEIGHT };
	if (credit_win_screen.photo/2 <= (credit_win_screen.height - SCREEN_HEIGHT)) {
		b = { 0, credit_win_screen.photo/2, SCREEN_WIDTH,  SCREEN_HEIGHT};
	}
	credit_win_screen.photo =( credit_win_screen.photo+1) % 1000000;
	if (credit_win_screen.photo == 3400) {
		screen_status = HOME;
	}
	credit_win_screen.renderFlexible(&b, &a);
	SDL_RenderPresent(gRenderer);

}