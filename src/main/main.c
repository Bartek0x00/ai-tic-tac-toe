#include <stdio.h>
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
	
	srand(time(0));
	Color playerColor = (rand() % 2) + 1;

	if (playerColor == RED)
		printf("%sYou're red cross X%s\n", T_RED, T_CLR);
	else
		printf("%sYou're blue circle O%s\n", T_BLUE, T_CLR);

	while (1) {
		drawBoard(display, board);
		if (scanf(" %c", &input) != 1) continue;
		if (input == 'q') {
			deleteBoard(display);
			free(display);
			break;
		} else if (input >= '0' && input <= '8' && !board[input - '0']) {
			board[input - '0'] = playerColor;
		}
		while (getchar() != '\n');
		/* 
		switch(AI_Solve(&board)) {
			case WON:
				break;
			case LOST:
				break;
			default:
				continue;
		}
		*/
	}
	return 0;
}
