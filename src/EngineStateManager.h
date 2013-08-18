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
		static void OnEvent(SDL_Event* Event);

		static void OnLoop();

		static void OnRender(SDL_Surface* Surf_Display);

	public:
		static void SetActiveEngineState(int EngineStateID);

		static EngineState* GetActiveEngineState();
};

#endif
