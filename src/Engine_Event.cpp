#include "Engine.h"
#include <io.hpp>
#include <Game.h>

void Engine::Event_Process(SDL_Event* Event) {
	Game game;
	report("Engine::Event_Process executing", MSG_DEBUG);
	if(Event->type == SDL_QUIT || (Event->type == SDL_KEYDOWN && Event->key.keysym.sym == SDLK_q)) {
		Engine_Running = false;
	}
	//game.Handle_Events(Event);
}
