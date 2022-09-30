#ifndef WINDOW_H 
#define WINDOW_H 

#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>

SDL_Window* createWindow(void);
SDL_Renderer* createRenderer(SDL_Window*);

#endif
