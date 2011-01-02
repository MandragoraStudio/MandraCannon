/*******************************************************
MusicManager.cpp

Created by: Juan Manuel Amador Olivares
********************************************************/

#include "StdAfx.h"
#include "MusicManager.h"
#include "SDL_mixer.h"

/*** Construtor ***/
// Inicializa las variables
MusicManager::MusicManager(void){}

/*** Deconstructor ***/
// Destruye la memoria del objeto
MusicManager::~MusicManager(void){}

/*** loadMusic ***/
// Carga una musica en la superficie
int MusicManager::loadMusic(const char path[]){
	if ((music = Mix_LoadMUS(path)) == NULL){			// Si no se puede cargar
		return -1;										// sale y devuelve -1
	}
	return 0;
}

/*** setVolume ***/
// Cambia el volumen de la musica (de 0 a 128)
void MusicManager::setVolume(int volume){
	Mix_VolumeMusic(volume);
}

/*** playChunk ***/
// Reproduce el sonido tantas veces como se pase como argumento
// Para que el sonido sea reproducido indefinidamente debe pasarse el argumento REPEAT
// Para reproducirlo una vez debe pasarse el valor ONETIME
void MusicManager::playMusic(int loops){
	Mix_PlayMusic(music,loops);
}

/*** fadeInMusic ***/
// Reproduce el sonido tantas veces como se pase como argumento con un efecto de volumen ascendente
void MusicManager::fadeInMusic(int loops, int ms){
	Mix_FadeInMusic(music,loops,ms);
}

/*** pause ***/
// Pausa la reproduccion del chunk
void MusicManager::pause(){
	Mix_PauseMusic();
}

/*** resume ***/
// Reanuda la reproduccion del chunk
void MusicManager::resume(){
	Mix_ResumeMusic();
}

/*** halt ***/
// Para la reproduccion del chunk
void MusicManager::halt(){
	Mix_HaltMusic();
}

/*** fadeOut ***/
// Para la reproduccion del chunk con un efecto de volumen ascendente
void MusicManager::fadeOut(int ms){
	Mix_FadeOutMusic(ms);
}
