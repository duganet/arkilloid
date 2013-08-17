#include "Engine.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <io.hpp>
#include <sound.hpp>
#include "Constants.h"

extern AudioEngine *audio;
extern AudioSoundFX *snd_bonusget, *snd_hit, *snd_pow;
extern AudioMusic *audio_music;

bool Engine::Init() {
	report("Engine::Init started", MSG_DEBUG);
	report("SDL_Init started", MSG_DEBUG);
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		report("SDL Initialization failed!", MSG_ERROR);
		return false;
	}
	report("SDL_Init finished", MSG_DEBUG);
	
	report("Creating Surface_Engine_Window started", MSG_DEBUG);
	if((Surf_Engine_Window = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_OPENGL)) == NULL) {
		return false;
	}
	report("Creating Surface_Engine_Window finished", MSG_DEBUG);
	
	::AudioEngine::Start();
	
	report("Engine::Init finished", MSG_DEBUG);
	return true;
}
