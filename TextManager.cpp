/*******************************************************
TextManager.cpp

Created by: Juan Manuel Amador Olivares
********************************************************/

#include "StdAfx.h"
#include "TextManager.h"
#include "SDL_image.h"
#include "SDL_rotozoom.h"

int TextManager::textNumber = 0;		// Se inicia la variable de clase que guarda el numero de imagenes de texto

/*** Construtor ***/
// Inicializa las variables
TextManager::TextManager(void)
{
	textNumber++;		// Cada vez que se crea un objeto se incrementa una unidad el numero de imagenes
	imageRect.x = 0;	// Se inicializa la estructura que contiene los atributos
	imageRect.y = 0;	// de la imagen original. Los atributos x e y son comunes a la imagen original y la auxiliar
	imageRect.w = 0;	// (realmente la imagen auxiliar no utiliza los atributos x e y, por lo que se usan
	imageRect.h = 0;	// los mismo que los de la imagen original)
	rotation = 0;		// La imagen no sufre ninguna rotacion al crear el objeto
	scale = 1;			// La imagen no sufre ningun escalado al crear el objeto
	opacity = -1;		// La opacidad esta desactivada al crear el objeto
	R = -1;				// EL ColorKey esta desactivado al crear el objeto
	G = -1;
	B = -1;
	textSize = 20;		// El tamaño de texto inicial es 20
	fgcolor.r = 0;		// El color inicial del texto establecido es negro
	fgcolor.g = 0;
	fgcolor.b = 0;
}

/*** Deconstructor ***/
// Destruye la memoria del objeto
TextManager::~TextManager()
{
		textNumber--;		// Cuando el objeto se destruye se decrementa una unidad
}

/*** getTextImages ***/
// Esta funcion devuelve el numero de imagenes creadas
// es decir, el numero de objetos creados
int TextManager::getNumberTexts(){
	return textNumber;
}

/*** loadFont ***/
// Esta funcion carga una un archivo de fuente de texto. El texto de la imagen se creara utilizando esta fuente
void TextManager::loadFont(const char path[]){
	this->path = path;
	font = TTF_OpenFont(path, textSize);
}

/*** setTextSize ***/
// Esta funcion cambia el tamaño del texto. Los valore spermitidos estan entre 5 y 500
int TextManager::setTextSize(int textSize){
	if (textSize < 5 || textSize > 500){		// TextSize tiene que estar entre 5 o 500 sino sale y devuelve -1
		return -1;
	}else{										// Sino
		font = TTF_OpenFont(path, textSize);	// se carga la fuente con le tamaño seleccionado
	}
	return 0;									// Se devuelve 0 si todo ha salido correctamente
}

/*** setFontStyle ***/
// Con esta funcion se selecciona el estilo de texto. Las posibilidades son:
// negrita: pasar el argumento BOLD
// subrayado: pasar el argumento UNDERLINE
// estilo italica: pasar el argumento ITALIC
// normal: pasar el argumento NORMAL
void TextManager::setFontStyle(int style){
	TTF_SetFontStyle(font,style);
}

/*** setTextColor ***/
// Selecciona un color para el texto. Los valores RGB se guardan en la estrutura SDL_Color que despues sera utilizada para crear
// la superficie de la imagen con el texto
int TextManager::setTextColor(int R, int G, int B){
	if (R < 0 || G < 0 || B < 0 || R > 255 || G > 255 || B > 255){	// Se comprueba que el color RGB
		return -1;													// este dentro de los valores permitidos sino sale y devuelve -1
	}else{
		fgcolor.r = R;
		fgcolor.g = G;
		fgcolor.b = B;
	}
	return 0;
}

