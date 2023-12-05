#include "248.h"
#include "Leaderboard.h"
#include "Draw.h"
#include "Gamelogic.h"
#include "Style.h"
#include "Save.h"
#include <Windows.h>

int main()
{
	Gamestate game{};

	Gamestate empty_game{};

	bool up_prev = false;
	bool down_prev = false;
	bool left_prev = false;
	bool right_prev = false;
	bool return_prev = false;
	bool esc_prev = false;
	int menu = 0;
	char control = 'M';

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

				game = empty_game;

				printf("Insert player name:");
				scanf(" %16s", &(game.gameinfo.name));

				generate(game.gametrix);
				generate(game.gametrix);

				draw(game.gameinfo.name, game.gameinfo.score, game.gametrix);
			}
			else {

				if (control == 'R')
				{
					if (load(game) == 1 || game.gameinfo.score == 0)
					{
						system("cls");
						printf("\033[0;31m");
						printf("Nothing to load!");
						printf("\033[0m");
						Sleep(2000);
						draw_menu(menu);
						control = 'M';
					}
					else {
						draw(game.gameinfo.name, game.gameinfo.score, game.gametrix);
					}
				}
			}

			while (control == 'N' || control == 'R')
			{
				if (GetKeyState(VK_UP) & 0x8000)
				{
					if (up_prev == false)
					{
						merge('U', &game.gameinfo.score, game.gametrix);
						
						if (generate(game.gametrix) == 1)
						{
							if (leaderboard_append(game.gameinfo.name, game.gameinfo.score) == 1 || save(game) == 1)
							{
								system("cls");
								printf("\033[0;31m");
								printf("Nowhere to save!");
								printf("\033[0m");
								Sleep(2000);
							}
							draw_menu(menu);
							control = 'M';
						}
						
						draw(game.gameinfo.name, game.gameinfo.score, game.gametrix);

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
						merge('D', &game.gameinfo.score, game.gametrix);

						if (generate(game.gametrix) == 1)
						{
							if (leaderboard_append(game.gameinfo.name, game.gameinfo.score) == 1 || save(game) == 1)
							{
								system("cls");
								printf("\033[0;31m");
								printf("Nowhere to save!");
								printf("\033[0m");
								Sleep(2000);
							}
							draw_menu(menu);
							control = 'M';
						}

						draw(game.gameinfo.name, game.gameinfo.score, game.gametrix);

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
						merge('L', &game.gameinfo.score, game.gametrix);

						if (generate(game.gametrix) == 1)
						{
							if (leaderboard_append(game.gameinfo.name, game.gameinfo.score) == 1 || save(game) == 1)
							{
								system("cls");
								printf("\033[0;31m");
								printf("Nowhere to save!");
								printf("\033[0m");
								Sleep(2000);
							}
							draw_menu(menu);
							control = 'M';
						}

						draw(game.gameinfo.name, game.gameinfo.score, game.gametrix);

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
						merge('R', &game.gameinfo.score, game.gametrix);

						if (generate(game.gametrix) == 1)
						{
							if (leaderboard_append(game.gameinfo.name, game.gameinfo.score) == 1 || save(game) == 1)
							{
								system("cls");
								printf("\033[0;31m");
								printf("Nowhere to save!");
								printf("\033[0m");
								Sleep(2000);
							}
							draw_menu(menu);
							control = 'M';
						}

						draw(game.gameinfo.name, game.gameinfo.score, game.gametrix);

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

						save(game);

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
			if (draw_leaderboard() == 1)
			{
				system("cls");
				printf("\033[0;31m");
				printf("No leaderboard data!");
				printf("\033[0m");
				Sleep(2000);
				draw_menu(menu);
				control = 'M';
			}

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
