/*******************************************************
SpriteManager.cpp

Created by: Juan Manuel Amador Olivares
********************************************************/

#include "StdAfx.h"
#include "SpriteManager.h"
#include "SDL_image.h"
#include "SDL_rotozoom.h"

#define numberInstances nrows*ncolumns	// Esta macro sera utilizada para calcular el numero de instancias del sprite

/*** Constructor ***/
// Inicializa las variables
// NOTA: La clase SpriteManager clase hereda de ImageManager, por tanto al crear un objeto de SpriteManager tambien
// se llamara al construtor de ImageManager, por lo que la variable de clase imageNumber tambien cuenta el numero
// de sprites cargados.
SpriteManager::SpriteManager(int numberRows,int numberColumns)
{
	nrows = numberRows;
	ncolumns = numberColumns;
	actualInstance = 1;
	auxiliar = new SDL_Surface*[numberInstances];
}


/*** Deconstructor ***/
// Destruye la memoria del objeto
// NOTA: La clase SpriteManager clase hereda de ImageManager, por tanto al destruir un objeto de SpriteManager tambien
// se llamara al deconstrutor de ImageManager, por lo que la variable de clase imageNumber tambien cuenta el numero
// de sprites destruidos.
SpriteManager::~SpriteManager(void){}

/*** loadImage ***/
// Esta funcion carga la imagen del sprite y lo prepara para ser utilizado
// La imagen original se divide y se copia en un array de superficies auxiliares. AL igual que en la clase ImageManager
// estas superficies auxiliares no se escalaran ni rotaran, sino que serviran de base para rotarlas y escalarlas
// mediante la funcion "rotozoomSurface" de SDL_gfx y la superficie image sera la que guarde la superficie devuelta por 
// esta funcion.
int SpriteManager::loadImage(const char folder[]){
	// Se carga la imagen del sprite
	if ((image = IMG_Load(folder)) == NULL){	// Si no se puede cargar
		return -1;								// sale y devuelve -1
	}else{										// sino
		imageRect.w = image->w/ncolumns;		// se guardan los atributos de las instancias. Para calcularlos se utilizan
		imageRect.h = image->h/nrows;			// los atributos de la imagen cargada y se dividen entre el numero de filas y columnas

	// Se crean las superficies necesarias para las instancias del sprite
	for (int i = 0; i<numberInstances; i++){
		auxiliar[i] = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCCOLORKEY|SDL_SRCALPHA,
			imageRect.w,imageRect.h,32,0,0,0,255);
	}

	// Se copian cada una de las instancias del sprite en superficies distintas
	SDL_Rect copyRect;			// Este SDL_Rect se usara para copiar partes del sprite (instancias) en superficies auxiliares distintas
	copyRect.w = imageRect.w;	// El ancho y alto son los mismos para todas las instancias
	copyRect.h = imageRect.h;
	for (int i = 0; i<nrows; i++){	// Se usan dos bucles anidados para ir copiando la siguiente parte cada vez
		for (int j = 0; j<ncolumns; j++){
			copyRect.x = j*copyRect.w;
			copyRect.y = i*copyRect.h;
			SDL_BlitSurface(image,&copyRect,auxiliar[i*ncolumns + j],&imageRect);
		}
	}

	// La imagen que se va a mostrar es la que esta en la superficie image, por lo que copiamos la superficie
	// de la instancia que se va a mostrar en esta superficie
	image = auxiliar[actualInstance-1];
	}
	return 0;		// Si todo va bien devuelve 0
}

/*** setInstance ***/
// Con esta funcion se selecciona la instancia del sprite que se va a mostrar
int SpriteManager::setInstance(int instanceNumber){
	if (instanceNumber < 1 || instanceNumber > numberInstances){	// Se comprueba que el valor pasado como argumento
		return -1;													// no sea menor que 1 o mayor que el numero de instancias
	} else{
		actualInstance = instanceNumber;							
		image = auxiliar[actualInstance-1];						// Se actualiza image
	}
	return 0;
}

/*** getInstance ***/
// Con esta funcion se obtiene la instancia del sprite que se va a mostrar
int SpriteManager::getInstance(){
	return actualInstance;
}

/*** rotate ***/
// Similar a ImageManager
void SpriteManager::rotate(double rotation){
	this->rotation = rotation;
	image = rotozoomSurface(auxiliar[actualInstance-1],rotation,escale,1);
}

/*** rotateCentre ***/
// Similar a ImageManager
void SpriteManager::rotateCentre(double rotation){
	SpriteManager::rotate(rotation);
	imageRect.x += (imageRect.w - image->w)/2;
	imageRect.y += (imageRect.h - image->h)/2;
}

/*** escalate ***/
// Similar a ImageManager
void SpriteManager::escalate(double escale){
	this->escale = escale;
	image = rotozoomSurface(auxiliar[actualInstance-1],rotation,escale,1);
}

/*** escalateCentre ***/
// Similar a ImageManager
void SpriteManager::escalateCentre(double escale){
	SpriteManager::escalate(escale);
	imageRect.x += (imageRect.w - image->w)/2;
	imageRect.y += (imageRect.h - image->h)/2;
}