/*** setText ***/
int TextManager::setText(const char text[]){
	// Se crea la imagen
	if ((image = TTF_RenderText_Blended(font,text,fgcolor/*,bgcolor*/)) == NULL){	// Si no se puede cargar
		return -1;																// sale y devuelve -1
	}else{																		
		imageRect.w = image->w;													// se guardan los atributos
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
SDL_Surface *TextManager::getSurface(){
	return image;
}

/*** getOriginalRect ***/
// Devuelve el SDL_Rect de la imagen original
SDL_Rect TextManager::getOriginalRect(){
	return imageRect;
}

/*** getOriginalWIDTH ***/
// Devuelve el ancho de la imagen original
int TextManager::getOriginalWIDTH(){
	return imageRect.w;
}

/*** getOriginalHEIGHT ***/
// Devuelve el alto de la imagen original
int TextManager::getOriginalHEIGHT(){
	return imageRect.h;
}

/*** getWIDTH ***/
// Devuelve el ancho de la imagen
int TextManager::getWIDTH(){
	return image->w;
}

/*** getHEIGHT ***/
// Devuelve el alto de la imagen
int TextManager::getHEIGHT(){
	return image->h;
}

/*** getRect ***/
// Devuelve el SDL_Rect de la imagen
SDL_Rect TextManager::getRect(){
	SDL_Rect newRect;			// Se crea una nueva estructura SDL_Rect
	newRect.x = imageRect.x;	// El atributo x sera igual que el de la imagen original
	newRect.y = imageRect.y;	// El atributo y sera igual que el de la imagen original
	newRect.w = image->w;		// Se guarda el nuevo ancho
	newRect.h = image->h;		// Se guarda el nuevo alto
	return newRect;
}

/*** getX ***/
// Devuelve la coordenada X
int TextManager::getX(){
	return imageRect.x;
}

/*** getY ***/
// Devuelve la coordenada Y
int TextManager::getY(){
	return imageRect.y;
}

/*** setX ***/
// Cambia la coordenada X
void TextManager::setX(int x){
	imageRect.x = x;
}

/*** setY ***/
// Cambia la coordenada Y
void TextManager::setY(int y){
	imageRect.y = y;
}

/*** getRotation ***/
// Devuelve la rotacion
double TextManager::getRotation(){
	return rotation;
}

/*** getEscale ***/
// Devuelve el escalado (de 0 a 1)
double TextManager::getScale(){
	return scale;
}

/*** rotate ***/
// Utiliza la funcion rotozoomSurface para rotar la superficie auxiliar, que es similar a image pero no
// ha sufrido ninguna rotacion ni escalado. La superficie devuelta por esta funcion es la imagen rotada
// y esta superficie se guarda en la superficie image, que es la que se muestra.
// Tambien se guarda la rotacion
void TextManager::rotate(double rotation){
	this->rotation = rotation;		
	image = rotozoomSurface(auxiliar,rotation,scale,1);
}

/*** scalate ***/
// Utiliza la funcion rotozoomSurface para escalar la superficie auxiliar, que es similar a image pero no
// ha sufrido ninguna rotacion ni escalado. La superficie devuelta por esta funcion es la imagen escalada
// y esta superficie se guarda en la superficie image, que es la que se muestra.
// Tambien se guarda el escalado
// El escalado va de 0 a 1. 1 seria la imagen en sus estado original. Tambien puede sobre pasar 1 pero
// se produciria un aumento de la imagen y se perderia calidad de imagen.
void TextManager::scalate(double scale){
	this->scale = scale;
	image = rotozoomSurface(auxiliar,rotation,scale,1);
}

/*** setOpacity ***/
// Cambia la opacidad la imagen
int TextManager::setOpacity(int opacity){
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
void TextManager::disabledOpacity(){
	SDL_SetAlpha(image,0,255);
	opacity = -1;
}

/*** blitSurface ***/
// Copia la imagen en la superficie pasada como argumento
void TextManager::blitSurface(SDL_Surface *surface){
	setOpacity(opacity);	// Se actualizan la opacidad y el ColorKey de la imagen por si ha habida alguna
	auxRect.w = image->w;
	auxRect.h = image->h;
	auxRect.x = imageRect.x - auxRect.w/2;
	auxRect.y = imageRect.y - auxRect.h/2;
	SDL_BlitSurface(image, NULL, surface, &auxRect);	// Se copia toda la imagen
}

/*** blitSurface ***/
// Copia la una parte de la imagen definida por el SDL_Rect pasado como argumento en la superficie superficie pasada como argumento
void TextManager::blitSurface(SDL_Surface *surface, SDL_Rect section){
	setOpacity(opacity);	// Se actualizan la opacidad y el ColorKey de la imagen por si ha habida alguna
	auxRect.w = image->w;
	auxRect.h = image->h;
	auxRect.x = imageRect.x - auxRect.w/2;
	auxRect.y = imageRect.y - auxRect.h/2;
	SDL_BlitSurface(image, &section, surface, &auxRect);	// Se copia una parte de la imagen
}