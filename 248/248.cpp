#include "248.h"
#include <Windows.h>
#include <Math.h>
#include <stdlib.h.>


int gametrix[4][4] = {
						{1, 2, 3, 4},
						{2, 2, 0, 1},
						{3, 0, 356, 0},
						{4, 1, 0, 4},
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

void draw(void)
{
	int largest_tile = 0;
	int curr_tile_length = 0;
	int scale = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			(largest_tile < gametrix[j][i]) ? (largest_tile = gametrix[j][i]) : (largest_tile = largest_tile);
		}
	}

	(largest_tile > 0) ? (scale = floor(log10(abs(largest_tile))) + 1) : (scale = 0);

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			printf("%d", gametrix[x][y]);

			(gametrix[x][y] > 0) ? (curr_tile_length = floor(log10(abs(gametrix[x][y]))) + 1) : (curr_tile_length = 1);

			for (int k = 0; k < (scale - curr_tile_length + 1); k++)
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

				draw();

				//printf(" up ");

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
