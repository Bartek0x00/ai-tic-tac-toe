#include <stdio.h>
#include <unistd.h>

int getEvent(unsigned char *output)
{
	scanf("%c", output);
	ioctl(stdin, TCFLSH, TCIFLUSH);
	if (*output == 'q') return true;
	if ((*output >= '0') && (*output <= '8')) return true;
	return false;
}
