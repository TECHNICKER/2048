#pragma once

#include <iostream>
#include <io.h>
#include "Save.h"


int save(Gamestate game)
{
	FILE* gamestate = nullptr;

	if (_access("Gamestate.bin", 0) == 0)
	{
		gamestate = fopen("Gamestate.bin", "wb");
		fwrite(&game, sizeof(Gamestate), 1, gamestate);
		fclose(gamestate);
	}
	else 
	{
		return 1;
	}

}

int load(Gamestate game)
{
	FILE* gamestate = nullptr;

	if (_access("Gamestate.bin", 0) == 0)
	{
		gamestate = fopen("Gamestate.bin", "rb");
		fread(&game, sizeof(Gamestate), 1, gamestate);
		fclose(gamestate);
	}
	else
	{
		return 1;
	}

}