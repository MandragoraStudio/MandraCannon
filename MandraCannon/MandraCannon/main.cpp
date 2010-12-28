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


int main (int argc, char* argv[])
{
	atexit(SDL_Quit);
	SDL_Init(SDL_INIT_VIDEO);

	SSM main_screen(800, 600, 1280, 800);
	main_screen.fillScreen(255,0,0);


	SpriteManager spri(2,3);
	spri.loadImage("recursos/pruebas/verde.jpg");
	spri.setInstance(4);
	spri.setColorKey(255,255,255);
	spri.setOpacity(100);
	spri.rotate(34);
	spri.setX(100);
	spri.blitSurface(main_screen.getSurface());


	main_screen.flip();

	SDL_Event event;
	int done = 0;
	Uint8 *keys;

	while(done==0){
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_KEYDOWN){
				if (event.key.keysym.sym == SDLK_ESCAPE){
					done = 1;
				}
			}else if (event.type == SDL_VIDEORESIZE){
				main_screen.setResolution(event.resize.w,event.resize.h);
			}else if (event.type == SDL_QUIT){
				done = 1;
			}
		}

		/*keys=SDL_GetKeyState(NULL);

		if (keys[SDLK_a] == 1){
			spri.setX(spri.getX()-5);
			if (keys[SDLK_s] == 1){
				spri.setY(spri.getY()+5);
			}else if (keys[SDLK_w] == 1){
				spri.setY(spri.getY()-5);
			}else if (keys[SDLK_d] == 1){
				spri.setX(spri.getX()+5);
			}

		
		}else if (keys[SDLK_s] == 1){
			spri.setY(spri.getY()+5);
			if (keys[SDLK_p] == 1){
				spri.setX(spri.getX()+5);
			}
			
		}else if (keys[SDLK_d] == 1){
			spri.setX(spri.getX()+5);
			if (keys[SDLK_l] == 1){
				spri.setY(spri.getY()+5);
			}
		
		}else if (keys[SDLK_w] == 1){
			spri.setY(spri.getY()-5);
			if (keys[SDLK_p] == 1){
				spri.setX(spri.getX()+5);
			}
			
		}
		main_screen.fillScreen(0,0,1);
		spri.blitSurface(main_screen.getSurface());		
		main_screen.flip();*/

	}
	return 1;
}

/*int main(int argc, char* argv[])
=======
int main(int argc, char* argv[])
>>>>>>> origin/master
{
	SDL_Event event;
	int done = 0;
<<<<<<< HEAD
	ImageManager imagen;
	ImageManager robot;
	SpriteManager sprite(2,3);
	SSM pantalla(1000,600, 1600, 900);
	SurfaceManager misuperficie(800,600);
	ImageManager boton1;
	ImageManager boton2;
	SpriteManager caca(1,1);
=======
	int i = 1;
	SSM pantalla;
	Uint8 *keys;
>>>>>>> origin/master

	atexit(SDL_Quit);

	SDL_Init(SDL_INIT_VIDEO);
	//SDL_ShowCursor(SDL_DISABLE);

<<<<<<< HEAD
	pantalla.setWindowsTitle("Amono señoresss");
=======
	//pantalla.enabledFullScreen();
	pantalla.setResolution(PANORAMICSMALL);
	pantalla.setWindowsTitle("MandraCannon");
>>>>>>> origin/master
	pantalla.setIcon("recursos/logoventana/logoventana.png");
	
<<<<<<< HEAD
	
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
	misuperficie.fillSurface(245,0,0);
	
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
=======
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
>>>>>>> origin/master

	while(done==0){
		while (SDL_PollEvent(&event)){
			if (keys[SDLK_ESCAPE] == 1){
				done = 1;
			} else if (event.type == SDL_VIDEORESIZE){
				pantalla.setResolution(event.resize.w, event.resize.h);
			}else if (event.type == SDL_QUIT){
				done = 1;
			}
		}
	}
<<<<<<< HEAD
	return 1;
}*/
