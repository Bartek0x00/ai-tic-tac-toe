#ifndef _MAIN_H
#define _MAIN_H

#include "../AI/Color.h"
#include "../AI/Board.h"

#define T_CLR   "\033[0m"
#define T_RED   "\033[38;5;1m"
#define T_BLUE  "\033[38;5;4m"
#define T_GREEN "\033[38;5;2m"

extern void *initDisplay(void);
extern int getEvent(unsigned char *output);
extern void drawDisplay(void *display, Board board);
extern void deleteDisplay(void *display);

extern Color Solve(Board board);

#endif // _MAIN_H
