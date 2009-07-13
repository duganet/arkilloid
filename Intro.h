//Intro.h
#ifndef INTRO_H
#define INTRO_H

#include "GameState.h"
#include "SDLUtils.h"
#include "Constants.h"
#include "Globals.h"
#include "Timer.h"

class Intro : public GameState
{
public:
    Intro();
    ~Intro();
    void handle_events(SDL_Event &event);
    void logic();
    void render(SDL_Surface *screen);

private:
    Timer introTime;
};




#endif
