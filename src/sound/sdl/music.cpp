#include <file.h>
#include <SDLUtils.h>
#include <string>
#include <SDL/SDL_mixer.h>
#include "music.hpp"

AudioMusic::AudioMusic(std::string filename)
{
	filename = path_construct("sounds/music", filename);
	#ifdef DEBUG
		log("Loading music file \"" + filename + "\"");
	#endif
	music = Mix_LoadMUS(filename.c_str());
	if (!music)
	{
		log("ERROR: Can't load music file \"" + filename + "\"");
	}
}

AudioMusic::~AudioMusic()
{
	Mix_FreeMusic(music);
	music=NULL;
}

void AudioMusic::Play()
{
	#ifdef DEBUG
		log("Playing music");
	#endif
	if (Mix_PlayMusic(music, -1) == -1)
	{
		log("ERROR: Can't play music");
	}
}
