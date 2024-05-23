#ifndef _WINDOW_H
#define _WINDOW_H

#include <SDL2/SDL.h>
#include "display.h"

#define WINDOW_TITLE "AI-TIC-TAC-TOE"
#define WINDOW_POS_X SDL_WINDOWPOS_CENTERED
#define WINDOW_POS_Y SDL_WINDOWPOS_CENTERED
#define WINDOW_SIZE 600
#define GRID_SIZE 3
#define CELL_SIZE (WINDOW_SIZE / GRID_SIZE)

#endif // _WINDOW_H
