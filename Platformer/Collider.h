#ifndef COLLIDER_H
#define COLLIDER_H

#include <SDL.h>
#include "mywindow.h"
#include "Level.h"
#include <string>

using namespace std;

class Collider : public Level
{
public:
	string imagename;

	Collider();
	Collider(string s);
	int loadLevel(SDL_Renderer *renderer);
	void display(SDL_Renderer *prenderer);

protected:
	SDL_Texture *texture;
};


#endif