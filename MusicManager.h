/*******************************************************
MusicManager.h

Created by: Juan Manuel Amador Olivares
********************************************************/

#pragma once
#include <SDL.h>
#include "SDL_mixer.h"

class MusicManager
{
protected:
	Mix_Music *music;
public:
	MusicManager(void);						// Constructor, inicializa los atributos
	~MusicManager(void);					// Deconstrutor
	int loadMusic(const char path[]);			// Carga la musica en la superficie
};

