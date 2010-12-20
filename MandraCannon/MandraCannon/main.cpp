// MandraCannon.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"



int main(int argc, char* argv[])
{
	SDL_Surface *screen, *image, *rot;
	SDL_Rect dest, rrot;
	SDL_Event event;
	int done = 0;

	atexit(SDL_Quit);

	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(640,480,24,SDL_HWSURFACE);

	printf("Se carga la imagen\n");
	image = IMG_Load("pra.png");

	dest.x = 0;
	dest.y = 0;
	dest.w = image->w;
	dest.h = image->h;

	rot = IMG_Load("rot.png");

	rrot.x = 0;
	rrot.y = 0;
	rrot.w = rot->w;
	rrot.h = rot->h;

	SDL_BlitSurface(rot, NULL, screen, &rrot);
	SDL_BlitSurface(image, NULL, screen, &dest);
	SDL_Flip(screen);

	SDL_FreeSurface(image);
	SDL_FreeSurface(rot);

	while(done==0){
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_KEYDOWN){
				done = 1;
			}
		}
	}
	return 1;
}
