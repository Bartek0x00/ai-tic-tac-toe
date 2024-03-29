#include "display.h"
#include <SDL2/SDL_image.h>

void deleteBoard(void *input)
{
	Display *display = (Display *)input;
	SDL_DestroyTexture(display->circle);
	SDL_DestroyTexture(display->cross);
	SDL_DestroyTexture(display->background);
	SDL_DestroyRenderer(display->renderer);
	SDL_DestroyWindow(display->window);
	IMG_Quit();
	SDL_Quit();
}
