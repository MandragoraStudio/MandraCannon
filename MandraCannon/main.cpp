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


int main (int argc, char* argv[])
{
	atexit(SDL_Quit);
	atexit(TTF_Quit);

	TTF_Init();
	SDL_Init(SDL_INIT_VIDEO);

	SSM miPantalla(1280,720, 1280, 720); // construimos la superficie
	miPantalla.fillScreen(45,56,67);
	miPantalla.setWindowsTitle("lo k sea");
	miPantalla.setIcon("recursos/logoventana/logoventana.png");

	SurfaceManager pro(200,100);
	pro.setX(100);
	pro.setY(143);
	pro.fillSurface(255,0,0);
	pro.blitSurface(miPantalla.getSurface());

	pro.setY(323);
	pro.blitSurface(miPantalla.getSurface());

	pro.setY(503);
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
		}
	}
	return 1;
}