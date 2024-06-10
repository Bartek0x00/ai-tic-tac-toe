#include <limits.h>
#include <stdio.h>
#include "Board.h"
#include "Color.h"

static int negamax(Board board, int depth, Color color)
{
	int score = Board_GetWinner(board);
	if (score == 1) score = -1;
	if (score == 2) score = 1;
	if (!score || depth >= 3) return color * score;
	
	int bestVal = INT_MIN;
	for (int i = 0; i < 9; i++) {
		if (!Board_Get(board, i)) {
			board = Board_Set(board, i, color);
			
			int value = -negamax(board, ++depth, (color ^ 0b11));
			
			board = Board_Set(board, i, NONE);

			if (value > bestVal)
				bestVal = value;
		}
	}
	return bestVal;
}

Board solve(Board board, Color color)
{
	Board ret = Board_Set(board, negamax(board, 0, color), color);
	printf("%u", ret);
	return ret;
}
