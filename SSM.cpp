/*******************************************************
SSM.cpp

Created by: Juan Manuel Amador Olivares
********************************************************/

#include "stdafx.h"
#include "SSM.h"
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_rotozoom.h"

/*** Construtor ***/
// Inicializa las variables
// Hay que pasarle 4 argumentos: el alto y ancho de la pantalla incial y
// el alto y ancho de la resolucion sobre la que se va a trabajar
// la pantalla podra ser escalada, por lo que la reoslucion mostrada cambiara, pero siempre tendra la misma proporcion.
// Ademas, la clase te permite trabajar sobre la resolucion "base", te abstrae de todo tipo de cambios de resolucion
// y de reescalado de la ventana. Cuando la proporcion de la ventana y de la resolucion base no coinciden se sigue manteniendo la
// proporcion de la la resolucion base (aunque puede que sea escalado ajustandose a la nueva resolucion de la ventana,
// pero siempre manteniendo la misma proporcion) y se crean a los lados o arriba y abajo dos bordes iguales para centrar el rectangulo
// mostrable. El rectangulo mostrable siempre mantendra la misma proporcion (la de la resolucion base) y se ajustara a la resolucion
// de la ventana buscando siempre la resolucion mayor.
// Por defecto se crea una ventana resizable, es decir se puede cambiar su tamaño
SSM::SSM(int WIDTHScreen, int HEIGHTScreen, int WKWIDTH, int WKHEIGHT){
	// Se inicializan los atributos y se crea una ventana predeterminada
	resizable = true;
	frame = false;
	fullScreen = false;																// EL modo pantalla completa se desactiva
	screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_RESIZABLE);			// Se configura el modo de video
	auxiliar = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,WKWIDTH,WKHEIGHT,32,0,0,0,0);	// Se crea la superfifice auxiliar
	this->WKWIDTH = WKWIDTH;														// Se guarda el ancho base
	this->WKHEIGHT = WKHEIGHT;													// Se guarda el alto base
	this->WIDTHScreen = WIDTHScreen;															// Se guarda el ancho de la ventana
	this->HEIGHTScreen = HEIGHTScreen;															// Se guarda el alto de la ventana
	rect.w = WKWIDTH*getPercent();													// se guarda el alto y ancho del rectangulo "mostrable"
	rect.h = WKHEIGHT*getPercent();												// usando el porcentaje de escalado que devuelve getPercent()
	rect.x = getWIDTHborder();														// La coordenada x sera el ancho del borde
	rect.y = getHEIGHTborder();														// La coordenada y sera el alto del borde
}

/*** getSurface ***/
// Devuelve una superficie auxiliar sobre la que se trabajara. Esta superficie tiene la resolucion base
// y es como base para el escalado
SDL_Surface *SSM::getSurface(){
	return auxiliar;
}

/*** getWIDTH ***/
// Devuelve el ancho de la imagen
int SSM::getWIDTH(){
	return rect.w;
}

/*** getHEIGHT ***/
// Devuelve el alto del rectangulo mostrable
int SSM::getHEIGHT(){
	return rect.h;
}

/*** getWIDTHScreen ***/
// Devuelve el ancho de la ventana
int SSM::getWIDTHScreen(){
	return WIDTHScreen;
}

/*** getHEIGHTScreen ***/
// Devuelve el alto de la ventana
int SSM::getHEIGHTScreen(){
	return HEIGHTScreen;
}

/*** getMAXWIDTH ***/
// Devuelve el alto de la resolucion base, sobre la que se trabaja
int SSM::getWKWITH(){
	return WKWIDTH;
}

/*** getMAXHEIGHT ***/
// Devuelve el alto de la resolucion base, sobre la que se trabaja
int SSM::getWKHEIGHT(){
	return WKHEIGHT;
}

/*** getFullScreen ***/
// Este  metodo devuelve true si el modo de pantalla completa esta activado o false en caso contrario
bool SSM::getFullScreen(){
	return fullScreen;
}

