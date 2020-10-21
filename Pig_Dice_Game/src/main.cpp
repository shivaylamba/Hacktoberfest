#include <iostream>

#include "../include/game.h"

int main()
{
	game_state state;
	ini(state);

	while(game_over(state) == false)
	{
		call_and_update(state);
	}

}