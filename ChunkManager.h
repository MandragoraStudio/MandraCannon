/*******************************************************
ChunkManager.h

Created by: Juan Manuel Amador Olivares
********************************************************/

#pragma once
#include <SDL.h>
#include "SDL_mixer.h"

// Definiciones que describen la cantidad de veces que se reproducira un sonido
#define REPEAT -1
#define ONETIME 0

class ChunkManager
{
protected:
	Mix_Chunk *chunk;										// Estrutura que guardara el sonido
	static int chunkNumber;									// Cuenta el numero de chunks creados
	static int maxChannels;									// Guarda el numero maximo de canales que se utilizaran simultaneamente
	static int *channels;									// Mediante este puntero se accedera a un array que guardara que canales estan ocupados
	int channel;											// Guarda el canal asignado al chunk
public:
	ChunkManager(void);										// Constructor, inicializa los atributos
	~ChunkManager(void);									// Deconstrutor
	static int setMaxChannels(int maxNumberChannels);		// A este metodo se le pasa el numero maximo de canales que va aser utilizado simultaneamente
	int getNumberChunks();									// Devuelve el numero de chunks creados
	int loadChunk(const char path[]);						// Carga un chunk en la superficie
	void setVolume(int volume);								// Cambia el volumen del chunk (de 0 a 128)
	void playChunk(int loops);								// Reproduce el sonido tantas veces como se pase como argumento
	void playChunkTimed(int loops, int ticks);				// Reproduce una parte del sonido tantas veces como se pase como argumento
	void fadeInChunk(int loops, int ms);					// Reproduce el sonido tantas veces como se pase como argumento con un efecto de volumen ascendente
	void fadeInChunkTimed(int loops, int ms, int ticks);	// Reproduce el sonido tantas veces como se pase como argumento una parte del sonido con un efecto ascendente
	void pause();											// Pausa la reproduccion del chunk
	void resume();											// Reanuda la reproduccion del chunk
	void halt();											// Para la reproduccion del chunk
	void fadeOut(int ms);									// Para la reproduccion del chunk con un efecto de volumen ascendente
	bool getChannelState();									// Devuelve true si el canal asociado al chunk se esta reproducciendo y false si esta en pausa
	int getChunkChannel();									// Devuelve el canal utilizado por el chunk
	int getMaxNumberChannels();								// Devuelve el numero maximo de canales que se utilizaran simultaneamente
	static bool getFreeChannel(int channel);				// Devuelve true si el canala pasado como argumento puede utilizarse o false si esta siendo utilizado
};

