/*
 *		audio.cpp - audio engine C++ source (SDL version)
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

#include <SDL/SDL_mixer.h>
#include <io.hpp>
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
