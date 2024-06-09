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
	drawDisplay(display, board);	
	srand(time(0));
	Color playerColor = (rand() % 2) + 1;

	if (playerColor == RED) 
		printf("%sYou're red cross X%s\n", T_RED, T_CLR);
	else {
		printf("%sYou're blue circle O%s\n", T_BLUE, T_CLR);
		goto Algorithm;
	}

	while (remainingMoves) {
		while(getEvent(&input));
		if (input == 'q') {
			goto Exit;
		} else if (input >= '0' && input <= '8') {
			input -= '0';
			if(!Board_Get(board, input)) {
				board = Board_Set(board, input, playerColor);
				remainingMoves--;
			}
		}		
		drawDisplay(display, board);	
		Algorithm:
		switch(Board_GetWinner(board)) {
		case NONE:
			if (remainingMoves) {
				board = Solve(board);
				continue;
			}
			printf("%sIt's a TIE%s\n", T_GREEN, T_CLR);
			goto Exit;
		case RED:
			if (playerColor == RED)
				printf("%sYou've won%s\n", T_RED, T_CLR);
			else
				printf("%sYou've lost%s\n", T_BLUE, T_CLR);
			goto Exit;
		case BLUE:
			if (playerColor == BLUE)
				printf("%sYou've won%s\n", T_BLUE, T_CLR);
			else
				printf("%sYou've lost%s\n", T_RED, T_CLR);
			goto Exit;
		}
	}
Exit:
	deleteDisplay(display);
	return 0;
}
