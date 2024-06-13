#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "window.h"
#include "images.h"

static SDL_Texture *loadTexture(SDL_Window *window,
								SDL_Renderer *renderer, 
								void *mem, 
								const unsigned int len,
								const char *name)
{
	SDL_Surface *surface = IMG_Load_RW(
		SDL_RWFromMem(mem, len), 
		1
	);
	if (!surface) {
		SDL_Log(
			"Failed to load surface %s: %s", 
			name, 
			SDL_GetError()
		);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		IMG_Quit();
		TTF_Quit();
		SDL_Quit();
		exit(-1);
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(
		renderer,
		surface
	);
	SDL_FreeSurface(surface);
	if(!texture) {
		SDL_Log(
			"Failed to load texture %s: %s",
			name,
			SDL_GetError()
		);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		IMG_Quit();
		TTF_Quit();
		SDL_Quit();
		exit(-1);
	}

	return texture;
}

void *initDisplay(void)
{
	if (SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log(
			"Failed to init SDL: %s\n", 
			SDL_GetError()
		);
		exit(-1);
	}
	if (!IMG_Init(IMG_INIT_PNG)) {
		SDL_Log(
			"Failed to init IMG: %s\n",
			SDL_GetError()
		);
		SDL_Quit();
		exit(-1);
	}
	if (TTF_Init() == -1) {
		SDL_Log(
			"Failed to init TTF: %s\n",
			SDL_GetError()
		);
		IMG_Quit();
		SDL_Quit();
		exit(-1);
	}

	SDL_Window *window = SDL_CreateWindow(
		WINDOW_TITLE,
		WINDOW_POS_X,
		WINDOW_POS_Y,
		WINDOW_SIZE,
		WINDOW_SIZE + 50,
		SDL_WINDOW_SHOWN
	);
	if (!window) {
		SDL_Log(
			"Failed to create window: %s\n", 
			SDL_GetError()
		);
		IMG_Quit();
		TTF_Quit();
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
			"Failed to create renderer: %s\n", 
			SDL_GetError()
		);
		SDL_DestroyWindow(window);
		IMG_Quit();
		TTF_Quit();
		SDL_Quit();
		exit(-1);
	}
	
	SDL_Texture *background = loadTexture(
		window,
		renderer,
		background_png,
		background_png_len,
		"background.png"
	);
	SDL_Texture *cross = loadTexture(
		window,
		renderer,
		cross_png,
		cross_png_len,
		"cross.png"
	);
	SDL_Texture *circle = loadTexture(
		window,
		renderer,
		circle_png,
		circle_png_len,
		"circle.png"
	);				

	TTF_Font *font = TTF_OpenFont(NULL, 24);
	if (!font) {
		SDL_Log("Failed to load font: %s\n", TTF_GetError());
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
		exit(-1);
	}

	Display *display = malloc(sizeof(Display));
	if (!display) {
		SDL_Log("Failed to allocate memory for the display\n");
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		IMG_Quit();
		TTF_Quit();
		SDL_Quit();
		exit(-1);
	}

	*display = (Display){
		.window = window,
		.renderer = renderer,
		.background = background,
		.circle = circle,
		.cross = cross,
		.font = font
	};

	return (void *)display;
}
