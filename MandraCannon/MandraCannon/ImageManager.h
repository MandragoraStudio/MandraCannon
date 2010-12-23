#pragma once
#include <SDL.h>

class ImageManager
{
protected:
	static int imageNumber;		// Cuenta el numero de imagenes creadas
	SDL_Surface *image;			// Superficie de la imagen
	SDL_Rect imageRect;			// Estructura con los parametros x,y,w,h
	double rotation;			// Rotacion de la imagen
	double escale;				// Escalado de la imagen (de 0 a 1)

public:
	ImageManager(void);			// Constructor, inicializa los atributos
	~ImageManager(void);		// Deconstrutor
	int getNumberImages();		// Devuelve el numero de imagenes creadas
	int loadImage(const char folder[]);		// Carga una imagen en la superficie
	SDL_Surface *getSurface();		// Devuelve la superficie de la imagen
	SDL_Rect getRect();				// Devuelve el SDL_Rect de la imagen
	int getWIDTH();					// Devuelve el ancho
	int getHEIGHT();				// Devuelve el alto
	double getRotation();			// Devuelve la rotacion
	double getEscale();				// Devuelve el escalado (de 0 a 1)
	int getX();						// Devuelve la coordenada X
	int getY();						// Devuelve la coordenada Y
	void setX(int x);					// Cambia la coordenada X
	void setY(int y);					// Cambia la coordenada X
	void rotate(double rotation);		// Rota la imagen
	void escalate(double escale);		// Escala la imagen (porcentaje de 0 a 1)
	void blitSurface(SDL_Surface *surface);	// Copia la imagen en otra superficie
};