#ifndef LOOP_H 
#define LOOP_H 

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <stdbool.h>

void processInput(bool* isRunning);

void render(SDL_Renderer* renderer);

#endif
