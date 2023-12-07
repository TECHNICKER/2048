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
				game = empty_game;
				save(&game);

				system("cls");
				printf("Insert player name:");

				char c;
				while ((c = getchar()) != '\n' && c != EOF);
				scanf(" %16s", &(game.gameinfo.name));

				generate(game.gametrix);
				generate(game.gametrix);

				save(&game);
				draw(game);
			}
			else {

				if (control == 'R')
				{
					game = empty_game;

					if (load(&game) == 1)
					{
						control = 'M';
						draw_menu(menu);
					}
					else
					{
						draw(game);
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

						//pokud už není kam dál vygenerovat blok, ukonči hru
						if (generate(game.gametrix) == 1)
						{
							//GAME OVER sekvence
							system("cls");
							printf("\033[0;31m");
							printf("GAME OVER");
							printf("\033[0m");
							leaderboard_append(game.gameinfo);
							remove("Gamestate.bin");

							Sleep(2000);
							
							draw_menu(menu);
							control = 'M';
							break;
						}
						
						save(&game);
						draw(game);

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
							system("cls");
							printf("\033[0;31m");
							printf("GAME OVER");
							printf("\033[0m");
							leaderboard_append(game.gameinfo);
							remove("Gamestate.bin");

							Sleep(2000);

							draw_menu(menu);
							control = 'M';
							break;
						}

						save(&game);
						draw(game);

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
							system("cls");
							printf("\033[0;31m");
							printf("GAME OVER");
							printf("\033[0m");
							leaderboard_append(game.gameinfo);
							remove("Gamestate.bin");

							Sleep(2000);

							draw_menu(menu);
							control = 'M';
							break;
						}

						save(&game);
						draw(game);

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
							system("cls");
							printf("\033[0;31m");
							printf("GAME OVER");
							printf("\033[0m");
							leaderboard_append(game.gameinfo);
							remove("Gamestate.bin");

							Sleep(2000);

							draw_menu(menu);
							control = 'M';
							break;
						}

						save(&game);
						draw(game);

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

						save(&game);

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
