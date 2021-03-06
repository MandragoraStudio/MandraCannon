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
	SDL_Rect auxRect;											// Estructura auxiliar utilizada para pintar la imagen
	double rotation;											// Rotacion de la imagen
	double scale;												// Escalado de la imagen (de 0 a 1)
	int opacity;												// Opacidad de la imagen
	int R,G,B;													// Color transparente de la imagen en RGB

public:
	ImageManager(void);											// Constructor, inicializa los atributos
	~ImageManager(void);										// Deconstrutor
	int getNumberImages();										// Devuelve el numero de imagenes creadas
	int loadImage(const char path[]);							// Carga una imagen en la superficie
	int createSurface(int WIDTH, int HEIGHT);					// Crea una superficie que pueda ser utilizada como imagen
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
	double getScale();											// Devuelve el escalado (de 0 a 1)
	void rotate(double rotation);								// Rota la imagen
	void scalate(double scale);									// Escala la imagen (porcentaje de 0 a 1)
	int setColorKey(int R, int G, int B);						// Selecciona un color para la transparencia
	void disabledColorKey();									// Desactiva el color seleccionado como transparente
	int setOpacity(int opacity);								// Cambia la opacidad la imagen (entre 0 y 255)
	void disabledOpacity();										// Desactiva la opacidad
	int fillSurface(int R,int G,int B);							// Pinta la superficie del color seleccionado
	int fillSurface(int R,int G,int B,SDL_Rect section);		// Pinta parte de la superficie del color seleccionado
	void blitSurface(SDL_Surface *surface);						// Copia la imagen en otra superficie
	void blitSurface(SDL_Surface *surface, SDL_Rect section);	// Copia una parte definida de la imagen en otra superficie
};