/*******************************************************
ImageManager.cpp

Created by: Juan Manuel Amador Olivares
********************************************************/

#include "StdAfx.h"
#include "ImageManager.h"
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_rotozoom.h"

int ImageManager::imageNumber = 0;		// Se inicia la variable de clase que guarda el numero de imagenes

/*** Construtor ***/
ImageManager::ImageManager(void)
{
	imageNumber++;		// Cada vez que se crea un objeto se incrementa una unidad el numero de imagenes
	imageRect.x = 0;	// Se inicializa la estructura que contiene los atributos
	imageRect.y = 0;	// de la imagen original. Los atributos x e y son comunes a la imagen original y la auxiliar
	imageRect.w = 0;	// (realmente la imagen auxiliar no utiliza los atributos x e y, por lo que se usan
	imageRect.h = 0;	// los mismo que los de la imagen original)
	rotation = 0;		// La imagen no sufre ninguna rotacion al crear el objeto
	escale = 1;			// La imagen no sufre ningun escalado al crear el objeto
	opacity = -1;		// La opacidad esta desactivada al crear el objeto
	R = -1;				// EL ColorKey esta desactivado al crear el objeto
	G = -1;
	B = -1;
}

/*** Deconstructor ***/
ImageManager::~ImageManager(void)
{
	imageNumber--;		// Cuando el objeto se destruye se decrementa una unidad
}

/*** getNumberImages ***/
// Esta funcion devuelve el numero de imagenes creadas
// es decir, el numero de objetos creados
int ImageManager::getNumberImages(){
	return imageNumber;
}

/*** loadImage ***/
// Esta funcion carga una imagen, preparandola para ser utilizada
// La superficie "auxiliar" se utiliza como contenedor de la imagen original
// Esta superficie no se rotara ni se escalara, sino que se usara como base
// para escalarla y rotarla mediante la funcion "rotozoomSurface" de SDL_gfx
// y la superficie image sera la que guarde la superficie devuelta por esta funcion.
int ImageManager::loadImage(const char path[]){
	// Se carga la imagen
	if ((image = IMG_Load(path)) == NULL){	// Si no se puede cargar
		return -1;								// sale y devuelve -1
	} else{										// sino
		imageRect.w = image->w;					// se guardan los atributos
		imageRect.h = image->h;					// de la imagen cargada

		// Se crea la superfie auxiliar
		auxiliar = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCCOLORKEY|SDL_SRCALPHA,
			imageRect.w,imageRect.h,32,0,0,0,0);

		// Se copia la imagen original en la superficie auxiliar
		SDL_BlitSurface(image,NULL,auxiliar,&imageRect);
		return 0;								// Si todo va bien devuelve 0
	}
}

/*** getSurface ***/
// Devuelve la superficie de la imagen
// Esta superficie puede ser utilizada para hacer operaciones manualmente con ella
SDL_Surface *ImageManager::getSurface(){
	return image;
}

/*** getOriginalRect ***/
// Devuelve el SDL_Rect de la imagen original
SDL_Rect ImageManager::getOriginalRect(){
	return imageRect;
}

/*** getOriginalWIDTH ***/
// Devuelve el ancho de la imagen original
int ImageManager::getOriginalWIDTH(){
	return imageRect.w;
}

/*** getOriginalHEIGHT ***/
// Devuelve el alto de la imagen original
int ImageManager::getOriginalHEIGHT(){
	return imageRect.h;
}

/*** getWIDTH ***/
// Devuelve el ancho de la imagen
int ImageManager::getWIDTH(){
	return image->w;
}

/*** getHEIGHT ***/
// Devuelve el alto de la imagen
int ImageManager::getHEIGHT(){
	return image->h;
}

/*** getRect ***/
// Devuelve el SDL_Rect de la imagen
SDL_Rect ImageManager::getRect(){
	SDL_Rect newRect;			// Se crea una nueva estructura SDL_Rect
	newRect.x = imageRect.x;	// El atributo x sera igual que el de la imagen original
	newRect.y = imageRect.y;	// El atributo y sera igual que el de la imagen original
	newRect.w = image->w;		// Se guarda el nuevo ancho
	newRect.h = image->h;		// Se guarda el nuevo alto
	return newRect;
}

/*** getX ***/
// Devuelve la coordenada X
int ImageManager::getX(){
	return imageRect.x;
}

/*** getY ***/
// Devuelve la coordenada Y
int ImageManager::getY(){
	return imageRect.y;
}

/*** setX ***/
// Cambia la coordenada X
void ImageManager::setX(int x){
	imageRect.x = x;
}

/*** setY ***/
// Cambia la coordenada Y
void ImageManager::setY(int y){
	imageRect.y = y;
}

/*** getRotation ***/
// Devuelve la rotacion
double ImageManager::getRotation(){
	return rotation;
}

/*** getEscale ***/
// Devuelve el escalado (de 0 a 1)
double ImageManager::getEscale(){
	return escale;
}

