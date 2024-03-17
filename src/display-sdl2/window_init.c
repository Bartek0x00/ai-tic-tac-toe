#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "window_settings.h"

int window_init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow(
		WINDOW_TITLE,
		WINDOW_POS_X,
		WINDOW_POS_Y,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN
	);

	if (window == NULL) {
		SDL_Log("Failed to create window: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RENDERER_ACCELERATED
	);

	if (renderer == NULL) {
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}
	
	bool isRunning = true;
	SDL_Event event;
	while (isRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				isRunning = false;
			}
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
