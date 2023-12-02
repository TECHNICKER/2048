#include "248.h"
#include <Windows.h>
#include <Math.h>
#include <stdlib.h>


int gametrix[4][4] = {
						{0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0},
					 };

int score = 0;

int control = 0;

inline void setFontSize(int a, int b)

{

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();

	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);

	GetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);

	lpConsoleCurrentFontEx->dwFontSize.X = a;

	lpConsoleCurrentFontEx->dwFontSize.Y = b;

	SetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);

}

void draw(void)
{
	int largest_tile = 0;
	int curr_tile_length = 0;
	int scale = 0;

	system("cls");
	
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

void generate(void)
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

		//control = 3;
		break;

	case 1:

		random_tile = 0;
		break;

	default:

		random_tile = rand() % (index - 1);
		break;
	}

	gametrix[free[random_tile].y][free[random_tile].x] = value;

}

int main()
{
	bool up_prev = false;
	bool down_prev = false;
	bool left_prev = false;
	bool right_prev = false;

	setFontSize(50, 50);
	srand(time(NULL));

	generate();
	generate();
	draw();

	while (1)
	{
		if (GetKeyState(VK_UP) & 0x8000)
		{
			if (up_prev == false)
			{
				draw();
				merge('U');
				draw();
				generate();
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
				generate();
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
				generate();
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
				generate();
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
