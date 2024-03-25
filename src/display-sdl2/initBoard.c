#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "initBoard.h"
#include "images.h"

void *initBoard()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log(
			"Failed to initialize SDL: %s", 
			SDL_GetError()
		);
		exit(EXIT_FAILURE);
	}

	SDL_Window *window = SDL_CreateWindow(
		WINDOW_TITLE,
		WINDOW_POS_X,
		WINDOW_POS_Y,
		WINDOW_SIZE,
		WINDOW_SIZE,
		SDL_WINDOW_SHOWN
	);

	if (window == NULL) {
		SDL_Log(
			"Failed to create window: %s", 
			SDL_GetError()
		);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
	
	SDL_Renderer *renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RENDERER_ACCELERATED
	);

	if (renderer == NULL) {
		SDL_Log(
			"Failed to create renderer: %s", 
			SDL_GetError()
		);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		SDL_Log(
			"Failed to initialize img: %s",
			SDL_GetError()
		);
		exit(EXIT_FAILURE);
	}

	SDL_Surface *surface;
	surface = IMG_Load_RW(
		SDL_RWFromMem(
			background_png, 
			background_png_len 
		),
		1
	);
	if(surface == NULL) {
		SDL_Log(
			"Failed to load an image %s\n %s",
			"background.png",
			SDL_GetError()
		);
		exit(EXIT_FAILURE);
	}
	SDL_Texture *background = SDL_CreateTextureFromSurface(
		renderer,
		surface
	);
	SDL_FreeSurface(surface);
	if (background == NULL) {
		SDL_Log(
			"Failed to create a texture from %s\n %s",
			"background.png",
			SDL_GetError()
		);
		exit(EXIT_FAILURE);
	}

	surface = IMG_Load_RW(
		SDL_RWFromMem(
			circle_png,
			circle_png_len
		),
		1
	);
	if (surface == NULL) {
		SDL_Log(
			"Failed to load an image %s\n %s",
			"circle.png",
			SDL_GetError()
		);
		exit(EXIT_FAILURE);
	}
	SDL_Texture *circle = SDL_CreateTextureFromSurface(
		renderer,
		surface
	);
	SDL_FreeSurface(surface);
	if (circle == NULL) {
		SDL_Log(
			"Failed to create a texture from %s\n %s",
			"circle.png",
			SDL_GetError()
		);
		exit(EXIT_FAILURE);
	}

	surface = IMG_Load_RW(
		SDL_RWFromMem(
			cross_png,
			cross_png_len
		),
		1
	);
	if (surface == NULL) {
		SDL_Log(
			"Failed to load an image %s\n %s",
			"cross.png",
			SDL_GetError()
		);
		exit(EXIT_FAILURE);
	}
	SDL_Texture *cross = SDL_CreateTextureFromSurface(
		renderer, surface	
	);
	SDL_FreeSurface(surface);
	if (cross == NULL) {
		SDL_Log(
			"Failed to create a texture from %s\n %s",
			"cross.png",
			SDL_GetError()
		);
		exit(EXIT_FAILURE);
	}
	
	Display *display = malloc(sizeof(Display));
	if (display == NULL) {
		fprintf(
			stderr, 
			"Failed to allocate memory for the board\n"
		);
		exit(EXIT_FAILURE);
	}

	*display = (Display){
		.window = window,
		.renderer = renderer,
		.background = background,
		.circle = circle,
		.cross = cross
	};

	return (void *)display;
}
