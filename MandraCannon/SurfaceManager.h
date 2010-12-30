/*******************************************************
SurfaceManager.h

Created by: Juan Manuel Amador Olivares
********************************************************/

#pragma once
#include <SDL.h>

class SurfaceManager
{
protected:
	static int surfaceNumber;									// Cuenta el numero de superficies creadas
	SDL_Surface *surface;										// Superficie
	SDL_Rect surfaceRect;										// Estructura con los parametros x,y,w,h de la superficie

public:
	SurfaceManager(int WIDTH, int HEIGHT);						// Constructor
	~SurfaceManager(void);										// Deconstructor
	int getNumberSurfaces();									// Devuelve el numero de imagenes creadas
	SDL_Surface *getSurface();									// Devuelve la superficie
	SDL_Rect getRect();											// Devuelve el SDL_Rect de la imagen
	int getWIDTH();												// Devuelve el ancho
	int getHEIGHT();											// Devuelve el alto
	int getX();													// Devuelve la coordenada X
	int getY();													// Devuelve la coordenada Y
	void setX(int x);											// Cambia la coordenada X
	void setY(int y);											// Cambia la coordenada X
	int setColorKey(int R, int G, int B);						// Selecciona un color para la transparencia
	void disabledColorKey();									// Desactiva el color seleccionado como transparente
	int setOpacity(int opacity);								// Cambia la opacidad (entre 0 y 255)
	void disabledOpacity();										// Desactiva la opacidad (la imagen se veria totalmente opaca)
	int fillSurface(int R,int G,int B);							// Pinta la superficie del color seleccionado
	void blitSurface(SDL_Surface *surface);						// Copia la imagen en otra superficie
	void blitSurface(SDL_Surface *surface, SDL_Rect section);	// Copia una parte definida de la imagen en otra superficie
};

