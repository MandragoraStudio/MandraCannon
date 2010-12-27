#pragma once
#include <SDL.h>

class SurfaceManager
{
protected:
	static int imageNumber;		// Cuenta el numero de imagenes creadas
	SDL_Surface *image;// Superficie de la imagen
	SDL_Rect imageRect;			// Estructura con los parametros x,y,w,h
public:
	SurfaceManager(int WIDTH, int HEIGHT);	// Constructor
	~SurfaceManager(void);					// Deconstructor
	int getNumberSurface();		// Devuelve el numero de imagenes creadas
	SDL_Surface *getSurface();		// Devuelve la superficie de la imagen
	SDL_Rect getRect();				// Devuelve el SDL_Rect de la imagen
	int getWIDTH();					// Devuelve el ancho
	int getHEIGHT();				// Devuelve el alto
	int getX();						// Devuelve la coordenada X
	int getY();						// Devuelve la coordenada Y
	void setX(int x);					// Cambia la coordenada X
	void setY(int y);					// Cambia la coordenada X
	void blitSurface(SDL_Surface *surface);	// Copia la imagen en otra superficie
	int setTransparency(int R, int G, int B);	// Selecciona un color para la transparencia
	void disabledTransparency();		// Desactiva el color seleccionado como transparente
	int setAlpha(int alpha);			// Cambia la opacidad (entre 0 y 255)
	void disabledAlpha();				// Desactiva la opacidad (la imagen se veria totalmente opaca)
	int fillSurface(int R,int G,int B);	// Pinta la superficie del color seleccionado
};

