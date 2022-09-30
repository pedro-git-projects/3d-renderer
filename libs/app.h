#ifndef APP_H 
#define APP_H 

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <bits/stdint-uintn.h>
#include <stdbool.h>

typedef struct App {
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	uint32_t* colorBuffer;	
	SDL_Texture* colorBufferTexture;
} App;

App* newApp();
void destroyApp(App* app);

#endif
