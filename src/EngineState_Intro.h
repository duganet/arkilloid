#ifndef _ENGINESTATE_INTRO_H_
	#define _ENGINESTATE_INTRO_H_

#include "EngineState.h"
#include "Surface.h"

class EngineStateIntro : public EngineState {
	private:
		static EngineStateIntro Instance;

		SDL_Surface* Surf_Background;

		int StartTime;

	private:
		EngineStateIntro();

	public:
		void OnLButtonDown(int mX, int mY);

	public:
		void OnActivate();

		void OnDeactivate();

		void OnLoop();

		void OnRender(SDL_Surface* Surf_Display);

	public:
		static EngineStateIntro* GetInstance();
};

#endif
