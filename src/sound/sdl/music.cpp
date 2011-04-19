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
#include <SDL_mixer.h>
#include <io.hpp>
#include "music.hpp"

AudioMusic::AudioMusic()
{
	report("Starting AudioMusic", MSG_DEBUG);
	tracks.push_back("intro.ogg");
	tracks.push_back("arkilloid_track_01.ogg");
	current_tracknum = -1;
	this->ChangeTrack();
	played = false;
}

AudioMusic::~AudioMusic()
{
	Mix_FreeMusic(music);
	music=NULL;
}

void AudioMusic::ChangeTrack()
{
	if (current_tracknum < tracks.size() - 1)
	{
		current_tracknum++;
	}
	else
	{
		current_tracknum = 0;
	}
	this->Load(tracks[current_tracknum]);
	this->Play();
}

void AudioMusic::CheckPlay()
{
	if (played)
	{
		if (!Mix_PlayingMusic())
		{
			this->ChangeTrack();
		}
	}
}

void AudioMusic::Load(std::string filename)
{
	filename = path_construct("sounds/music", filename);
	report("Loading music file \"" + filename + "\"", MSG_DEBUG);
	music = Mix_LoadMUS(filename.c_str());
	if (!music)
	{
		report("Can't load music file \"" + filename + "\"", MSG_ERROR);
	}
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
	played = true;
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
		if (Mix_PlayMusic(music, 0) == -1)
		{
			report("ERROR: Can't play music", MSG_ERROR);
		}
	}
}
