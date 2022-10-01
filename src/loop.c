#include "loop.h"
#include "draw.h"
#include "window.h"
#include <SDL2/SDL_render.h>
#include <bits/stdint-uintn.h>
#include <stdint.h>
#include <stdlib.h>

void processInput(bool* isRunning) {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch(event.type) {
		case SDL_QUIT:
			*isRunning = false;
			break;
		case SDL_KEYDOWN:
			if(event.key.keysym.sym == SDLK_ESCAPE) *isRunning = false;
			break;
	}
}

void renderColorBuffer(SDL_Renderer* renderer, uint32_t* colorBuffer, SDL_Texture* colorBufferTexture) {
	SDL_UpdateTexture(
			colorBufferTexture, 
			NULL, 
			colorBuffer,
			(int)(WINWIDTH * sizeof(uint32_t))
		);
	SDL_RenderCopy(
			renderer, 
			colorBufferTexture, 
			NULL, 
			NULL
		);
}

void clearColorBuffer(uint32_t *colorBuffer, uint32_t color) {
	for(int y = 0; y < WINHEIGHT; y++) {
		for(int x = 0; x < WINWIDTH; x++) {
			colorBuffer[(WINWIDTH * y) + x] = color;
		}
	}
}

void render(SDL_Renderer* renderer, uint32_t* colorBuffer, SDL_Texture* colorBufferTexture) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	drawGrid(colorBuffer);
	drawRectangle(300, 200, 300, 150, 0xFFFF00FF, colorBuffer);
	renderColorBuffer(renderer, colorBuffer, colorBufferTexture);
	clearColorBuffer(colorBuffer, 0xFF000000);
	SDL_RenderPresent(renderer);
}


