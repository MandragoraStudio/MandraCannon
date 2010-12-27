#pragma once
#include "imagemanager.h"
class SpriteManager :
	public ImageManager
{
protected:
	int nrows;
	int ncolumns;
	int actualInstance;	// Guarda la imagen del sprite que se va a mostrar
	SDL_Surface **notEscalate;
public:
	SpriteManager(int numberRows,int numberColumns);
	~SpriteManager(void);
	int loadImage(const char folder[]);
	int setInstance(int instanceNumber);	// Selecciona la instancia del sprite
	int getInstance();	// Devuelve la instancia en la que esta el sprite
	void rotate(double rotation);
	void rotateCentre(double rotation);	// Rota la imagen respecto al centro
	void escalate(double escale);
	void escalateCentre(double escale);		// Escala la imagen (porcentaje de 0 a 1) respecto al centro
};

