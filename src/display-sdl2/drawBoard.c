#include <stdbool.h>
#include "../AI/Board.h"
#include "window.h"
#include "display.h"

void drawBoard(void *displayRaw, Board board)
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

			if (Board_GET(board, count)) {
				SDL_RenderCopy(
					display->renderer,
					Board_GET(board, count) == 1 ? display->cross : 
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
