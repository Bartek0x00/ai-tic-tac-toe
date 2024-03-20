#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <SDL2/SDL.h>

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Texture *background;
	SDL_Texture *circle;
	SDL_Texture *cross;
} Display;

#endif // _DISPLAY_H
