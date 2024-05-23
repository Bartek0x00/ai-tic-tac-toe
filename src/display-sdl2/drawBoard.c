#include <stdbool.h>
#include "window.h"
#include "display.h"

void drawBoard(void *displayRaw, unsigned int board[])
{
	Display *display = (Display *)displayRaw;
	
	SDL_RenderCopy(
		display->renderer,
		display->background,
		NULL,
		NULL
	);
	
	int count = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (count == 9) count = 0;
			SDL_Rect destination = {
				j * CELL_SIZE,
				i * CELL_SIZE,
				200,
				200
			};

			if (board[count]) {
				SDL_RenderCopy(
					display->renderer,
					board[count] == 1 ? display->cross : 
					display->circle,
					NULL,
					&destination
				);
			}
			count++;
		}
	}
	SDL_RenderPresent(display->renderer);
}
