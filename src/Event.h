#ifndef __EVENT_H__
	#define __EVENT_H__

#include <SDL.h>

class Event {
	public:
		Event();
		
		virtual ~Event();
		
		virtual void OnEvent(SDL_Event* Event);

#endif
