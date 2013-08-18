#include "Engine.h"

void Engine::OnLoop() {
	Music.CheckPlay();
	EngineStateManager::OnLoop();
}
