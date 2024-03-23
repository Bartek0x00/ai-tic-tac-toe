#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

int main()
{
	void *display = initBoard(); 

	char input = '\0';
	
	unsigned int board[9] = {
		0, 0, 0,
		0, 0, 0,
		0, 0, 0
	};
	while (true) {
		drawBoard(display, board);
	}
	/*
	while (1) {
		drawBoard(display, board);
		if (scanf(" %c", &input) != 1) continue;
		if (input == 'q') {
			deleteBoard(display);
			free(display);
			break;
		} else if (input >= '0' && input <= '8') {
			board[input - '0']++;
		}
		while (getchar() != '\n');
		// handle input, change Board according to input
		switch(AI_Solve(&board)) {
			case WON:
				break;
			case LOST:
				break;
			default:
				continue;
		}
		// handle AI output, change Board accordingly
	}*/
	return 0;
}
