#include <limits.h>
#include <stdio.h>
#include "Board.h"
#include "Color.h"

#define TO_SIGNED(x) (((x) == 1) ? -1 : 1) 

static int isDraw(Board board)
{
	for (int i = 0; i < 9; i++) 
		if (!Board_Get(board, i))
			return 0;
	return 1;
}

static int negamax(Board board, Color color, int alpha, int beta)
{
	int eval = Board_GetWinner(board);
	if (eval != 0)
		return TO_SIGNED(eval) * TO_SIGNED(color);
	if (isDraw(board)) return 0;

	int bestScore = -2;
	for (int i = 0; i < 9; i++) {
		if (!Board_Get(board, i)) {
			int score = -negamax(
				Board_Set(board, i, color),
				(color ^ 0b11),
				-beta,
				-alpha
			);

			if (score > bestScore)
				bestScore = score;
			if (bestScore > alpha)
				alpha = bestScore;
			if (alpha >= beta)
				break;
		}
	}
	return bestScore;
}

Board solve(Board board, Color color)
{
	int bestScore = -2;
	int bestMove = -1;
	int alpha = -2;
	int beta = 2;

	for (int i = 0; i < 9; i++) {
		if (!Board_Get(board, i)) {
			int score = -negamax(
				Board_Set(board, i, color),
				(color ^ 0b11),
				-beta,
				-alpha
			);

			if (score > bestScore) {
				bestScore = score;
				bestMove = i;
				if (bestScore > alpha)
					alpha = bestScore;
				if (alpha >= beta)
					break;
			} 
		}
	}
	return Board_Set(board, bestMove, color);
}
