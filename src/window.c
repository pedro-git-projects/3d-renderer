#include "window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <bits/stdint-uintn.h>
#include <stdio.h>
#include <sys/types.h>

uint32_t WINWIDTH = 800;
uint32_t WINHEIGHT = 600;

SDL_DisplayMode displayMode;

void setDisplayMode() {
	for(int i = 0; i < SDL_GetNumVideoDisplays(); i++) {
		int err = SDL_GetCurrentDisplayMode(i, &displayMode);
		
		if(err != 0) fprintf(stderr, "Could not get display mode for video display #%d: %s", i, SDL_GetError());
      
		SDL_Log("Display #%d: current display mode is %dx%dpx @ %dhz.", i, displayMode.w, displayMode.h, displayMode.refresh_rate);	
		WINWIDTH = displayMode.w;
		WINHEIGHT = displayMode.h;
	}
}

int getDisplayHeight() {
	return displayMode.h; 
}

int getDisplayWidth() {
	return displayMode.w; 
}

void setWinSize() {
	SDL_GetCurrentDisplayMode(0, &displayMode);
	WINWIDTH = displayMode.w;
	WINHEIGHT = displayMode.h;
}

SDL_Window* createWindow(void) {
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "::Error initizing SDL.\n"); 
		return NULL;
	}

	setDisplayMode();

	SDL_Window* window = SDL_CreateWindow(
			"3dRenderer",
			SDL_WINDOWPOS_CENTERED, 
			SDL_WINDOWPOS_CENTERED,
			WINWIDTH, 
			WINHEIGHT, 
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
