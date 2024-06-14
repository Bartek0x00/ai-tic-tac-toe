#include <stdio.h>

void *initDisplay(void)
{
	puts(
		"\tTIC-TAC-TOE"
		"To make a move, enter the index:"
		" 0 | 1 | 2 "
		"---|---|---"
		" 3 | 4 | 5 "
		"---|---|---"
		" 6 | 7 | 8 "
	);
	return NULL;
}
