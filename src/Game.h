//Game.h

#ifndef GAME_H
#define GAME_H

#include "Constants.h"
#include "GameState.h"
#include "Globals.cpp"
#include "Help.h"
#include "Intro.h"
#include "Level_1.h"
#include "SDLUtils.h"
#include "Texture.h"
#include "Timer.h"
#include "Title.h"
#include "Window.h"
#include <io.hpp>
#include <GLFT_Font.hpp>
#include <vector>

class Game
{
public:
	Game();
	~Game();
	int Exec();
	bool Start();
	bool LoadFiles();
	bool InitGL();
	void Close();
	void change_state();
private:
	bool Init();
	bool MainLoop();
	bool quit;
	GameState *currentState;
	SDL_Event event;
};

#endif
