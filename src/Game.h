//Game.h

#ifndef GAME_H
#define GAME_H

#include "../extern/GLFT_Font/GLFT_Font.h"
#include "Constants.h"
#include "Globals.cpp"
#include "SDLUtils.h"
#include "Timer.h"
#include "GameState.h"
#include "Intro.h"
#include "Title.h"
#include "Help.h"
#include "Level_1.h"
#include "Window.h"
#include "Texture.h"
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
