#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "../AI/Board.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/html5.h>
#endif 
	
static unsigned int isPlayerMove = 0;
static unsigned char input = '\0';
static char buffer[32] = {'\0'};
static unsigned int remainingMoves = 9;
static unsigned int gameOver = 0;
static Color playerColor = 0;

static void User(void);
static void Algorithm(void);
static inline _Noreturn void Exit(void);
static Board board = Board_EMPTY;	

static void Algorithm(void)
{
	drawDisplay(board);
	Color winner = Board_GetWinner(board);

	if (winner) {
		showText("You've lost\n", RED);
		gameOver = 1;
		User();
	}

	if (!remainingMoves) {
		showText("It's a tie\n", BLUE);	
		gameOver = 1;
		User();
	}

#ifdef __EMSCRIPTEN__
	double startTime = emscripten_performance_now();

	board = solve(board, (playerColor ^ 0b11));

	double endTime = emscripten_performance_now();
	long elapsedTime = (long)((endTime - startTime) * 1e6);
#else
	struct timespec startTime, endTime;
	clock_gettime(CLOCK_MONOTONIC, &startTime);

	board = solve(board, (playerColor ^ 0b11));
		
	clock_gettime(CLOCK_MONOTONIC, &endTime);
	long elapsedTime = (endTime.tv_nsec - startTime.tv_nsec);
#endif
	sprintf(
		buffer,
		"Solve time: %ldns\n", 
		elapsedTime
	);
	showText(buffer, NONE);

	if (!(--remainingMoves) || Board_GetWinner(board)) 
		Algorithm();
}

static void User(void)
{
	drawDisplay(board); 
	while(!getEvent(&input))
	{
#ifdef __EMSCRIPTEN__
		emscripten_sleep(1);
#endif
	}

	if (input == 'q') Exit();
	if (gameOver) User();
	if (!Board_Get(board, (input - '0'))) {
		board = Board_Set(board, (input - '0'), playerColor);
		remainingMoves--;
	} else {
		User();
	}		
}

static void main_loop(void)
{
	if (isPlayerMove) {
		User();
		isPlayerMove = 0;
	}

	Algorithm();
	User();
}

static inline _Noreturn void Exit(void)
{
	deleteDisplay();
	exit(0);	
}

int main(void)
{
	initDisplay(); 
	
	srand(time(0));
	playerColor = (rand() % 2) + 1;

	if (playerColor == RED) {
		showText("You're red cross X\n", RED);
		isPlayerMove = 1;
	} else
		showText("You're blue circle O\n", BLUE);
	
#ifdef __EMSCRIPTEN__
	emscripten_set_main_loop(main_loop, 0, 1);
#else
	while (1) {
		main_loop();
	}
#endif 
}
