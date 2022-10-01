#include "draw.h"
#include "window.h"
#include <bits/stdint-uintn.h>

void drawGrid(uint32_t* colorBuffer) {
	for(int y = 0; y < getDisplayHeight(); y += 10) {
		for(int x = 0; x < getDisplayWidth(); x += 10) {
			colorBuffer[(getDisplayWidth() * y) + x] = 0xFF333333;
		}
	}
}
