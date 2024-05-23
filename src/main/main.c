#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include <SDL2/SDL.h>

int main()
{
	void *display = initBoard(); 
	char input = '\0';
	Board board = 0;	
	drawBoard(display, board);	
	srand(time(0));
	AI_Color playerColor = (rand() % 2) + 1;

	if (playerColor == RED) 
		printf("%s%sYou're red cross X%s\n", T_RED, B_GREY, T_CLR);
	else {
		printf("%s%sYou're blue circle O%s\n", T_BLUE, B_GREY, T_CLR);
		goto Algorithm;
	}

	while (1) {
		while(getEvent(&input));
		if (input == 'q') {
			deleteBoard(display);
			break;
		} /*else if (input >= '0' && input <= '8' && !board[input - '0']) {
			board[input - '0'] = playerColor;
		}*/
		drawBoard(display, board);	
		Algorithm:
		switch(AI_Solve(board)) {
		case ONGOING:
			continue;
		case LOST:
			puts("You lost!");
			break;
		case WON:
			puts("You won!");
			break;
		}
	}
	return 0;
}
