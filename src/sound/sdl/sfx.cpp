#include <file.h>
#include <SDLUtils.h>
#include <string>
#include <SDL/SDL_mixer.h>
#include "sfx.hpp"

SoundFX::SoundFX(std::string filename)
{
	filename = path_construct("sounds/sfx", filename);
	#ifdef DEBUG
		log("Loading SFX \"" + filename + "\"");
	#endif
	sound_chunk = Mix_LoadWAV(filename.c_str());
		if(sound_chunk == NULL)
		{
			log("ERROR: Can't load sound \"" + filename + "\"");
		}
}

SoundFX::~SoundFX()
{
	Mix_FreeChunk(sound_chunk);
	sound_chunk=NULL;
}

void SoundFX::LoadFromFile(std::string filename)
{

}

void SoundFX::Play()
{
	#ifdef DEBUG
		log("Playing sound");
	#endif
	if(Mix_PlayChannel(-1, sound_chunk, 0) == -1)
	{
			//log("ERROR: can't play sound. " + char* Mix_GetError());
			log("ERROR: can't play sound");
	}
}
