#ifndef _ENGINE_H_
	#define _ENGINE_H_

#include <SDL.h>

class Engine {
	private:
		bool            engine_running;
		
		SDL_Surface*    surf_engine;
		
	public:
		Engine();
		
		int Exec();
		
	public:
		bool Init();

		void Event_Process(SDL_Event* event);
		
		void MainLoop_Process();
		
		void Render_Process();
		
		void Cleanup_Process();
};

#endif
