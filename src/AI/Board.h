#ifndef _BOARD_H
#define _BOARD_H

#include "Color.h"

typedef unsigned int Board;

#define Board_EMPTY (Board)0

extern const Board Board_WIN_RED[8];
extern const Board Board_WIN_BLUE[8];

extern Color Board_GetWinner(Board board);

inline Board Board_Get(Board board, int index) 
{
	return ((board >> (index * 2)) & 0b11);
}

inline Board Board_Set(Board board, int index, Color color)
{
	int mask = 0b11 << (index * 2);
	return (Board)(board & ~mask) | (color << (index * 2));
}

//Indexes of a Board:
//0 1 2
//3 4 5
//6 7 8

#endif //_BOARD_H
