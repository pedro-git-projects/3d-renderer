#ifndef DRAW_H
#define DRAW_H 

#include <bits/stdint-uintn.h>

void drawGrid(uint32_t* colorBuffer);
void drawRectangle(int x, int y, int width, int height, uint32_t color, uint32_t* colorBuffer);

#endif
