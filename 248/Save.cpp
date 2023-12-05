#pragma once

#include <iostream>
#include "Save.h"


void save(Gamestate game)
{
	FILE* gamestate = nullptr;

	gamestate = fopen("Gamestate.bin", "wb");
	fwrite(&game, sizeof(Gamestate), 1, gamestate);
	fclose(gamestate);

}

int load(Gamestate *game)
{
	FILE* gamestate = nullptr;

	if ((gamestate = fopen("Gamestate.bin", "rb")) != NULL)
	{
		fread(&game, sizeof(Gamestate), 1, gamestate);
		fclose(gamestate);
	}
	else
	{
		return 1;
	}

}