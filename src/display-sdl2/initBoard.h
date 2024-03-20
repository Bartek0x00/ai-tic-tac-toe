#ifndef _INIT_BOARD_H
#define _INIT_BOARD_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "display.h"

#define WINDOW_TITLE "AI-TIC-TAC-TOE"
#define WINDOW_POS_X SDL_WINDOWPOS_CENTERED
#define WINDOW_POS_Y SDL_WINDOWPOS_CENTERED
#define WINDOW_SIZE 600
#define CELL_SIZE (WINDOW_SIZE / 3)
#define LINE_GIRTH 3

#endif // _INIT_BOARD_H
