#ifndef _MAIN_H
#define _MAIN_H

#define T_CLR "\033[0m"
#define T_RED "\033[38;5;1m"
#define T_BLUE "\033[38;5;4m"

typedef enum {
	ONGOING,
	LOST,
	WIN
} Response;

typedef enum {
	NONE,
	RED,
	BLUE
} Color;

void *initBoard(void);
void drawBoard(void *display, unsigned int board[]);
void deleteBoard(void *display);

Response AI_Solve(unsigned int board[]);

#endif // _MAIN_H
