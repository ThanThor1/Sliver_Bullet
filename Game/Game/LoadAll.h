#pragma once
#include"Library.h"
#include"SomeConst.h"
#include "Wave.h"
void loadAll();  // bao gồm 5 cái dươi
void loadAllPlayer();
void loadAllEnnemies();
void loadAllIcon();
void loadAllSound();
void loadAllMap();
//
//
//
void renewAll();  // bao gồm 2 cái dưới
void renewAllPlayer();
void renewAllEnnemies();
//
//
int Rand(int a, int b);
//
void loadFightBackGround();
void loadPauseButton();
void loadPauseScreen();
void loadFightScreen();
void loadHomeScreen();