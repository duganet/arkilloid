#include "EngineState_MainMenu.h"

#include "EngineStateManager.h"

EngineStateMainMenu EngineStateMainMenu::Instance;

EngineStateMainMenu::EngineStateMainMenu() {
	Surf_Background = NULL;
}

void EngineStateMainMenu::OnActivate() {
	/* Load background */
	Surf_Background = Surface::OnLoad("/usr/local/share/arkilloid/images/bg_title.png");

	StartTime = SDL_GetTicks();
}

void EngineStateMainMenu::OnDeactivate() {
	if(Surf_Background) {
		SDL_FreeSurface(Surf_Background);
		Surf_Background = NULL;
	}
}

void EngineStateMainMenu::OnLoop() {
	if(SDL_GetTicks() > StartTime + 3000) {
		EngineStateManager::SetActiveEngineState(ENGINESTATE_MAINMENU);
	}
}

void EngineStateMainMenu::OnRender(SDL_Surface* Surf_Display) {
	if(Surf_Background) {
		Surface::OnDraw(Surf_Display, Surf_Background, 0, 0);
	}
}

EngineStateMainMenu* EngineStateMainMenu::GetInstance() {
	return &Instance;
}
