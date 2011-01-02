#pragma once
#include <SDL.h>

/*******************************************************
SSM.h

Created by: Juan Manuel Amador Olivares
********************************************************/

class SSM
{
protected:
	bool fullScreen;						// ¿Pantalla completa?
	int WIDTH;								// Ancho de la ventana
	int HEIGHT;								// Alto de la ventana
	SDL_Surface *screen;					// Superficie de la ventana
	SDL_Surface *auxiliar;					// Superficie del rectangulo "pintable"
	SDL_Rect rect;							// Atributos de notEscalate, necesario para hacer el BlitSurface
	int MAXWIDTH;							// Maximo ancho
	int MAXHEIGHT;							// Maximo alto
public:
	SSM(int WIDTH, int HEIGHT,int MAXWIDTH,int MAXHEIGHT);		// Constructor
	SDL_Surface *getSurface();	// Devuelve la superficie de la pantalla que servira para pintar
	int getWIDTH();				// Devuelve el ancho (del rectangulo mostrado, no de la ventana)
	int getHEIGHT();			// Devuelve el alto (del rectangulo mostrado, no de la ventana)
	int getWIDTHScreen();		// Devuelve el ancho de la ventana
	int getHEIGHTScreen();		// Devuelve el alto de la ventana
	bool getFullScreen();		// Devuelve si la pantalla esta o no en pantalla completa
	void enabledFullScreen();	// Activa pantalla completa
	void disabledFullScreen();	// Desactiva pantalla completa
	int setResolution(int WIDTH, int HEIGHT);	// Cambia la resolucion de la ventana
	void setWindowsTitle(const char title[]);	// Establece el titulo de la ventana
	void setIcon(const char folder[]);			// Establece el icono de la ventana
	void flip();				// Muestra la superficie principal en pantalla
	int getMAXWITH();		// Devuelve el maximo ancho
	int getMAXHEIGHT();		// Devuelve el maximo alto
	int fillScreen(int R,int G,int B);	// Pinta el rectangulo pintable del color seleccionado
	double getPercent();	// Devuelve el porcentaje menor del rectangulo pintable respecto de la ventana
	int getWIDTHborder();	// Devuelve el tamnaño de los bordes del ancho
	int getHEIGHTborder();	// Devuelve el tamnaño de los bordes del alto
};