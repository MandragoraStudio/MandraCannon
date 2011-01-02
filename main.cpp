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
#include "SurfaceManager.h"
#include "textManager.h"
#include "Mouse.h"
#include "ChunkManager.h"


int main (int argc, char* argv[])
{
	atexit(SDL_Quit);
	atexit(TTF_Quit);
	atexit(Mix_CloseAudio);

	TTF_Init();
	SDL_Init(SDL_INIT_VIDEO);
	Mix_OpenAudio(22050,AUDIO_S16,2,4096);

	ChunkManager igame;
	igame.setMaxChannels(8);
	igame.loadChunk("recursos/finfase.wav");
	igame.playChunk(REPEAT);

	SSM miPantalla(1280,720, 1280, 720); // construimos la superficie
	miPantalla.fillScreen(45,56,67);
	miPantalla.setWindowsTitle("lo k sea");
	miPantalla.setIcon("recursos/logoventana/logoventana.png");
	SDL_ShowCursor(SDL_DISABLE);
	SDL_ShowCursor(SDL_ENABLE);

	// raton
	Mouse raton;

	SurfaceManager pro(175,75);
	pro.setX(100);
	pro.setY(143);
	pro.fillSurface(255,0,0);
	pro.blitSurface(miPantalla.getSurface());

	TextManager lanza;
	lanza.loadFont("recursos/pruebas/ariblk.ttf");
	lanza.setTextSize(30);
	lanza.setFontStyle(ITALIC|UNDERLINE);
	lanza.setTextColor(255,0,0);
	lanza.setText("Lanzamiento de Last Hope");
	lanza.setX(370);
	lanza.setOpacity(120);
	lanza.escalate(0.8);
	lanza.rotate(67);

	lanza.blitSurface(miPantalla.getSurface());
	
	miPantalla.flip();

	SDL_Event event;
	int done = 0;
	MouseEvent evrat;

	while(done==0){
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
			if (raton.over(pro.getRect()) == true)
			{
				miPantalla.fillScreen(45,56,67);
				pro.blitSurface(miPantalla.getSurface());
				lanza.blitSurface(miPantalla.getSurface());
				miPantalla.flip();
			} else{
				miPantalla.fillScreen(45,56,67);
				pro.blitSurface(miPantalla.getSurface());
				miPantalla.flip();
			}

			
			if (raton.overReleased(pro.getRect(),event) == true){
				done = 1;
			}
		}
		
	}
	return 1;
}