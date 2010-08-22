/*
 *		music.cpp - music playing module (SDL version)
 *
 *		Copyright 2010 Maxim Kachur <mcdebugger@duganet.ru>
 *		Copyright 2010 Sergey Babneev <plughead@mail.ru>
 *		
 *		This file is part of Arkilloid.
 *
 *		Arkilloid is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		Arkilloid is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with Arkilloid.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string>
#include <SDL/SDL_mixer.h>
#include <io.hpp>
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
