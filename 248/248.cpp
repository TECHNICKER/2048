#include "248.h"
#include <Windows.h>
#include <stdlib.h.>


int gametrix[4][4] = {
						{0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0},
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
				printf(" up ");

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
