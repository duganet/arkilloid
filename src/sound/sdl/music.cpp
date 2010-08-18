#include <file.h>
#include <SDLUtils.h>
#include <string>
#include <SDL/SDL_mixer.h>
#include <report.hpp>
#include "music.hpp"

AudioMusic::AudioMusic(std::string filename)
{
	filename = path_construct("sounds/music", filename);
	report("Loading music file \"" + filename + "\"", MSG_DEBUG);
	music = Mix_LoadMUS(filename.c_str());
	if (!music)
	{
		report("Can't load music file \"" + filename + "\"", MSG_ERROR);
	}
}

AudioMusic::~AudioMusic()
{
	Mix_FreeMusic(music);
	music=NULL;
}

void AudioMusic::Off()
{
	Mix_PauseMusic();
}

void AudioMusic::On()
{
	this->Play();
}

void AudioMusic::Play()
{
	report("Playing music", MSG_DEBUG);
	if (Mix_PausedMusic())
	{
		Mix_ResumeMusic();
	}
	else if (Mix_PlayingMusic())
	{
		
	}
	else
	{
		if (Mix_PlayMusic(music, -1) == -1)
		{
			log("ERROR: Can't play music");
		}
	}
}
