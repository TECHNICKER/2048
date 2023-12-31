#pragma once

#include <iostream>
#include <Windows.h>
#include <String.h>
#include "Leaderboard.h"


void draw_leaderboard()
{
	Leaderboard_entry leaderboard[10] = {};
	FILE* file;
	int longest_name = 0;

	if ((file = fopen("Leaderboard.bin", "rb")) != NULL)
	{
		fread(&leaderboard[0], sizeof(struct Leaderboard_entry), 10, file);
		fclose(file);
	}
	else
	{
		file = fopen("Leaderboard.bin", "wb");
		fwrite(&leaderboard, sizeof(struct Leaderboard_entry), 10, file);
		fclose(file);
	}

	for (int index = 0; index < 10; index++)
	{
		if (strlen(leaderboard[index].name) > longest_name) { longest_name = strlen(leaderboard[index].name); }
	}

	system("cls");

	for (int index = 0; index < 10; index++)
	{
		switch (index + 1)
		{
		case 1:
			printf("\033[1;33m");
			printf("%d. %s", index + 1, leaderboard[index].name);

			break;

		case 2:
			printf("\033[1;30m");
			printf("%d. %s", index + 1, leaderboard[index].name);

			break;

		case 3:
			printf("\033[0;33m");
			printf("%d. %s", index + 1, leaderboard[index].name);

			break;

		default:
			printf("\033[0m");
			printf("%d. %s", index + 1, leaderboard[index].name);

			break;
		}

		for (int spacer = 0; spacer < longest_name - strlen(leaderboard[index].name); spacer++)
		{
			printf(" ");
		}

		if ((index + 1) == 10)
		{
			printf("| ");
		}
		else {
			printf(" | ");
		}

		printf("%d\n", leaderboard[index].score);

	}

}

void leaderboard_append(Leaderboard_entry gameinfo)
{
	Leaderboard_entry leaderboard[10] = {};
	FILE* file;
	int index = 0;

	if ((file = fopen("Leaderboard.bin", "rb")) != NULL)
	{
		fread(&leaderboard[0], sizeof(struct Leaderboard_entry), 10, file);
		fclose(file);
	}

	while (1)
	{
		if (index > 9) { break; }

		if (index == 0)
		{

			if ((gameinfo.score > leaderboard[index + 1].score) && (gameinfo.score > leaderboard[index].score))
			{

				for (int i = 9; i > index; i--)
				{
					leaderboard[i] = leaderboard[i - 1];
				}

				leaderboard[index].score = gameinfo.score;
				strcpy(leaderboard[index].name, gameinfo.name);

				break;
			}
			else {
				index++;
			}

		}
		else {

			if ((gameinfo.score < leaderboard[index - 1].score) && (gameinfo.score > leaderboard[index + 1].score) && (gameinfo.score > leaderboard[index].score))
			{
				
				for (int i = 9; i > index; i--)
				{
					leaderboard[i] = leaderboard[i - 1];
				}

				leaderboard[index].score = gameinfo.score;
				strcpy(leaderboard[index].name, gameinfo.name);

				break;
			}
			else {
				index++;
			}
		}		
	}

	file = fopen("Leaderboard.bin", "wb");
	fwrite(&leaderboard, sizeof(struct Leaderboard_entry), 10, file);
	fclose(file);

}