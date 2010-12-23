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
}


ImageManager::~ImageManager(void)
{
	imageNumber--;		// Cuando el objeto se destruye se decrementa una unidad
}

int ImageManager::getNumberImages(){
	return imageNumber;
}

int ImageManager::loadImage(const char folder[]){
	if ((image = IMG_Load(folder)) == NULL){
		return -1;
	} else{
		imageRect.w = image->w;
		imageRect.h = image->h;
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

void ImageManager::rotate(double rotation){
	this->rotation = rotation;
	image = rotozoomSurface(image,rotation,escale,1);
}

void ImageManager::escalate(double escale){
	this->escale = escale;
	image = rotozoomSurface(image,rotation,escale,1);
}

void ImageManager::blitSurface(SDL_Surface *surface){
	SDL_BlitSurface(image, NULL, surface, &imageRect);
}
