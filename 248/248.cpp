#include "248.h"
#include "Leaderboard.h"
#include "Draw.h"
#include "Gamelogic.h"
#include <Windows.h>
#include <Math.h>
#include <stdlib.h>

int gametrix[4][4] = {
						{0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0},
					 };

//struct GameInfo {
//	char name[16];
//	int score;
//};

char player_name[16] = "";
int score = 0;

char control = 'M';

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

void game_clear()
{
	score = 0;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			gametrix[y][x] = 0;
		}
	}
}

int main()
{
	bool up_prev = false;
	bool down_prev = false;
	bool left_prev = false;
	bool right_prev = false;
	bool return_prev = false;
	bool esc_prev = false;
	int menu = 0;
	FILE *file;
	FILE *file2;

	//init
	setFontSize(50, 50);
	srand(time(NULL));

	draw_menu(menu);

	while (1)
	{

		while (control == 'M')
		{
			//nahoru v menu
			if (GetKeyState(VK_UP) & 0x8000)
			{
				if (up_prev == false)
				{
					menu--;
					if (menu < 0) { menu = 2; }

					draw_menu(menu);

					up_prev = true;
				}
			}
			else
			{
				up_prev = false;
			}

			//dolu v menu
			if (GetKeyState(VK_DOWN) & 0x8000)
			{
				if (down_prev == false)
				{
					menu++;
					if (menu > 2) { menu = 0; }

					draw_menu(menu);

					down_prev = true;
				}
			}
			else
			{
				down_prev = false;
			}

			//potvrdit vyber
			if (GetKeyState(VK_RETURN) & 0x8000)
			{
				if (return_prev == false)
				{
					switch (menu)
					{
					case 0:

						control = 'N';

						break;

					case 1:

						control = 'R';

						break;

					case 2:

						control = 'L';

						break;

					}

					return_prev = true;
				}
			}
			else
			{
				return_prev = false;
			}

		}

		if (control == 'N' || control == 'R')
		{
			if (control == 'N')
			{
				system("cls");

				game_clear();

				printf("Insert player name:");
				scanf(" %16s", &player_name);

				generate();
				generate();
			}

			if (control == 'R')
			{
				file2 = fopen("Gameinfo.bin", "rb");
				fread(&gametrix[0][0], sizeof(int), 16, file2);
				fclose(file2);

				file = fopen("Gameboard.bin", "rb");
				fread(&gametrix[0][0], sizeof(int), 16, file);
				fclose(file);
			}

			draw(&player_name, score, gametrix);

			while (control == 'N' || control == 'R')
			{
				if (GetKeyState(VK_UP) & 0x8000)
				{
					if (up_prev == false)
					{
						merge('U');
						
						if (generate() == 1)
						{
							leaderboard_append(player_name, score);
							control = 'M';
						}
						
						draw(&player_name, score, gametrix);

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

						if (generate() == 1)
						{
							leaderboard_append(player_name, score);
							control = 'M';
						}

						draw(&player_name, score, gametrix);

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

						if (generate() == 1)
						{
							leaderboard_append(player_name, score);
							control = 'M';
						}

						draw(&player_name, score, gametrix);

						left_prev = true;
					}
				}
				else
				{
					left_prev = false;
				}

				if (GetKeyState(VK_RIGHT) & 0x8000)
				{
					if (right_prev == false)
					{
						merge('R');

						if (generate() == 1)
						{
							leaderboard_append(player_name, score);
							control = 'M';
						}

						draw(&player_name, score, gametrix);

						right_prev = true;
					}
				}
				else
				{
					right_prev = false;
				}

				if (GetKeyState(VK_ESCAPE) & 0x8000)
				{

					if (esc_prev == false)
					{

						file = fopen("Gameboard.bin", "wb");
						fwrite(&gametrix, sizeof(int), 16, file);
						fclose(file);

						control = 'M';
						draw_menu(menu);

						esc_prev = true;
					}
				}
				else
				{
					esc_prev = false;
				}
			}
		}

		if (control == 'L')
		{
			draw_leaderboard();

			while (control == 'L')
			{
				if (GetKeyState(VK_ESCAPE) & 0x8000)
				{

					if (esc_prev == false)
					{
						
						control = 'M';
						draw_menu(menu);

						esc_prev = true;
					}
				}
				else
				{
					esc_prev = false;
				}
			}

		}

	}

	return 0;
}
