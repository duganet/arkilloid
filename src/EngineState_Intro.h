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
		void Activate_Process();
		
		void Deactivate_Process();
		
		void Loop_Process();
		
		void Render_Process(SDL_Surface* Surf_Engine_Window);
	
	public:
		static EngineStateIntro* GetInstance();
};

#endif
