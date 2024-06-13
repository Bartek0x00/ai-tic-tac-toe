#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
		showText(display, "You're red cross X\n");
		goto User;
	} else {
		showText(display, "You're blue circle O\n");
	}

	while (1) {
		drawDisplay(display, board);
		Color winner = Board_GetWinner(board);

		if (winner) {
			printf("%sYou've lost%s\n", T_RED, T_CLR);
			break;
		}

		if (!remainingMoves) {
			printf("%sIt's a tie%s\n", T_BLUE, T_CLR);	
			break;
		}
		
		struct timespec startTime, endTime;
		clock_gettime(CLOCK_MONOTONIC, &startTime);

		board = solve(
			board, 
			(playerColor ^ 0b11)
		);
		
		clock_gettime(CLOCK_MONOTONIC, &endTime);
		printf(
			"Solve time: %ldµs\n", 
			(endTime.tv_nsec - startTime.tv_nsec) / 1000
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
