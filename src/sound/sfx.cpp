#include "sfx.hpp"

SoundFX::SoundFX(std::string filename)
{
	SoundFX::LoadFromFile(std::string filename);
}

void SoundFX::LoadFromFile(std::string filename)
{
	filename = path_construct("sounds/sfx", filename);
	SoundChunk = Mix_LoadWAV(filename.c_str());
		if(SoundChunk == NULL)
		{
			log("ERROR: Can't load" + filename);
			return false;
		}
}

void SoundFX::Play()
{
	Mix_PlayChannel(-1, SoundChunk, 0);
}
