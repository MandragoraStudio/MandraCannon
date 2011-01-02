/*******************************************************
ChunkManager.cpp

Created by: Juan Manuel Amador Olivares
********************************************************/

#include "StdAfx.h"
#include "ChunkManager.h"
#include "SDL_mixer.h"

int ChunkManager::chunkNumber = 0;		// Se inicia la variable de clase que guarda el numero de imagenes
int ChunkManager::maxChannels = 0;		// Se inicia la variable de clase que guarda el numero de imagenes
int *ChunkManager::channels = NULL;		// Se inicia la variable de clase que guarda el numero de imagenes


/*** Construtor ***/
// Inicializa las variables
ChunkManager::ChunkManager(void){}

/*** Deconstructor ***/
// Destruye la memoria del objeto
ChunkManager::~ChunkManager(void)
{
	channels[channel-1] = 0;	// Se deja libre ese canal
	chunkNumber--;				// Cuando el objeto se destruye se decrementa una unidad
}

/*** setMaxChannels ***/
// A este metodo hay que pasarle el numero de canales simultaneos que se van a utilizar
// es decir, el numero de sonidos simultaneos que se van a utilizar. Hay que llamarlo ciuando se cargue el primer sonido.
// Channels es un array que guardara el estado de los canales. Hay dos valores posibles:
// 0, si el canal esta libre y puede ser utilizado
// 1, si el canal esta asociado a un chunk
int ChunkManager::setMaxChannels(int maxNumberChannels){
	if (maxNumberChannels < 0){						// Si el valor es 0 o menor
		return -1;									// sale y devuelve -1
	}else{											// sino
		maxChannels = maxNumberChannels;			// se guarda el numero maximo de canales
		Mix_AllocateChannels(maxChannels);			// Se seleccionan el numero maximo de canales que SDL va a usar simultaneamente
		channels = new int[maxChannels];			// Se crea el array que guardara el estado de los canales
		for (int i = 0; i < maxChannels; i++){		// Se inicializa el array en 0
			channels[i] = 0;						// Si el canal esta a 1 es que esta siendo usado sino valdra 0
		}
	}
	return 0;
}

/*** getNumberImages ***/
// Esta funcion devuelve el numero de chunks creados
// es decir, el numero de objetos creados
int ChunkManager::getNumberChunks(){
	return chunkNumber;
}

/*** loadChunk ***/
// Carga un chunk en la superficie
// Antes de cargar el primer chunk hay que seleccionar el numero maximo de canales que se van a utilizar
int ChunkManager::loadChunk(const char path[]){
	if ((chunk = Mix_LoadWAV(path)) == NULL){			// Si no se puede cargar
		return -1;										// sale y devuelve -1
	} else{
		if (maxChannels > 0){							// El numero de canales maximo debe ser mayor que 0
			channel = 0;								// Se inicializa el canal						
			// Se le asigna al chunk el primer canal del array de canales que este libre
			for (int i = 0; i < maxChannels && channel == 0; i++){
				if (getFreeChannel(i+1) == true){
					channels[i] = 1;
					channel = i+1;
				}
			}
			chunkNumber++;								// Cada vez que se crea un objeto se incrementa una unidad el numero de chunks
		}else{
			return -1;
		}
		return 0;
	}
}

/*** setVolume ***/
// Cambia el volumen del chunk (de 0 a 128)
void ChunkManager::setVolume(int volume){
	Mix_VolumeChunk(chunk,volume);
}

/*** playChunk ***/
// Reproduce el sonido tantas veces como se pase como argumento
// Para que el sonido sea reproducido indefinidamente debe pasarse el argumento REPEAT
// Para reproducirlo una vez debe pasarse el valor ONETIME
void ChunkManager::playChunk(int loops){
	Mix_PlayChannel(channel,chunk,loops);
}

/*** playChunkTimed ***/
// Reproduce una parte del sonido tantas veces como se pase como argumento
void ChunkManager::playChunkTimed(int loops, int ticks){
	Mix_PlayChannelTimed(channel,chunk,loops,ticks);
}

/*** fadeInChunk ***/
// Reproduce el sonido tantas veces como se pase como argumento con un efecto de volumen ascendente
void ChunkManager::fadeInChunk(int loops, int ms){
	Mix_FadeInChannel(channel,chunk,loops,ms);
}

/*** fadeInChunkTimed ***/
// Reproduce el sonido tantas veces como se pase como argumento una parte del sonido con un efecto ascendente
void ChunkManager::fadeInChunkTimed(int loops, int ms, int ticks){
	Mix_FadeInChannelTimed(channel,chunk,loops,ms,ticks);
}

/*** pause ***/
// Pausa la reproduccion del chunk
void ChunkManager::pause(){
	Mix_Pause(channel);
}

/*** resume ***/
// Reanuda la reproduccion del chunk
void ChunkManager::resume(){
	Mix_Resume(channel);
}

/*** halt ***/
// Para la reproduccion del chunk
void ChunkManager::halt(){
	Mix_HaltChannel(channel);
}

/*** fadeOut ***/
// Para la reproduccion del chunk con un efecto de volumen ascendente
void ChunkManager::fadeOut(int ms){
	Mix_FadeOutChannel(channel, ms);
}

/*** getChannelState ***/
// Devuelve true si el canal asociado al chunk se esta reproducciendo y false si esta en pausa
bool ChunkManager::getChannelState(){
	if (Mix_Paused(channel) == 1){
		return true;
	}else{
		return false;
	}
}

/*** getChunkChannel ***/
// Devuelve el canal utilizado por el chunk
int ChunkManager::getChunkChannel(){
	return channel;
}

/*** getMaxNumberChannels ***/
// Devuelve el numero maximo de canales que se utilizaran simultaneamente
int ChunkManager::getMaxNumberChannels(){
	return maxChannels;
}

/*** getFreeChannel ***/
// Devuelve true si el canal pasado como argumento puede utilizarse o false si esta siendo utilizado
bool ChunkManager::getFreeChannel(int channel){
	if (channels[channel-1] == 0){
		return true;
	}else{
		return false;
	}
}





