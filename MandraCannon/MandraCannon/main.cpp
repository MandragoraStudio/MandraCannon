// MandraCannon.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "SDL.h"


int main(int argc, char* argv[])
{
	SDL_Surface *screen;
	SDL_Event event;
	int done = 0;

	atexit(SDL_Quit);

	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(640,480,24,SDL_HWSURFACE);

	while(done==0){
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_KEYDOWN){
				done = 1;
			}
		}
	}
	return 1;
}
