#include "stdafx.h"
#include "SSM.h"
#include <stdio.h>
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_rotozoom.h"


SSM::SSM(int WIDTH, int HEIGHT, int MAXWIDTH, int MAXHEIGHT){
	// Se inicializan los atributos y se crea una ventana predeterminada
	fullScreen = false;
	screen = SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_HWSURFACE|SDL_RESIZABLE);
	notEscalate	= SDL_CreateRGBSurface(SDL_HWSURFACE,MAXWIDTH,MAXHEIGHT,32,0,0,0,0);
	this->MAXWIDTH = MAXWIDTH;
	this->MAXHEIGHT = MAXHEIGHT;
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
	rect.w = MAXWIDTH*getPercent();
	rect.h = MAXHEIGHT*getPercent();
	rect.x = getWIDTHborder();
	rect.y = getHEIGHTborder();
}

SDL_Surface *SSM::getSurface(){
	return notEscalate;
}

int SSM::getWIDTH(){
	return rect.w;
}

int SSM::getHEIGHT(){
	return rect.h;
}

bool SSM::getFullScreen(){
	return fullScreen;
}

void SSM::enabledFullScreen(){
	screen = SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_HWSURFACE|SDL_RESIZABLE|SDL_FULLSCREEN);
	fullScreen = true;
}

void SSM::disabledFullScreen(){
	screen = SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_HWSURFACE|SDL_RESIZABLE);
	fullScreen = false;
}

int SSM::setResolution(int WIDTH, int HEIGHT){
	if (WIDTH < MAXWIDTH/10 | HEIGHT < MAXHEIGHT/10){	// Resolucion Minima
		return -1;
	}else{
		if (fullScreen == true){
			screen = SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_HWSURFACE|SDL_RESIZABLE|SDL_FULLSCREEN);
		}else{
			screen = SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_HWSURFACE|SDL_RESIZABLE);
		}
		this->WIDTH = WIDTH;
		this->HEIGHT = HEIGHT;
		rect.w = MAXWIDTH*getPercent();
		rect.h = MAXHEIGHT*getPercent();
		rect.x = getWIDTHborder();
		rect.y = getHEIGHTborder();
		flip();
	}
	return 0;
}

void SSM::setWindowsTitle(const char title[]){
	SDL_WM_SetCaption(title, NULL);
}

void SSM::setIcon(const char folder[]){
	SDL_WM_SetIcon(IMG_Load(folder),NULL);
}

void SSM::flip(){
	SDL_BlitSurface(rotozoomSurface(notEscalate,0,getPercent(),1),NULL,screen,&rect);
	SDL_Flip(screen);
}

int SSM::getMAXWITH(){
	return MAXWIDTH;
}

int SSM::getMAXHEIGHT(){
	return MAXHEIGHT;
}

int SSM::getWIDTHScreen(){
	return WIDTH;
}

int SSM::getHEIGHTScreen(){
	return HEIGHT;
}

double SSM::getPercent(){
	if ((double)WIDTH/MAXWIDTH < (double)HEIGHT/MAXHEIGHT){
		return (double)WIDTH/MAXWIDTH;
	}else{
		return (double)HEIGHT/MAXHEIGHT;
	}
}

int SSM::fillScreen(int R, int G, int B){
	if (R < 0 | G < 0 | B < 0 | R > 255 | G > 255 | B > 255){
		return -1;
	}else{
		SDL_Rect fill;
		fill.x = 0;
		fill.y = 0;
		fill.w = MAXWIDTH;
		fill.h = MAXHEIGHT;
		SDL_FillRect(notEscalate,&fill,(notEscalate->format,R,G,B));
	}
	return 0;
}

int SSM::getWIDTHborder(){
	return (WIDTH - rect.w)/2;
}

int SSM::getHEIGHTborder(){
	return (HEIGHT - rect.h)/2;
}





