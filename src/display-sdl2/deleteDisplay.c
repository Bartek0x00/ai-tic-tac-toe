#include "display.h"

void deleteDisplay(void *displayRaw)
{
	Display *display = (Display *)displayRaw;
	SDL_DestroyTexture(display->circle);
	SDL_DestroyTexture(display->cross);
	SDL_DestroyTexture(display->background);
	SDL_DestroyRenderer(display->renderer);
	SDL_DestroyWindow(display->window);
	SDL_Quit();
	free(display);
}
