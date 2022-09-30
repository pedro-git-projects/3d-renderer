#include "app.h"
#include "window.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <bits/stdint-uintn.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

App* newApp() {
	App* a = malloc(sizeof(App));
	a->isRunning = false;

	SDL_Window* w = createWindow(); if(!w) return NULL; 
	a->window = w;

	SDL_Renderer* r = createRenderer(w); if (!r) return NULL;
	a->renderer = r; 

	uint32_t* c = createColorBuffer(); if (!c) return NULL;
	a->colorBuffer = c;

	SDL_Texture* t = SDL_CreateTexture(
			r, 
			SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING,
			WINWIDTH, 
			WINHEIGHT
			); if (!t) return  NULL; 
	a->colorBufferTexture = t;

	return a;
}

void destroyApp(App* app) {
	free(app->colorBuffer);
	SDL_DestroyRenderer(app->renderer);
	SDL_DestroyWindow(app->window);
	SDL_Quit();
}
