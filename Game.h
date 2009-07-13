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
    SDL_Surface *bg;
    SDL_Surface *brk_spr;
    SDL_Surface *brkstr_spr;
    SDL_Surface *brkbtn_spr;
    SDL_Surface *bita_sprite;
    SDL_Surface *ball_sprite;
    SDL_Surface *bonus_speed_up_spr;
    SDL_Surface *bonus_speed_down_spr;
    SDL_Surface *bonus_life_spr;
    SDL_Surface *bonus_die_spr;
    SDL_Surface *bonus_add_spr;
    SDL_Surface *heart_sprite;
    SDL_Surface *particle_sprite;
    TTF_Font *font;
    TTF_Font *font_level;
    TTF_Font *font_small;
    //SDL_Color textColor;
};

#endif
