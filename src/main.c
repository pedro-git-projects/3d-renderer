#include "app.h"
#include "loop.h"
#include "window.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	App* app = newApp(); if(!app) return EXIT_FAILURE;
	app->isRunning = true;

	while (app->isRunning) {
		processInput(&app->isRunning);
		render(app->renderer, app->colorBuffer, app->colorBufferTexture);
	}

	destroyApp(app);

	return EXIT_SUCCESS;
}
