#include "248.h"
#include <Windows.h>
#include <Math.h>
#include <stdlib.h.>


int gametrix[4][4] = {
						{2, 0, 2, 2},
						{0, 2, 2, 2},
						{0, 2, 0, 2},
						{2, 0, 0, 2},
					 };

//find movable blocks in desired direction -> return list of pairs of coords
//find if said blocks are mergible with the closest block in the direction of play ->
//??return list of pairs of values, a = further most taken coord, b = further most free coord if not mergible with a or a if mergible
//merge said blocks

void draw(void)
{
	int largest_tile = 0;
	int curr_tile_length = 0;
	int scale = 0;

	system("cls");

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
			printf("%d", gametrix[y][x]);

			(gametrix[y][x] > 0) ? (curr_tile_length = floor(log10(abs(gametrix[y][x]))) + 1) : (curr_tile_length = 1);

			for (int spacer = 0; spacer < (scale - curr_tile_length + 1); spacer++)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void merge(char dir)
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
		for (int y = 3; y >= 0; y--)
		{
			for (int x = 0; x < 4; x++)
			{
				if (gametrix[y][x] == gametrix[y - 1][x] && (gametrix[y][x] * 2 != temptrix[y][x]))
				{
					temptrix[y - 1][x] = gametrix[y][x] * 2;
					temptrix[y][x] = -1; //MARK WHERE MERGED FROM
				}
			}
		}
		//

		//MOVE MERGED IF ZEROS INBETWEEN
		/*for (int i = 0; i < 3; i++)
		{
			for (int y = 0; y < 3; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					if (temptrix[y][x] == 0)
					{
						temptrix[y][x] = temptrix[y + 1][x];
						temptrix[y + 1][x] = 0;
					}
				}
			}
		}*/

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
						gametrix[y][x] = gametrix[y + 1][x];
						gametrix[y + 1][x] = 0;
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
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (gametrix[y][x] == gametrix[y + 1][x] && (gametrix[y][x] * 2 != temptrix[y][x]))
				{
					temptrix[y + 1][x] = gametrix[y][x] * 2;
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
						gametrix[y][x] = gametrix[y - 1][x];
						gametrix[y - 1][x] = 0;
					}
				}
			}
		}

		break;

	case 'L':

		break;

	case 'R':

		break;
	}

	
}

int main()
{
	bool up_prev = false;
	bool down_prev = false;
	bool left_prev = false;
	bool right_prev = false;

	draw();

	while (1)
	{
		if (GetKeyState(VK_UP) & 0x8000)
		{
			if (up_prev == false)
			{

				merge('U');
				draw();

				up_prev = true;
			}
		}
		else
		{
			up_prev = false;
		}

		if (GetKeyState(VK_DOWN) & 0x8000)
		{
			if (down_prev == false)
			{
				merge('D');
				draw();

				down_prev = true;
			}
		}
		else
		{
			down_prev = false;
		}

		if (GetKeyState(VK_LEFT) & 0x8000)
		{
			if (left_prev == false)
			{
				merge('L');
				draw();

				left_prev = true;
			}
		}
		else
		{
			left_prev = false;
		}

		if(GetKeyState(VK_RIGHT) & 0x8000)
		{
			if (right_prev == false)
			{
				merge('R');
				draw();

				right_prev = true;
			}
		}
		else
		{
			right_prev = false;
		}
	}

	return 0;
}
