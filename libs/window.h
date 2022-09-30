#ifndef WINDOW_H 
#define WINDOW_H 

#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>
#include <bits/stdint-uintn.h>
#include <sys/types.h>

extern const u_int32_t WINWIDTH;
extern const u_int32_t WINHEIGHT;

SDL_Window* createWindow(void);
SDL_Renderer* createRenderer(SDL_Window*);
uint32_t * createColorBuffer(void);
void destroyWindow(SDL_Window* window, SDL_Renderer* renderer, uint32_t* colorBuffer);

#endif
