#ifndef _ANSI_H
#define _ANSI_H

//Cursor manipulating
#define CURSOR_UP	 "\033[A" 
#define CURSOR_DOWN  "\033[B"
#define CURSOR_RIGHT "\033[C"
#define CURSOR_LEFT  "\033[D"
#define CURSOR_PREV  "\033[F"
#define CURSOR_NEXT  "\033[G"
#define CURSOR_START "\033[H"
#define CURSOR_TOCOL "\033[G"
#define CURSOR_SAVE  "\033[s"
#define CURSOR_LOAD  "\033[u"
#define CURSOR(x, y) printf("\033[%d;%dH", y, x)

//Text formatting
#define FORMAT_RESET "\033[0m"
#define FORMAT_BOLD  "\033[1m"
#define FORMAT_FAINT "\033[2m"
#define FORMAT_UNDER "\033[4m"
#define FORMAT_BLINK "\033[5m"

//Text foreground color
#define FCOLOR_BLACK "\033[30m"
#define FCOLOR_RED   "\033[31m"
#define FCOLOR_GREEN "\033[32m"
#define FCOLOR_BLUE  "\033[34m"
#define FCOLOR_WHITE "\033[37m"
#define FCOLOR(r, g, b) printf("\033[38;2;%d;%d;%dm", r, g, b)

//Text background color
#define BCOLOR_BLACK "\033[40m"
#define BCOLOR_RED   "\033[41m"
#define BCOLOR_GREEN "\033[42m"
#define BCOLOR_BLUE  "\033[44m"
#define BCOLOR_WHITE "\033[47m"
#define BCOLOR(r, g, b) printf("\033[48;2;%d;%d;%dm", r, g, b)

//Screen clear options
#define CLEAR_EOL	 "\033[K"
#define CLEAR_LINE   "\033[2K"
#define CLEAR_EOS    "\033[J"
#define CLEAR_SCREEN "\033[2J"

#endif //_ANSI_H
