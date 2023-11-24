#include "248.h"
#include <Windows.h>
#include <stdlib.h.>
#include <Math.h>

int score = 0;

int gametrix[4][4] = {
						{0, 1, 2, 64},
						{1, 512, 3, 4},
						{2, 3, 4, 5},
						{3, 4, 5, 2048},
					 };

class Block {

	private:

		int value = 0;

	public:

		Block()
		{
			//generate a block with less than 100 % chance, change block start value limit according to the highest block alive
			;
		}

		void merge()
		{
			//generate a new block (at the coordinate of the one being merged to - this prolly in main loop), make it the combination of values of the two dying blocks
			;
		}
};

//find movable blocks in desired direction -> return list of pairs of coords
//find if said blocks are mergible with the closest block in the direction of play ->
//??return list of pairs of values, a = further most taken coord, b = further most free coord if not mergible with a or a if mergible
//merge said blocks

void redraw()
{
	//printf("score: %d \n\n  %d %d %d %d \n  %d %d %d %d \n  %d %d %d %d \n  %d %d %d %d \n ", score, gametrix[0][0], gametrix[0][1], gametrix[0][2], gametrix[0][3], gametrix[1][0], gametrix[1][1], gametrix[1][2], gametrix[1][3], gametrix[2][0], gametrix[2][1], gametrix[2][2], gametrix[2][3], gametrix[3][0], gametrix[3][1], gametrix[3][2], gametrix[3][3]);
	
	int scale = 0;
	int largest_tile = 0;
	int curr_tile_len = 0;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			largest_tile = (gametrix[x][y] > largest_tile) ? gametrix[x][y] : largest_tile;
		}
	}

	if (largest_tile != 0)
	{
		scale = floor(log10(abs(largest_tile))) + 1;
	}


	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			printf("%d", gametrix[x][y]);
			curr_tile_len = (gametrix[x][y] != 0) ? (floor(log10(abs(gametrix[x][y]))) + 1) : 1;

			for (int spacer = 0; spacer < scale - curr_tile_len + 1; spacer++)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main()
{
	bool up_prev = false;
	bool down_prev = false;
	bool left_prev = false;
	bool right_prev = false;

	while (1)
	{
		if (GetKeyState(VK_UP) & 0x8000)
		{
			if (up_prev == false)
			{
				system("cls");
				/*printf(" up ");*/
				redraw();

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
				system("cls");
				printf(" down ");

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
				system("cls");
				printf(" left ");

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
				system("cls");
				printf(" right ");

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
