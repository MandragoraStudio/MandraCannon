/*******************************************************
SpriteManager.h

Created by: Juan Manuel Amador Olivares
********************************************************/

#pragma once
#include "imagemanager.h"

class SpriteManager :
	public ImageManager								// Hereda de ImageManager
{
protected:
	int nrows;										// Numero de columnas del sprite
	int ncolumns;									// Numero de filas del sprite
	int actualInstance;								// Guarda la imagen de la instancia que se va a mostrar
	SDL_Surface **notEscalate;						// Puntero que apunta a un array de superficies que contiene las inastancias

public:
	SpriteManager(int numberRows,int numberColumns);// Construtor
	~SpriteManager(void);							// Deconstructor
	int loadImage(const char folder[]);				// Carga un sprite y la divide en sus instancias
	int setInstance(int instanceNumber);			// Selecciona la instancia del sprite que sera mostrada
	int getInstance();								// Devuelve la instancia actual que sera mostrada dek sprite
	void rotate(double rotation);					// Rota las instancias del sprite
	void rotateCentre(double rotation);				// Rota las instancias del sprite respecto a su centro
	void escalate(double escale);					// Escala las instancias del sprite (porcentaje de 0 a 1)
	void escalateCentre(double escale);				// Escala las instancias del sprite (porcentaje de 0 a 1) respecto a su centro
};

