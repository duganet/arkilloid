#include "EngineStateManager.h"
#include <io.hpp>

// Include engine states headers
#include "EngineStateIntro.h"
//#include "EngineStateMainMenu.h"
//#include "EngineStateGame.h"

EngineState* EngineStateManager::ActiveEngineState = 0;

void EngineStateManager::OnEvent(SDL_Event* EventHolder) {
	if(ActiveEngineState) ActiveEngineState->Event_Process(EventHolder);
}

void EngineStateManager::OnLoop() {
	if(ActiveEngineState) ActiveEngineState->Loop_Process();
}

void EngineStateManager::OnRender(SDL_Surface* Surf_Display) {
	if(ActiveEngineState) ActiveEngineState->Render_Process(Surf_Display);
}

void EngineStateManager::SetActiveEngineState(int EngineStateID) {
	if(ActiveEngineState) ActiveEngineState->Deactivate_Process();

	// Also, add your Engine State here so that the Manager can switch to it
	if(EngineStateID == ENGINESTATE_NONE) ActiveEngineState = 0;
	if(EngineStateID == ENGINESTATE_INTRO) ActiveEngineState = EngineStateIntro::GetInstance();
	//if(EngineStateID == ENGINESTATE_MAINMENU) ActiveEngineState = EngineStateMainMenu::GetInstance();
	//if(EngineStateID == ENGINESTATE_GAME) ActiveEngineState = EngineStateGame::GetInstance();

	if(ActiveEngineState) ActiveEngineState->Activate_Process();
}

EngineState* EngineStateManager::GetActiveEngineState() {
	return ActiveEngineState;
}