/*** enabledFullScreen ***/
// Este metodo activa el modo de pantalla completa
void SSM::enabledFullScreen(){
	fullScreen = true;
	if (resizable == true)
	{
		if (frame = true)
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_FULLSCREEN);
		}
		else
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_FULLSCREEN|SDL_NOFRAME);
		}
	}
	else
	{
		if (frame = true)
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
		}
		else
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN|SDL_NOFRAME);
		}
	}	
}

/*** disabledFullScreen ***/
// Este metodo desactiva el modo de pantalla completa
void SSM::disabledFullScreen(){
	fullScreen = false;
	if (resizable == true)
	{
		if (frame = true)
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
		}
		else
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_NOFRAME);
		}
	}
	else
	{
		if (frame = true)
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
		}
		else
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_NOFRAME);
		}
	}	
}

/*** getResizable ***/
// Este  metodo devuelve true si el modo de ventana cambiable de tamaño esta activado o false en caso contrario
bool SSM::getResizable(){
	return resizable;
}

/*** enabledResizable ***/
// Este metodo activa el modo de ventana cambiable de tamaño
void SSM::enabledResizable(){
	resizable = true;
	if (fullScreen == true)
	{
		if (frame = true)
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_FULLSCREEN);
		}
		else
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_FULLSCREEN|SDL_NOFRAME);
		}
	}
	else
	{
		if (frame = true)
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
		}
		else
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_NOFRAME);
		}
	}
}

/*** disabledResizable ***/
// Este metodo desactiva el modo de ventana cambiable de tamaño
void SSM::disabledResizable(){
	resizable = false;
	if (fullScreen == true)
	{
		if (frame = true)
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
		}
		else
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN|SDL_NOFRAME);
		}
	}
	else
	{
		if (frame = true)
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
		}
		else
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_NOFRAME);
		}
	}
}

/*** getFrame ***/
// Este  metodo devuelve true si el modo de ventana con borde esta activado o false en caso contrario
bool SSM::getFrame(){
	return frame;
}

/*** enabledFrame ***/
// Este metodo activa el modo de ventana con borde
void SSM::enabledFrame(){
	frame = true;
	if (fullScreen == true)
	{
		if (resizable = true)
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_FULLSCREEN);
		}
		else
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
		}
	}
	else
	{
		if (resizable = true)
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
		}
		else
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
		}
	}
}

/*** disabledFrame ***/
// Este metodo desactiva el modo de ventana con borde
void SSM::disabledFrame(){
	frame = false;
	if (fullScreen == true)
	{
		if (resizable = true)
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_FULLSCREEN|SDL_NOFRAME);
		}
		else
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN|SDL_NOFRAME);
		}
	}
	else
	{
		if (resizable = true)
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_NOFRAME);
		}
		else
		{
			screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_NOFRAME);
		}
	}
}

/*** setResolution ***/
// Cambia la resolucion de la ventana y recalcula la resolucion del rectangulo "mostrable" y su posicion (los bordes)
int SSM::setResolution(int WIDTHScreen, int HEIGHTScreen){
	if (WIDTHScreen < WKWIDTH/10 | HEIGHTScreen < WKHEIGHT/10){	// La resolucion minima es la  decima parte de la resolucion base
		return -1;										// si la resolucion es demasiado pequeña sale y devuelve -1
	}else{												// sino
		// Se cambia la resolucion teniendo en cuenta si se esta en modo pantalla completa, si la ventana es reescalable y si tiene borde
		if (fullScreen == true)
		{
			if (resizable == true)
			{
				if (frame = true)
				{
					screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_FULLSCREEN);
				}
				else
				{
					screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_FULLSCREEN|SDL_NOFRAME);
				}
			}
			else
			{
				if (frame = true)
				{
					screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
				}
				else
				{
					screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN|SDL_NOFRAME);
				}
			}
		}
		else
		{
			if (resizable == true)
			{
				if (frame = true)
				{
					screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
				}
				else
				{
					screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_NOFRAME);
				}
			}
			else
			{
				if (frame = true)
				{
					screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
				}
				else
				{
					screen = SDL_SetVideoMode(WIDTHScreen,HEIGHTScreen,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_NOFRAME);
				}
			}	
		}
		this->WIDTHScreen = WIDTHScreen;				// Guarda el nuevo ancho de la ventana
		this->HEIGHTScreen = HEIGHTScreen;				// GUarda el nuevo alto de la ventana
		rect.w = WKWIDTH*getPercent();		// Calcula el nuevo ancho del rectangulo mostrable
		rect.h = WKHEIGHT*getPercent();	// Calcula el nuevo alto del rectangulo mostrable
		rect.x = getWIDTHborder();			// Calcula el nuevo borde a lo ancho
		rect.y = getHEIGHTborder();			// Calucla el nuevo borde a lo alto
		flip();
	}
	return 0;								// Si todo va bien devuelve 0
}

