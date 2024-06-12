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

	while (remainingMoves) {	
		drawDisplay(display, board);
		Color winner = Board_GetWinner(board);
		if (winner) {
			printf("You've lost");
			break;
		} 
		
		if (remainingMoves--) {
			board = solve(
				board, 
				(playerColor ^ 0b11)
			);
			if (remainingMoves) goto User;
		} else {
			printf("%sIt's a tie%s", T_GREEN, T_CLR);
			break;
		}

		User:
		drawDisplay(display, board);
		while(!getEvent(&input));

		if (input == 'q') break;
		if (!Board_Get(board, input)) {
			board = Board_Set(board, (input - '0'), playerColor);
			remainingMoves--;
		}		
	}

	deleteDisplay(display);
	return 0;
}
