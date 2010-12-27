#include "StdAfx.h"
#include "ImageManager.h"
#include <stdio.h>
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_rotozoom.h"

int ImageManager::imageNumber = 0;

ImageManager::ImageManager(void)
{
	imageNumber++;		// Cada vez que se crea un objeto se incrementa una unidad
	imageRect.x = 0;
	imageRect.y = 0;
	imageRect.w = 0;
	imageRect.h = 0;
	rotation = 0;
	escale = 1;
	alpha = -1;
	R = -1;
	G = -1;
	B = -1;
}


ImageManager::~ImageManager(void)
{
	imageNumber--;		// Cuando el objeto se destruye se decrementa una unidad
}

int ImageManager::getNumberImages(){
	return imageNumber;
}

int ImageManager::loadImage(const char folder[]){
	// Se carga la imagen
	if ((image = IMG_Load(folder)) == NULL){
		return -1;
	} else{
		imageRect.w = image->w;
		imageRect.h = image->h;

		// Se crea la superfie que no se escalara ni se rotara
		notEscalate = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCCOLORKEY|SDL_SRCALPHA,
			imageRect.w,imageRect.h,32,0,0,0,255);

		// Se copia la imagen original en la superficie que no se escalara ni rotara
		SDL_BlitSurface(image,NULL,notEscalate,&imageRect);
		return 0;		
	}
}

SDL_Surface *ImageManager::getSurface(){
	return image;
}

SDL_Rect ImageManager::getRect(){
	return imageRect;
}

int ImageManager::getWIDTH(){
	return imageRect.w;
}

int ImageManager::getHEIGHT(){
	return imageRect.h;
}

double ImageManager::getRotation(){
	return rotation;
}

double ImageManager::getEscale(){
	return escale;
}

int ImageManager::getX(){
	return imageRect.x;
}

int ImageManager::getY(){
	return imageRect.y;
}

void ImageManager::setX(int x){
	imageRect.x = x;
}

void ImageManager::setY(int y){
	imageRect.y = y;
}

int ImageManager::setAlpha(int alpha){
	if (alpha < 0 || alpha > 255){
		return -1;
	}else{
		SDL_SetAlpha(image,SDL_SRCALPHA|SDL_RLEACCEL,alpha);
		this->alpha = alpha;
	}
	return 0;
}

void ImageManager::disabledAlpha(){
	SDL_SetAlpha(image,0,255);
	alpha = -1;
}

void ImageManager::rotate(double rotation){
	this->rotation = rotation;
	image = rotozoomSurface(notEscalate,rotation,escale,1);
}
void ImageManager::rotateCentre(double rotation){
	rotate(rotation);
	imageRect.x += (imageRect.w - image->w)/2;
	imageRect.y += (imageRect.h - image->h)/2;
}

void ImageManager::escalate(double escale){
	this->escale = escale;
	image = rotozoomSurface(notEscalate,rotation,escale,1);
}

void ImageManager::escalateCentre(double escale){
	escalate(escale);
	imageRect.x += (imageRect.w - image->w)/2;
	imageRect.y += (imageRect.h - image->h)/2;
}

void ImageManager::blitSurface(SDL_Surface *surface){
	SDL_Rect newRect;
	newRect.x = imageRect.x;
	newRect.y = imageRect.y;
	newRect.w = image->w;
	newRect.h = image->h;
	setAlpha(alpha);
	setTransparency(R,G,B);
	SDL_BlitSurface(image, NULL, surface, &newRect);
}

int ImageManager::setTransparency(int R, int G, int B){
	if (R < 0 || G < 0 || B < 0 || R > 255 || G > 255 || B > 255){
		return -1;
	}else{
		SDL_SetColorKey(image,SDL_SRCCOLORKEY|SDL_RLEACCEL,SDL_MapRGB(image->format,R,G,B));
		this->R = R;
		this->G = G;
		this->B = B;
	}
	return 0;
}

void ImageManager::disabledTransparency(){
	SDL_SetColorKey(image,0,SDL_MapRGB(image->format,0,0,0));
	R = -1;
	G = -1;
	B = -1;
}

int ImageManager::getNewWIDTH(){
	return image->w;
}

int ImageManager::getNewHEIGHT(){
	return image->h;
}

SDL_Rect ImageManager::getNewRect(){
	SDL_Rect newRect;
	newRect.x = imageRect.x;
	newRect.y = imageRect.y;
	newRect.w = image->w;
	newRect.h = image->h;
	return newRect;
}
