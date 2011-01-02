/*******************************************************
SSM.cpp

Created by: Juan Manuel Amador Olivares
********************************************************/

#include "stdafx.h"
#include "SSM.h"
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_rotozoom.h"

/*** Construtor ***/
// Inicializa las variables
// Hay que pasarle 4 argumentos: el alto y ancho de la pantalla incial y
// el alto y ancho de la resolucion sobre la que se va a trabajar
// la pantalla podra ser escalada, por lo que la reoslucion mostrada cambiara, pero siempre tendra la misma proporcion.
// Ademas, la clase te permite trabajar sobre la resolucion "base", te abstrae de todo tipo de cambios de resolucion
// y de reescalado de la ventana. Cuando la proporcion de la ventana y de la resolucion base no coinciden se sigue manteniendo la
// proporcion de la la resolucion base (aunque puede que sea escalado ajustandose a la nueva resolucion de la ventana,
// pero siempre manteniendo la misma proporcion) y se crean a los lados o arriba y abajo dos bordes iguales para centrar el rectangulo
// mostrable. El rectnagulo mostrable siempre mantendra la misma proporcion (la de la resolucion base) y se ajustara a la resolucion
// de la ventana buscando siempre la resolucion mayor.
SSM::SSM(int WIDTH, int HEIGHT, int MAXWIDTH, int MAXHEIGHT){
	// Se inicializan los atributos y se crea una ventana predeterminada
	fullScreen = false;																// EL modo pantalla completa se desactiva
	screen = SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_HWSURFACE|SDL_RESIZABLE);			// Se configura el modo de video
	auxiliar = SDL_CreateRGBSurface(SDL_HWSURFACE,MAXWIDTH,MAXHEIGHT,32,0,0,0,0);	// Se crea la superfifice auxiliar
	this->MAXWIDTH = MAXWIDTH;														// Se guarda el ancho base
	this->MAXHEIGHT = MAXHEIGHT;													// Se guarda el alto base
	this->WIDTH = WIDTH;															// Se guarda el ancho de la ventana
	this->HEIGHT = HEIGHT;															// Se guarda el alto de la ventana
	rect.w = MAXWIDTH*getPercent();													// se guarda el alto y ancho del rectangulo "mostrable"
	rect.h = MAXHEIGHT*getPercent();												// usando el porcentaje de escalado que devuelve getPercent()
	rect.x = getWIDTHborder();														// La coordenada x sera el ancho del borde
	rect.y = getHEIGHTborder();														// La coordenada y sera el alto del borde
}

/*** getSurface ***/
// Devuelve una superficie auxiliar sobre la que se trabajara. Esta superficie tiene la resolucion base
// y es como base para el escalado
SDL_Surface *SSM::getSurface(){
	return auxiliar;
}

/*** getWIDTH ***/
// Devuelve el ancho de la imagen
int SSM::getWIDTH(){
	return rect.w;
}

/*** getHEIGHT ***/
// Devuelve el alto del rectangulo mostrable
int SSM::getHEIGHT(){
	return rect.h;
}

/*** getWIDTHScreen ***/
// Devuelve el ancho de la ventana
int SSM::getWIDTHScreen(){
	return WIDTH;
}

/*** getHEIGHTScreen ***/
// Devuelve el alto de la ventana
int SSM::getHEIGHTScreen(){
	return HEIGHT;
}

/*** getMAXWIDTH ***/
// Devuelve el alto de la resolucion base, sobre la que se trabaja
int SSM::getMAXWITH(){
	return MAXWIDTH;
}

/*** getMAXHEIGHT ***/
// Devuelve el alto de la resolucion base, sobre la que se trabaja
int SSM::getMAXHEIGHT(){
	return MAXHEIGHT;
}

/*** getFullScreen ***/
// Este  metodo devuelve true si el modo de pantalla completa esta activado o false en caso contrario
bool SSM::getFullScreen(){
	return fullScreen;
}

/*** enabledFullScreen ***/
// Este metodo activa el modo de pantalla completa
void SSM::enabledFullScreen(){
	screen = SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_HWSURFACE|SDL_RESIZABLE|SDL_FULLSCREEN);
	fullScreen = true;
}

/*** disabledFullScreen ***/
// Este metodo activa el modo de pantalla completa
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
	SDL_BlitSurface(rotozoomSurface(auxiliar,0,getPercent(),1),NULL,screen,&rect);
	SDL_Flip(screen);
}

double SSM::getPercent(){
	if ((double)WIDTH/MAXWIDTH < (double)HEIGHT/MAXHEIGHT){
		return (double)WIDTH/MAXWIDTH;
	}else{
		return (double)HEIGHT/MAXHEIGHT;
	}
}

int SSM::fillScreen(int R, int G, int B){
	if (R < 0 || G < 0 || B < 0 || R > 255 || G > 255 || B > 255){
		return -1;
	}else{
		SDL_Rect fill;
		fill.x = 0;
		fill.y = 0;
		fill.w = MAXWIDTH;
		fill.h = MAXHEIGHT;
		SDL_FillRect(auxiliar,&fill,SDL_MapRGB(auxiliar->format,R,G,B));
	}
	return 0;
}

int SSM::getWIDTHborder(){
	return (WIDTH - rect.w)/2;
}

int SSM::getHEIGHTborder(){
	return (HEIGHT - rect.h)/2;
}




