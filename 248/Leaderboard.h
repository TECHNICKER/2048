#pragma once


struct Leaderboard_entry {
	char name[16];
	int score;
};

int draw_leaderboard();

int leaderboard_append(char name[], int score);

