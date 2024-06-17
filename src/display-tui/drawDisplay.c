#include <stdio.h>
#include <stdlib.h>
#include "../AI/Board.h"

static inline char getChar(Board board, int index)
{
	switch(Board_Get(board, index)) {
		case RED: return 'X';
		case BLUE: return 'O';
		default: return ' ';
	}
}

void drawDisplay(Board board)
{
	printf(
		" %c | %c | %c \n"
		"---|---|---\n"
		" %c | %c | %c \n"
		"---|---|---\n"
		" %c | %c | %c \n",
		getChar(board, 0),
		getChar(board, 1),
		getChar(board, 2),
		getChar(board, 3),
		getChar(board, 4),
		getChar(board, 5),
		getChar(board, 6),
		getChar(board, 7),
		getChar(board, 8)
	);
}
