#include "248.h"
#include <Windows.h>


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

//func move - return list of pairs of values, a = further most taken coord, b = further most free coord if not mergible with a or a if mergible

int main()
{
	bool up_prev = false;
	bool down_prev = false;
	bool left_prev = false;
	bool right_prev = false;


	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		if (up_prev == false)
		{
			//do stuff
			up_prev = true;
		}
	} 
	else 
	{
		up_prev = false;
	}

	/*if ((GetAsyncKeyState(VK_DOWN) & 0x8000) == true)
	{
		;// Do stuff
	}

	if ((GetAsyncKeyState(VK_LEFT) & 0x8000) == true)
	{
		;// Do stuff
	}

	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) == true)
	{
		;// Do stuff
	}*/



	return 0;
}
