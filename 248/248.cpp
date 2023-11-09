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
			//generator
			;
		}

		void merge()
		{
			;
		}
};

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
