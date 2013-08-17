#include "Engine.h"

void Engine::OnRender() {
	Surface::OnDraw(Surf_Display, Surf_Background, 0, 0);
	
	SDL_Flip(Surf_Display);
}
