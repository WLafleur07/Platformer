//==============================================================================
#include "Game.h"

//==============================================================================
void Game::Render()
{

	SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
	SDL_RenderClear(renderer);

	for (int i = 0; i < 15; i++)
	{
		collider[i].display(renderer);
	}
	level.display(renderer);

	character.loadSpriteSheet(renderer);
	
	static Uint32 cnt = 0;
	if (cnt % 2 == 0)
		character.play(renderer, &character.position, true);
	else
		character.play(renderer, &character.position, false);
	cnt++;

    /* Update the screen! */
    SDL_RenderPresent(renderer);
    //SDL_Delay(10);
    SDL_Delay(time_left());
    next_time += TICK_INTERVAL;

}

//==============================================================================
