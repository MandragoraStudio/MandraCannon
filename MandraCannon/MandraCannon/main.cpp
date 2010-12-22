// MandraCannon.cpp: define el punto de entrada de la aplicación de consola.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_rotozoom.h"
#include "SSM.h"



int main(int argc, char* argv[])
{
	SDL_Surface *screen, *image, *rot;
	SDL_Rect dest, rrot;
	SDL_Event event;
	int done = 0;
	SSM pantalla;

	atexit(SDL_Quit);

	SDL_Init(SDL_INIT_VIDEO);
	//SDL_ShowCursor(SDL_DISABLE);

	//pantalla.enabledFullScreen();
	pantalla.setResolution(PANORAMICSMALL);
	pantalla.setWindowsTitle("Amono señoresss");
	pantalla.setIcon("recursos/logoventana/logoventana.png");
	screen = pantalla.getSurface();
	
	printf("%f", pantalla.getPercent());
	image = IMG_Load("recursos/pruebas/pra.png");

	dest.x = 200;
	dest.y = 200;
	dest.w = image->w;
	dest.h = image->h;

	rot = IMG_Load("recursos/pruebas/rot.png");

	rrot.x = 0;
	rrot.y = 0;
	rrot.w = rot->w;
	rrot.h = rot->h;

	image = rotozoomSurface(image, 45, 2.5,  1);


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
