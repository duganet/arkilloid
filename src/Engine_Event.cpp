#include "Engine.h"
#include "Game.h"
#include <io.hpp>

void Engine::OnEvent(SDL_Event* Event) {
	Event::OnEvent(Event);

	EngineStateManager::OnEvent(Event);
	//Game game;

	//game.Handle_Events(Event);
}

void Engine::OnExit() {
	Engine_Running = false;
}

void Engine::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	if(sym == SDLK_q) Engine_Running = false;
}
