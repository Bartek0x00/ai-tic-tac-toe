#include <SDL2/SDL.h>
#include "window.h"
#include "display.h"
#include <stdio.h>

char getSquareClicked(int x, int y)
{
	int row = y / CELL_SIZE;
	int col = x / CELL_SIZE;
	return ((row * GRID_SIZE + col) + '0');
}

int getEvent(char *output)
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT:
			*output = 'q';
			return 0;
		case SDL_MOUSEBUTTONDOWN:
			*output = getSquareClicked(
				event.motion.x,
				event.motion.y
			);
			return 0;		
		}
	}
	return 1;
}
