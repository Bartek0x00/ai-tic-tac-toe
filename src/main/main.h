#ifndef _MAIN_H
#define _MAIN_H

#include "board.h"
#include <stdbool.h>

enum Response {
	ONGOING,
	LOST,
	WIN
};

enum Color {
	NONE,
	RED,
	BLUE
};

void *initBoard(void);
void drawBoard(void *display, unsigned int board[]);
void deleteBoard(void *display);

enum Response AI_Solve(unsigned int board[]);

#endif // _MAIN_H
