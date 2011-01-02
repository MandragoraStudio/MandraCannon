/*******************************************************
TextManager.h

Created by: Juan Manuel Amador Olivares
********************************************************/

#pragma once
#include <SDL.h>
#include "SDL_ttf.h"

#define BOLD TTF_STYLE_BOLD
#define	UNDERLINE TTF_STYLE_UNDERLINE
#define ITALIC TTF_STYLE_ITALIC
#define NORMAL TTF_STYLE_NORMAL

class TextManager
{
protected:
	static int textNumber;										// Cuenta el numero de imagenes creadas
	SDL_Surface *image, *auxiliar;								// Superficie de la imagen final y de la imagen auxiliar
	SDL_Rect imageRect;											// Estructura con los parametros x,y,w,h de la imagen original
	double rotation;											// Rotacion de la imagen
	double escale;												// Escalado de la imagen (de 0 a 1)
	int opacity;												// Opacidad de la imagen
	int R,G,B;													// Color transparente de la imagen en RGB
	TTF_Font *font;												// Puntero a estrutura que guarda la fuente de letra
	const char *path;											// Apunta a la cadena de caractares del la direccion de la fuente de texto
	int textSize;												// Variable que guarda el tamaño del texto
	SDL_Color fgcolor;											// Color RGB del texto 

public:
	TextManager(void);											// Constructor, inicializa los atributos
	~TextManager(void);											// Deconstrutor
	int getNumberTexts();										// Devuelve el numero de imagenes de textos creados creadas
	void loadFont(const char path[]);							// Carga una fuente de texto en la superficie
	int setTextSize(int textSize);								// Cambia el tamaño del texto (de 5 a 500)
	void setFontStyle(int style);								// Cambia el estilo del texto
	int setTextColor(int R, int G, int B);						// Cambia el color del texto
	int setText(const char text[]);								// Cambie el texto de la imagen
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
	void rotateCentre(double rotation);							// Rota la imagen respecto a su centro
	void escalate(double escale);								// Escala la imagen (porcentaje de 0 a 1)
	void escalateCentre(double escale);							// Escala la imagen (porcentaje de 0 a 1) respecto a su centro
	int setOpacity(int opacity);								// Cambia la opacidad la imagen (entre 0 y 255)
	void disabledOpacity();										// Desactiva la opacidad
	void blitSurface(SDL_Surface *surface);						// Copia la imagen en otra superficie
};
