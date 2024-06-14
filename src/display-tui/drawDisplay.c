#include <stdio.h>
#include "../AI/Board.h"

void drawDisplay(void *display, Board board)
{
	printf(
		"%u |%u |%u "
		"---|---|---"
		"%u |%u |%u "
		"---|---|---"
		"%u |%u |%u \n",
		Board_Get(board, 0),
		Board_Get(board, 1),
		Board_Get(board, 2),
		Board_Get(board, 3),
		Board_Get(board, 4),
		Board_Get(board, 5),
		Board_Get(board, 6),
		Board_Get(board, 7),
		Board_Get(board, 8)
	);

}
