#include "window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <bits/stdint-uintn.h>
#include <stdio.h>
#include <sys/types.h>

const uint32_t WINWIDTH = 800;
const uint32_t WINHEIGHT = 600;

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

uint32_t* createColorBuffer(void) {
	uint32_t* colorBuffer = (uint32_t*) malloc(sizeof(uint32_t) * WINWIDTH * WINHEIGHT);	
	if(!colorBuffer) {
		fprintf(stderr, "::Failed to create color buffer");
		return NULL;
	}
	return colorBuffer;
}

void destroyWindow(SDL_Window *window, SDL_Renderer *renderer, u_int32_t *colorBuffer) {
	free(colorBuffer);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
};
