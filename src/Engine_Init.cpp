#include "Engine.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <io.hpp>
#include <sound.hpp>

extern AudioEngine *audio;
extern AudioSoundFX *snd_bonusget, *snd_hit, *snd_pow;
extern AudioMusic *audio_music;

bool Engine::Init() {
	report("Initializing Engine...", MSG_DEBUG);
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		report("SDL Initialization failed!", MSG_ERROR);
		return false;
	}
	report("Initializing Engine phase complete", MSG_DEBUG);
	
	/*
	if((surf_engine = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}
	*/
	
	::AudioEngine::Start();
	
	return true;
}
