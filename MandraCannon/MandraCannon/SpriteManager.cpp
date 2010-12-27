#include "StdAfx.h"
#include "SpriteManager.h"
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_rotozoom.h"

#define numberInstances nrows*ncolumns


SpriteManager::SpriteManager(int numberRows,int numberColumns)
{
	nrows = numberRows;
	ncolumns = numberColumns;
	actualInstance = 1;
	notEscalate = new SDL_Surface*[numberInstances];
}


SpriteManager::~SpriteManager(void)
{
}

int SpriteManager::loadImage(const char folder[]){
	// Se carga la imagen del sprite
	if ((image = IMG_Load(folder)) == NULL){
		return -1;
	} else{
		imageRect.w = image->w/ncolumns;
		imageRect.h = image->h/nrows;	

	// Se crean las superficies necesarias para las instance del sprite
	for (int i = 0; i<numberInstances; i++){
		notEscalate[i] = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCCOLORKEY|SDL_SRCALPHA,
			imageRect.w,imageRect.h,32,0,0,0,255);
	}

	// Se copian cada una de las instancias del sprite en superficies distintas
	SDL_Rect copyRect;		// Este SDL_Rect se usara para copiar partes del sprites en superficies distintas
	copyRect.w = imageRect.w;
	copyRect.h = imageRect.h;
	for (int i = 0; i<nrows; i++){
		for (int j = 0; j<ncolumns; j++){
			copyRect.x = j*copyRect.w;
			copyRect.y = i*copyRect.h;
			SDL_BlitSurface(image,&copyRect,notEscalate[i*ncolumns + j],&imageRect);
		}
	}
	// La imagen que se va a mostrar es la que esta en la superficie image
	image = notEscalate[actualInstance-1];
	}
	return 0;
}

int SpriteManager::setInstance(int instanceNumber){
	if (instanceNumber < 1 || instanceNumber > numberInstances){
		return -1;
	} else{
		actualInstance = instanceNumber;
		image = notEscalate[actualInstance-1];
	}
	return 0;
}

int SpriteManager::getInstance(){
	return actualInstance;
}

void SpriteManager::rotate(double rotation){
	this->rotation = rotation;
	image = rotozoomSurface(notEscalate[actualInstance-1],rotation,escale,1);
}

void SpriteManager::rotateCentre(double rotation){
	SpriteManager::rotate(rotation);
	imageRect.x += (imageRect.w - image->w)/2;
	imageRect.y += (imageRect.h - image->h)/2;
}

void SpriteManager::escalate(double escale){
	this->escale = escale;
	image = rotozoomSurface(notEscalate[actualInstance-1],rotation,escale,1);
}

void SpriteManager::escalateCentre(double escale){
	SpriteManager::escalate(escale);
	imageRect.x += (imageRect.w - image->w)/2;
	imageRect.y += (imageRect.h - image->h)/2;
}



