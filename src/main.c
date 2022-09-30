#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <bits/stdint-uintn.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "loop.h"
#include "window.h"

int main(void) {
	bool isRunning = false;	

	SDL_Window* window = createWindow(); 
	if(!window) EXIT_FAILURE; 

	SDL_Renderer* renderer = createRenderer(window);
	if(!renderer) EXIT_FAILURE;
	isRunning = true;
	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	uint32_t* colorBuffer = createColorBuffer(); 
	if(!colorBuffer) EXIT_FAILURE;

	SDL_Texture* colorBufferTexture = SDL_CreateTexture(
			renderer, 
			SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING,
			WINWIDTH, 
			WINHEIGHT
		); 
	if(!colorBufferTexture) EXIT_FAILURE;

	while (isRunning) {
		processInput(&isRunning);
		render(renderer, colorBuffer, colorBufferTexture);
	}

	destroyWindow(window, renderer, colorBuffer);
	
	return EXIT_SUCCESS;
}
