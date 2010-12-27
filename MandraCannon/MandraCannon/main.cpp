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

int main(int argc, char* argv[])
{
	SDL_Event event;
	int done = 0;
	ImageManager imagen;
	ImageManager robot;
	SpriteManager sprite(2,3);
	SSM pantalla(1000,600, 1600, 900);
	SurfaceManager misuperficie(800,600);
	ImageManager boton1;
	ImageManager boton2;
	SpriteManager caca(1,1);

	atexit(SDL_Quit);

	SDL_Init(SDL_INIT_VIDEO);
	//SDL_ShowCursor(SDL_DISABLE);

	pantalla.setWindowsTitle("Amono señoresss");
	pantalla.setIcon("recursos/logoventana/logoventana.png");
	
	
	printf("%d\n", pantalla.getWIDTHborder());
	printf("%d\n", pantalla.getHEIGHTborder());
	imagen.loadImage("recursos/pruebas/pra.png");
	imagen.setX(600);
	imagen.setY(200);
	imagen.rotate(120);
	imagen.escalate(0.8);

	robot.loadImage("recursos/pruebas/rot.png");
	robot.setX(250);
	
	sprite.loadImage("recursos/pruebas/verde.jpg");
	sprite.setInstance(4);
	
	sprite.setAlpha(120);
	sprite.setTransparency(255,255,255);
	sprite.escalate(0.8);
	sprite.rotateCentre(56);

	caca.loadImage("recursos/pruebas/boton.jpg");
	
	caca.rotate(130);
	caca.setAlpha(120);
	caca.escalate(1.3);
	caca.rotate(130);
	caca.setX(150);
	caca.setY(0);

	// botones
	boton1.loadImage("recursos/pruebas/boton.jpg");
	boton2.loadImage("recursos/pruebas/boton.jpg");

	boton1.setX(150);
	boton1.setY(150);
	boton2.setX(250);
	boton2.setY(150);

	boton1.setAlpha(120);
	boton2.rotateCentre(56);
	
	boton2.escalate(0.3);
	//boton2.setAlpha(120);
	

	pantalla.fillScreen(120,45,211);
	misuperficie.fillSurface(45,134,67);
	
	misuperficie.setAlpha(120);

	robot.blitSurface(misuperficie.getSurface());

	

	sprite.blitSurface(pantalla.getSurface());
	caca.blitSurface(pantalla.getSurface());
		
	
	imagen.blitSurface(pantalla.getSurface());

	boton2.blitSurface(misuperficie.getSurface());
	boton1.blitSurface(misuperficie.getSurface());
	misuperficie.setX(300);
	misuperficie.setY(300);

	misuperficie.blitSurface(pantalla.getSurface());

	
	
	pantalla.flip();

	printf("%lf", pantalla.getPercent());

	imagen.~ImageManager();
	sprite.~SpriteManager();
	robot.~ImageManager();

	while(done==0){
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_KEYDOWN){
				done = 1;
			} else if (event.type == SDL_VIDEORESIZE){
				pantalla.setResolution(event.resize.w, event.resize.h);
			}else if (event.type == SDL_QUIT){
				done = 1;
			}
		}
	}
	return 1;
}
