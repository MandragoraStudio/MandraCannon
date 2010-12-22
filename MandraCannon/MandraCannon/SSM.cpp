#include "stdafx.h"
#include "SSM.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "SDL_image.h"

SSM::SSM(void){
	// Se inicializan los atributos y se crea una ventana predeterminada
	fullScreen = false;
	WIDTH = 1600;
	HEIGHT = 810;
	percent = 1;
	screen = SDL_SetVideoMode(WIDTH,HEIGHT,24,SDL_HWSURFACE);
}

SSM::~SSM(void){}

SDL_Surface *SSM::getSurface(){
	if (fullScreen == true){
		screen = SDL_SetVideoMode(WIDTH,HEIGHT,24,SDL_HWSURFACE|SDL_FULLSCREEN);
	} else{
		screen = SDL_SetVideoMode(WIDTH,HEIGHT,24,SDL_HWSURFACE);
	}
	return screen;
}

double SSM::getPercent(){
	return percent;
}

int SSM::getWIDTH(){
	return WIDTH;
}

int SSM::getHEIGHT(){
	return HEIGHT;
}

bool SSM::getFullScreen(){
	return fullScreen;
}

void SSM::enabledFullScreen(){
	fullScreen = true;
}

void SSM::disabledFullScreen(){
	fullScreen = false;
}

// Esta funcion cambia el alto y ancho de la pantalla segun el tamañano seleccionad
// Tambien calcula el porcentaje de escalado respecto a las resoluciones
// 1600x900 (16:9) o 1600x1200 (4:3), segun la resolucion elegida.
void SSM::setResolution(int resolution){
	switch (resolution){
		// Panoramico
	case PANORAMICMAX:
		WIDTH = 1600;
		HEIGHT = 900;
		break;
	case PANORAMICHUGE:
		WIDTH = 1440;
		HEIGHT = 810;
		break;
	case PANORAMICBIG:
		WIDTH = 1280;
		HEIGHT = 720;
		break;
	case PANORAMICNORMAL:
		WIDTH = 1120;
		HEIGHT = 630;
		break;
	case PANORAMICSMALL:
		WIDTH = 960;
		HEIGHT = 540;
		break;
	case PANORAMICMIN:
		WIDTH = 800;
		HEIGHT = 450;
		break;
		// Normal
	case NORMALMAX:
		WIDTH = 1600;
		HEIGHT = 1200;
		break;
	case NORMALHUGE:
		WIDTH = 1440;
		HEIGHT = 1080;
		break;
	case NORMALBIG:
		WIDTH = 1280;
		HEIGHT = 960;
		break;
	case NORMALNORMAL:
		WIDTH = 1120;
		HEIGHT = 840;
		break;
	case NORMALSMALL:
		WIDTH = 960;
		HEIGHT = 720;
		break;
	case NORMALMIN:
		WIDTH = 800;
		HEIGHT = 600;
		break;
	}
	// El ancho (que es comun al panoramico y normal) nos sirve para calcular el porcentaje de escalado
	// dividiendolo entre 1600 (por lo que la resolucion maxima tendra 1600 pixeles de ancho, es decir
	// porcentaje de escalado 1, por lo que hay que diseñar las imagenes para la maxima resolucion
	// (panoramico o normal) y en caso de elegir una resolucion menor el juego se encarga de reducirlas)
	percent = WIDTH%16%100;
}

void SSM::setWindowsTitle(const char title[]){
	SDL_WM_SetCaption(title, NULL);
}

void SSM::setIcon(const char folder[]){
	SDL_WM_SetIcon(IMG_Load(folder),NULL);
}




