#include "StdAfx.h"
#include <SDL.h>
#include <math.h>
#include "Utilities.h"

const double PI = 3.14159265;

/*** rotatePoint ***/
// Devuelve en un SDL_Rect las coordenadas de un punto rotado respecto
// a un centro (otro punto)
SDL_Rect rotatePoint(int x, int y, int Xorigin, int Yorigin, double rotation)
{
	// Hago la rotacion respecto al origen, para ello utilizo un punto auxiliar
	int auxX, auxY;		// Punto auxiliar para calculos

	auxX = x - Xorigin;
	auxY = y - Yorigin;
	
	// Roto el punto auxiliar respecto al origen
	SDL_Rect newRect;
	newRect.h = 0;
	newRect.w = 0;
	newRect.x = (int)(auxX*cos(rotation) - auxY*sin(rotation)) + Xorigin;
	newRect.y = (int)(auxX*sin(rotation) + auxY*cos(rotation)) + Yorigin;
	return newRect;
}

/*** degreeToRads ***/
// Convierte grados a radianes
double degreeToRads(double degree)
{
	return (PI*degree)/180;
}

/*** overRect ***/
// Comprueba si el punto esta sobre el rectangulo pasado como argumento
bool overRect(int x, int y, SDL_Rect rect)
{
	if ( (x < (rect.x + rect.w) && x > rect.x) &&	// Se comprueba si el evento se ha producido en el rectnagulo
		(y < (rect.y + rect.h) && y > rect.y) ){		// pasado como argumento
			return true;
	}
	return false;
}

/*** overRect ***/
// Comprueba si el punto esta sobre el rectangulo pasado como argumento
// Teniendo en cuenta el escalado del rectangulo mostrado y los bordes
bool overRect(int x, int y, SDL_Rect rect,
		double percent, int HEIGHTborder, int WIDTHborder)
{

	if ( (x < (rect.x + rect.w) && x > rect.x) &&		// Se comprueba si el evento se ha producido en el rectangulo
		(y < (rect.y + rect.h) && y > rect.y) ){		// pasado como argumento
			return true;
	}
	return false;
}

bool over(int x, int y, SDL_Rect OriginalRect, double rotation, double scale, double screen, double percent, int HEIGHTborder, int WIDTHborder)
{
	return true;
}

