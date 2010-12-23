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
	int i = 1;
	SSM pantalla;
	Uint8 *keys;

	atexit(SDL_Quit);

	SDL_Init(SDL_INIT_VIDEO);
	//SDL_ShowCursor(SDL_DISABLE);

	//pantalla.enabledFullScreen();
	pantalla.setResolution(PANORAMICSMALL);
	pantalla.setWindowsTitle("MandraCannon");
	pantalla.setIcon("recursos/logoventana/logoventana.png");
	screen = pantalla.getSurface();
	
	printf("%f", pantalla.getPercent());
	
	image = IMG_Load("recursos/pruebas/pra.png");

	dest.x = 100;
	dest.y = 200;
	dest.w = image->w;
	dest.h = image->h;
	
	rot = IMG_Load("recursos/pruebas/rot.png");

	rrot.x = 10;
	rrot.y = 10;
	rrot.w = rot->w;
	rrot.h = rot->h;

	image = rotozoomSurface(image, 135, 3.2, 1);
	
	SDL_BlitSurface(rot, NULL, screen, &rrot);
	SDL_BlitSurface(image, NULL, screen, &dest);
	
	SDL_Flip(screen);

	keys=SDL_GetKeyState(NULL);
	
	if(keys[SDLK_w] == 1){
		rrot.y=rrot.y-(5);
	}
	if(keys[SDLK_s] == 1){
		rrot.y=rrot.y+(5);
	}
	if(keys[SDLK_d] == 1){
		rrot.x=rrot.x+(5);
	}
	if(keys[SDLK_a] == 1){
		rrot.x=rrot.x-(5);
	}

	while(done==0){
		while (SDL_PollEvent(&event)){
			if (keys[SDLK_ESCAPE] == 1){
				done = 1;
			}
		}
	}

	SDL_FreeSurface(image);
	SDL_FreeSurface(rot);
	
	return 0;
}
