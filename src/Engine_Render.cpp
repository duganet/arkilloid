#include "Engine.h"

void Engine::OnRender() {
	EngineStateManager::OnRender(Surf_Display);

	SDL_Flip(Surf_Display);
}
