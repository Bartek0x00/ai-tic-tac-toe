#ifndef _MAIN_H
#define _MAIN_H

#include "../AI/Color.h"
#include "../AI/Board.h"

extern void *initDisplay(void);
extern int getEvent(unsigned char *output);
extern void drawDisplay(void *display, Board board);
extern void deleteDisplay(void *display);
extern void showText(void *display, char *text, Color color);

extern Board solve(Board board, Color color);

#endif // _MAIN_H
