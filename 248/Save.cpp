#pragma once

#include <iostream>
#include "Save.h"


int save(Gamestate game)
{
	FILE* gamestate = nullptr;

	if ((gamestate = fopen("Gamestate.bin", "wb")) != NULL)
	{
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