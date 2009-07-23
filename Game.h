//Game.h

#ifndef GAME_H
#define GAME_H

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
#include <vector>

class Game
{
public:
    Game();
    ~Game();
    bool Start();
    bool LoadFiles();
    bool Init();
    bool MainLoop();
    void Close();
    void change_state();
private:
    bool quit;
    Mix_Chunk* hit;
    Mix_Chunk *sound;
    //SDL_Surface *screen;
    GameState *currentState;
    SDL_Event event;
    TTF_Font *font;
    TTF_Font *font_level;
    TTF_Font *font_small;
    //SDL_Color textColor;
};

#endif
