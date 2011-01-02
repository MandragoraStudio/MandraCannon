/*******************************************************
Mouse.cpp

Created by: Juan Manuel Amador Olivares
********************************************************/

#include "StdAfx.h"
#include "Mouse.h"
#include <SDL.h>

/*** Construtor ***/
// Inicializa las variables
Mouse::Mouse(void)
{
	x = 0;						// Se inicializan las coordenadas x e y del raton
	y = 0;
	buttonEvent.x = 0;			// Se inicilizan los atributos del ultimo evento de raton
	buttonEvent.y = 0;
	buttonEvent.button = 0;
	buttonEvent.type = 0;
}

/*** Deconstructor ***/
// Destruye la memoria del objeto
Mouse::~Mouse(void){}

/*** getX ***/
// Devuelve la posicion x actual del raton
int Mouse::getX(){
	SDL_GetMouseState(&x, &y);
	return x;
}

/*** getX ***/
// Devuelve la posicion x actual del raton
int Mouse::getY(){
	SDL_GetMouseState(&x, &y);
	return y;
}

/*** over ***/
// Este metodo comprueba si el raton se encuentra sobre el rectangulo pasado como argumento
// Primero actualiza las coordenadas x e y del raton y comprueba si estas estan dentro del rectangulo
bool Mouse::over(SDL_Rect rect){
	x = getX();
	y = getY();
	if ( (x < (rect.x + rect.w) && x > rect.x) &&
		(y < (rect.y + rect.h) && y > rect.y) ){
			return true;
	}else{
		return false;
	}
}

/*** getMouseEvent ***/
// Este metodo comprueba si el evento pasado por argumento es un evento de las teclas del raton
// En el caso de serlo, rellena la estructura tipo MouseEvent y la devuelve
MouseEvent Mouse::getMouseEvent(SDL_Event event){
	if (event.type == SDL_MOUSEBUTTONDOWN){	// Si el evento es de la pulsacion de una tecla del raton
		buttonEvent.type = PRESSED;			// Se llena la estructura MouseEvent convenientemente
		buttonEvent.x = event.motion.x;
		buttonEvent.y = event.motion.y;
		switch (event.button.button){
		case SDL_BUTTON_LEFT:
			buttonEvent.button = LEFTBUTTON;
			break;
		case SDL_BUTTON_MIDDLE:
			buttonEvent.button = MIDDLEBUTTON;
			break;
		case SDL_BUTTON_RIGHT:
			buttonEvent.button = RIGHTBUTTON;
			break;
		}
	}else if (event.type == SDL_MOUSEBUTTONUP){	// Si el evento es de soltar una tecla del raton
		buttonEvent.type = RELEASED;			// Se llena la estructura MouseEvent convenientemente
		buttonEvent.x = event.motion.x;
		buttonEvent.y = event.motion.y;
		switch (event.button.button){
		case SDL_BUTTON_LEFT:
			buttonEvent.button = LEFTBUTTON;
			break;
		case SDL_BUTTON_MIDDLE:
			buttonEvent.button = MIDDLEBUTTON;
			break;
		case SDL_BUTTON_RIGHT:
			buttonEvent.button = RIGHTBUTTON;
			break;
		}
	}
	return buttonEvent;
}

/*** overPressed ***/
// Comprueba si el ultimo evento de pulsado del raton se ha producido en el rectangulo pasado como argumento
// Primero actualiza las coordenadas x e y del raton y comprueba si estas estan dentro del rectangulo
bool Mouse::overPressed(SDL_Rect rect, SDL_Event event){
	getMouseEvent(event);	// Primero actualizo la estrutura que guarda el ultimo evento del raton
	if (buttonEvent.type == PRESSED){								// Si se ha presinado una tecla del raton
		if ( (buttonEvent.x < (rect.x + rect.w) && x > rect.x) &&	// Se comprueba si el evento se ha producido en el rectnagulo
		(buttonEvent.y < (rect.y + rect.h) && y > rect.y) ){		// pasado como argumento
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

/*** overReleased ***/
// Este metodo comprueba si el raton se encuentra sobre el rectangulo pasado como argumento
// Comprueba si el ultimo evento de soltado del raton se ha producido en el rectangulo pasado como argumento
bool Mouse::overReleased(SDL_Rect rect, SDL_Event event){
	getMouseEvent(event);	// Primero actualizo la estrutura que guarda el ultimo evento del raton
	if (buttonEvent.type == RELEASED){								// Si se ha presinado una tecla del raton
		if ( (buttonEvent.x < (rect.x + rect.w) && x > rect.x) &&	// Se comprueba si el evento se ha producido en el rectnagulo
		(buttonEvent.y < (rect.y + rect.h) && y > rect.y) ){		// pasado como argumento
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

/*** disableCursor ***/
// Desactiva la visibilidad del raton
void Mouse::disableCursor(){
	SDL_ShowCursor(SDL_DISABLE);
}

/*** enableCursor ***/
// Activa la visibilidad del raton
void Mouse::enableCursor(){
	SDL_ShowCursor(SDL_ENABLE);
}
/*** getCursorState ***/
// Devuelve true si el raton es visible y false en caso contrario
bool Mouse::getCursorState(){
	if (SDL_ShowCursor(SDL_QUERY) == SDL_ENABLE){		// Si la visibilidad del raton esta activada
		return true;									// devuelve true
	}else{												// sino
		return false;									// devuelve false
	}
}




