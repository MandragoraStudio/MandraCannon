/*******************************************************
Mouse.h

Created by: Juan Manuel Amador Olivares
********************************************************/

#pragma once
#include <SDL.h>

typedef struct{											// Estructura que guardara el ultimo evento de pulsacion o soltado de los botones del raton
	int x, y;											// Coordenadas x e y
	int button;											// Boton pulsado: izquierdo (LEFTBUTTON), derecho (RIGHTBUTTON) o central (MIDDLEBUTTON)
	int type;											// Tipo: pulsar (PRESSED) o soltar el boton (RELEASED)
} MouseEvent;

// Definiciones del tipo de boton y el tipo de evento
#define LEFTBUTTON 1									// Boton izquierdo
#define MIDDLEBUTTON 2									// Boton central
#define RIGHTBUTTON 3									// Boton derecho

#define PRESSED 4										// Evento de boton presionado
#define RELEASED 5										// Evento de boton soltado

class Mouse
{
protected:
	int x, y;											// Coordenadas x e y del raton actuales
	MouseEvent buttonEvent;								// Estructura que guardara el ultimo evento de pulsacion o soltado de los botones del raton
public:
	Mouse(void);										// Constructor, inicializa los atributos
	~Mouse(void);										// Deconstrutor
	int getX();											// Devuelve la coordenada x actual del raton
	int getY();											// Devuelve la coordenada y actual del raton
	bool over(SDL_Rect rect);							// Comprueba si el raton esta en el rectangulo pasado como argumento
	MouseEvent getMouseEvent(SDL_Event event);			// Devuelve una estrutura tipo MouseEvent con el ultimo evento de raton
	bool overPressed(SDL_Rect rect, SDL_Event event);	// Comprueba si el ultimo evento de pulsado del raton se ha producido en el rectangulo pasado como argumento
	bool overReleased(SDL_Rect rect, SDL_Event event);	// Comprueba si el ultimo evento de soltado del raton se ha producido en el rectangulo pasado como argumento
	void disableCursor();								// Desactiva la visibilidad del raton
	void enableCursor();								// Activa la visibilidad del raton
	bool getCursorState();								// Devuelve true si el raton es visible y false en caso contrario
};

