/*******************************************************
SurfaceManager.cpp

Created by: Juan Manuel Amador Olivares
********************************************************/

#include "StdAfx.h"
#include "SurfaceManager.h"
#include <stdio.h>
#include "SDL_image.h"

int SurfaceManager::surfaceNumber = 0;	// Se inicia la variable de clase que guarda el numero de superficies

/*** Construtor ***/
// Inicializa las variables
SurfaceManager::SurfaceManager(int WIDTH, int HEIGHT)
{
	surfaceNumber++;		// Cada vez que se crea un objeto se incrementa una unidad el numero de superficies
	surfaceRect.x = 0;		// // Se inicializa la estructura que contiene los atributos de la superficie
	surfaceRect.y = 0;
	surfaceRect.w = WIDTH;
	surfaceRect.h = HEIGHT;
	// Se crea la superficie
	surface = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCCOLORKEY|SDL_SRCALPHA,WIDTH,HEIGHT,32,0,0,0,0);
}

/*** Deconstructor ***/
// Destruye la memoria del objeto
SurfaceManager::~SurfaceManager(void)
{
	surfaceNumber--;		// Cuando el objeto se destruye se decrementa una unidad
}

/*** getNumberSurfaces ***/
// Esta funcion devuelve el numero de superficies creadas
// es decir, el numero de objetos creados
int SurfaceManager::getNumberSurfaces(){
	return surfaceNumber;
}

/*** getSurface ***/
// Devuelve la superficie
// Esta superficie puede ser utilizada para hacer operaciones de blit en ella
SDL_Surface *SurfaceManager::getSurface(){
	return surface;
}

/*** getRect ***/
// Devuelve el SDL_Rect de la superficie
SDL_Rect SurfaceManager::getRect(){
	return surfaceRect;
}

/*** getWIDTH ***/
// Devuelve el ancho de la superficie
int SurfaceManager::getWIDTH(){
	return surfaceRect.w;
}

/*** getHEIGHT ***/
// Devuelve el alto de la superficie
int SurfaceManager::getHEIGHT(){
	return surfaceRect.h;
}

/*** getX ***/
// Devuelve la coordenada X
int SurfaceManager::getX(){
	return surfaceRect.x;
}

/*** getY ***/
// Devuelve la coordenada Y
int SurfaceManager::getY(){
	return surfaceRect.y;
}

/*** setX ***/
// Cambia la coordenada X
void SurfaceManager::setX(int x){
	surfaceRect.x = x;
}

/*** setY ***/
// Cambia la coordenada Y
void SurfaceManager::setY(int y){
	surfaceRect.y = y;
}

/*** setColorKey ***/
// Selecciona un color para la transparencia. Este color no se mostrara, es decir sera totalmente transparente.
int SurfaceManager::setColorKey(int R, int G, int B){
	if (R < 0 || G < 0 || B < 0 || R > 255 || G > 255 || B > 255){	// Se comprueba que el color RGB
		return -1;													// este dentro de los valores permitidos sino sale y devuelve -1
	}else{
		SDL_SetColorKey(surface,SDL_SRCCOLORKEY|SDL_RLEACCEL,SDL_MapRGB(surface->format,R,G,B));
	}
	return 0;		// Si todo va bien se devuelve 0
}

/*** disabledColorKey ***/
// Desactiva el color seleccionado como transparente
void SurfaceManager::disabledColorKey(){
	SDL_SetColorKey(surface,0,SDL_MapRGB(surface->format,0,0,0));
}

/*** setOpacity ***/
// Cambia la opacidad la superficie
int SurfaceManager::setOpacity(int opacity){
	if (opacity < 0 || opacity > 255){
		return -1;
	}else{
		SDL_SetAlpha(surface,SDL_SRCALPHA|SDL_RLEACCEL,opacity);
	}
	return 0;
}

/*** disabledOpacity ***/
// Desactiva la opacidad
void SurfaceManager::disabledOpacity(){
	SDL_SetAlpha(surface,0,255);
}

/*** fillSurface ***/
// Pinta de el color RGB pasado como argumento toda la superficie
int SurfaceManager::fillSurface(int R, int G, int B){
	if (R < 0 || G < 0 || B < 0 || R > 255 || G > 255 || B > 255){
		return -1;
	}else{
		SDL_Rect fill;
		fill.x = 0;
		fill.y = 0;
		fill.w = surfaceRect.w;
		fill.h = surfaceRect.h;
		SDL_FillRect(surface,&fill,SDL_MapRGB(surface->format,R,G,B));
	}
	return 0;
}

/*** blitSurface ***/
// Copia la superficie en la superficie pasada como argumento
void SurfaceManager::blitSurface(SDL_Surface *surface){
	SDL_BlitSurface(this->surface, NULL, surface, &surfaceRect);
}

/*** blitSurface ***/
// Copia la una parte de la superficie definida por el SDL_Rect pasado como argumento en la superficie superficie pasada como argumento
void SurfaceManager::blitSurface(SDL_Surface *surface, SDL_Rect section){
	SDL_BlitSurface(this->surface, &section, surface, &getRect());	// Se copia una parte de la imagen
}

