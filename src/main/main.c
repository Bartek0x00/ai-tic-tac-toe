#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
#include <time.h>

int main()
{
	int color = 0;
	srand(time(0));
	switch (rand() % 2) {
		case 0:
			color = RED;
		case 1:
			color = BLUE;
	}

	void *display = initBoard(); 

	bool isRunning = true;
	char input = '\0';

	while (isRunning) {
		drawBoard(display, board);
		if (scanf(" %c", &input) != 1) continue;
		/*if (input_occured) {
			// handle input, change Board according to input
			switch(AI_Solve(&board)) {
			case WON:
				[[unlikely]]
				break;
			case LOST:
				break;
			case NONE:
				[[fallthrough]]
			default:
				[[likely]]
				continue;
			}
			// handle AI output, change Board accordingly
		}*/
		if (input == 'q') {
			deleteBoard(display);
			free(display);
			isRunning = false;
		}
	}
	return 0;
}
