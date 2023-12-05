#pragma once

#include <iostream>
#include "Gamelogic.h"


void merge(char dir, int *score, int gametrix[4][4])
{
	int temptrix[4][4] = {
							{0, 0, 0, 0},
							{0, 0, 0, 0},
							{0, 0, 0, 0},
							{0, 0, 0, 0},
	};

	switch (dir)
	{
	case 'U':

		//MOVE
		for (int i = 0; i < 3; i++)
		{
			for (int y = 0; y < 3; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					if (gametrix[y][x] == 0)
					{
						gametrix[y][x] = gametrix[y + 1][x];
						gametrix[y + 1][x] = 0;
					}
				}
			}
		}
		//

		//MERGE
		for (int y = 3; y > 0; y--)
		{
			for (int x = 0; x < 4; x++)
			{
				if (gametrix[y][x] == gametrix[y - 1][x] && (gametrix[y][x] * 2 != temptrix[y][x]))
				{
					temptrix[y - 1][x] = gametrix[y][x] * 2;
					score += temptrix[y - 1][x];
					temptrix[y][x] = -1; //MARK WHERE MERGED FROM
				}
			}
		}
		//


		//UPDATE GAME MATRIX FROM MERGED TILES MATRIX
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (temptrix[y][x] != 0)
				{
					gametrix[y][x] = temptrix[y][x];
				}
			}
		}

		//REMOVE MERGED FROM MARKERS AND MOVE UP
		for (int i = 0; i < 3; i++)
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					if (gametrix[y][x] == -1)
					{
						if (y == 3)
						{
							gametrix[y][x] = 0;
						}
						else {
							gametrix[y][x] = gametrix[y + 1][x];
							gametrix[y + 1][x] = 0;
						}
					}
				}
			}
		}

		break;

	case 'D':

		//MOVE
		for (int i = 0; i < 3; i++)
		{
			for (int y = 3; y > 0; y--)
			{
				for (int x = 0; x < 4; x++)
				{
					if (gametrix[y][x] == 0)
					{
						gametrix[y][x] = gametrix[y - 1][x];
						gametrix[y - 1][x] = 0;
					}
				}
			}
		}
		//

		//MERGE
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (gametrix[y][x] == gametrix[y + 1][x] && (gametrix[y][x] * 2 != temptrix[y][x]))
				{
					temptrix[y + 1][x] = gametrix[y][x] * 2;
					score += temptrix[y + 1][x];
					temptrix[y][x] = -1; //MARK WHERE MERGED FROM
				}
			}
		}
		//

		//UPDATE GAME MATRIX FROM MERGED TILES MATRIX
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (temptrix[y][x] != 0)
				{
					gametrix[y][x] = temptrix[y][x];
				}
			}
		}

		//REMOVE MERGED FROM MARKERS AND MOVE DOWN
		for (int i = 0; i < 3; i++)
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					if (gametrix[y][x] == -1)
					{
						if (y == 0)
						{
							gametrix[y][x] = 0;
						}
						else {
							gametrix[y][x] = gametrix[y - 1][x];
							gametrix[y - 1][x] = 0;
						}
					}
				}
			}
		}

		break;

	case 'L':

		//MOVE
		for (int i = 0; i < 3; i++)
		{
			for (int x = 0; x < 3; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					if (gametrix[y][x] == 0)
					{
						gametrix[y][x] = gametrix[y][x + 1];
						gametrix[y][x + 1] = 0;
					}
				}
			}
		}
		//

		//MERGE
		for (int y = 0; y < 4; y++)
		{
			for (int x = 3; x > 0; x--)
			{
				if (gametrix[y][x] == gametrix[y][x - 1] && (gametrix[y][x] * 2 != temptrix[y][x]))
				{
					temptrix[y][x - 1] = gametrix[y][x] * 2;
					score += temptrix[y][x - 1];
					temptrix[y][x] = -1; //MARK WHERE MERGED FROM
				}
			}
		}
		//

		//UPDATE GAME MATRIX FROM MERGED TILES MATRIX
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (temptrix[y][x] != 0)
				{
					gametrix[y][x] = temptrix[y][x];
				}
			}
		}

		//REMOVE MERGED FROM MARKERS AND MOVE LEFT
		for (int i = 0; i < 3; i++)
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 3; x >= 0; x--)
				{
					if (gametrix[y][x] == -1)
					{
						if (x == 3)
						{
							gametrix[y][x] = 0;
						}
						else {
							gametrix[y][x] = gametrix[y][x + 1];
							gametrix[y][x + 1] = 0;
						}
					}
				}
			}
		}

		break;

	case 'R':

		//MOVE
		for (int i = 0; i < 3; i++)
		{
			for (int x = 3; x > 0; x--)
			{
				for (int y = 0; y < 4; y++)
				{
					if (gametrix[y][x] == 0)
					{
						gametrix[y][x] = gametrix[y][x - 1];
						gametrix[y][x - 1] = 0;
					}
				}
			}
		}
		//

		//MERGE
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				if (gametrix[y][x] == gametrix[y][x + 1] && (gametrix[y][x] * 2 != temptrix[y][x]))
				{
					temptrix[y][x + 1] = gametrix[y][x] * 2;
					score += temptrix[y][x + 1];
					temptrix[y][x] = -1; //MARK WHERE MERGED FROM
				}
			}
		}
		//

		//UPDATE GAME MATRIX FROM MERGED TILES MATRIX
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (temptrix[y][x] != 0)
				{
					gametrix[y][x] = temptrix[y][x];
				}
			}
		}

		//REMOVE MERGED FROM MARKERS AND MOVE RIGHT
		for (int i = 0; i < 3; i++)
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					if (gametrix[y][x] == -1)
					{
						if (x == 0)
						{
							gametrix[y][x] = 0;
						}
						else {
							gametrix[y][x] = gametrix[y][x - 1];
							gametrix[y][x - 1] = 0;
						}
					}
				}
			}
		}

		break;
	}

}

int generate(int gametrix[4][4])
{
	struct Coords {
		int x;
		int y;
	};

	int value_chance = 0;
	int value = 0;
	Coords free[16] = {};
	int index = 0;
	int random_tile = 0;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (gametrix[y][x] == 0)
			{
				struct Coords pair;
				pair.x = x;
				pair.y = y;

				free[index] = pair;

				index += 1;
			}
		}
	}

	value_chance = (rand() % (5 - 1 + 1)) + 1;

	(value_chance < 5) ? (value = 2) : (value_chance = 4);

	switch (index)
	{
	case 0:

		return 1;
		break;

	case 1:

		random_tile = 0;
		gametrix[free[random_tile].y][free[random_tile].x] = value;
		break;

	default:

		random_tile = rand() % (index - 1);
		gametrix[free[random_tile].y][free[random_tile].x] = value;
		break;
	}

}