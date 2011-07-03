/*******************************************************
MusicManager.h

Created by: Juan Manuel Amador Olivares
********************************************************/

#pragma once
#include <SDL.h>
#include "SDL_mixer.h"

// Definiciones que describen la cantidad de veces que se reproducira una musica
#define REPEAT -1
#define ONETIME 0

class MusicManager
{
protected:
	Mix_Music *music;						// Estrutura que guardara la musica

public:
	MusicManager(void);						// Constructor, inicializa los atributos
	~MusicManager(void);					// Deconstrutor
	int loadMusic(const char path[]);		// Carga la musica en la superficie
	void setVolume(int volume);				// Cambia el volumen del de la musica (de 0 a 128)
	void playMusic(int loops);				// Reproduce el sonido tantas veces como se pase como argumento
	void fadeInMusic(int loops, int ms);	// Reproduce el sonido tantas veces como se pase como argumento 
											// con un efecto de volumen ascendente
	void pause();							// Pausa la reproduccion de la musica
	void resume();							// Reanuda la reproduccion del musica
	void halt();							// Para la reproduccion de la musica
	void fadeOut(int ms);					// Para la reproduccion de la musica con un efecto de volumen 
											// descendente
};

