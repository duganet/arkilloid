/*
 *		music.hpp - music playing module headers (SDL version)
 *
 *		Copyright 2010-2012 Maxim Kachur <mcdebugger@duganet.ru>
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

#ifndef _MUSIC_H_
	#define _MUSIC_H_

#include <vector>
#include <SDL_mixer.h>

class AudioMusic
{
	private:
		int current_tracknum;
		Mix_Music* music;
		std::vector<std::string> tracks;
	public:
		AudioMusic();
		~AudioMusic();
		void OnInit();
		void ChangeTrack();
		void CheckPlay();
		void Load(std::string filename);
		void Off();
		void On();
		void Play();
};

#endif
