#pragma once
#include <SDL.h>

class ImageManager
{
protected:
	static int imageNumber;		// Cuenta el numero de imagenes creadas
	SDL_Surface *image, *notEscalate;// Superficie de la imagen y de la imagene que no se escalara
	SDL_Rect imageRect;			// Estructura con los parametros x,y,w,h
	double rotation;			// Rotacion de la imagen
	double escale;				// Escalado de la imagen (de 0 a 1)
	int alpha;					// Opacidad de la imagen
	int R,G,B;					// Color transparente de la imagen

public:
	ImageManager(void);			// Constructor, inicializa los atributos
	~ImageManager(void);		// Deconstrutor
	int getNumberImages();		// Devuelve el numero de imagenes creadas
	int loadImage(const char folder[]);		// Carga una imagen en la superficie
	SDL_Surface *getSurface();		// Devuelve la superficie de la imagen
	SDL_Rect getRect();				// Devuelve el SDL_Rect de la imagen
	int getWIDTH();					// Devuelve el ancho
	int getHEIGHT();				// Devuelve el alto
	int getNewWIDTH();	// Devuelve el ancho despues de sufrir las trasnformaciones
	int getNewHEIGHT();	// Devuelve el alto despues de sufrir las trasnformaciones
	SDL_Rect getNewRect();	// Devuelve el SDL_Rect despues de sufrir las trasnformaciones
	double getRotation();			// Devuelve la rotacion
	double getEscale();				// Devuelve el escalado (de 0 a 1)
	int getX();						// Devuelve la coordenada X
	int getY();						// Devuelve la coordenada Y
	void setX(int x);					// Cambia la coordenada X
	void setY(int y);					// Cambia la coordenada X
	void rotate(double rotation);		// Rota la imagen
	void rotateCentre(double rotation);	// Rota la imagen respecto al centro
	void escalate(double escale);		// Escala la imagen (porcentaje de 0 a 1)
	void escalateCentre(double escale);		// Escala la imagen (porcentaje de 0 a 1) respecto al centro
	void blitSurface(SDL_Surface *surface);	// Copia la imagen en otra superficie
	int setTransparency(int R, int G, int B);	// Selecciona un color para la transparencia
	void disabledTransparency();		// Desactiva el color seleccionado como transparente
	int setAlpha(int alpha);			// Cambia la opacidad la imagen
	void disabledAlpha();				// Desactiva la opacidad
};