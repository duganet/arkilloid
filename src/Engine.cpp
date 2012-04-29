#include "Engine.h"
#include "Game.h"

Engine::Engine() {
	surf_engine = NULL;
	
	engine_running = true;
}

int Engine::Exec() {
	Game game;
	if(game.MainLoop() == false)
	{
		return 1;
	}
	return 0;
}
