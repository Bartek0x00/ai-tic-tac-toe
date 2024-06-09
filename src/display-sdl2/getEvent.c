#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "window.h"
#include "display.h"

static inline char getSquareClicked(int x, int y)
{
	int row = y / CELL_SIZE;
	int col = x / CELL_SIZE;
	return ((row * GRID_SIZE + col) + '0');
}

bool getEvent(unsigned char *output)
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT:
			*output = 'q';
			return true;
		case SDL_MOUSEBUTTONDOWN:
			*output = getSquareClicked(
				event.motion.x,
				event.motion.y
			);
			return true;		
		}
	}
	return false;
}
