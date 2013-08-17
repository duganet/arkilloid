#include "EngineState_Intro.h"

#include "EngineStateManager.h"

EngineStateIntro EngineStateIntro::Instance;

EngineStateIntro::EngineStateIntro() {
	Surf_Background = NULL;
}

void EngineStateIntro::Activate_Process() {
	/* Load background */
	Surf_Background = Surface::OnLoad("splash.png");
	
	StartTime = SDL_GetTicks();
}

void EngineStateIntro::Deactivate_Process() {
	if(Surf_Background) {
		SDL_FreeSurface(Surf_Background);
		Surf_Background = NULL;
	}
}

void EngineStateIntro::Loop_Process() {
	if(SDL_GetTicks() > StartTime + 3000) {
		EngineStateManager::SetActiveEngineState(ENGINESTATE_MAINMENU);
	}
}

void EngineStateIntro::Render_Process(SDL_Surface* Surf_Engine_Window) {
	if(Surf_Background) {
		Surface::OnDraw(Surf_Engine_Window, Surf_Background, 0, 0);
	}
}

EngineStateIntro* EngineStateIntro::GetInstance() {
	return &Instance;
}
