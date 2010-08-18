#include <file.h>
#include <string>
#include <SDL/SDL_mixer.h>
#include <report.hpp>
#include "sfx.hpp"

AudioSoundFX::AudioSoundFX(std::string filename)
{
	filename = path_construct("sounds/sfx", filename);
	report("Loading SFX \"" + filename + "\"", MSG_DEBUG);
	sound_chunk = Mix_LoadWAV(filename.c_str());
		if(sound_chunk == NULL)
		{
			report("Can't load sound \"" + filename + "\"", MSG_ERROR);
		}
}

AudioSoundFX::~AudioSoundFX()
{
	Mix_FreeChunk(sound_chunk);
	sound_chunk=NULL;
}

void AudioSoundFX::LoadFromFile(std::string filename)
{

}

void AudioSoundFX::Play()
{
	report("Playing sound", MSG_DEBUG);
	if(Mix_PlayChannel(-1, sound_chunk, 0) == -1)
	{
			//log("ERROR: can't play sound. " + char* Mix_GetError());
			report("Can't play sound", MSG_ERROR);
	}
}
