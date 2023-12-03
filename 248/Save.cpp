#pragma once

#include <iostream>
#include "Save.h"


void save(Gamestate game)
{
	FILE* gamestate;

	gamestate = fopen("binaries/Gamestate.bin", "wb");
	fwrite(&game, sizeof(Gamestate), 1, gamestate);
	fclose(gamestate);
}

int load(Gamestate game)
{
	FILE* gamestate;

	gamestate = fopen("binaries/Gamestate.bin", "rb");

	if (gamestate == NULL)
	{
		return 1;
	}

	fread(&game, sizeof(Gamestate), 1, gamestate);
	fclose(gamestate);
}