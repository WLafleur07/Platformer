#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>
#include "mywindow.h"
#include <string>

#define MAX_SPRITE_IMAGES 100

using namespace std;

class Character
{
public:
	SDL_Rect position;
	SDL_Rect velocity;
	string spritesheet;	//filename of spritesheet
	SDL_Rect images[MAX_SPRITE_IMAGES];
	int max_images;		//max images in spritesheet
	int cur_image;		//current image displayed in spritesheet
	int w_width;		//Whole width and height of spritesheet
	int w_height;
	int gravity = 15;
	bool charIdle = false;
	bool charRunning = false;
	bool charJumping = false;


	Character();//constructor
	void setSpriteSheet(string s) { spritesheet = s; }
	virtual ~Character();	//destructor

	int loadSpriteSheet(SDL_Renderer *renderer);
	//function that takes the parameters of the spritesheet
	void configSpriteSheet(int num_of_images, int sx, int sy, int sw, int sh, int wx, int hy, int border);
	void characterPosDimen(int characerterW, int characterH, int characterPosX, int characterPosY);
	void setDimensions(int characerterW, int characterH);
	void play(SDL_Renderer *r, SDL_Rect *pos, bool gotonext);
	void rewind() { cur_image = 0; }
	void move();
	//void setW_H(int w, int h);

protected:
private:
	SDL_Texture *texture;
	SDL_Surface *ps;




};
#endif

