#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "display.h"
#include "../AI/Color.h"

void terminate(int stage);

void showText(char *text, Color color)
{
	SDL_Color textColor = {0, 0, 0, 255};

	if (!color) {
		textColor.r = 227;
		textColor.g = 227;
		textColor.b = 227;
	} 
	if (color == RED)
		textColor.r = 255;
	if (color == BLUE)
		textColor.b = 255;
	
	SDL_Surface *textSurface = TTF_RenderText_Blended(
		display.font, 
		text,
		textColor
	);
	if (!textSurface) {
		SDL_Log(
			"Failed to create textSurface: %s\n",
			TTF_GetError()	
		);
		terminate(4);
		exit(-1);
	}

	SDL_Texture *textTexture = SDL_CreateTextureFromSurface(
		display.renderer,
		textSurface
	);
	if (!textTexture) {
		SDL_Log(
			"Failed to create textTexture: %s\n",
			SDL_GetError()
		);
		SDL_FreeSurface(textSurface);
		terminate(4);
		exit(-1);
	}
	
	SDL_Rect textRect = {0, 600, 600, 50};

	SDL_SetRenderDrawColor(display.renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(display.renderer, &textRect);

	textRect.w = (strlen(text) * 16);
	textRect.x = 300 - (textRect.w / 2);
	SDL_RenderCopy(display.renderer, textTexture, NULL, &textRect);

	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
}
