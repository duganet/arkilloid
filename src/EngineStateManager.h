#ifndef __ENGINESTATEMANAGER_H__
	#define __ENGINESTATEMANAGER_H__

#include "EngineState.h"

enum {
	ENGINESTATE_NONE,
	ENGINESTATE_INTRO,
	ENGINESTATE_MAINMENU,
	ENGINESTATE_GAME
};

class EngineStateManager {
	private:
		static EngineState* ActiveEngineState;
	
	public:
		static void Event_Process(SDL_Event* Event);
		
		static void Loop_Process();
		
		static void Render_Process(SDL_Surface* Surf_Engine_Window);
	
	public:
		static void SetActiveEngineState(int EngineStateID);
		
		static EngineState* GetActiveEngineState();
};

#endif
