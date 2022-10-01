#include "draw.h"
#include "window.h"
#include <bits/stdint-uintn.h>
#include <stdio.h>

void drawGrid(uint32_t* colorBuffer) {
	int h = getDisplayHeight();
	int w = getDisplayWidth();
	for(int y = 0; y < h; y += 10) {
		for(int x = 0; x < w; x += 10) {
			colorBuffer[(w * y) + x] = 0xFF333333;
		}
	}
}

void drawRectangle(int x, int y, int rWidth, int rHeight, uint32_t color, uint32_t* colorBuffer) {
	int winWidth = getDisplayWidth(); 
	for(int i = 0; i < rWidth; i++) {
		for(int j = 0; j < rHeight; j++) {
			int currentX = x + i;
			int currentY = y + j;
			colorBuffer[(winWidth * currentY) + currentX] = color; 
		}
	}
}

void drawPixel(int x, int y, uint32_t color, uint32_t *colorBuffer) {
	int winWidth  = getDisplayWidth();
	int winHeight =  getDisplayHeight();

	if(x < winWidth && y < winHeight) colorBuffer[winWidth * y + x] = color; 
}
