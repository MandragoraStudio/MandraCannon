#include "StdAfx.h"
#include "SurfaceManager.h"
#include <stdio.h>
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_rotozoom.h"

int SurfaceManager::imageNumber = 0;


SurfaceManager::SurfaceManager(int WIDTH, int HEIGHT)
{
	imageNumber++;		// Cada vez que se crea un objeto se incrementa una unidad
	imageRect.x = 0;
	imageRect.y = 0;
	imageRect.w = WIDTH;
	imageRect.h = HEIGHT;
	image = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCCOLORKEY|SDL_SRCALPHA,WIDTH,HEIGHT,32,0,0,0,0);
}


SurfaceManager::~SurfaceManager(void)
{
	imageNumber--;		// Cuando el objeto se destruye se decrementa una unidad
}

SDL_Surface *SurfaceManager::getSurface(){
	return image;
}

SDL_Rect SurfaceManager::getRect(){
	return imageRect;
}

int SurfaceManager::getWIDTH(){
	return imageRect.w;
}

int SurfaceManager::getHEIGHT(){
	return imageRect.h;
}

int SurfaceManager::getX(){
	return imageRect.x;
}

int SurfaceManager::getY(){
	return imageRect.y;
}

void SurfaceManager::setX(int x){
	imageRect.x = x;
}

void SurfaceManager::setY(int y){
	imageRect.y = y;
}

void SurfaceManager::blitSurface(SDL_Surface *surface){
	SDL_BlitSurface(image, NULL, surface, &imageRect);
}

int SurfaceManager::setTransparency(int R, int G, int B){
	if (R < 0 || G < 0 || B < 0 || R > 255 || G > 255 || B > 255){
		return -1;
	}else{
		SDL_SetColorKey(image,SDL_SRCCOLORKEY|SDL_RLEACCEL,SDL_MapRGB(image->format,R,G,B));
	}
	return 0;
}

void SurfaceManager::disabledTransparency(){
	SDL_SetColorKey(image,0,SDL_MapRGB(image->format,0,0,0));
}

int SurfaceManager::setAlpha(int alpha){
	if (alpha < 0 || alpha > 255){
		return -1;
	}else{
		SDL_SetAlpha(image,SDL_SRCALPHA|SDL_RLEACCEL,alpha);
	}
	return 0;
}

void SurfaceManager::disabledAlpha(){
	SDL_SetAlpha(image,0,255);
}

int SurfaceManager::fillSurface(int R, int G, int B){
	if (R < 0 || G < 0 || B < 0 || R > 255 || G > 255 || B > 255){
		return -1;
	}else{
		SDL_Rect fill;
		fill.x = 0;
		fill.y = 0;
		fill.w = imageRect.w;
		fill.h = imageRect.h;
		SDL_FillRect(image,&fill,SDL_MapRGB(image->format,R,G,B));
	}
	return 0;
}
