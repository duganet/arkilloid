#ifndef __ENGINESTATE_H__
	#define __ENGINESTATE_H__

#include "Engine_Event.h"

class EngineState : public EngineEvent {
	public:
		EngineState();

	public:
		virtual void OnActivate() = 0;

		virtual void OnDeactivate() = 0;

		virtual void OnLoop() = 0;

		virtual void OnRender(SDL_Surface* Surf_Display) = 0;
};

#endif
