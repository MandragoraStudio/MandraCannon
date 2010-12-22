#pragma once
#include <SDL.h>

// Definiciones
#define PANORAMICMAX 11	// Estas definicones se usan para el modo panoramico (16:9)
#define PANORAMICHUGE 12
#define PANORAMICBIG 13
#define PANORAMICNORMAL 14
#define PANORAMICSMALL 15
#define PANORAMICMIN 16

#define NORMALMAX 21	// Estas definicones se usan para el modo normal (16:12)(4:3)
#define NORMALHUGE 22
#define NORMALBIG 23
#define NORMALNORMAL 24
#define NORMALSMALL 25
#define NORMALMIN 26


class SSM
{
protected:
	bool fullScreen;	// ¿Pantalla completa?
	int WIDTH;			// Ancho pantalla
	int HEIGHT;			// Alto pantalla
	SDL_Surface *screen;	// Superficie principal es la que se mostrara en pantalla
	double percent;		// Este valor sirve para escalar las imagenes
public:
	SSM(void);			// Constructor
	SDL_Surface *getSurface();	// Devuelve la superficie de la pantalla actualizandola
	double getPercent();		// Devuelve el porcentaje de escalado de las imagenes
	int getWIDTH();				// Devuelve el ancho
	int getHEIGHT();			// Devuelve el alto
	bool getFullScreen();		// Devuelve si la pantalla esta o no en pantalla completa
	void enabledFullScreen();	// Activa pantalla completa
	void disabledFullScreen();	// Desactiva pantalla completa
	int setResolution(int resolution);	// Cambia la resolucion, hay distintas opciones definidas
	void setWindowsTitle(const char title[]);	// Establece el titulo de la ventana
	void setIcon(const char folder[]);			// Establece el icono de la ventana
};