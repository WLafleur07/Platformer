#include "Game.h"

void Game::OnEvent(SDL_Event* Event)
{
	switch (Event->type)
	{
	case SDL_QUIT:
		Running = false;
	case SDL_KEYDOWN:
		switch (Event->key.keysym.sym)
		{
		case SDLK_ESCAPE:
			Running = false;
			break;
		case SDLK_w:
			character.velocity.y = -7;
			break;

		case SDLK_a:
			character.setSpriteSheet("Assets/characterRunLeft.bmp");
			character.configSpriteSheet(12, 0, 0, 66, 48, 12, 1, 0);
			character.setDimensions(character.images[0].w, character.images[0].h);
			character.charRunning = true;
			character.velocity.x = -6;

			for (int i = 0; i < 15; i++)
			{
				if (checkCollision(character.position, collider[i].position) == true)
				{
					if (character.position.x + character.position.w >= collider[i].position.x)
					{
						cout << "Character: Right\t" << "Collider: Left" << endl;
						character.velocity.x = -5;
					}
					else if (character.position.x <= collider[i].position.x + collider[i].position.w)
					{
						cout << "Character: Left\t" << "Collider: Right" << endl;
						character.velocity.x = 5;
					}
				}
			}
			break;

		case SDLK_d:
			printf("keydown\n");
			character.setSpriteSheet("Assets/characterRunRight.bmp");
			character.configSpriteSheet(12, 0, 0, 66, 48, 12, 1, 0);
			character.setDimensions(character.images[0].w, character.images[0].h);
			character.velocity.x = 6;

			for (int i = 0; i < 15; i++)
			{
				if (checkCollision(character.position, collider[i].position) == true)
				{
					if (character.position.x + character.position.w <= collider[i].position.x)
					{
						cout << "Character: Right\t" << "Collider: Left" << endl;
						character.velocity.x = -5;
					}
					else if (character.position.x <= collider[i].position.x + collider[i].position.w)
					{
						cout << "Character: Left\t" << "Collider: Right" << endl;
						character.velocity.x = 5;
					}
				}
			}
			break;

		default:
			break;
		}
	}
	switch (Event->type)
	{
	case SDL_KEYUP:
		switch (Event->key.keysym.sym)
		{
		case SDLK_w:
			character.velocity.y = character.gravity;
			break;

		case SDLK_a:
			character.setSpriteSheet("Assets/character.bmp");
			character.configSpriteSheet(4, 0, 0, 38, 48, 4, 1, 0);
			character.setDimensions(character.images[0].w, character.images[0].h);
			character.velocity.x = 0;
			break;

		case SDLK_d:
			printf("keyup\n");
			character.setSpriteSheet("Assets/character.bmp");
			character.configSpriteSheet(4, 0, 0, 38, 48, 4, 1, 0);
			character.setDimensions(character.images[0].w, character.images[0].h);
			character.velocity.x = 0;
			break;

		default:
			break;
		}
	}
	
}


//==============================================================================
