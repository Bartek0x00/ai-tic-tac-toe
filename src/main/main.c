#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "../AI/Board.h"

int main(void)
{
	void *display = initDisplay(); 
	unsigned char input = '\0';
	char buffer[32] = {'\0'};
	unsigned int remainingMoves = 9;
	register Board board = Board_EMPTY;	
	srand(time(0));
	Color playerColor = (rand() % 2) + 1;

	if (playerColor == RED) {
		showText(display, "You're red cross X\n", RED);
		goto User;
	}

	while (1) {
		drawDisplay(display, board);
		Color winner = Board_GetWinner(board);

		if (winner) {
			showText(display, "You've lost\n", RED);
			goto User;
		}

		if (!remainingMoves) {
			showText(display, "It's a tie\n", BLUE);	
			goto User;
		}
		
		struct timespec startTime, endTime;
		clock_gettime(CLOCK_MONOTONIC, &startTime);

		board = solve(
			board, 
			(playerColor ^ 0b11)
		);
		
		clock_gettime(CLOCK_MONOTONIC, &endTime);

		sprintf(
			buffer,
			"Solve time: %ldns\n", 
			(endTime.tv_nsec - startTime.tv_nsec)
		);
		showText(display, buffer, NONE);

		if (!(--remainingMoves) || Board_GetWinner(board)) continue;

	User:
		drawDisplay(display, board);
		while(!getEvent(&input));

		if (input == 'q') break;
		if (!Board_Get(board, (input - '0'))) {
			board = Board_Set(board, (input - '0'), playerColor);
			remainingMoves--;
		} else {
			goto User;
		}		
	}

	deleteDisplay(display);
	return 0;
}
