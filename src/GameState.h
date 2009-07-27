//GameState.h
#ifndef GAME_STATE_H
#define GAME_STATE_H
#include "SDLUtils.h"

class GameState
{
public:
    virtual void handle_events(SDL_Event &event) = 0;
    virtual void logic()         = 0;
    virtual void render(SDL_Surface *screen)        = 0;

    virtual ~GameState(){};
    void set_next_state( int newState );
protected:
    SDL_Surface *bg;
};

void buttonStart_click();
void buttonExit_click();

#endif
