/*******************************************************
ImageManager.h

Created by: Juan Manuel Amador Olivares
********************************************************/

#pragma once
#include <SDL.h>

class ImageManager
{
protected:
	static int imageNumber;										// Cuenta el numero de imagenes creadas
	SDL_Surface *image, *auxiliar;								// Superficie de la imagen final y de la imagen auxiliar
	SDL_Rect imageRect;											// Estructura con los parametros x,y,w,h de la imagen original
	double rotation;											// Rotacion de la imagen
	double escale;												// Escalado de la imagen (de 0 a 1)
	int opacity;												// Opacidad de la imagen
	int R,G,B;													// Color transparente de la imagen en RGB

public:
	ImageManager(void);											// Constructor, inicializa los atributos
	~ImageManager(void);										// Deconstrutor
	int getNumberImages();										// Devuelve el numero de imagenes creadas
	int loadImage(const char path[]);							// Carga una imagen en la superficie
	SDL_Surface *getSurface();									// Devuelve la superficie de la imagen que puede ser utilizada
	SDL_Rect getOriginalRect();									// Devuelve el SDL_Rect de la imagen original
	int getOriginalWIDTH();										// Devuelve el ancho de la imagen original
	int getOriginalHEIGHT();									// Devuelve el alto de la imagen original
	int getWIDTH();												// Devuelve el ancho de la imagen
	int getHEIGHT();											// Devuelve el alto de la imagen
	SDL_Rect getRect();											// Devuelve el SDL_Rect de la imagen
	int getX();													// Devuelve la coordenada X
	int getY();													// Devuelve la coordenada Y
	void setX(int x);											// Cambia la coordenada X
	void setY(int y);											// Cambia la coordenada Y
	double getRotation();										// Devuelve la rotacion
	double getEscale();											// Devuelve el escalado (de 0 a 1)
	void rotate(double rotation);								// Rota la imagen
	void rotateCentre(double rotation);							// Rota la imagen respecto al centro
	void escalate(double escale);								// Escala la imagen (porcentaje de 0 a 1)
	void escalateCentre(double escale);							// Escala la imagen (porcentaje de 0 a 1) respecto al centro
	int setColorKey(int R, int G, int B);						// Selecciona un color para la transparencia
	void disabledColorKey();									// Desactiva el color seleccionado como transparente
	int setOpacity(int opacity);								// Cambia la opacidad la imagen
	void disabledOpacity();										// Desactiva la opacidad
	void blitSurface(SDL_Surface *surface);						// Copia la imagen en otra superficie
	void blitSurface(SDL_Surface *surface, SDL_Rect section);	// Copia la una parte definida imagen en otra superficie
};