#include <stdbool.h>
#include "window.h"
#include "display.h"
#include "../AI/Board.h"

void drawDisplay(void *displayRaw, Board board)
{
	Display *display = (Display *)displayRaw;
	
	SDL_Rect background = {
		0, 
		0,
		WINDOW_SIZE,
		WINDOW_SIZE
	};
	SDL_RenderCopy(
		display->renderer,
		display->background,
		NULL,
		&background
	);
	
	int count = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			SDL_Rect cell = {
				j * CELL_SIZE, 
				i * CELL_SIZE,
				CELL_SIZE, 
				CELL_SIZE
			};

			if (Board_Get(board, count)) {
				SDL_RenderCopy(
					display->renderer,
					Board_Get(board, count) == 1 ? \
					display->cross : \
					display->circle,
					NULL,
					&cell
				);
			}
			count++;
		}
	}
	SDL_RenderPresent(display->renderer);
}
