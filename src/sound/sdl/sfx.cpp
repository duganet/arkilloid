/*
 *		sfx.cpp - sounds playing module (SDL version)
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
