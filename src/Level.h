//Level.h
#ifndef LEVEL_H
#define LEVEL_H

#include "GameState.h"
#include "BrickControl.h"
#include "SDLUtils.h"

class Level : public GameState
{
public:
    Level();
    virtual ~Level();
    virtual void handle_events(SDL_Event &event);
    virtual void logic();
    virtual void render();
};

#endif
