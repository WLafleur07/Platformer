//==============================================================================
#include "Game.h"

//==============================================================================
Game::Game()
{
    Running = true;
}


Uint32 Game::time_left(void)
{
    Uint32 now;

    now = SDL_GetTicks();
    if(next_time <= now)
        return 0;
    else
        return next_time - now;
}

int Game::OnExecute()
{
    if(Init() == false)
    {
        return -1;
    }

    SDL_Event Event;
    next_time = SDL_GetTicks() + TICK_INTERVAL;
    while(Running)
    {
        while(SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }

        Loop();
        Render();
    }

    Cleanup();

    return 0;
}

int main(int argc, char* argv[])
{
	Game game;

    return game.OnExecute();
}

