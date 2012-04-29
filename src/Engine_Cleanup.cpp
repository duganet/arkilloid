#include "Engine.h"
#include <SDL_mixer.h>
#include <io.hpp>
#include <sound.hpp>

void Engine::Cleanup_Process() {
	report("Engine: cleaning up...", MSG_DEBUG);
	::AudioEngine::Stop();
	SDL_Quit();
	report("Engine: clean up phase complete.", MSG_DEBUG);
	logfile.close();
}
