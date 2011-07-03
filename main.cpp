// MandraCannon.cpp: define el punto de entrada de la aplicación de consola.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
//#include "SDL_rotozoom.h"
#include "SSM.h"
#include "ImageManager.h"
#include "SpriteManager.h"
#include "textManager.h"
#include "Mouse.h"
#include "ChunkManager.h"
#include "Utilities.h"

int main (int argc, char* argv[])
{
	atexit(SDL_Quit);
	atexit(TTF_Quit);
	atexit(Mix_CloseAudio);

	TTF_Init();
	SDL_Init(SDL_INIT_VIDEO);
	Mix_OpenAudio(22050,AUDIO_S16,2,4096);
	
	SSM miPantalla(800,600, 1280, 720);
	miPantalla.setWindowsTitle("titulo");
	miPantalla.setIcon("recursos/logoventana/logoventana.png");

	printf("%d", sizeof(miPantalla));
	miPantalla.flip();

	SDL_Event event;
	int done = 0;
	MouseEvent evrat;

		double i = 30.0;
		while(done==0){	
		miPantalla.fillScreen(45,56,67);
		miPantalla.flip();
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_KEYUP){
				if (event.key.keysym.sym == SDLK_ESCAPE){
					done = 1;
				}
			}else if (event.type == SDL_VIDEORESIZE){
				miPantalla.setResolution(event.resize.w,event.resize.h);
			}else if (event.type == SDL_QUIT){
				done = 1;
			}
		}
		
	}
	return 1;
}