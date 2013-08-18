#ifndef _ENGINESTATE_MAINMENU_H_
	#define _ENGINESTATE_MAINMENU_H_

#include "EngineState.h"
#include "Surface.h"

class EngineStateMainMenu : public EngineState {
	private:
		static EngineStateMainMenu Instance;

		SDL_Surface* Surf_Background;

		int StartTime;

	private:
		EngineStateMainMenu();

	public:
		void OnActivate();

		void OnDeactivate();

		void OnLoop();

		void OnRender(SDL_Surface* Surf_Display);

	public:
		static EngineStateMainMenu* GetInstance();
};

#endif
