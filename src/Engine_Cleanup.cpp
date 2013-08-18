#include "Engine.h"
#include <SDL_mixer.h>
#include <io.hpp>
#include <sound.hpp>

void Engine::OnCleanup() {
	report("Engine: cleaning up...", MSG_DEBUG);
	::AudioEngine::Stop();

	EngineStateManager::SetActiveEngineState(ENGINESTATE_NONE);

	SDL_FreeSurface(Surf_Display);
	SDL_Quit();
	report("Engine: clean up phase complete.", MSG_DEBUG);
	logfile.close();
}
