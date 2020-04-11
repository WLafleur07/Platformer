#include "Character.h"
#include <string>

using namespace std;

Character::Character() {

}

Character::~Character()
{
	
}

int Character::loadSpriteSheet(SDL_Renderer *renderer)
{
	SDL_Surface *temp;

	/* Load the sprite image */
	temp = SDL_LoadBMP(spritesheet.c_str());
	if (temp == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s", spritesheet, SDL_GetError());
		return (-1);
	}
	w_width = temp->w;
	w_height = temp->h;

	/* Set transparent pixel as the pixel at (0,0) */
	if (temp->format->palette)
	{
		SDL_SetColorKey(temp, SDL_TRUE, *(Uint8 *)temp->pixels);
	}
	else
	{
		switch (temp->format->BitsPerPixel)
		{
		case 15:
			SDL_SetColorKey(temp, SDL_TRUE,
				(*(Uint16 *)temp->pixels) & 0x00007FFF);
			break;
		case 16:
			SDL_SetColorKey(temp, SDL_TRUE, *(Uint16 *)temp->pixels);
			break;
		case 24:
			SDL_SetColorKey(temp, SDL_TRUE,
				(*(Uint32 *)temp->pixels) & 0x00FFFFFF);
			break;
		case 32:
			SDL_SetColorKey(temp, SDL_TRUE, *(Uint32 *)temp->pixels);
			break;
		}
	}

	/* Create textures from the image */
	texture = SDL_CreateTextureFromSurface(renderer, temp);
	if (!texture)
	{
		fprintf(stderr, "Couldn't create texture: %s\n", SDL_GetError());
		SDL_FreeSurface(temp);
		return (-1);
	}
	SDL_FreeSurface(temp);

	return (0);
}
/*
	int num_of_images    How many images to extract from texture
	 int sx,             Start image x loc in texture
	  int sy,            Start image y loc in texture
	   int sw,           Width of ONE image in texture
		int sh,          Height of ONE image in texture
		 int wx,         How many images on ONE row
		  int hy,        How many rows of images on texture
		   int border    How many pixels between images

	Note: Images are not really extracted... locations are saved to allow quick display...

*/

//function to take in parameters of the spritesheet
void Character::configSpriteSheet(int num_of_images, int sx, int sy, int sw, int sh, int wx, int hy, int border)
{
	SDL_Rect *pr;
	int curx, cury;
	int working_rec = 0;
	int working_row = 1;
	int working_col = 1;

	curx = sx;
	cury = sy;
	while (working_rec < num_of_images && working_row <= hy)
	{
		pr = &images[working_rec];
		pr->x = curx;
		pr->y = cury;
		pr->w = sw;
		pr->h = sh;
		working_col++;
		working_rec++;
		curx += sw + border;
		if (working_col > wx)
		{
			working_row++;
			working_col = 1;
			cury += sh + border;
			curx = sx;
		}

	}
	max_images = num_of_images;

}
/*
	Display the Sprite (current position) to the screen
	and optionally move to next image....

*/
void Character::play(SDL_Renderer *r, SDL_Rect *pos, bool gotonext)
{
	SDL_RenderCopy(r, texture, &images[cur_image], pos);
	if (gotonext)
	{
		cur_image++;
		if (cur_image >= max_images)
			cur_image = 0;
		SDL_Delay(100);
	}
}

void Character::characterPosDimen(int characerterW, int characterH, int characterPosX, int characterPosY)
{
	position.w = characerterW;
	position.h = characterH;
	position.x = characterPosX;
	position.y = characterPosY;
}

void Character::setDimensions(int characerterW, int characterH)
{
	position.w = characerterW;
	position.h = characterH;
}

void Character::move()
{

	SDL_Rect *p;
	SDL_Rect *v;

	p = &position;
	v = &velocity;

	p->x += v->x;
	if ((p->x < 0) || (p->x >= (window_w - p->w)))
	{
		v->x = -v->x;
		p->x += v->x;
	}
	p->y += v->y;
	if ((p->y < 0) || (p->y >= (window_h - p->h)))
	{
		p->y = window_h + 40;
		p->x = window_w / 2;
	}
	
}