/*** setWindowsTitle ***/
// Establece el titulo de la ventana
void SSM::setWindowsTitle(const char title[]){
	SDL_WM_SetCaption(title, NULL);
}

/*** setIcon ***/
// Establece el icono de la ventana
void SSM::setIcon(const char folder[]){
	SDL_WM_SetIcon(IMG_Load(folder),NULL);
}

/*** flip ***/
// Copia la superficie auxiliar en la superficie principal que sera mostrada. La superficie auxiliar se escala
// antes de ser utilizada con los porcentajes ya calculados
void SSM::flip(){
	//SDL_BlitSurface(rotozoomSurface(auxiliar,0,getPercent(),1),NULL,screen,&rect);
	SDL_Flip(screen);
	/*SDL_FreeSurface(screen);
	SDL_FreeSurface(auxiliar);*/
}

/*** getPercent ***/
// Devuelve el porcentaje menor del rectangulo pintable respecto de la ventana
// Para ello calcula dos porcentajes, el de la proporcion entre los anchos y entre los altos
// la que nos es util es el menor para que el rectangulo mostrable se ajuste al maximo sin que
// sobrepase la resolucion de la ventana
double SSM::getPercent(){
	if ((double)WIDTHScreen/WKWIDTH < (double)HEIGHTScreen/WKHEIGHT){
		return (double)WIDTHScreen/WKWIDTH;
	}else{
		return (double)HEIGHTScreen/WKHEIGHT;
	}
}

/*** fillScreen ***/
// Pinta el rectangulo mostrable del color seleccionado	
int SSM::fillScreen(int R, int G, int B){
	if (R < 0 || G < 0 || B < 0 || R > 255 || G > 255 || B > 255){
		return -1;			// Comprueba que el valor RGB esta dentro de los limites, sino, sale y devuelve -1
	}else{
		SDL_Rect fill;		// Se crea un SDL_Rect usado para el proceso de blit
		fill.x = 0;			// Se confugura el SDL_Rect
		fill.y = 0;
		fill.w = WKWIDTH;
		fill.h = WKHEIGHT;
		SDL_FillRect(auxiliar,&fill,SDL_MapRGB(auxiliar->format,R,G,B));	// Se pinta el cuadrado del color pasado
	}
	return 0;
}

/*** getWIDTHborder ***/
// Devuelve el tamaño de los bordes interiores del ancho
// Para ello le resta al ancho de la ventana el ancho del rectangulo mostrable y lo divide entre dos
// (hay dos bordes, uno a cada lado)
int SSM::getWIDTHborder(){
	return (WIDTHScreen - rect.w)/2;
}

/*** getHEIGHTborder ***/
// Devuelve el tamaño de los bordes interiores del alto
// Para ello le resta al alto de la ventana el alto del rectangulo mostrable y lo divide entre dos
// (hay dos bordes, uno arriba y otro abajo)
int SSM::getHEIGHTborder(){
	return (HEIGHTScreen - rect.h)/2;
}




