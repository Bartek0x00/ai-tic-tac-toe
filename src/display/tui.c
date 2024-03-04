#include <stdio.h>
#include "ansi.h"
#include <stdlib.h>

//Creates empty board
void initBoard()
{
	printf("%s", CURSOR_NEXT);
	printf("%sTIC ", FCOLOR_RED);
	printf("%sTAC ", FCOLOR_GREEN);
	printf("%sTOE\n", FCOLOR_BLUE);
}
