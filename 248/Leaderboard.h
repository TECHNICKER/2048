#pragma once


struct Leaderboard_entry {
	char name[16];
	int score;
};

void draw_leaderboard();

void leaderboard_append(Leaderboard_entry gameinfo);

