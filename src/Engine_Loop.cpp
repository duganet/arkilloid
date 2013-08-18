#include "Engine.h"

void Engine::OnLoop() {
	EngineStateManager::OnLoop();
	Music.CheckPlay();
}
