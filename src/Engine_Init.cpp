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
	
	report("Creating Surf_Display started", MSG_DEBUG);
	if((Surf_Display = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}
	report("Creating Surf_Display finished", MSG_DEBUG);
	
	if((Surf_Background = Surface::OnLoad("/usr/local/share/arkilloid/images/bg_title.png")) == NULL) {
		return false;
	}
	
	::AudioEngine::Start();
	
	report("Engine::Init finished", MSG_DEBUG);
	return true;
}
