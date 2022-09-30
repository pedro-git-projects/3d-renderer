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

	uint32_t* colorBuffer = createColorBuffer(); 
	if(!colorBuffer) EXIT_FAILURE;
	

	while (isRunning) {
		processInput(&isRunning);
		render(renderer);
	}

	destroyWindow(window, renderer, colorBuffer);
	
	return EXIT_SUCCESS;
}
