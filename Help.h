//Help.h
#ifndef HELP_H
#define HELP_H
#include "Intro.h"
#include "Button.h"

class Help : public Intro
{
public:
    Help(SDL_Surface* sprite);
    ~Help();
    void handle_events(SDL_Event &event);
    void render(SDL_Surface* screen);
    void logic();
private:
    Button *buttonStart;
    Button *buttonExit;
};

#endif