/*** rotate ***/
// Utiliza la funcion rotozoomSurface para rotar la superficie auxiliar, que es similar a image pero no
// ha sufrido ninguna rotacion ni escalado. La superficie devuelta por esta funcion es la imagen rotada
// y esta superficie se guarda en la superficie image, que es la que se muestra.
// Tambien se guarda la rotacion
void ImageManager::rotate(double rotation){
	this->rotation = rotation;		
	image = rotozoomSurface(auxiliar,rotation,escale,1);
}

/*** rotateCentre ***/
// Se rota la imagen con la funcion escalate y se calculan las nuevas coordenadas para que de la sensacion
// de haber rotado la imagen respecto a su centro
// Para ello se le resta al ancho y alto orginal el ancho y alto de la nueva imagen tras ser rotada
// se divide entre dos y el resultado de esta operacion se le suma a las coordenadas x e y
void ImageManager::rotateCentre(double rotation){
	rotate(rotation);
	imageRect.x += (imageRect.w - image->w)/2;
	imageRect.y += (imageRect.h - image->h)/2;
}

/*** escalate ***/
// Utiliza la funcion rotozoomSurface para escalar la superficie auxiliar, que es similar a image pero no
// ha sufrido ninguna rotacion ni escalado. La superficie devuelta por esta funcion es la imagen escalada
// y esta superficie se guarda en la superficie image, que es la que se muestra.
// Tambien se guarda el escalado
// El escalado va de 0 a 1. 1 seria la imagen en sus estado original. Tambien puede sobre pasar 1 pero
// se produciria un aumento de la imagen y se perderia calidad de imagen.
void ImageManager::escalate(double escale){
	this->escale = escale;
	image = rotozoomSurface(auxiliar,rotation,escale,1);
}

/*** escalateCentre ***/
// Se escala la imagen con la funcion escalate y se calculan las nuevas coordenadas para que de la sensacion
// de haber escalado la imagen respecto a su centro
// Para ello se le resta al ancho y alto orginal el ancho y alto de la nueva imagen tras ser escalada
// se divide entre dos y el resultado de esta operacion se le suma a las coordenadas x e y
void ImageManager::escalateCentre(double escale){
	escalate(escale);
	imageRect.x += (imageRect.w - image->w)/2;
	imageRect.y += (imageRect.h - image->h)/2;
}

/*** setColorKey ***/
// Selecciona un color para la transparencia. Este color no se mostrara, es decir sera totalmente transparente.
int ImageManager::setColorKey(int R, int G, int B){
	if (R < 0 || G < 0 || B < 0 || R > 255 || G > 255 || B > 255){	// Se comprueba que el color RGB
		return -1;													// este dentro de los valores permitidos sino sale y devuelve -1
	}else{
		SDL_SetColorKey(image,SDL_SRCCOLORKEY|SDL_RLEACCEL,SDL_MapRGB(image->format,R,G,B));
		this->R = R;
		this->G = G;
		this->B = B;
	}
	return 0;		// Si todo va bien se devuelve 0
}

/*** disabledColorKey ***/
// Desactiva el color seleccionado como transparente
void ImageManager::disabledColorKey(){
	SDL_SetColorKey(image,0,SDL_MapRGB(image->format,0,0,0));
	R = -1;
	G = -1;
	B = -1;
}

/*** setOpacity ***/
// Cambia la opacidad la imagen
int ImageManager::setOpacity(int opacity){
	if (opacity < 0 || opacity > 255){
		return -1;
	}else{
		SDL_SetAlpha(image,SDL_SRCALPHA|SDL_RLEACCEL,opacity);
		this->opacity = opacity;
	}
	return 0;
}

/*** disabledOpacity ***/
// Desactiva la opacidad
void ImageManager::disabledOpacity(){
	SDL_SetAlpha(image,0,255);
	opacity = -1;
}

/*** blitSurface ***/
// Copia la imagen en la superficie pasada como argumento
void ImageManager::blitSurface(SDL_Surface *surface){
	setOpacity(opacity);	// Se actualizan la opacidad y el ColorKey de la imagen por si ha habida alguna
	setColorKey(R,G,B);		// rotacion o escalado, ya que lo desactivan
	SDL_BlitSurface(image, NULL, surface, &getRect());	// Se copia toda la imagen
}

/*** blitSurface ***/
// Copia la una parte de la imagen definida por el SDL_Rect pasado como argumento en la superficie superficie pasada como argumento
void ImageManager::blitSurface(SDL_Surface *surface, SDL_Rect section){
	setOpacity(opacity);	// Se actualizan la opacidad y el ColorKey de la imagen por si ha habida alguna
	setColorKey(R,G,B);		// rotacion o escalado, ya que lo desactivan
	SDL_BlitSurface(image, &section, surface, &getRect());	// Se copia una parte de la imagen
}

