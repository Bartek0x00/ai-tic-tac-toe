#ifndef _MAIN_H
#define _MAIN_H

#include "../AI/AI_Response.h"
#include "../AI/AI_Color.h"
#include "../AI/Board.h"

#define T_CLR "\033[0m"
#define T_RED "\033[38;5;1m"
#define T_BLUE "\033[38;5;4m"

void *initBoard(void);
int getEvent(char *output);
void drawBoard(void *display, Board board);
void deleteBoard(void *display);

AI_Response AI_Solve(Board board);

#endif // _MAIN_H
