#include <stdlib.h>
#include <SDL2/SDL.h>
#include "window.h"
#include "images.h"

void *initDisplay(void)
{
	if (SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log(
			"Failed to initialize SDL: %s", 
			SDL_GetError()
		);
		exit(-1);
	}

	SDL_Window *window = SDL_CreateWindow(
		WINDOW_TITLE,
		WINDOW_POS_X,
		WINDOW_POS_Y,
		WINDOW_SIZE,
		WINDOW_SIZE,
		SDL_WINDOW_SHOWN
	);
	if (!window) {
		SDL_Log(
			"Failed to create window: %s", 
			SDL_GetError()
		);
		SDL_Quit();
		exit(-1);
	}
	
	SDL_Renderer *renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RENDERER_ACCELERATED
	);
	if (!renderer) {
		SDL_Log(
			"Failed to create renderer: %s", 
			SDL_GetError()
		);
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(-1);
	}

	SDL_RWops *rw = SDL_RWFromConstMem(
		background_bmp, 
		background_bmp_len
	);
	if (!rw) {
		SDL_Log(
			"Failed to create RWops from memory: %s",
			SDL_GetError()
		);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(-1);
	}

	SDL_Surface *surface = SDL_LoadBMP_RW(rw, 1);
	if(!surface) {
		SDL_Log(
			"Failed to load an image %s\n %s",
			"background.bmp",
			SDL_GetError()
		);
		SDL_RWclose(rw);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(-1);
	}

	SDL_Texture *background = SDL_CreateTextureFromSurface(
		renderer,
		surface
	);
	SDL_FreeSurface(surface);
	if (!background) {
		SDL_Log(
			"Failed to create a texture from %s\n %s",
			"background.bmp",
			SDL_GetError()
		);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(-1);
	}
	
	rw = SDL_RWFromConstMem(
		cross_bmp, 
		cross_bmp_len
	);
	if (!rw) {
		SDL_Log(
			"Failed to create RWops from memory: %s",
			SDL_GetError()
		);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(-1);
	}

	surface = SDL_LoadBMP_RW(rw, 1);
	if(!surface) {
		SDL_Log(
			"Failed to load an image %s\n %s",
			"cross.bmp",
			SDL_GetError()
		);
		SDL_RWclose(rw);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(-1);
	}

	SDL_Texture *cross = SDL_CreateTextureFromSurface(
		renderer,
		surface
	);
	SDL_FreeSurface(surface);
	if (!cross) {
		SDL_Log(
			"Failed to create a texture from %s\n %s",
			"cross.png",
			SDL_GetError()
		);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(-1);
	}
		
	rw = SDL_RWFromConstMem(
		circle_bmp, 
		circle_bmp_len
	);
	if (!rw) {
		SDL_Log(
			"Failed to create RWops from memory: %s",
			SDL_GetError()
		);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(-1);
	}

	surface = SDL_LoadBMP_RW(rw, 1);
	if(!surface) {
		SDL_Log(
			"Failed to load an image %s\n %s",
			"circle.bmp",
			SDL_GetError()
		);
		SDL_RWclose(rw);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(-1);
	}

	SDL_Texture *circle = SDL_CreateTextureFromSurface(
		renderer, surface	
	);
	SDL_FreeSurface(surface);
	if (!circle) {
		SDL_Log(
			"Failed to create a texture from %s\n %s",
			"circle.png",
			SDL_GetError()
		);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(-1);
	}
	
	Display *display = malloc(sizeof(Display));
	if (display == NULL) {
		SDL_Log("Failed to allocate memory for the display\n");
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(-1);
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
