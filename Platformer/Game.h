#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>
#include "mywindow.h"
#include "Character.h"
#include "Level.h"
#include "Collider.h"
#include <SDL_mixer.h>
#include "iostream"

#define TICK_INTERVAL    10
#define NUM_SPRITES     10
#define MAX_SPEED       1

class Game : public Level
{
private:
    bool Running;

    Uint32 next_time;
    SDL_Window *window;
    SDL_Renderer *renderer;
	Character character;
	Level level;
	Collider collider[100];
	SDL_Rect position;
	Mix_Music *music = NULL;

	

public:
	
	Game();
    Uint32 time_left(void);
    int OnExecute();
	bool checkCollision(SDL_Rect A, SDL_Rect B);
	
public:
    bool Init();

    void OnEvent(SDL_Event* Event);

    void Loop();

    void Render();
    void MoveSprites();

    void Cleanup();
};

#endif
