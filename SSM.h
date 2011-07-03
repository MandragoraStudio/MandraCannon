/*******************************************************
SSM.h

Created by: Mandrágora Code Studio
********************************************************/

#pragma once
#include <SDL.h>

class SSM
{
protected:
	bool fullScreen;							// ¿Pantalla completa?
	bool resizable;								// ¿Se puede cambiar el tamaño de la ventana?
	bool frame;									// ¿Ventana con borde o sin borde?
	int WIDTHScreen;							// Ancho de la ventana
	int HEIGHTScreen;							// Alto de la ventana
	SDL_Surface *screen;						// Superficie de la ventana
	SDL_Surface *auxiliar;						// Superficie del rectangulo "pintable"
	SDL_Rect rect;								// Atributos del rectangulo mostrado
	int WKWIDTH;								// Ancho con el que se va a trabajar
	int WKHEIGHT;								// Alto con el que se va a trabajar
public:
	SSM(int WIDTHScreen, int HEIGHTScreen,int WKWIDTH,int WKHEIGHT);		// Constructor
	SDL_Surface *getSurface();					// Devuelve la superficie de la pantalla que servira para pintar
	int getWIDTH();								// Devuelve el ancho (del rectangulo mostrado, no de la ventana)
	int getHEIGHT();							// Devuelve el alto (del rectangulo mostrado, no de la ventana)
	int getWIDTHScreen();						// Devuelve el ancho de la ventana
	int getHEIGHTScreen();						// Devuelve el alto de la ventana
	int getWKWITH();							// Devuelve el maximo ancho
	int getWKHEIGHT();							// Devuelve el maximo alto
	bool getFullScreen();						// Devuelve si la pantalla esta o no en pantalla completa
	void enabledFullScreen();					// Activa pantalla completa
	void disabledFullScreen();					// Desactiva pantalla completa
	bool getResizable();						// Devuelve se puede cambiar el tamaño de la ventana o no
	void enabledResizable();					// Activa el modo de ventana cambiable de tamaño
	void disabledResizable();					// Desactiva el modo de ventana cambiable de tamaño
	bool getFrame();							// Devuelve si la ventana tiene o no bordes
	void enabledFrame();						// Activa ventana con borde
	void disabledFrame();						// Desactiva ventana con borde
	int setResolution(int WIDTHScreen, int HEIGHTScreen);	// Cambia la resolucion de la ventana
	void setWindowsTitle(const char title[]);	// Establece el titulo de la ventana
	void setIcon(const char folder[]);			// Establece el icono de la ventana
	void flip();								// Muestra la superficie principal en pantalla
	double getPercent();						// Devuelve el porcentaje menor del rectangulo pintable respecto de la ventana
	int fillScreen(int R,int G,int B);			// Pinta el rectangulo mostrable del color seleccionado	
	int getWIDTHborder();						// Devuelve el tamaño de los bordes interiores del ancho
	int getHEIGHTborder();						// Devuelve el tamaño de los bordes intenriores del alto
};