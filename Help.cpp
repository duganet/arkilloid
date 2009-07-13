//Help.cpp
#include "Help.h"

extern int stateID;
extern int nextState;
extern std::ofstream loger;

Help::Help()
{
    bg = image_load("images/bg_Help.bmp");
    if(bg == NULL)
    {
        log("ERROR: bg_title.bmp not load");
        stateID = STATE_EXIT;
    }
    buttonStart = new Button(413,436, "images/buttonStart.bmp");
    buttonExit = new Button(518,436, "images/buttonExit.bmp");
    SDL_WM_GrabInput(SDL_GRAB_OFF);
}

Help::~Help()
{
    SDL_FreeSurface(bg);
    bg = NULL;
    delete buttonExit;
    delete buttonStart;
}

void Help::handle_events(SDL_Event &event)
{
    buttonStart->handle_events(event, buttonStart_click);
    buttonExit->handle_events(event, buttonExit_click);
}

void Help::logic()
{
}

void Help::render(SDL_Surface* screen)
{
    apply_surface(0,0,bg,screen);
    buttonStart->show(screen);
    buttonExit->show(screen);
}
