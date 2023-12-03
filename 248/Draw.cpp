#pragma once

#include <iostream>
#include "Draw.h"


void draw(char name[16], int score, int gametrix[4][4])
{
	int largest_tile = 0;
	int curr_tile_length = 0;
	int scale = 0;

	system("cls");

	printf("\033[0m");
	printf("%s\n", name);
	printf("score: %d\n", score);

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (largest_tile < gametrix[y][x]) { largest_tile = gametrix[y][x]; }
		}
	}

	(largest_tile > 0) ? (scale = floor(log10(abs(largest_tile))) + 1) : (scale = 1);

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			switch (gametrix[y][x])
			{
			case 0:

				printf("\033[1;30m");
				printf("%d", gametrix[y][x]);

				break;

			case 2:

				printf("\033[1;33m");
				printf("%d", gametrix[y][x]);

				break;

			case 4:

				printf("\033[0;33m");
				printf("%d", gametrix[y][x]);

				break;

			case 8:

				printf("\033[1;32m");
				printf("%d", gametrix[y][x]);

				break;

			case 16:

				printf("\033[0;32m");
				printf("%d", gametrix[y][x]);

				break;

			case 32:

				printf("\033[1;36m");
				printf("%d", gametrix[y][x]);

				break;

			case 64:

				printf("\033[1;34m");
				printf("%d", gametrix[y][x]);

				break;

			case 128:

				printf("\033[0;34m");
				printf("%d", gametrix[y][x]);

				break;

			case 256:

				printf("\033[1;35m");
				printf("%d", gametrix[y][x]);

				break;

			case 512:

				printf("\033[0;35m");
				printf("%d", gametrix[y][x]);

				break;

			case 1024:

				printf("\033[1;31m");
				printf("%d", gametrix[y][x]);

				break;

			case 2048:

				printf("\033[0;31m");
				printf("%d", gametrix[y][x]);

				break;

			default:

				printf("\033[0m");
				printf("%d", gametrix[y][x]);

				break;

			}

			(gametrix[y][x] > 0) ? (curr_tile_length = floor(log10(abs(gametrix[y][x]))) + 1) : (curr_tile_length = 1);

			for (int spacer = 0; spacer < (scale - curr_tile_length + 1); spacer++)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void draw_menu(int menu)
{
	system("cls");

	switch (menu)
	{
	case 0:

		printf("\033[1;31m");
		printf("New Game\n");
		printf("\033[0m");
		printf("Resume\nLeaderboards\n");

		break;

	case 1:

		printf("\033[0m");
		printf("New Game\n");
		printf("\033[1;31m");
		printf("Resume\n");
		printf("\033[0m");
		printf("Leaderboards\n");

		break;

	case 2:

		printf("\033[0m");
		printf("New Game\n");
		printf("Resume\n");
		printf("\033[1;31m");
		printf("Leaderboards\n");
		printf("\033[0m");

		break;

	}
}