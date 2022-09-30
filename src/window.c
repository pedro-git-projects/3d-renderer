#include "window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

SDL_Window* createWindow(void) {
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "::Error initizing SDL.\n"); 
		return NULL;
	}

	SDL_Window* window = SDL_CreateWindow(
			"3dRenderer",
			SDL_WINDOWPOS_CENTERED, 
			SDL_WINDOWPOS_CENTERED,
			800, 
			600, 
			SDL_WINDOW_BORDERLESS
		);

	if(!window) { 
		fprintf(stderr, "::Failed to create window");
		return NULL;
	}

	return window;
};

SDL_Renderer* createRenderer(SDL_Window* window) {
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0); 
	if(!renderer) {
		fprintf(stderr,"::Failed to create renderer"); 
		return NULL;
	}
	return renderer;
}
