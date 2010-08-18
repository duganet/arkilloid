#include <SDL/SDL_mixer.h>
#include <SDLUtils.h>
#include "audio.hpp"

bool AudioEngine::Start()
{
	#ifdef DEBUG
		log("Starting SDL_Mixer audio engine");
	#endif
	int mix_flags=MIX_INIT_OGG;
	int initted=Mix_Init(mix_flags);
	#ifdef DEBUG
		log("Mix_Init();");
	#endif
	if (initted&mix_flags != mix_flags)
	{
		log("Mix_Init failed");
	}
	#ifdef DEBUG
		log("Mix_OpenAudio();");
	#endif
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
		log("Mix_OpenAudio failed");
	}
}
bool AudioEngine::Stop()
{
	Mix_CloseAudio();
	Mix_Quit();
}
