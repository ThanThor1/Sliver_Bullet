#pragma once
#include"Library.h"
#include"SomeConst.h"
#include "Wave.h"
void loadAll();  // bao gồm 5 cái dươi
void loadAllEnnemies();
void loadAllPlayer();
void loadAllIcon();
void loadAllSound();
void loadAllMap();
void loadAllItem();
//
//
//
void renewAll();  // bao gồm 2 cái dưới
void renewAllPlayer();
void renewAllBullet();
void renewAllItem();
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