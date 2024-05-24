#ifndef _BOARD_H
#define _BOARD_H

#include "AI_Color.h"

#define Board register unsigned int

#define Board_EMPTY ((Board)0b##NONE##NONE##NONE\
							  ##NONE##NONE##NONE\
							  ##NONE##NONE##NONE)

#define Board_GET(board, index) (((board) >> ((index) * 2)) & 0x3)

#define Board_SET(

#endif //_BOARD_H
