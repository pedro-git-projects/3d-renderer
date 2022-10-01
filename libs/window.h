#ifndef WINDOW_H 
#define WINDOW_H 

#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <bits/stdint-uintn.h>
#include <sys/types.h>

extern u_int32_t WINWIDTH;
extern u_int32_t WINHEIGHT;

SDL_Window* createWindow(void);
SDL_Renderer* createRenderer(SDL_Window*);
uint32_t * createColorBuffer(void);
void destroyWindow(SDL_Window* window, SDL_Renderer* renderer, uint32_t* colorBuffer);
void setWinSize();
void setDisplayMode();
int getDisplayHeight();
int getDisplayWidth();

#endif
