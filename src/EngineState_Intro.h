#ifndef __ENGINESTATE_INTRO_H__
	#define __ENGINESTATE_INTRO_H__

#include "EngineState.h"
#include "Engine_Surface.h"

class EngineStateIntro : public EngineState {
	private:
		static EngineStateIntro Instance;

		SDL_Surface* Surf_Background;

		int StartTime;

	private:
		EngineStateIntro();

	public:
		void OnActivate();

		void OnDeactivate();

		void OnLoop();

		void OnRender(SDL_Surface* Surf_Display);

	public:
		static EngineStateIntro* GetInstance();
};

#endif
