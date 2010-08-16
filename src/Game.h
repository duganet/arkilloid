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
#include <file.h>
#include <GLFT_Font.hpp>
#include <vector>

class Game
{
public:
    Game();
    ~Game();
    bool Start();
    bool LoadFiles();
    bool Init();
    bool InitGL();
    bool MainLoop();
    void Close();
    void change_state();
private:
    bool quit;
    GameState *currentState;
    SDL_Event event;
};

#endif
