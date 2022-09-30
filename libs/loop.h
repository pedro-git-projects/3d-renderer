#ifndef LOOP_H 
#define LOOP_H 

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <bits/stdint-uintn.h>
#include <stdbool.h>

void processInput(bool* isRunning);
void renderColorBuffer(SDL_Renderer* renderer, uint32_t* colorBuffer, SDL_Texture* colorBufferTexture);
void clearColorBuffer(uint32_t* colorBuffer, uint32_t color);
void render(SDL_Renderer* renderer, uint32_t* colorBuffer, SDL_Texture* colorBufferTexture);

#endif
