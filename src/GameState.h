//GameState.h
#ifndef GAME_STATE_H
#define GAME_STATE_H
#include "SDLUtils.h"
#include "Texture.h"

class GameState
{
public:
    GameState();
    virtual ~GameState();
    virtual void handle_events(SDL_Event &event) = 0;
    virtual void logic()         = 0;
    virtual void render()        = 0;
    void set_next_state( int newState );
protected:
    Texture *bg;
};

void buttonStart_click();
void buttonExit_click();

#endif
