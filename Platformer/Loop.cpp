//==============================================================================
#include "Game.h"

using namespace std;


void Game::MoveSprites() {
	character.move();
}


//==============================================================================
void Game::Loop()
{
	/*for (int i = 0; i < 15; i++)
	{
		if(checkCollision(character.position, collider[i].position) == true)
		{
			if (character.position.y <= collider[i].position.y)
			{
				cout << "Character: Bottom\t" << "Collider: Top" << endl;
				character.position.y = collider[i].position.y - character.position.h;
				character.velocity.y = 0;
			}
			else if (character.position.y <= collider[i].position.y + collider[i].position.h)
			{
				cout << "Character: Top\t" << "Collider: Bottom" << endl;
				character.position.y = collider[i].position.y + collider[i].position.h;
			}

		}
	}*/
    MoveSprites();
}

//==============================================================================
