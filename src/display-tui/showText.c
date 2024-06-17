#include <stdio.h>
#include "../AI/Color.h"

#define T_CLR "\033[0m"
#define T_RED "\033[38;5;1m"
#define T_BLUE "\033[38;5;4m"

void showText(char *text, Color color)
{
	char *tColor = "";

	if (color == RED) tColor = T_RED;
	if (color == BLUE) tColor = T_BLUE;

	printf("\n%s%s%s", tColor, text, T_CLR);
}
