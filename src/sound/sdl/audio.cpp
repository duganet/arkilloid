#include <SDL/SDL_mixer.h>
#include <report.hpp>
#include "audio.hpp"

bool AudioEngine::Start()
{
	report("Starting SDL_Mixer audio engine", MSG_DEBUG);
	int mix_flags=MIX_INIT_OGG;
	int initted=Mix_Init(mix_flags);
	report("Mix_Init()", MSG_DEBUG);
	if (initted&mix_flags != mix_flags)
	{
		report("Mix_Init failed", MSG_ERROR);
	}
	report("Mix_OpenAudio()", MSG_DEBUG);
	if (Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
		report("Mix_OpenAudio failed", MSG_ERROR);
	}
}
bool AudioEngine::Stop()
{
	Mix_CloseAudio();
	Mix_Quit();
}
