#ifndef __ENGINESTATE_H__
	#define __ENGINESTATE_H__

#include "Engine_Event.h"

class EngineState : public EngineEvent {
	public:
		EngineState();
	
	public:
		virtual void Activate_Process() = 0;
		
		virtual void Deactivate_Process() = 0;
		
		virtual void Loop_Process() = 0;
		
		virtual void Render_Process(SDL_Surface* Surf_Engine_Window) = 0;
};

#endif
