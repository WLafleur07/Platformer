#include "Game.h"
#include <stdlib.h>
#include <time.h>

bool Game::Init()
{

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO) < 0)
	{
		return false;
	}
	window = SDL_CreateWindow("Platformer",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window)
		return false;
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
		return false;

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	music = Mix_LoadMUS("Assets/03-Before-the-Dawn.wav");
	Mix_VolumeMusic(SDL_MIX_MAXVOLUME / 6);
	//Mix_PlayMusic(music, -1);

	level = Level("Assets/PlatformerMap.bmp", 0, 0, 1600, 640);
	level.loadLevel(renderer);

	character.setSpriteSheet("Assets/character.bmp");
	character.configSpriteSheet(4, 0, 0, 38, 48, 4, 1, 0);
	character.characterPosDimen(character.images[0].w, character.images[0].h, 32, 170);
	//character.velocity.y = character.gravity;
	character.charIdle = true;


	for (int i = 0; i < 15; i++)
	{
		collider[i] = Collider("Assets/Grey_Square.bmp");
		collider[i].loadLevel(renderer);
	}

	//ceiling collider
	collider[0].position.x = 0, collider[0].position.y = 0, collider[0].position.w = 1600, collider[0].position.h = 32;
	//left wall collider
	collider[1].position.x = 0, collider[1].position.y = 0, collider[1].position.w = 32, collider[1].position.h = 640;
	//first floor collider
	collider[2].position.x = 0, collider[2].position.y = 224, collider[2].position.w = 448, collider[2].position.h = 64;
	//floor  collider
	collider[3].position.x = 0, collider[3].position.y = 608, collider[3].position.w = 1600, collider[3].position.h = 32;
	//right wall collider
	collider[4].position.x = 1568, collider[4].position.y = 0, collider[4].position.w = 32, collider[4].position.h = 640;
	//center wall collider
	collider[5].position.x = 640, collider[5].position.y = 0, collider[5].position.w = 96, collider[5].position.h = 512;
	//center wall nub1 collider
	collider[6].position.x = 736, collider[6].position.y = 224, collider[6].position.w = 64, collider[6].position.h = 64;
	//center wall nub1 collider
	collider[7].position.x = 736, collider[7].position.y = 382, collider[7].position.w = 64, collider[7].position.h = 64;
	//top rigt floor collider
	collider[8].position.x = 864, collider[8].position.y = 128, collider[8].position.w = 640, collider[8].position.h = 64;
	//right wall platform collider
	collider[9].position.x = 1376, collider[9].position.y = 448, collider[9].position.w = 192, collider[9].position.h = 64;
	//bottom floor steps collider (last)
	collider[10].position.x = 864, collider[10].position.y = 576, collider[10].position.w = 320, collider[10].position.h = 32;
	//bottom floor steps collider (second last)
	collider[11].position.x = 896, collider[11].position.y = 544, collider[11].position.w = 256, collider[11].position.h = 32;
	//bottom floor steps collider (middle)
	collider[12].position.x = 928, collider[12].position.y = 512, collider[12].position.w = 192, collider[12].position.h = 32;
	//bottom floor steps collider (second from the top)
	collider[13].position.x = 960, collider[13].position.y = 480, collider[13].position.w = 128, collider[13].position.h = 32;
	//bottom floor steps collider (top)
	collider[14].position.x = 992, collider[14].position.y = 448, collider[14].position.w = 64, collider[14].position.h = 32;

    return true;
}




//==============================================================================
