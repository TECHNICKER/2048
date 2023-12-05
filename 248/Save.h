#pragma once
#include "Leaderboard.h"


struct Gamestate {
	Leaderboard_entry gameinfo;
	int gametrix[4][4];
};

int save(Gamestate game);

int load(Gamestate game);