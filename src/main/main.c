#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "main.h"
#include "../AI/Board.h"

int main(void)
{
	void *display = initDisplay(); 
	unsigned char input = '\0';
	unsigned int remainingMoves = 9;
	register Board board = Board_EMPTY;	
	srand(time(0));
	Color playerColor = (rand() % 2) + 1;

	if (playerColor == RED) {
		printf("%sYou're red cross X%s\n", T_RED, T_CLR);
		goto User;
	} else {
		printf("%sYou're blue circle O%s\n", T_BLUE, T_CLR);
	}

	while (1) {
		drawDisplay(display, board);
		Color winner = Board_GetWinner(board);

		if (winner) {
			printf("%sYou've lost%s", T_RED, T_CLR);
			break;
		}

		if (!remainingMoves) {
			printf("%sIt's a tie%s", T_BLUE, T_CLR);	
			break;
		}

		board = solve(
			board, 
			(playerColor ^ 0b11)
		);
		if (!(--remainingMoves) || Board_GetWinner(board)) continue;

	User:
		drawDisplay(display, board);
		while(!getEvent(&input));

		if (input == 'q') break;
		if (!Board_Get(board, input)) {
			board = Board_Set(board, (input - '0'), playerColor);
			remainingMoves--;
		} else {
			goto User;
		}		
	}

	deleteDisplay(display);
	return 0;
}
