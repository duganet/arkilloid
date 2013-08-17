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

class Engine {
	private:
		bool            Engine_Running;
		
		SDL_Surface*    Surf_Engine_Window;
						
	public:
	
		Engine();
		
		int Exec();
		
	public:
		
		bool Init();
		
		void Event_Process(SDL_Event* event);
		
		void Loop_Process();
		
		void Render_Process();
		
		void Cleanup_Process();
		
		void Stop();
};

#endif
