#include "sfx.hpp"

SoundFX::SoundFX(std::string filename)
{
	filename = path_construct("sounds/sfx", filename);
	#ifdef DEBUG
		log("Loading SFX \"" + filename + "\"");
	#endif
	SoundChunk = Mix_LoadWAV(filename.c_str());
		if(SoundChunk == NULL)
		{
			log("ERROR: Can't load sound \"" + filename + "\"");
		}
}

void SoundFX::LoadFromFile(std::string filename)
{

}

void SoundFX::Play()
{
	#ifdef DEBUG
		log("Playing sound");
	#endif
	Mix_PlayChannel(-1, SoundChunk, 0);
}
