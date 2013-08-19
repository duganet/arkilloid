#include "EngineState_Intro.h"

#include "EngineStateManager.h"

EngineStateIntro EngineStateIntro::Instance;

EngineStateIntro::EngineStateIntro() {
	Surf_Background = NULL;
}

void EngineStateIntro::OnLButtonDown(int mX, int mY) {
	EngineStateManager::SetActiveEngineState(ENGINESTATE_MAINMENU);
}

void EngineStateIntro::OnActivate() {
	/* Load background */
	Surf_Background = Surface::OnLoad("images/bg_intro.png");

	StartTime = SDL_GetTicks();
}

void EngineStateIntro::OnDeactivate() {
	if(Surf_Background) {
		SDL_FreeSurface(Surf_Background);
		Surf_Background = NULL;
	}
}

void EngineStateIntro::OnLoop() {
	if(SDL_GetTicks() > StartTime + 3000) {
		EngineStateManager::SetActiveEngineState(ENGINESTATE_MAINMENU);
	}
}

void EngineStateIntro::OnRender(SDL_Surface* Surf_Display) {
	if(Surf_Background) {
		Surface::OnDraw(Surf_Display, Surf_Background, 0, 0);
	}
}

EngineStateIntro* EngineStateIntro::GetInstance() {
	return &Instance;
}
