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
	SDL_Surface **auxiliar;							// Puntero que apunta a un array de superficies que contiene las instancias

public:
	SpriteManager(int numberRows,int numberColumns);// Construtor
	~SpriteManager(void);							// Deconstructor
	int loadImage(const char folder[]);				// Carga un sprite y la divide en sus instancias
	int setInstance(int instanceNumber);			// Selecciona la instancia del sprite que sera mostrada
	int getInstance();								// Devuelve la instancia actual que sera mostrada del sprite
	int getNumberInstances();						// Devuelve el numero de instancias del sprite
	void rotate(double rotation);					// Rota las instancias del sprite
	void scalate(double scale);						// Escala las instancias del sprite (porcentaje de 0 a 1)

	// El uso de estas funciones no esta permitido en sprites, uanque si se puedan utilizar en ImageManager
	int createSurface(int WIDTH, int HEIGHT);
	int fillSurface(int R,int G,int B);
	int fillSurface(int R,int G,int B,SDL_Rect section);
};

