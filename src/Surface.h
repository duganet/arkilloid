#ifndef _SURFACE_H_
	#define _SURFACE_H_

#include <SDL.h>
#include <SDL_image.h>
#include <io.hpp>

class Surface {
	public:
		Surface();

	public:
		static SDL_Surface* OnLoad(char* File);

		static SDL_Surface* OnLoad(const char* File);

		static SDL_Surface* OnLoad(std::string File, std::string Subdir);

		static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);

		static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H);

		static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};

#endif
