/*
 *		Engine.h - Arkilloid core engine headers
 *
 *		Copyright 2012 Maxim Kachur <mcdebugger@duganet.ru>
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

#ifndef _ENGINE_H_
	#define _ENGINE_H_

#include <SDL.h>

#include "Event.h"
#include "Surface.h"

class Engine : public Event {
	private:
		bool            Engine_Running;

		SDL_Surface*    Surf_Display;

		SDL_Surface*	Surf_Background;

	public:

		Engine();

		int OnExec();

	public:

		bool OnInit();

		void OnEvent(SDL_Event* event);

		void OnLoop();

		void OnRender();

		void OnCleanup();

		void Stop();

		void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

		void OnExit();
};

#endif
